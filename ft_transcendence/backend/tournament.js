import { 
    createTournament, getAllTournaments, updateTournamentWinner
} from './models/tournamentModel.js';
import {
    createMatch, getMatchesByTournament, updateMatchResult, getAllMatches, countPendingMatches, checkWinners
} from './models/t_matchModel.js';

import { getUserIdByName, getUserIdByEmail } from './src/auth.js';

export default async function (fastify) {
    fastify.post('/tournament', { preHandler: fastify.authenticate }, async (request, reply) => {

        const { name, players } = request.body;
        const username = request.user.user;
        const email = request.user.email;

        let created_by;    
        let userObj;

        try {
            if (username)
                userObj = await getUserIdByName(username);
            else if (email)
                userObj = await getUserIdByEmail(email);
            else
                userObj = request.user.userId;

            if (userObj.id)
                created_by = userObj.id;
            else
                created_by = userObj;
            const num_players = players.length;

            const tournament = await createTournament({ name, num_players, created_by });

            const shuffledPlayers = [...players];
            for (let i = shuffledPlayers.length - 1; i > 0; i--) {
                const j = Math.floor(Math.random() * (i + 1));
                [shuffledPlayers[i], shuffledPlayers[j]] = [shuffledPlayers[j], shuffledPlayers[i]];
            }

            const matches = [];
            for (let i = 0; i < shuffledPlayers.length; i += 2) {
                const player1 = shuffledPlayers[i];
                const player2 = i + 1 < shuffledPlayers.length ? shuffledPlayers[i + 1] : null;
                
                const match = await createMatch({ 
                    tournament_id: tournament.id,
                    player1: player1, 
                    player2: player2,
                    round: 1
                });
                
                matches.push(match);
            }
            reply.send({ success: true, tournament, matches });
        } catch (error) {
            console.error('Error al crear torneo:', error);
            reply.status(500).send({ error: 'Error al crear el torneo' });
        }
    });
    
    fastify.post('/updateMatchWinner', async (request, reply) => {
        const { match_id, winner, player1_score, player2_score } = request.body;

        try {
            const result = await updateMatchResult(match_id, player1_score, player2_score, winner);
            reply.send({ success: true, result });
        } catch (error) {
            console.error('Error al actualizar el ganador del partido:', error);
            reply.code(500).send({ error: 'Error al actualizar el ganador del partido' });
        }
    });


    fastify.post('/checkMatches', async (request, reply) => {
        const { tournament_id } = request.body;

        try {
            const pendingMatches = await countPendingMatches(tournament_id);

            if (pendingMatches === 0) {
                const currentRound = await getCurrentRound(tournament_id);
                const winners = await checkWinners(tournament_id, currentRound);
                
                if (winners) {
                
                    let winnerArray = winners.map(winner => winner.winner);
                   
                    if (winnerArray.length > 1) {
                        const nextRoundMatches = [];

                        for (let i = winnerArray.length - 1; i > 0; i--) {
                            const j = Math.floor(Math.random() * (i + 1));
                            [winnerArray[i], winnerArray[j]] = [winnerArray[j], winnerArray[i]];
                        }
                
                        for (let i = 0; i < winnerArray.length; i += 2) {
                            const player1 = winnerArray[i];
                            const player2 = i + 1 < winnerArray.length ? winnerArray[i + 1] : null;
                
                            const match = await createMatch({
                                tournament_id,
                                player1,
                                player2,
                                round: currentRound + 1
                            });
                
                            nextRoundMatches.push(match);
                        }
                        reply.send({ success: true, winners: winnerArray, nextRound: nextRoundMatches });
                        winnerArray = [];
                        return;
                    } else {
                        const winner = winnerArray[0];
                        updateTournamentWinner(winner, tournament_id);
                        reply.send({ success: true, winner: winner });
                        return;
                    }
                
                }
            }

            reply.send({ success: true, pendingMatches });
        } catch (error) {
            console.error('Error al verificar los partidos:', error);
            reply.code(500).send({ error: 'Error al verificar los partidos' });
        }
    });

    fastify.get('/tournaments', async (request, reply) => {
        try {
            const tournaments = await getAllTournaments();
            reply.send(tournaments);
        } catch (error) {
            console.error('Error al obtener torneos:', error);
            reply.status(500).send({ error: 'Error al obtener los torneos' });
        }
    });

    fastify.get('/matches', async (request, reply) => {
        try {
            const matches = await getAllMatches();
            reply.send(matches);
        } catch (error) {
            console.error('Error al obtener partidos:', error);
            reply.status(500).send({ error: 'Error al obtener los partidos' });
        }
    });
    
    fastify.put('/api/matches/:id', async (request, reply) => {
        const { id } = request.params;
        const { player1_score, player2_score, winner } = request.body;
        
        try {
            const result = await updateMatchResult(id, player1_score, player2_score, winner);
            reply.send({ success: true, result });
        } catch (error) {
            console.error('Error al actualizar partido:', error);
            reply.code(500).send({ error: 'Error al actualizar el partido' });
        }
    });

    fastify.get('/matches/:tournamentId', async (request, reply) => {
        const { tournamentId } = request.params;

        try {
            const matches = await getMatchesByTournament(tournamentId);
            reply.send(matches);
        } catch (error) {
            console.error('Error al obtener partidos:', error);
            reply.status(500).send({ error: 'Error al obtener los partidos' });
        }
    });
    
    async function getCurrentRound(tournament_id) {
        const matches = await getMatchesByTournament(tournament_id);
        if (matches.length === 0) return 1;
        const rounds = matches.map(match => match.round);
        return Math.max(...rounds);
    }
}
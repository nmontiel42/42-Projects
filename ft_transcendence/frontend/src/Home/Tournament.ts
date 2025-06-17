const numPlayersInput = document.getElementById('numPlayers') as HTMLInputElement;
const tournamentForm = document.getElementById('tournamentForm') as HTMLFormElement;
const playersInput = document.getElementById('playersInput') as HTMLDivElement;
const generateTournamentBtn = document.getElementById('generateTournamentBtn') as HTMLButtonElement;
const tournamentBracket = document.getElementById('tournamentBracket') as HTMLDivElement;
const tournamentView = document.getElementById('tournamentView') as HTMLDivElement;
const tourWinner = document.getElementById('tourWinner') as HTMLDivElement;
const tournamentWinnerView = document.getElementById('tournamentWinnerView') as HTMLDivElement;

let tournamentId: string;

document.addEventListener('DOMContentLoaded', () => {
    tournamentForm.addEventListener('submit', (event) => {
        event.preventDefault();
    });

    numPlayersInput.addEventListener('change', createTournament);
    numPlayersInput.value = '0';
});

function createTournament(): void {
    const numPlayers = parseInt(numPlayersInput.value);
    playersInput.innerHTML = '';

    for (let i = 0; i < numPlayers; i++) {
        const playerInput = document.createElement('input');
        playerInput.type = 'text';
        playerInput.id = `player${i + 1}`;
        playerInput.name = `player${i + 1}`;
        const lang = localStorage.getItem('lang') || 'es';
        if (lang === 'en') {
            playerInput.placeholder = `Name of player ${i + 1}`;
        }
        else if (lang === 'es') {
            playerInput.placeholder = `Nombre del Jugador ${i + 1}`;
        }
        else if (lang === 'fr') {
            playerInput.placeholder = `Nom du joueur ${i + 1}`;
        }
        playersInput.appendChild(playerInput);
    }
    generateTournamentBtn.onclick = generateBracket;

}

async function generateBracket(): Promise<void> {
    const numPlayers = parseInt(numPlayersInput.value);
    const players: string[] = [];
    const playerNamesSet = new Set<string>();

    for (let i = 0; i < numPlayers; i++) {
        const playerNameInput = document.getElementById(`player${i + 1}`) as HTMLInputElement;
        const playerName = playerNameInput.value.trim();

        if (playerName === '' || playerNamesSet.has(playerName)) {
            const lang = localStorage.getItem('lang') || 'es';
            if (lang === 'en') {
                alert('All players must have a unique name.');
            }
            else if (lang === 'es') {
                alert('Todos los jugadores deben tener un nombre único.');
            }
            else if (lang === 'fr') {
                alert('Tous les joueurs doivent avoir un nom unique.');
            }
            return;
        }

        playerNamesSet.add(playerName);
        players.push(playerName);
    }

    try {
        generateTournamentBtn.disabled = true;
        generateTournamentBtn.textContent = 'Creando torneo...';

        const now = new Date();
        const tournamentName = `Torneo ${now.toLocaleDateString()} ${now.toLocaleTimeString()}`;
        const response = await fetch('https://localhost:3000/tournament', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                'Authorization': `Bearer ${localStorage.getItem('authToken')}`
            },
            body: JSON.stringify({
                name: tournamentName,
                players: players
            })
        });

        if (!response.ok) {
            throw new Error('Error al crear el torneo');
        }

        const data = await response.json();

        tournamentId = data.tournament.id;
        localStorage.setItem('currentTournamentId', tournamentId.toString());

        const winners = data.winners || [];
        const nextRound = data.nextRound || [];

        generateTournamentTree(players, data.tournament, data.matches, winners, nextRound);

        tournamentForm.style.display = 'none';
        playersInput.style.display = 'none';
        tournamentBracket.style.display = 'block';

        const lang = localStorage.getItem('lang') || 'es';
        if (lang === 'en') {
            generateTournamentBtn.textContent = 'New Tournament';
        }
        else if (lang === 'es') {
            generateTournamentBtn.textContent = 'Nuevo Torneo';
        }
        else if (lang === 'fr') {
            generateTournamentBtn.textContent = 'Nouveau Tournoi';
        }
        generateTournamentBtn.disabled = false;
        generateTournamentBtn.onclick = resetTournament;

    } catch (error) {
        console.error('Error:', error);
        generateTournamentBtn.disabled = false;
        const lang = localStorage.getItem('lang') || 'es';
        if (lang === 'en') {
            generateTournamentBtn.textContent = 'Generate Tournament';
        }
        else if (lang === 'es') {
            generateTournamentBtn.textContent = 'Generar Torneo';
        }
        else if (lang === 'fr') {
            generateTournamentBtn.textContent = 'Générer le tournoi';
        }
    }
}

function generateTournamentTree(
    players: string[],
    tournament: any,
    matches: any[],
    winners: string[],
    nextRound: any[] 
): void {
    tournamentBracket.innerHTML = '';

    const numRounds = Math.ceil(Math.log2(players.length));

    const bracketElement = document.createElement('div');
    bracketElement.className = 'tournament-bracket';
    bracketElement.dataset.tournamentId = tournament.id.toString();

    let currentRoundPlayers = [...players];

    for (let round = 0; round < numRounds; round++) {
        const columnElement = document.createElement('div');
        columnElement.className = 'tournament-column';

        const columnTitle = document.createElement('div');
        columnTitle.className = 'column-title';
        columnTitle.textContent = round === 0 ? '1' :
            round === numRounds - 1 ? 'Final' :
                `${round + 1}`;
        columnElement.appendChild(columnTitle);

        const nextRoundPlayers: string[] = [];

        if (round === 0) {
            for (const match of matches) {
                const matchButton = document.createElement('button');
                matchButton.className = 'match-button';
                matchButton.dataset.matchId = (match as any).match_id.toString();

                const player1 = (match as any).player1;
                const player2 = match.player2 || '';

                if (player2 == '') {
                    matchButton.textContent = `${player1}`;
                    matchButton.disabled = true;
                } else {
                    matchButton.textContent = `${player1} vs ${player2}`;
                }

                matchButton.addEventListener('click', () => {

                    currentMatchId = matchButton.dataset.matchId || '';
                    player1Name = player1;
                    player2Name = player2;
                    isTournament = true;
                    aiEnabled = false;
                    localPlayView.style.display = 'block';
                    tournamentView.style.display = 'none';
                    resetButtonLogic();
                    iaGameBtn.style.display = 'none';
                });

                columnElement.appendChild(matchButton);

                if (match.winner) {
                    nextRoundPlayers.push(match.winner);
                } else {
                    const winner = Math.random() < 0.5 ? player1 : player2;
                    nextRoundPlayers.push(winner);
                }
            }
        } else {
            let index = 0;

            for (let i = 0; i < currentRoundPlayers.length; i += 2) {
                const matchButton = document.createElement('button');
                matchButton.className = 'match-button future-match';

                const player1 = nextRound[index++];
                const player2 = nextRound[index++] || '';

                if (player1 === '' || player1 === undefined)
                    matchButton.textContent = '...';
                else if (player1 !== '' && player1 !== undefined && player2 === '')
                    matchButton.textContent = `${player1}`;
                else
                    matchButton.textContent = `${player1} vs ${player2}`;
                matchButton.disabled = true;

                columnElement.appendChild(matchButton);

                if (player2 !== '') {
                    nextRoundPlayers.push(player1);
                    nextRoundPlayers.push(player2);
                } else {
                    nextRoundPlayers.push(player1);
                }
            }
        }
        bracketElement.appendChild(columnElement);
        currentRoundPlayers = nextRoundPlayers;
    }
    tournamentBracket.appendChild(bracketElement);
}

function updateBracket(): void {

    const futureMatches = document.querySelectorAll('.future-match');

    if (nextRound && nextRound.length > 0) {
        let matchIndex = 0;

        futureMatches.forEach((matchBtn) => {
            const matchButton = matchBtn as HTMLButtonElement;
            if (matchIndex < nextRound.length) {
                const match = nextRound[matchIndex];
                const player1 = (match as any).player1;
                const player2 = (match as any).player2 || '';

                if (player1 === '')
                    matchButton.textContent = '...';
                else if (player1 !== '' && player2 === '')
                    matchButton.textContent = `${player1}`;
                else
                    matchButton.textContent = `${player1} vs ${player2}`;
                matchButton.dataset.matchId = (match as any).match_id.toString();

                if (player2 === '')
                    matchButton.disabled = true
                else
                    matchButton.disabled = false;
                matchButton.classList.remove('future-match');

                matchButton.addEventListener('click', () => {
                    currentMatchId = matchButton.dataset.matchId || '';
                    player1Name = player1;
                    player2Name = player2;
                    isTournament = true;
                    aiEnabled = false;
                    const lang = localStorage.getItem("lang") || "es";
                    if (lang === "es") {
                        iaGameBtn.innerText = "Jugar contra IA";
                    }
                    else if (lang === "en") {
                        iaGameBtn.innerText = "Play against AI";
                    }
                    else if (lang === "fr") {
                        iaGameBtn.innerText = "Jouer contre l'IA";
                    }
                    localPlayView.style.display = 'block';
                    tournamentView.style.display = 'none';
                    resetButtonLogic();
                    iaGameBtn.style.display = 'none';
                });
                matchIndex++;
            }
        });
    }
}

function resetTournament(): void {

    tournamentForm.style.display = 'inline-block';
    playersInput.style.display = 'block';

    numPlayersInput.value = '2'; 
    playersInput.innerHTML = ''; 

    tournamentBracket.innerHTML = '';

    const lang = localStorage.getItem('lang') || 'es';
    if (lang === 'en') {
        generateTournamentBtn.textContent = 'Generate Tournament';
    }
    else if (lang === 'es') {
        generateTournamentBtn.textContent = 'Generar Torneo';
    }
    else if (lang === 'fr') {
        generateTournamentBtn.textContent = 'Générer le tournoi';
    }
    generateTournamentBtn.onclick = generateBracket;

    createTournament();

    numPlayersInput.value = '2';
    tourWinner.innerText = ``;
    tournamentWinnerView.style.display = "none";
}

(window as any).createTournament = createTournament;
(window as any).generateBracket = generateBracket;

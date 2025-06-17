import db from '../src/database.js';

export function createMatch({ tournament_id, player1, player2, round }) {
    return new Promise((resolve, reject) => {
        let sql;
        let params;
        if (player2 === null) {
            sql = `INSERT INTO t_match
                        (tournament_id, player1, player2, winner, round, status) 
                        VALUES (?, ?, NULL, ?, ?, 'completed')`;
            params = [tournament_id, player1, player1, round];
        } else {
            sql = `INSERT INTO t_match 
                        (tournament_id, player1, player2, round, status) 
                        VALUES (?, ?, ?, ?, 'pending')`;
            params = [tournament_id, player1, player2, round];
        }
        db.run(sql, params, function(err) {
            if (err) {
                reject(err);
                return;
            }
            
            db.get(`SELECT * FROM t_match WHERE match_id = ?`, [this.lastID], (err, row) => {
                if (err) {
                    reject(err);
                    return;
                }
                resolve(row);
            });
        });
    });
}

export function getMatchById(match_id) {
    return new Promise((resolve, reject) => {
        db.get(`SELECT * FROM t_match WHERE match_id = ?`, [match_id], (err, row) => {
            if (err) reject(err);
            else resolve(row);
        });
    });
}

export function getMatchesByTournament(tournament_id) {
    return new Promise((resolve, reject) => {
        db.all(`SELECT * FROM t_match WHERE tournament_id = ?`, 
            [tournament_id], 
            (err, rows) => {
                if (err) reject(err);
                else resolve(rows);
            }
        );
    });
}

export function getAllMatches() {
    return new Promise((resolve, reject) => {
        db.all(`SELECT * FROM t_match`,
            (err, rows) => {
                if (err) reject(err);
                else resolve(rows);
            }
        );
    });
}

export function updateMatchResult(match_id, player1_score, player2_score, winner) {
    return new Promise((resolve, reject) => {
        const sql = `UPDATE t_match 
                    SET player1_score = ?, player2_score = ?, winner = ?, 
                    status = 'completed'
                    WHERE match_id = ?`;
        
        db.run(sql, [player1_score, player2_score, winner, match_id], function(err) {
            if (err) reject(err);
            else resolve({ match_id, changes: this.changes });
        });
    });
}

export function updateMatchStatus(match_id, status) {
    return new Promise((resolve, reject) => {
        db.run(`UPDATE t_match SET status = ? WHERE match_id = ?`, 
            [status, match_id], 
            function(err) {
                if (err) reject(err);
                else resolve({ match_id, changes: this.changes });
            }
        );
    });
}

export function getPendingMatches(tournament_id) {
    return new Promise((resolve, reject) => {
        db.all(`SELECT * FROM t_match WHERE tournament_id = ? AND status = 'pending'`, 
            [tournament_id], 
            (err, rows) => {
                if (err) reject(err);
                else resolve(rows);
            }
        );
    });
}

export function countPendingMatches(tournament_id) {
    return new Promise((resolve, reject) => {
        db.get(`SELECT COUNT(*) as count FROM t_match WHERE tournament_id = ? AND status = 'pending'`, 
            [tournament_id], 
            (err, row) => {
                if (err) reject(err);
                else resolve(row.count);
            }
        );
    });
}

export function getCompletedMatches(tournament_id) {
    return new Promise((resolve, reject) => {
        db.all(`SELECT * FROM t_match WHERE tournament_id = ? AND status = 'completed'`, 
            [tournament_id], 
            (err, rows) => {
                if (err) reject(err);
                else resolve(rows);
            }
        );
    });
}

export function deleteMatch(match_id) {
    return new Promise((resolve, reject) => {
        db.run(`DELETE FROM t_match WHERE match_id = ?`, [match_id], function(err) {
            if (err) reject(err);
            else resolve({ match_id, changes: this.changes });
        });
    });
}

export function deleteMatchesByTournament(tournament_id) {
    return new Promise((resolve, reject) => {
        db.run(`DELETE FROM t_match WHERE tournament_id = ?`, [tournament_id], function(err) {
            if (err) reject(err);
            else resolve({ tournament_id, changes: this.changes });
        });
    });
}

export function checkWinners(tournament_id, round) {
    return new Promise((resolve, reject) => {
        db.all(
            `SELECT * FROM t_match 
             WHERE tournament_id = ? AND round = ? AND winner IS NOT NULL`,
            [tournament_id, round],
            (err, rows) => {
                if (err) {
                    console.error('Error en checkWinners:', err);
                    reject(err);
                } else {
                    resolve(rows);
                }
            }
        );
    });
}
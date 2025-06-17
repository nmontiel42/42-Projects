import db from '../src/database.js';

export function createTournament({ name, num_players, created_by }) {
    return new Promise((resolve, reject) => {
        const sql = `INSERT INTO tournament 
                    (name, num_players, created_by) 
                    VALUES (?, ?, ?)`;
        
        db.run(sql, [name, num_players, created_by], function(err) {
            if (err) {
                reject(err);
                return;
            }
            
            db.get(`SELECT * FROM tournament WHERE id = ?`, [this.lastID], (err, row) => {
                if (err) {
                    reject(err);
                    return;
                }
                resolve(row);
            });
        });
    });
}

export function getTournamentById(id) {
    return new Promise((resolve, reject) => {
        db.get(`SELECT * FROM tournament WHERE id = ?`, [id], (err, row) => {
            if (err) reject(err);
            else resolve(row);
        });
    });
}

export function getTournamentWinner(id) {
    return new Promise((resolve, reject) => {
        db.get(`SELECT winner FROM tournament WHERE id = ?`, [id], (err, row) => {
            if (err) reject(err);
            else resolve(row.winner);
        });
    });
}

export function getAllTournaments() {
    return new Promise((resolve, reject) => {
        db.all(`SELECT * FROM tournament`, [], (err, rows) => {
            if (err) reject(err);
            else resolve(rows);
        });
    });
}

export function getTournamentsByUser(userId) {
    return new Promise((resolve, reject) => {
        db.all(`SELECT * FROM tournament WHERE created_by = ?`, 
            [userId], 
            (err, rows) => {
                if (err) reject(err);
                else resolve(rows);
            }
        );
    });
}

export function updateTournamentWinner(winner, id) {
    return new Promise((resolve, reject) => {
        db.run(`UPDATE tournament SET winner = ? WHERE id = ?`, 
            [winner, id], 
            function(err) {
                if (err) reject(err);
                else resolve({ id, changes: this.changes });
            }
        );
    });
}

export function deleteTournament(id) {
    return new Promise((resolve, reject) => {
        db.run(`DELETE FROM t_match WHERE tournament_id = ?`, [id], (err) => {
            if (err) {
                reject(err);
                return;
            }
            
            db.run(`DELETE FROM tournament WHERE id = ?`, [id], function(err) {
                if (err) reject(err);
                else resolve({ id, changes: this.changes });
            });
        });
    });
}
import { generateEmailVerificationCode, verifyEmailVerificationCode } from "../firebaseConfigFile.js";
import db from '../src/database.js';
import bcrypt from 'bcrypt';


export default async function(fastify, options) {

	fastify.get('/2fa-test', async(request, reply) => {
		return { status: 'ok', message: '2FA routes are registered' };
	});

	fastify.post('/enroll-2fa', { preHandler:fastify.authenticate }, async(request, reply) => {
        try {
            const { email } = request.body;
            
            const user = await getUserByEmail(email);
            if (!user) {
                return reply.status(404).send({ error: 'User not found' });
            }
            
            const session = await generateEmailVerificationCode(email);
            await saveSessionInfo(user.id, session.sessionInfo);
            await updateUserWith2FA(user.id, email, 'pending');
            
            reply.send({
                success: true,
                sessionInfo: session.sessionInfo,
                email
            });
        } catch (error) {
            console.error('Error enrolling 2FA:', error);
            reply.status(500).send({ error: 'Failed to enroll 2FA', details: error.message });
        }
    });

	fastify.post('/verify-2fa-enrollment', { preHandler: fastify.authenticate }, async(request, reply) => {
        try {
            const { verificationCode, sessionInfo, email } = request.body;

            const user = await getUserByEmail(email);
            if (!user) {
                return reply.status(404).send({ error: 'User not found' });
            }
            
            const emailVerified = await verifyEmailVerificationCode(sessionInfo, verificationCode);
            
            if (emailVerified) {
                await updateUserWith2FA(user.id, email, 'active');
                reply.send({
                    success: true,
                    message: '2FA has been successfully enabled'
                });
            } else {
                reply.status(400).send({ error: 'Invalid verification code' });
            }
        } catch(error) {
            console.error('Error verifying 2FA code:', error);
            reply.status(500).send({ error: ' code', details: error.message });
        }
    });

	fastify.post('/login-with-2fa', async (request, reply) => {
		try {
			const { email, password } = request.body;

			if (!email || !password){
				return reply.status(400).send({
					error: 'Missing required fields'
				});
			}

			const user = await getUserByEmail(email);

			if (!user) {
				return reply.status(400).send({ error: 'User not found' });
			}
			
			const validPassword = await bcrypt.compare(password, user.password)
			if (!validPassword) {
				return reply.status(400).send({ error: 'Invalid password' });
			}
			
			if (user.has2FA === 1 && user.two_fa_status === 'active') {
				try{
					const emailTo = user.two_fa_email || user.email;
					const session = await generateEmailVerificationCode(emailTo);
					
					await saveSessionInfo(user.id, session.sessionInfo);
					
					const tempToken = fastify.jwt.sign({
						userId: user.id,
						requires2FA: true
					}, { expiresIn: '5m' });
					
					return reply.send({
						requires2FA: true,
						tempToken,
						userId: user.id,
						sessionInfo: session.sessionInfo,
						message: 'Verification code sent to your email'
					});
				}catch (error){
					console.error('Error generating 2FA code:', error);
					return reply.status(500).send({
						error: 'Error generating 2FA code'
					});
				}
			}
			
			const token = fastify.jwt.sign({ userId: user.id, email: user.email, username: user.username });
			return reply.send({
				token,
				username: user.username,
				email: user.email,
				id: user.id,
				picture: user.picture,
				has2FA: user.has2FA || 0,
				two_fa_status: user.two_fa_status || 'inactive',
				requires2FA: false
			});
		} catch(error) {
			console.error('Error in 2FA login:', error);
			return reply.status(500).send({ error: 'Error during login', details: error.message });
		}
	});
	fastify.post('/verify-2fa-login', async(request, reply) => {
		try{

			const { verificationCode, tempToken } = request.body;
			if (!verificationCode || !tempToken) {
                return reply.status(400).send({ error: 'Missing required fields' });
            }

			let decoded;

			try{
				decoded = fastify.jwt.verify(tempToken);
				if (!decoded.requires2FA){
					return reply.status(400).send({ error: 'invalid token' });
				}
			} catch(error){
				return reply.status(401).send({error: 'Invalid or expired token '});
			}
			const userId = decoded.userId;

			const user = await getUserById(userId);

			if (!user){
				return reply.status(404).send({ error: 'User not found' });
			}

			const email = user.email;

			const isValidCode = await verify2FACodeByEmail(email, verificationCode);
			if (!isValidCode){
				return reply.status(401).send({ error: 'Invalid verification code' });
			}
			const token = fastify.jwt.sign({
				userId: user.id,
				email: user.email,
				username: user.username
			});

			const randomAvatarId = Math.floor(Math.random() * 10) + 1;
			const defaultAvatar = `../public/avatars/avatar${randomAvatarId}.png`;

			return reply.send({
				token,
				username: user.username,
				email: user.email,
				id: user.id,
				picture: defaultAvatar,
				has2FA: user.has2FA || 0,
				two_fa_status: user.two_fa_status || 'inactive'
			});
		}catch (error){
			console.error('Error verifying 2FA loign:', error);
			reply.status(500).send({ error: 'Failed to verify 2FA', details: error.message });
		}
	});

	fastify.post('/2fa-status', { preHandler: fastify.authenticate }, async (request, reply) => {
        try {
            const { email } = request.body;
            
            const user = await getUserByEmail(email);
            if (!user) {
                return reply.status(404).send({ error: 'User not found' });
            }
        
            const status = {
                enabled: user.has2FA === 1,
                status: user.two_fa_status,
                email: user.two_fa_email
            }

            return reply.send(status);
        } catch (error) {
            console.error('Error getting 2FA status:', error);
            return reply.status(500).send({ error: 'Internal server error' });
        }
    });

	fastify.post('/disable-2fa', { preHandler: fastify.authenticate }, async (request, reply) => {
        
        try {
            const { email } = request.body;
            
            if (!email) {
                console.error('No email provided in request');
                return reply.status(400).send({ error: 'Missing email parameter' });
            }
            
            const user = await getUserByEmail(email);
            
            if (!user) {
                return reply.status(404).send({ error: 'User not found' });
            }
            
            db.run(
				`UPDATE users SET has2FA = 0, two_fa_status = 'inactive' WHERE id = ?`,
				[user.id]
			);
            
            const token = fastify.jwt.sign({ 
                userId: user.id,
                email: user.email,
                username: user.username
            });

            return reply.send({
                success: true,
                message: '2FA has been successfully disabled',
                token,
                user: {
                    id: user.id,
                    username: user.username,
                    email: user.email,
                    has2FA: 0,
                    two_fa_status: 'inactive'
                }
            });
        } catch (error) {
            console.error('Error disabling 2FA:', error);
            return reply.status(500).send({ error: 'Internal server error', details: error.message });
        }
    });

}

async function getUserById(id){
	return new Promise((resolve, reject) => {
		db.get(
			`SELECT id, username, email, has2FA, two_fa_status, two_fa_email FROM users WHERE id = ?`,
			[id],
			(err, row) => {
				if (err) reject(err);
				else resolve(row);
			}
		);
	});
}

async function updateUserWith2FA(userId, email, status = 'active') {
	return new Promise((resolve, reject) => {
		db.run(
			`UPDATE users SET "has2FA" = 1, "two_fa_email" = ?, two_fa_status = ? WHERE id = ?`,
			[email, status, userId],
			function(err) {
				if (err) reject(err);
				else resolve({ updated: this.changes > 0 });
			}
		);
	});
}

export async function saveSessionInfo(userId, sessionInfo){
	return new Promise((resolve, reject) => {
		db.run(
			`INSERT INTO user_2fa_sessions (user_id, session_info, created_at)
			 VALUES (?, ?, datetime('now'))`,
			[userId, sessionInfo],
			function(err){
				if (err) reject(err);
				else resolve({ id: this.lastID});
			}
		);
	});
}

export async function saveSessionInfoByEmail(email, sessionInfo) {
    const user = await getUserByEmail(email);
    if (!user) throw new Error('User not found');
    
    return saveSessionInfo(user.id, sessionInfo);
}

async function verify2FACodeByEmail(email, code) {
    try {
        const user = await getUserByEmail(email);
        if (!user) return false;
        
        const sessionInfo = await getSessionInfoForUser(user.id);
        if (!sessionInfo) {
            return false;
        }
        return await verifyEmailVerificationCode(sessionInfo, code);
    } catch(error) {
        console.error("Error in verify2FACodeByEmail:", error);
        return false;
    }
}

async function getSessionInfoForUser(userId) {
	return new Promise((resolve, reject) => {
	 db.get(
		`SELECT session_info FROM user_2fa_sessions WHERE user_id = ? ORDER BY created_at DESC LIMIT 1`,
		[userId],
		(err, row) => {
		 if (err) reject(err);
		 else resolve(row ? row.session_info : null);
		}
	 );
	});
}

async function getUserByEmail(email) {
    return new Promise((resolve, reject) => {
        const query = `
            SELECT id, username, email, password, has2FA, two_fa_status, two_fa_email 
            FROM users 
            WHERE email = ?
        `;
        
        db.get(query, [email], (err, row) => {
            if (err) {
                console.error('Database error:', err);
                reject(err);
            } else {
                if (row) {

                    row.has2FA = row.has2FA || 0;
                    row.two_fa_status = row.two_fa_status || 'inactive';
                }
                console.log('Found user:', row);
                resolve(row);
            }
        });
    });
}
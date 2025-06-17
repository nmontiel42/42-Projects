import db from './database.js';
import { createUser } from '../models/userModel.js';
import bcrypt from 'bcryptjs';
import { OAuth2Client } from 'google-auth-library';
import jwt from 'jsonwebtoken';
import dotenv from 'dotenv';
import { generateEmailVerificationCode } from '../firebaseConfigFile.js';
import { saveSessionInfo } from '../controllers/2faControllers.js';

dotenv.config();

export default async function (fastify) {
    fastify.post('/register', async (request, reply) => {
        const { username, email, password } = request.body;

        if (!username || !email || !password) {
            return reply.status(400).send({ error: 'Faltan datos obligatorios' });
        }

        try {
            const hashedPassword = await bcrypt.hash(password, 10);
            const newUser = await createUser({ username, email, password: hashedPassword });

            const token = fastify.jwt.sign({ userId: newUser.id, 
                email: newUser.email
            });

            reply.send({
                message: 'Usuario registrado exitosamente',
                token,
                user: newUser
            });
        } catch (error) {
            console.error('Error en el registro:', error);
            reply.status(500).send({ error: 'Error al registrar el usuario' });
        }
    });

    fastify.post('/login', async (request, reply) => {
        try {
            const { email, password } = request.body;

            if (!email || !password) {
                return reply.status(400).send({ error: 'Email and password are required' });
            }

            const isEmail = /^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(email);
            let user;

            try {
                if (isEmail) {
                    user = await getUserByEmail(email);
                } else {
                    user = await getUserByUsername(email);
                }
            } catch (dbError) {
                console.error('Database error:', dbError);
                return reply.status(500).send({ error: 'Database error' });
            }
            if (!user) {
                return reply.status(400).send({ error: 'Usuario no encontrado' });
            }

            const validPassword = await bcrypt.compare(password, user.password);
            if (!validPassword) {
                return reply.status(400).send({ error: 'Contraseña incorrecta ' });
            }

            if (user.has2FA === 1 && user.two_fa_status === 'active') {
                const emailTo = user.two_fa_email || user.email;
                const session = await generateEmailVerificationCode(emailTo);
                await saveSessionInfo(user.id, session.sessionInfo);
                const tempToken = fastify.jwt.sign(
                    { userId: user.id, requires2FA: true },
                    { expiresIn: '5m' }
                );
                return reply.send({
                    requires2FA: true,
                    tempToken,
                    sessionInfo: session.sessionInfo
                });
            }

            const token = fastify.jwt.sign({
                userId: user.id,
                email: user.email,
                username: user.usename
            });

            const randomAvatarId = Math.floor(Math.random() * 10) + 1;
            const defaultAvatar = `../public/avatars/avatar${randomAvatarId}.png`;

            const responseData = {
                token,
                username: user.username,
                email: user.email,
                id: user.id,
                picture: defaultAvatar,
                has2FA: user.has2FA || 0,
                two_fa_status: user.two_fa_status || 'inactive',
            };
            return reply.send(responseData);
        } catch (error) {
            console.error('Error en el login:', error);
            return reply.status(500).send({ error: 'Error al iniciar sesión' });
        }
    });


    fastify.get('/users', async (request, reply) => {
        try {
            const users = await getAllUsers();
            reply.send(users);
        } catch (error) {
            console.error('Error al obtener usuarios:', error);
            reply.status(500).send({ error: 'Error al obtener los usuarios' });
        }
    });

    const client = new OAuth2Client(process.env.GOOGLE_ID);

    fastify.post('/google-login', async (request, reply) => {
        const { token } = request.body;

        try {

            const googleResponse = await client.verifyIdToken({
                idToken: token,
                audience: process.env.GOOGLE_ID
            });

            const googleData = googleResponse.getPayload();

            if (!googleData.email) {
                return reply.code(401).send({ error: "Invalid Google token" });
            }

            const existingUser = await getUserByEmail(googleData.email);

            if (existingUser) {
                const jwtToken = jwt.sign(
                    { id: googleData.sub, email: googleData.email },
                    process.env.JWT_SECRET,
                    { expiresIn: '1h' }
                );


                if (existingUser.has2FA === 1 && existingUser.two_fa_status === 'active') {
                    const emailTo = existingUser.two_fa_email || existingUser.email;
                    const session = await generateEmailVerificationCode(emailTo);
                    await saveSessionInfo(existingUser.id, session.sessionInfo);
                    const tempToken = fastify.jwt.sign(
                        { userId: existingUser.id, requires2FA: true },
                        { expiresIn: '5m' }
                    );
                    return reply.send({
                        requires2FA: true,
                        tempToken,
                        sessionInfo: session.sessionInfo,
                        token: jwtToken,
                        userExists: true,
                    });
                }

                return reply.send({
                    token: jwtToken,
                    userExists: true,
                    user: {
                        email: googleData.email,
                        name: googleData.name,
                        picture: googleData.picture,
                        locale: googleData.locale,
                        username: existingUser.username,
                        has2FA: existingUser.has2FA || 0,
                        two_fa_status: existingUser.two_fa_status || 'inactive',
                    }
                });

            } else {
                const jwtToken = jwt.sign(
                    { id: googleData.sub, email: googleData.email },
                    process.env.JWT_SECRET,
                    { expiresIn: '1h' }
                );

                return reply.send({
                    token: jwtToken,
                    userExists: false,
                    user: {
                        requires2FA: true,
                        email: googleData.email,
                        name: googleData.name,
                        picture: googleData.picture,
                        locale: googleData.locale,
                        has2FA: 0,
                        two_fa_status: 'inactive',
                    }
                });
            }

        } catch (error) {
            console.error("Google Auth Error:", error);
            return reply.code(500).send({ error: "Server error" });
        }
    });

    fastify.post('/google-username', async (request, reply) => {

        const { token, username } = request.body;

        try {
            const googleResponse = await client.verifyIdToken({
                idToken: token,
                audience: process.env.GOOGLE_ID
            });

            const googleData = googleResponse.getPayload();

            if (!googleData.email) {
                return reply.code(401).send({ error: "Invalid Google token" });
            }

            let user = await getUserByEmail(googleData.email);
            let isNewUser = false;

            if (!user) {
                isNewUser = true;
                const email = googleData.email;
                const password = generateRandomPassword();
                const hashedPassword = await bcrypt.hash(password, 10);

                user = await createUser({ username, email, password: hashedPassword });
            }

            const jwtToken = jwt.sign(
                { id: googleData.sub, email: googleData.email },
                process.env.JWT_SECRET,
                { expiresIn: '1h' }
            );

            return reply.send({
                message: isNewUser ? 'Usuario registrado exitosamente' : 'Iniciado de sesion exitoso',
                token: jwtToken,
                picture: googleData.picture,
                user: user,
                has2FA: user.has2FA || 0,
                two_fa_status: user.two_fa_status || 'inactive',
            });
        } catch (error) {
            console.error("Google Auth Error:", error);
            return reply.code(500).send({ error: "Server error" });
        }
    });


    fastify.delete('/delete-account', { preHandler: fastify.authenticate }, async (req, reply) => {
        const email = req.user.email;
    
        if (!email) {
            return reply.status(400).send({ error: 'Email no proporcionado' });
        }

        db.run('DELETE FROM users WHERE email = ?', [email], function (err) {
            if (err) {
                console.error('Error al eliminar la cuenta:', err);
                return reply.status(500).send({ error: 'Error al eliminar la cuenta' });
            }
            if (this.changes === 0) {
                return reply.status(404).send({ error: 'No se encontró el usuario' });
            }
            reply.send({ message: 'Cuenta eliminada correctamente' });
        });
    });

    fastify.post('/change-username', { preHandler: fastify.authenticate }, async (request, reply) => {
        const { username } = request.body;
        const { email } = request.user;
    
        if (!username || username.trim().length === 0) {
            return reply.status(400).send({ error: 'El nombre de usuario no puede estar vacío.' });
        }

        if (!email) {
            console.error('No se proporcionó email en el token JWT');
            return reply.status(400).send({ error: 'No se pudo identificar al usuario.' });
        }

        try {

            const existingUser = await new Promise((resolve, reject) => {
                db.get('SELECT * FROM users WHERE username = ? AND email != ?', [username, email], (err, row) => {
                    if (err) {
                        console.error('Error al verificar el nombre de usuario existente:', err);
                        return reject(err);
                    }
                    resolve(row);
                });
            });

            if (existingUser) {
                return reply.status(400).send({ error: 'El nombre de usuario ya está en uso.' });
            }

            await new Promise((resolve, reject) => {
                db.run('UPDATE users SET username = ? WHERE email = ?', [username, email], function (err) {
                    if (err) {
                        console.error('Error al actualizar el nombre de usuario:', err);
                        return reject(err);
                    }

                    if (this.changes === 0) {
                        return reject(new Error('No se encontró el usuario para actualizar.'));
                    }

                    resolve();
                });
            });

            reply.send({
                message: 'Nombre de usuario actualizado correctamente.',
                username: username
            });

        } catch (error) {
            console.error('Error en el cambio de nombre de usuario:', error);
            return reply.status(500).send({ error: 'Error en el servidor al cambiar el nombre de usuario.' });
        }
    });

}

function generateRandomPassword(length = 12) {
    const chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+';
    let password = '';
    for (let i = 0; i < length; i++) {
        password += chars.charAt(Math.floor(Math.random() * chars.length));
    }
    return password;
}

async function getUserByEmail(email) {
    return new Promise((resolve, reject) => {
        db.get(
            `SELECT id, username, email, password, has2FA, two_fa_status, two_fa_email 
             FROM users WHERE email = ?`,
            [email],
            (err, row) => {
                if (err) {
                    console.error('Database error:', err);
                    reject(err);
                } else {
                    console.log('Found user:', row);
                    resolve(row);
                }
            }
        );
    });
}

export async function getUserIdByEmail(email) {
    return new Promise((resolve, reject) => {
        db.get(
            `SELECT id FROM users WHERE email = ?`,
            [email],
            (err, row) => {
                if (err) reject(err);
                else resolve(row);
            }
        );
    });
}

async function getAllUsers() {
    return new Promise((resolve, reject) => {
        db.all(
            `SELECT * FROM users`,
            [],
            (err, rows) => {
                if (err) reject(err);
                else resolve(rows);
            }
        );
    });
}

async function getUserById(id) {
    return new Promise((resolve, reject) => {
        db.get(
            `SELECT username FROM users WHERE id = ?`,
            [id],
            (err, row) => {
                if (err) reject(err);
                else resolve(row);
            }
        );
    });
}

export function getUserIdByName(username) {
    return new Promise((resolve, reject) => {
        db.get(
            `SELECT id FROM users WHERE username = ?`,
            [username],
            (err, row) => {
                if (err) reject(err);
                else resolve(row);
            }
        );
    });
}

function getUserByUsername(username) {
    return new Promise((resolve, reject) => {
        db.get(
            `SELECT * FROM users WHERE username = ?`,
            [username],
            (err, row) => {
                if (err) reject(err);
                else resolve(row);
            }
        );
    });
}
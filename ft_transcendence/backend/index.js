import Fastify from 'fastify';
import cors from '@fastify/cors';
import jwt from '@fastify/jwt';
import dotenv from 'dotenv';
import authRoutes from './src/auth.js';
import fs from 'fs';
import tournamentRoutes from './tournament.js';
import fastifyStatic from "@fastify/static";
import { fileURLToPath } from 'url';
import path from 'path';
import twoFactorAuthRoutes from './controllers/2faControllers.js';

const app = Fastify();

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

app.register(fastifyStatic, {
  root: path.join(__dirname, "../frontend"),
  prefix: "/",
});

app.setNotFoundHandler((req, reply) => {
  reply.sendFile("index.html");
});

dotenv.config();

const fastify = Fastify({
	https: {
	  key: fs.readFileSync('/app/certs/nginx-selfsigned.key'),
	  cert: fs.readFileSync('/app/certs/nginx-selfsigned.crt'),
	}
});

fastify.register(cors, {
  origin: true,
  methods: ['GET', 'POST', 'PUT', 'DELETE', 'PATCH'],
  credentials: true,
  allowedHeaders: ['Content-Type', 'Authorization'],
});

fastify.register(jwt, {
  secret: process.env.JWT_SECRET,
  sign: {
    expiresIn: '1d',
  },
});

fastify.addHook('onSend', (request, reply, payload, done) => {
  reply.header('Cross-Origin-Opener-Policy', 'same-origin-allow-popups');
  reply.header('Cross-Origin-Embedder-Policy', 'require-corp');

  reply.header('Content-Security-Policy', 
    "default-src 'self'; " +
    "script-src 'self' https://accounts.google.com https://*.googleusercontent.com 'unsafe-inline'; " +
    "frame-src https://accounts.google.com; " +
    "connect-src 'self' https://accounts.google.com https://localhost:3000; " +
    "img-src 'self' https://accounts.google.com data:; " +
    "style-src 'self' 'unsafe-inline' https://accounts.google.com; " +
    "frame-ancestors 'none';"
  );
  reply.header('X-Content-Type-Options', 'nosniff');
  reply.header('X-XSS-Protection', '1; mode=block');
  done();
});


fastify.decorate('authenticate', async (req, res) => {
  try {
    await req.jwtVerify();
    const token = await req.jwtDecode();
    req.user = { 
      userId: token.userId || token.id,
      email: token.email
    };
  } catch (err) {
    res.send(err);
  }
});

fastify.register(authRoutes);

fastify.register(tournamentRoutes);

fastify.register(twoFactorAuthRoutes);

fastify.listen({
  port: 3000,
  host: '0.0.0.0',
}, (err, address) => {
  if (err) {
    console.error(err);
    process.exit(1);
  }
  console.log(`Servidor Fastify corriendo en ${address}`);
});

export default fastify;
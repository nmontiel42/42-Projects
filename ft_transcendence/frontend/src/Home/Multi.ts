const multiplayerContainer = document.getElementById('multiplayerContainer')!;
const canvas2 = document.getElementById('multiplayerCanvas') as unknown as HTMLCanvasElement;

const restartBtn = document.getElementById("restartMultiplayerBtn") as HTMLButtonElement;
const stopStartBtn = document.getElementById("stopStartMultiplayerBtn") as HTMLButtonElement;

canvas2.width = 600;
canvas2.height = 600;
const ctx2 = canvas2.getContext('2d')!;

const paddleWidth2 = 10;
const paddleHeight2 = 100;
const paddleSpeed = 5;
const horizontalPaddleWidth2 = 100;
const horizontalPaddleHeight2 = 10;

let lastTouchedBy: 'left' | 'right' | 'top' | 'bottom' | null = null;

const scores = {
  left: 0,
  right: 0,
  top: 0,
  bottom: 0,
};

const paddles = {
  left: { x: 0, y: canvas2.height / 2 - paddleHeight2 / 2, width: paddleWidth2, height: paddleHeight2, dy: 0 },
  right: { x: canvas2.width - paddleWidth2, y: canvas2.height / 2 - paddleHeight2 / 2, width: paddleWidth2, height: paddleHeight2, dy: 0 },
  top: { x: canvas2.width / 2 - horizontalPaddleWidth2 / 2, y: 0, width: horizontalPaddleWidth2, height: horizontalPaddleHeight2, dx: 0 },
  bottom: { x: canvas2.width / 2 - horizontalPaddleWidth2 / 2, y: canvas2.height - horizontalPaddleHeight2, width: horizontalPaddleWidth2, height: horizontalPaddleHeight2, dx: 0 },
};

const ball2 = {
  x: canvas2.width / 2,
  y: canvas2.height / 2,
  radius: 10,
  speed: 4,
  dx: 4,
  dy: 4,
};

let isMultiPaused = true;
let ballMultiPreviousX = ball2.dx;
let ballMultiPreviousY = ball2.dy;
const winnerMultiScore = 5;

const keys: Record<string, boolean> = {};

window.addEventListener('keydown', (e) => {
  if (typeof e.key === 'string') {
    keys[e.key.toLowerCase()] = true;
  }
});

window.addEventListener('keyup', (e) => {
  if (typeof e.key === 'string') {
    keys[e.key.toLowerCase()] = false;
  }
});


function movePaddles() {
  if (keys['w']) paddles.left.dy = -paddleSpeed;
  else if (keys['s']) paddles.left.dy = paddleSpeed;
  else paddles.left.dy = 0;

  paddles.left.y += paddles.left.dy;
  paddles.left.y = Math.max(0, Math.min(canvas2.height - paddles.left.height, paddles.left.y));

  if (keys['arrowup']) paddles.right.dy = -paddleSpeed;
  else if (keys['arrowdown']) paddles.right.dy = paddleSpeed;
  else paddles.right.dy = 0;

  paddles.right.y += paddles.right.dy;
  paddles.right.y = Math.max(0, Math.min(canvas2.height - paddles.right.height, paddles.right.y));

  if (keys['t']) paddles.top.dx = -paddleSpeed;
  else if (keys['y']) paddles.top.dx = paddleSpeed;
  else paddles.top.dx = 0;

  paddles.top.x += paddles.top.dx;
  paddles.top.x = Math.max(0, Math.min(canvas2.width - paddles.top.width, paddles.top.x));

  if (keys['b']) paddles.bottom.dx = -paddleSpeed;
  else if (keys['n']) paddles.bottom.dx = paddleSpeed;
  else paddles.bottom.dx = 0;

  paddles.bottom.x += paddles.bottom.dx;
  paddles.bottom.x = Math.max(0, Math.min(canvas2.width - paddles.bottom.width, paddles.bottom.x));
}

function moveBall2() {
  ball2.x += ball2.dx;
  ball2.y += ball2.dy;

  if (ball2.x - ball2.radius < 0 || ball2.x + ball2.radius > canvas2.width) {
    if (lastTouchedBy) scores[lastTouchedBy]++;
    ball2.dx *= -1;
    lastTouchedBy = null;
  }

  if (ball2.y - ball2.radius < 0 || ball2.y + ball2.radius > canvas2.height) {
    if (lastTouchedBy) scores[lastTouchedBy]++;
    ball2.dy *= -1;
    lastTouchedBy = null;
  }

  if (collision(ball2, paddles.left)) {
    ball2.dx = Math.abs(ball2.dx);
    lastTouchedBy = 'left';
  }
  if (collision(ball2, paddles.right)) {
    ball2.dx = -Math.abs(ball2.dx);
    lastTouchedBy = 'right';
  }
  if (collision(ball2, paddles.top)) {
    ball2.dy = Math.abs(ball2.dy);
    lastTouchedBy = 'top';
  }
  if (collision(ball2, paddles.bottom)) {
    ball2.dy = -Math.abs(ball2.dy);
    lastTouchedBy = 'bottom';
  }

}

function collision(ball2: typeof ball, paddle: typeof paddles.left | typeof paddles.top) {
  return (
    ball2.x - ball2.radius < paddle.x + paddle.width &&
    ball2.x + ball2.radius > paddle.x &&
    ball2.y - ball2.radius < paddle.y + paddle.height &&
    ball2.y + ball2.radius > paddle.y
  );
}

function draw() {

  ctx2.clearRect(0, 0, canvas2.width, canvas2.height);

  ctx2.fillStyle = "rgba(11, 34, 90, 0.85)";
  ctx2.fillRect(0, 0, canvas2.width, canvas2.height);

  ctx2.font = "16px 'Press Start 2P', cursive";
  ctx2.fillStyle = "white";
  ctx2.textAlign = "center";

  ctx2.textAlign = "left";
  ctx2.fillStyle = "#FF00FF";
  ctx2.fillText("Pang", 10, 20);
  ctx2.fillText(`${scores.left}`, 10, 40);
  ctx2.fillRect(paddles.left.x, paddles.left.y, paddles.left.width, paddles.left.height);

  ctx2.textAlign = "right";
  ctx2.fillStyle = "#00FFFF";
  ctx2.fillText("Pung", canvas2.width - 10, 20);
  ctx2.fillText(`${scores.top}`, canvas2.width - 10, 40);
  ctx2.fillRect(paddles.top.x, paddles.top.y, paddles.top.width, paddles.top.height);

  ctx2.textAlign = "left";
  ctx2.fillStyle = "#39FF14";
  ctx2.fillText(`${scores.bottom}`, 10, canvas2.height - 30);
  ctx2.fillText("Ping", 10, canvas2.height - 10);
  ctx2.fillRect(paddles.bottom.x, paddles.bottom.y, paddles.bottom.width, paddles.bottom.height);

  ctx2.textAlign = "right";
  ctx2.fillStyle = "#FFFF33";
  ctx2.fillText(`${scores.right}`, canvas2.width - 10, canvas2.height - 30);
  ctx2.fillText("Pong", canvas2.width - 10, canvas2.height - 10);
  ctx2.fillRect(paddles.right.x, paddles.right.y, paddles.right.width, paddles.right.height);

  ctx2.beginPath();
  ctx2.arc(ball2.x, ball2.y, ball2.radius, 0, Math.PI * 2);
  ctx2.fillStyle = "#FFFFFF";
  ctx2.fill();
  ctx2.closePath();
}


function gameLoop2() {
  if (isMultiPaused)
    return;
  movePaddles();
  moveBall2();
  const winner = checkWinner();
  if (winner) {
    draw();
    showWinnerMessage(winner);
    isMultiPaused = true;
    stopStartBtn.disabled = true;
    return;
  }

  draw();
  requestAnimationFrame(gameLoop2);
}

function startMultiplayer() {
  isMultiPaused = true;

  multiplayerContainer.style.display = 'block';
  const canvas2 = multiplayerContainer.querySelector('canvas')!;
  if (canvas2) {
    canvas2.style.display = 'block';
  }

  ball2.x = canvas2.width / 2;
  ball2.y = canvas2.height / 2;
  ball2.dx = 0;
  ball2.dy = 0;

  scores.left = 0;
  scores.right = 0;
  scores.top = 0;
  scores.bottom = 0;
  ballMultiPreviousX = 4;
  ballMultiPreviousY = 4;

  paddles.left.y = canvas2.height / 2 - paddleHeight2 / 2;
  paddles.right.y = canvas2.height / 2 - paddleHeight2 / 2;
  paddles.top.x = canvas2.width / 2 - horizontalPaddleWidth2 / 2;
  paddles.bottom.x = canvas2.width / 2 - horizontalPaddleWidth2 / 2;

  const lang = localStorage.getItem("lang") || "es";
  if (lang === "es") stopStartBtn.textContent = "Iniciar Juego";
  if (lang === "en") stopStartBtn.textContent = "Start Game";
  if (lang === "fr") stopStartBtn.textContent = "ADémarrer le Jeu";
  stopStartBtn.disabled = false;
}

function stopMultiplayer() {
  isMultiPaused = true;
  const canvas2 = multiplayerContainer.querySelector('canvas')!;
  if (canvas2) {
    canvas2.style.display = 'none';
    ctx2.clearRect(0, 0, canvas2.width, canvas2.height);
  }
}

function checkWinner(): string | null {
  for (const side in scores) {
    if (scores[side as keyof typeof scores] >= winnerMultiScore) {
      return side;
    }
  }
  return null;
}

function showWinnerMessage(winner: string) {
  const lang = localStorage.getItem("lang") || "es";

  const boxWidth = canvas2.width * 0.8;
  const boxHeight = 120;
  const boxX = (canvas2.width - boxWidth) / 2;
  const boxY = (canvas2.height - boxHeight) / 2;

  ctx2.fillStyle = "rgba(0, 0, 0, 0.75)";
  ctx2.strokeStyle = "#BE36CD";
  ctx2.lineWidth = 4;
  ctx2.beginPath();
  ctx2.roundRect(boxX, boxY, boxWidth, boxHeight, 20);
  ctx2.fill();
  ctx2.stroke();

  ctx2.font = "28px 'Press Start 2P', cursive";
  ctx2.textAlign = "center";
  ctx2.textBaseline = "middle";

  const playerNames: Record<string, string> = {
    left: "Pang",
    right: "Pong",
    top: "Pung",
    bottom: "Ping"
  };

  let message = "";
  if (lang === "es") {
    message = `¡${playerNames[winner]} gana!`;
  } else if (lang === "en") {
    message = `${playerNames[winner]} wins!`;
  } else if (lang === "fr") {
    message = `${playerNames[winner]} gagne!`;
  }

  ctx2.fillStyle = "#FFFFFF";
  ctx2.shadowColor = "#000000";
  ctx2.shadowBlur = 6;
  ctx2.fillText(message, canvas2.width / 2, canvas2.height / 2);

  ctx2.shadowBlur = 0;
}

restartBtn.addEventListener("click", () => {
  startMultiplayer();
});

stopStartBtn.addEventListener("click", () => {
  const lang = localStorage.getItem("lang") || "es";

  if (!isMultiPaused) {

    ballMultiPreviousX = ball2.dx;
    ballMultiPreviousY = ball2.dy;
    ball2.dx = 0;
    ball2.dy = 0;
    isMultiPaused = true;
    if (lang === "es") stopStartBtn.textContent = "Reanudar Juego";
    if (lang === "en") stopStartBtn.textContent = "Resume Game";
    if (lang === "fr") stopStartBtn.textContent = "Reprendre le Jeu";
  } else {
    ball2.dx = ballMultiPreviousX;  
    ball2.dy = ballMultiPreviousY;  
    isMultiPaused = false;
    gameLoop2();
    if (lang === "es") stopStartBtn.textContent = "Detener Juego";
    if (lang === "en") stopStartBtn.textContent = "Stop Game";
    if (lang === "fr") stopStartBtn.textContent = "Arrêter le Jeu";
  }
});
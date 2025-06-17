interface Paddle {
  width: number;
  height: number;
  x: number;
  y: number;
  dy: number;
}

interface Ball {
  radius: number;
  x: number;
  y: number;
  dx: number;
  dy: number;
}

const canvas = document.getElementById("pongCanvas") as unknown as HTMLCanvasElement;
const ctx = canvas.getContext("2d") as CanvasRenderingContext2D;

const paddleWidth = 10;
const paddleHeight = 100;
const ballRadius = 10;


let leftPaddle: Paddle;
let rightPaddle: Paddle;
let ball: Ball;
let animation: number;
let player1Score: number = 0;
let player2Score: number = 0;
let player1Name = "Ping";
let player2Name = "Pong";
const winnerScore = 5;
let isTournament: boolean = false;
let currentMatchId: string;
let isGameOver: boolean = false;

let winner: string = "";

let isGamePaused: boolean = true;
let newGame: boolean = true;

let winners: string[] = [];
let nextRound: string[] = [];

const inicialBallSpeed = 6;
const maxBallSpeed = 20;
const speedIncrement = 0.01;

let aiEnabled = false;
let aiTargetY: number = canvas.height / 2 - paddleHeight / 2;

let countdownInterval: number | undefined = undefined;

function initializeGame() {
  leftPaddle = {
    width: paddleWidth,
    height: paddleHeight,
    x: 0,
    y: canvas.height / 2 - paddleHeight / 2,
    dy: 0,
  };

  rightPaddle = {
    width: paddleWidth,
    height: paddleHeight,
    x: canvas.width - paddleWidth,
    y: canvas.height / 2 - paddleHeight / 2,
    dy: 0,
  };

  ball = {
    radius: ballRadius,
    x: canvas.width / 2,
    y: canvas.height / 2,
    dx: 6,
    dy: 6,
  };
  gameLoop();
  cancelAnimationFrame(animation);
  drawGame();
}

function drawGame() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);

  ctx.font = "20px 'Press Start 2P', cursive";
  ctx.fillStyle = "white";
  ctx.textAlign = "center";
  
  if(!isTournament){
    player1Name = "Ping";
    if(aiEnabled)
      player2Name = "IA";
    else
      player2Name = "Pong";
  }
  ctx.fillText(player1Name, canvas.width / 4, 35);
  ctx.fillText(player2Name, (canvas.width / 4) * 3, 35);

  ctx.font = "25px 'Press Start 2P', cursive";
  ctx.fillStyle = "white";

  ctx.fillText(player1Score.toString(), canvas.width / 4, 80);
  ctx.fillText(player2Score.toString(), (canvas.width / 4) * 3, 80);

  ctx.fillStyle = "#BE36CD";
  ctx.fillRect(leftPaddle.x, leftPaddle.y, leftPaddle.width, leftPaddle.height);

  ctx.fillRect(rightPaddle.x, rightPaddle.y, rightPaddle.width, rightPaddle.height);

  ctx.beginPath();
  ctx.arc(ball.x, ball.y, ball.radius, 0, Math.PI * 2);
  ctx.fillStyle = "#FFFFFF";
  ctx.fill();
  ctx.closePath();
}

function moveGameObjects() {
  updatePaddlePositions();

  if (Math.abs(ball.dx) < maxBallSpeed) {
    ball.dx += ball.dx > 0 ? speedIncrement : -speedIncrement;
  }

  ball.x += ball.dx;
  ball.y += ball.dy;

  if (ball.y - ball.radius < 0 || ball.y + ball.radius > canvas.height) {
    ball.dy = -ball.dy;
  }

  const paddleCollisionMargin = 6;

  if (ball.x - ball.radius < leftPaddle.x + leftPaddle.width + paddleCollisionMargin &&
    ball.x - ball.radius > leftPaddle.x - paddleCollisionMargin &&
    ball.y > leftPaddle.y - paddleCollisionMargin && ball.y < leftPaddle.y + leftPaddle.height + paddleCollisionMargin) {
    ball.dx = -ball.dx;

    const impactPosition = (ball.y - leftPaddle.y) / leftPaddle.height;

    ball.dy = 8 * (impactPosition - 0.5);

    ball.x = leftPaddle.x + leftPaddle.width + ball.radius;

    if(aiEnabled)
      updateAITarget();
  }

  if (ball.x + ball.radius > rightPaddle.x - paddleCollisionMargin &&
    ball.x + ball.radius < rightPaddle.x + rightPaddle.width + paddleCollisionMargin &&
    ball.y > rightPaddle.y - paddleCollisionMargin && ball.y < rightPaddle.y + rightPaddle.height + paddleCollisionMargin) {
    ball.dx = -ball.dx;

    const impactPosition = (ball.y - rightPaddle.y) / rightPaddle.height;

    ball.dy = 8 * (impactPosition - 0.5);

    ball.x = rightPaddle.x - ball.radius;
  }

  if (ball.x - ball.radius < 0) {
    player2Score++;
    resetBall();
  } else if (ball.x + ball.radius > canvas.width) {
    player1Score++;
    resetBall();
  }
  if (player1Score === winnerScore || player2Score === winnerScore) {
    isGameOver = true;
    cancelAnimationFrame(animation);
    showGameResult();
  }
}

function resetButtonLogic() {
  const lang = localStorage.getItem("lang") || "es";

  switch (lang) {
    case "es":
      resetGameBtn.innerText = "Reiniciar Juego";
      startGameBtn.innerText = "Iniciar Juego";
      break;
    case "en":
      resetGameBtn.innerText = "Restart Game";
      startGameBtn.innerText = "Start Game";
      break;
    case "fr":
      resetGameBtn.innerText = "Redémarrer le jeu";
      startGameBtn.innerText = "Commencer le jeu";
      break;
  }

  resetAll();
  isGamePaused = true;
  newGame = true;
  cancelAnimationFrame(animation);
  drawGame();
  startGameBtn.style.display = "block";
  if(!isTournament)
    iaGameBtn.style.display = "block";
}

async function showGameResult() {
  isGamePaused = true;
  winner = player1Score > player2Score ? player1Name : player2Name;

  const lang = localStorage.getItem("lang") || "es";
  const translations = {
    es: {
      winText: " gana!",
      backToTournament: "Volver al Torneo",
      restart: "Reiniciar Juego"
    },
    en: {
      winText: " wins!",
      backToTournament: "Back to Tournament",
      restart: "Restart Game"
    },
    fr: {
      winText: " gagne!",
      backToTournament: "Retour au tournoi",
      restart: "Redémarrer le jeu"
    }
  };

  const t = translations[lang as keyof typeof translations];
  const resultText = `${winner}${t.winText}`;

  ctx.clearRect(0, 0, canvas.width, canvas.height);
  ctx.font = "48px 'Press Start 2P', cursive";
  ctx.fillStyle = "white";
  ctx.textAlign = "center";
  ctx.fillText(resultText, canvas.width / 2, canvas.height / 2);
  ctx.font = "24px 'Press Start 2P', cursive";
  ctx.fillText(`${player1Score} - ${player2Score}`, canvas.width / 2, canvas.height / 2 + 50);
  ctx.font = "16px 'Press Start 2P', cursive";

  if (isTournament) {
    resetGameBtn.innerText = t.backToTournament;
    resetGameBtn.onclick = function () {
      updateBracket();
    };
    startGameBtn.style.display = "none";
    iaGameBtn.style.display = "none";

    const matchButton = document.querySelector(`button[data-match-id="${currentMatchId}"]`);
    if (matchButton) {
      matchButton.innerHTML = `${player1Name} (${player1Score}) vs ${player2Name} (${player2Score})`;
      (matchButton as HTMLButtonElement).disabled = true;
    }

    try {
      const response = await fetch('https://localhost:3000/updateMatchWinner', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({
          match_id: currentMatchId,
          winner,
          player1_score: player1Score,
          player2_score: player2Score
        })
      });

      if (!response.ok) {
        console.error('Error al actualizar el torneo:', response.statusText);
        return;
      }

      const data = await response.json();

      const response2 = await fetch('https://localhost:3000/checkMatches', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ tournament_id: tournamentId })
      });

      if (!response2.ok) {
        console.error('Error obteniendo winners:', response2.statusText);
        return;
      }

      const data2 = await response2.json();
      winners = data2.winners || [];
      nextRound = data2.nextRound || [];

      const winnerTournament = data2.winner || '';

      if (winnerTournament !== '') {
        tourWinner.innerText = winner;
        tournamentWinnerView.style.display = "block";
      }
    } catch (error) {
      console.error('Error en la comunicación con el servidor:', error);
    }
  } else {
    resetGameBtn.innerText = t.restart;
    resetGameBtn.onclick = function () {
      resetButtonLogic();
    };
    startGameBtn.style.display = "none";
    iaGameBtn.style.display = "none";
  }
}

function showCountdown(callback: () => void) {
  let countdown = 3;

  startGameBtn.disabled = true;

  const drawCountdown = () => {

    ctx.clearRect(0, 0, canvas.width, canvas.height);

    ctx.font = "48px 'Press Start 2P', cursive";
    ctx.fillStyle = "white";
    ctx.textAlign = "center";
    ctx.fillText(countdown.toString(), canvas.width / 2, canvas.height / 2);
  };

  drawCountdown();

  countdownInterval = setInterval(() => {
    countdown--;
    if (countdown < 0) {
      clearInterval(countdownInterval);
      startGameBtn.disabled = false;
      resetGameBtn.disabled = false;
      callback();
    } else {
      drawCountdown();
    }
  }, 1000);
}

function stopCountdown() {
  if (countdownInterval !== undefined) {
    clearInterval(countdownInterval);
    countdownInterval = undefined;

    if (typeof startGameBtn !== 'undefined') {
      startGameBtn.disabled = false;
    }
    if (typeof resetGameBtn !== 'undefined') {
      resetGameBtn.disabled = false;
    }
    drawGame();
  }
}

function resetBall() {
  ball.x = canvas.width / 2;
  ball.y = canvas.height / 2;
  ball.dx = ball.dx < 0 ? inicialBallSpeed : -inicialBallSpeed;
  ball.dy = inicialBallSpeed;
  if(aiEnabled)
    updateAITarget();
}

function resetAll() {
  resetBall();
  isGameOver = false;
  leftPaddle.y = canvas.height / 2 - paddleHeight / 2;
  rightPaddle.y = canvas.height / 2 - paddleHeight / 2;
  player1Score = 0;
  player2Score = 0;
}

function updatePaddlePositions() {
  if (aiEnabled) {
    const diff = aiTargetY - rightPaddle.y;
    const speed = 5;
    if (Math.abs(diff) > speed) {
      rightPaddle.y += diff > 0 ? speed : -speed;
    } else {
      rightPaddle.y = aiTargetY;
    }
  } else {
    rightPaddle.y += rightPaddle.dy;
  }

  if (rightPaddle.y < 0) rightPaddle.y = 0;
  if (rightPaddle.y > canvas.height - rightPaddle.height)
    rightPaddle.y = canvas.height - rightPaddle.height;

  leftPaddle.y += leftPaddle.dy;
  if (leftPaddle.y < 0) leftPaddle.y = 0;
  if (leftPaddle.y > canvas.height - leftPaddle.height)
    leftPaddle.y = canvas.height - leftPaddle.height;
}

function gameLoop() {
  if (isGamePaused) {
    return;
  }
  isGameOver = false;
  drawGame();
  moveGameObjects();
  animation = requestAnimationFrame(gameLoop);
}

initializeGame();

function predictBallYAtPaddle(ball: Ball, paddleX: number): number {
  let x = ball.x;
  let y = ball.y;
  let dx = ball.dx;
  let dy = ball.dy;

  if (dx <= 0) return y;

  while (x < paddleX - ball.radius) {
    x += dx;
    y += dy;

    if (y - ball.radius < 0) {
      y = ball.radius;
      dy = -dy;
    } else if (y + ball.radius > canvas.height) {
      y = canvas.height - ball.radius;
      dy = -dy;
    }
  }
  return y;
}

function updateAITarget() {
  let predictedY = predictBallYAtPaddle(ball, rightPaddle.x);

  const randomOffset = (Math.random() - 0.5) * 105;

  aiTargetY = predictedY - rightPaddle.height / 2 + randomOffset;
  if (aiTargetY < 0) aiTargetY = 0;
  if (aiTargetY > canvas.height - rightPaddle.height)
    aiTargetY = canvas.height - rightPaddle.height;
}
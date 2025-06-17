const show3d = document.getElementById('show3d') as HTMLDivElement;
const activateScore = document.getElementById('activateScore') as HTMLButtonElement;
const reset3dGame = document.getElementById('reset3dGame') as HTMLButtonElement;
const winView = document.getElementById('winView') as HTMLDivElement;
const closeWin = document.getElementById('closeWin') as HTMLButtonElement;
const winnerPlayer = document.getElementById('winnerPlayer') as HTMLDivElement;
const player1Score3d = document.getElementById('player1Score') as HTMLDivElement;
const player2Score3d = document.getElementById('player2Score') as HTMLDivElement;
const lang = localStorage.getItem('lang') || 'es';

let isPaused = false;

const config = {
  canvas: 'renderCanvas',
  paddleSpeed: 0.3,
  ballSpeed: 0.15,
  paddleWidth: 1,
  paddleHeight: 3,
  borderThickness: 0.2,
  gameWidth: 20,
  gameHeight: 12,
  winScore: 5
};

const state = {
  scorePlayer1: 0,
  scorePlayer2: 0,
  paddle1Speed: 0,
  paddle2Speed: 0,
  ballVelocity: new BABYLON.Vector3(0, 0, 0)
};

let previuosSpeedX = 0;
let previousSpeedY = 0;

let paddle1 : BABYLON.Mesh;
let paddle2 : BABYLON.Mesh;
let ball3d : BABYLON.Mesh;

activateScore.addEventListener('click', () => {
    if (isPaused) {
      const lang = localStorage.getItem('lang') || 'es';
        if (lang === 'es') {
            activateScore.innerText = 'Pausar Juego';
        } else if (lang === 'en') {
            activateScore.innerText = 'Pause Game';
        } else if (lang === 'fr') {
            activateScore.innerText = 'Mettre le jeu sur pause';
        }
        isPaused = false;
        state.ballVelocity.x = previuosSpeedX;
        state.ballVelocity.y = previousSpeedY;
    } else {
      const lang = localStorage.getItem('lang') || 'es';
        if (lang === 'es') {
            activateScore.innerText = 'Iniciar Juego';
        } else if (lang === 'en') {
            activateScore.innerText = 'Start Game';
        } else if (lang === 'fr') {
            activateScore.innerText = 'Démarrer le jeu';
        }
        isPaused = true;
        previousSpeedY = state.ballVelocity.y;
        previuosSpeedX = state.ballVelocity.x;
        state.ballVelocity.x = 0;
        state.ballVelocity.y = 0;
    }
});

closeWin.addEventListener('click', () => {
    winView.style.display = 'none';
    show3d.style.display = 'block';
    resetGame3d();
});

window.addEventListener("DOMContentLoaded", () => {
  
  /* ----------------------CANVAS---------------------- */

  const canvas = document.getElementById(config.canvas) as unknown as HTMLCanvasElement;
  if (!canvas) {
    console.error("Canvas not found");
    return;
  }

  canvas.width = window.innerWidth * window.devicePixelRatio;
  canvas.height = window.innerHeight * window.devicePixelRatio;

  /* ----------------------MOTOR Y ESCENA---------------------- */

  const engine = new BABYLON.Engine(canvas, true, {
    antialias: true,
    preserveDrawingBuffer: true,
  });
  const scene = new BABYLON.Scene(engine);
  scene.clearColor = new BABYLON.Color4(0, 0.01, 0, 0.9);

  scene.getEngine().setHardwareScalingLevel(1 / window.devicePixelRatio);

  /* ----------------------CÁMARA Y LUCES---------------------- */

  const camera = new BABYLON.ArcRotateCamera(
    "Camera",
    Math.PI / 2,
    Math.PI / 4,
    40,
    BABYLON.Vector3.Zero(),
    scene
  );
  (camera.attachControl as any)(canvas, false);

  const light = new BABYLON.HemisphericLight(
    "light",
    new BABYLON.Vector3(1, 1, 0),
    scene
  );

  const pointLight = new BABYLON.PointLight("pointLight", new BABYLON.Vector3(0, 5, 0), scene);
  pointLight.intensity = 1;
  pointLight.diffuse = new BABYLON.Color3(0, 0, 1);

  /* ----------------------FONDO---------------------- */

  const skybox = BABYLON.MeshBuilder.CreateBox("skyBox", { width: 1000.0, height: 1000.0, depth: 1000.0 }, scene);

  const skyboxMaterial = new BABYLON.StandardMaterial("skyBox", scene);

  skyboxMaterial.backFaceCulling = false;

  skyboxMaterial.disableLighting = true;

  const textureData = new Uint8Array(1024 * 1024 * 4);

  for (let i = 0; i < 512; i++) {
    for (let j = 0; j < 512; j++) {
      const isGrid = (i % 50 === 0) || (j % 50 === 0);
      const idx = (i * 512 + j) * 4;
      textureData[idx] = isGrid ? 50 : 0;
      textureData[idx + 1] = isGrid ? 35 : 0;
      textureData[idx + 2] = isGrid ? 90 : 0;
      textureData[idx + 3] = 255;
    }
  }

  const digitalTexture = new BABYLON.RawTexture(
    textureData,
    512,
    512,
    BABYLON.Engine.TEXTUREFORMAT_RGBA,
    scene,
    false,
    false,
    BABYLON.Texture.NEAREST_SAMPLINGMODE
  );

  skyboxMaterial.emissiveTexture = digitalTexture;

  skyboxMaterial.diffuseColor = new BABYLON.Color3(0, 0, 0);

  skyboxMaterial.specularColor = new BABYLON.Color3(0, 0, 0);

  skybox.material = skyboxMaterial;

  skybox.infiniteDistance = true;

  /* ----------------------ELEMENTOS DEL JUEGO---------------------- */

  ball3d = BABYLON.MeshBuilder.CreateSphere("ball", { diameter: 0.5 }, scene);
  ball3d.position = new BABYLON.Vector3(0, 0, 0);

  paddle1 = BABYLON.MeshBuilder.CreateBox("paddle1", {
    width: config.paddleWidth,
    height: config.paddleHeight,
    depth: 0.5
  } as any, scene);
  paddle1.position.x = -config.gameWidth / 2 + 1;

  paddle2 = BABYLON.MeshBuilder.CreateBox("paddle2", {
    width: config.paddleWidth,
    height: config.paddleHeight,
    depth: 0.5
  } as any, scene);
  paddle2.position.x = config.gameWidth / 2 - 1;

  const ballMaterial = new BABYLON.StandardMaterial("ballMaterial", scene);
  ballMaterial.diffuseColor = new BABYLON.Color3(1, 1, 1);
  ballMaterial.specularColor = new BABYLON.Color3(0.5, 0.5, 0.5);
  ball3d.material = ballMaterial;

  const paddleMaterial = new BABYLON.StandardMaterial("paddleMaterial", scene);
  paddleMaterial.diffuseColor = new BABYLON.Color3(0.2, 0.5, 0.8);
  paddleMaterial.specularColor = new BABYLON.Color3(0.5, 0.5, 0.5);
  paddle1.material = paddleMaterial;
  paddle2.material = paddleMaterial;

  /* ----------------------BORDES---------------------- */

  const createBorder = (name: string, width: number, height: number, position: BABYLON.Vector3) => {
    const border = BABYLON.MeshBuilder.CreateBox(name, {
      width,
      height,
      depth: 0.5
    }, scene);
    border.position = position;
    return border;
  };

  const topBorder = createBorder("topBorder", config.gameWidth, config.borderThickness,
    new BABYLON.Vector3(0, config.gameHeight / 2, 0));
  const bottomBorder = createBorder("bottomBorder", config.gameWidth, config.borderThickness,
    new BABYLON.Vector3(0, -config.gameHeight / 2, 0));
  const leftBorder = createBorder("leftBorder", config.borderThickness, config.gameHeight,
    new BABYLON.Vector3(-config.gameWidth / 2, 0, 0));
  const rightBorder = createBorder("rightBorder", config.borderThickness, config.gameHeight,
    new BABYLON.Vector3(config.gameWidth / 2, 0, 0));
  const middleLine = createBorder("middleLine", config.borderThickness, config.gameHeight,
    new BABYLON.Vector3(0, 0, 0));

  const borderMaterial = new BABYLON.StandardMaterial("borderMaterial", scene);
  borderMaterial.diffuseColor = new BABYLON.Color3(1, 1, 1);
  [topBorder, bottomBorder, leftBorder, rightBorder, middleLine].forEach(border => {
    border.material = borderMaterial;
  });

  /* ----------------------PARTÍCULAS---------------------- */

  const particleSystem = new BABYLON.ParticleSystem("particles", 2000, scene);
  particleSystem.particleTexture = new BABYLON.Texture("data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVR42mP8/5+hHgAHggJ/PchI7wAAAABJRU5ErkJggg==", scene);
  particleSystem.minEmitBox = new BABYLON.Vector3(-0.1, -0.1, -0.1);
  particleSystem.maxEmitBox = new BABYLON.Vector3(0.1, 0.1, 0.1);
  particleSystem.color1 = new BABYLON.Color4(1, 0.5, 0, 1);
  particleSystem.color2 = new BABYLON.Color4(0, 0, 0, 1);
  particleSystem.emitter = ball3d;
  particleSystem.minSize = 0.1;
  particleSystem.maxSize = 0.5;
  particleSystem.minLifeTime = 0.1;
  particleSystem.maxLifeTime = 0.3;

  /* ----------------------CONTROL DE TECLADO---------------------- */

  const keyState: { [key: string]: boolean } = {};

  window.addEventListener("keydown", (event) => {
    keyState[event.key] = true;
  });

  window.addEventListener("keyup", (event) => {
    keyState[event.key] = false;
  });

  const movePaddles = () => {

    if (keyState['w'] && !isPaused) state.paddle2Speed = config.paddleSpeed;
    else if (keyState['s'] && !isPaused) state.paddle2Speed = -config.paddleSpeed;
    else state.paddle2Speed = 0;

    if (keyState['ArrowUp'] && !isPaused) state.paddle1Speed = config.paddleSpeed;
    else if (keyState['ArrowDown'] && !isPaused) state.paddle1Speed = -config.paddleSpeed;
    else state.paddle1Speed = 0;
  };

  /* ----------------------LOGÍCA DE JUEGO---------------------- */

  const lerp = (start: number, end: number, alpha: number) =>
    start + (end - start) * alpha;

  scene.registerBeforeRender(() => {
    movePaddles();

    paddle1.position.y = lerp(
      paddle1.position.y,
      paddle1.position.y + state.paddle1Speed,
      0.8
    );
    paddle2.position.y = lerp(
      paddle2.position.y,
      paddle2.position.y + state.paddle2Speed,
      0.8
    );

    const halfHeight = config.gameHeight / 2 - config.paddleHeight / 2;
    paddle1.position.y = Math.max(-halfHeight, Math.min(halfHeight, paddle1.position.y));
    paddle2.position.y = Math.max(-halfHeight, Math.min(halfHeight, paddle2.position.y));

    ball3d.position.addInPlace(state.ballVelocity);

    if (Math.abs(ball3d.position.y) >= config.gameHeight / 2 - config.borderThickness / 2) {
      state.ballVelocity.y *= -1;
    }

    const checkPaddleCollision = (paddle: BABYLON.Mesh, isLeftPaddle: boolean) => {

      const collisionMargin = 0.1;
      const ballRadius = 0.25;
    
      const paddleLeft = paddle.position.x - config.paddleWidth / 2;
      const paddleRight = paddle.position.x + config.paddleWidth / 2;
      const paddleTop = paddle.position.y + config.paddleHeight / 2;
      const paddleBottom = paddle.position.y - config.paddleHeight / 2;

      const ballInPaddleX = isLeftPaddle
        ? ball3d.position.x - ballRadius <= paddleRight && ball3d.position.x + ballRadius >= paddleLeft - collisionMargin
        : ball3d.position.x + ballRadius >= paddleLeft && ball3d.position.x - ballRadius <= paddleRight + collisionMargin;

      const ballInPaddleY = ball3d.position.y + ballRadius >= paddleBottom - collisionMargin &&
        ball3d.position.y - ballRadius <= paddleTop + collisionMargin;
    
      if (ballInPaddleX && ballInPaddleY) {

        state.ballVelocity.x *= -1;

        const minVelocity = 0.05;
        if (Math.abs(state.ballVelocity.x) < minVelocity) {
          state.ballVelocity.x = state.ballVelocity.x > 0 ? minVelocity : -minVelocity;
        }

        state.ballVelocity.y = (ball3d.position.y - paddle.position.y) * 0.2;

        state.ballVelocity.y += (Math.random() - 0.5) * 0.05;

        if (isLeftPaddle) {
          ball3d.position.x = paddleRight + ballRadius + 0.05;
        } else {
          ball3d.position.x = paddleLeft - ballRadius - 0.05;
        }

        particleSystem.start();
        setTimeout(() => particleSystem.stop(), 200);
      }
    };

    checkPaddleCollision(paddle1, true);
    checkPaddleCollision(paddle2, false);

    if (ball3d.position.x >= config.gameWidth / 2) {
      
      ball3d.position = new BABYLON.Vector3(0, 0, 0);
      state.ballVelocity.x = -config.ballSpeed;
     
        state.scorePlayer2++;
        player2Score3d.innerText = state.scorePlayer2.toString();
    }

    if (ball3d.position.x <= -config.gameWidth / 2) {
      ball3d.position = new BABYLON.Vector3(0, 0, 0);
      state.ballVelocity.x = config.ballSpeed;
        state.scorePlayer1++;
        player1Score3d.innerText = state.scorePlayer1.toString();
    }


    if (state.scorePlayer1 >= config.winScore || state.scorePlayer2 >= config.winScore) {
      const player1Won = state.scorePlayer1 >= config.winScore;

      isPaused = true;
      state.scorePlayer1 = 0;
      state.scorePlayer2 = 0;
      player1Score3d.innerHTML = '0';
      player2Score3d.innerHTML = '0';
      ball3d.position = new BABYLON.Vector3(0, 0, 0);
      state.ballVelocity.x = 0;
      state.ballVelocity.y = 0;
      previousSpeedY = config.ballSpeed;
      previuosSpeedX = config.ballSpeed;
      const lang = localStorage.getItem('lang') || 'es';
      if (lang === 'es') {
        activateScore.innerText = 'J';
      }
      else if (lang === 'en') {
        activateScore.innerText = 'Start Game';
      }
      else if (lang === 'fr') {
        activateScore.innerText = 'Démarrer le jeu';
      }
      winnerPlayer.innerText = player1Won ? ' Ping' : ' Pong';
      winView.style.display = "block";
      show3d.style.display = "none";
    }

    pointLight.position = ball3d.position.add(new BABYLON.Vector3(0, 2, 0));
  });

  reset3dGame.addEventListener("click", () => {
    ball3d.position = new BABYLON.Vector3(0, 0, 0);
    resetGame3d();
  });

  engine.runRenderLoop(() => {
    scene.render();
  });

  window.addEventListener("resize", () => {
    engine.resize();
  });
});


function resetGame3d() {
  isPaused = true;
  state.scorePlayer1 = 0;
  state.scorePlayer2 = 0;
  player1Score3d.innerText = state.scorePlayer1.toString();
  player2Score3d.innerText = state.scorePlayer2.toString();
  paddle1.position.y = 0;
  paddle2.position.y = 0;
  state.ballVelocity.x = 0;
  state.ballVelocity.y = 0;
  ball3d.position = new BABYLON.Vector3(0, 0, 0);
  previousSpeedY = config.ballSpeed;
  previuosSpeedX = config.ballSpeed;
  const lang = localStorage.getItem('lang') || 'es';
  if (lang === 'es') {
    activateScore.innerText = 'Iniciar Juego';
  } else if (lang === 'en') {
    activateScore.innerText = 'Start Game';
  } else if (lang === 'fr') {
    activateScore.innerText = 'Démarrer le jeu';
  }
}
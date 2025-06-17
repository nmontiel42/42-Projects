const startGameBtn = document.getElementById("startGameBtn") as HTMLButtonElement;
const resetGameBtn = document.getElementById("resetGameBtn") as HTMLButtonElement;
const iaGameBtn = document.getElementById("iaGameBtn") as HTMLButtonElement;

document.addEventListener("keydown", (event: KeyboardEvent) => {
    if (event.key === "ArrowUp") {
        if(rightPaddle.y > 0){ 
            rightPaddle.dy = -5;
        }
        else {
            rightPaddle.dy = 0;
        }
    } else if (event.key === "ArrowDown") {
        if(rightPaddle.y < canvas.height - rightPaddle.height){
            rightPaddle.dy = 5;
        }else{
            rightPaddle.dy = 0;  
        }
    }

    if (event.key === "w") {
        if(leftPaddle.y > 0){
            leftPaddle.dy = -5;
        }else{
            leftPaddle.dy = 0;
        }
    } else if (event.key === "s") {
        if(leftPaddle.y < canvas.height - leftPaddle.height){
            leftPaddle.dy = 5;
        }else{
            leftPaddle.dy = 0;
        }
    }
});

document.addEventListener("keyup", (event: KeyboardEvent) => {
    if (event.key === "ArrowUp" || event.key === "ArrowDown") {
        rightPaddle.dy = 0;
    }

    if (event.key === "w" || event.key === "s") {
        leftPaddle.dy = 0;
    }
});

startGameBtn.addEventListener("click", () => {
    if (!isGamePaused) {
        isGamePaused = true;
        cancelAnimationFrame(animation);
        const lang = localStorage.getItem("lang") || "es";
        if (lang === "es") {
            startGameBtn.innerText = "Reanudar Juego";
        }
        else if (lang === "en") {
            startGameBtn.innerText = "Resume Game";
        }
        else if (lang === "fr") {
            startGameBtn.innerText = "Reprendre le jeu";
        }
    }else{
        if(!newGame){
            isGamePaused = false;
            gameLoop();
            const lang = localStorage.getItem("lang") || "es";
            if (lang === "es") {
                startGameBtn.innerText = "Pausar Juego";
            }
            else if (lang === "en") {
                startGameBtn.innerText = "Pause Game";
            }
            else if (lang === "fr") {
                startGameBtn.innerText = "Mettre le jeu en pause";
            }
        }else{
            isGamePaused = false;
            newGame = false;
            showCountdown(() => {
               gameLoop();
                const lang = localStorage.getItem("lang") || "es";
                if (lang === "es") {
                     startGameBtn.innerText = "Pausar Juego";
                } else if (lang === "en") {
                    startGameBtn.innerText = "Pause Game";
                }
                else if (lang === "fr") {
                    startGameBtn.innerText = "Mettre le jeu en pause";
                }
           }); 
        }
    }
});

resetGameBtn.addEventListener("click", () => {
    if(!isGameOver){
        resetButtonLogic();
        stopCountdown();
    }else if(isTournament && isGameOver){
        isTournament = false;
        localPlayView.style.display = 'none';
        tournamentView.style.display = 'block';
    } else if (!isTournament && !isGameOver){
        resetButtonLogic();
    }
});

iaGameBtn.addEventListener("click", () => {
    if(isTournament){
        return;
    }
    if(aiEnabled){
        aiEnabled = false;
        player2Name = "IA";
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
    }else{
        aiEnabled = true;
        player2Name = "Pong";
        const lang = localStorage.getItem("lang") || "es";
        if (lang === "es") {
            iaGameBtn.innerText = "Jugar contra humano";
        }
        else if (lang === "en") {
            iaGameBtn.innerText = "Play against human";
        }
        else if (lang === "fr") {
            iaGameBtn.innerText = "Jouer contre un humain";
        }
    }
    resetAll();
});


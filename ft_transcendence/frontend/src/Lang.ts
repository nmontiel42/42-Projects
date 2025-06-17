const enBtn = document.getElementById('enBtn') as HTMLElement;
const frBtn = document.getElementById('frBtn') as HTMLElement;
const esBtn = document.getElementById('esBtn') as HTMLElement;
const esBtn2 = document.getElementById('esBtn2') as HTMLElement;
const enBtn2 = document.getElementById('enBtn2') as HTMLElement;
const frBtn2 = document.getElementById('frBtn2') as HTMLElement;

localStorage.setItem('lang', 'es');

changeLanguage();

function changeLanguage() {
    if (localStorage.getItem('lang')) {

        /*-------------------Login-------------------*/

        const logoText = document.getElementById('logo-text') as HTMLElement;
        const neonSubtitle = document.getElementById('neon-subtitle') as HTMLElement;
        const email = document.getElementById('email') as HTMLInputElement;
        const userName = document.getElementById('username') as HTMLInputElement;
        const password = document.getElementById('password') as HTMLInputElement;
        const loginEmail = document.getElementById('loginEmail') as HTMLInputElement;
        const loginPassword = document.getElementById('loginPassword') as HTMLInputElement;
        const usernameInput = document.getElementById('usernameInput') as HTMLInputElement;
        const submit = document.getElementById('submit') as HTMLElement;
        const theresAccount = document.getElementById('theresAccount') as HTMLElement;
        const goToLogin = document.getElementById('goToLogin') as HTMLElement;
        const oGoogle = document.getElementById('oGoogle') as HTMLElement;
        const loginTitle = document.getElementById('loginTitle') as HTMLElement;
        const submitLogin = document.getElementById('submitLogin') as HTMLElement;
        const goToRegister = document.getElementById('goToRegister') as HTMLElement;
        const usernameWelcome = document.getElementById('usernameWelcome') as HTMLElement;
        const usernameText = document.getElementById('usernameText') as HTMLElement;
        const submitUsername = document.getElementById('submitUsername') as HTMLElement;

        /*-------------------Options-------------------*/

        const homePlay = document.getElementById('homePlay') as HTMLButtonElement;
        const tourPlay = document.getElementById('tourPlay') as HTMLButtonElement;
        const logoutBtn = document.getElementById('logoutBtn') as HTMLElement;
        const deleteAccountBtn = document.getElementById('deleteAccountBtn') as HTMLElement;
        const optionsBtn = document.getElementById('optionsBtn') as HTMLElement;
        const changeUsernameBtn = document.getElementById('changeUsernameBtn') as HTMLElement;
        const changeLanguage = document.getElementById('changeLanguage') as HTMLElement;
        const esBtn2 = document.getElementById('esBtn2') as HTMLElement;
        const enBtn2 = document.getElementById('enBtn2') as HTMLElement;
        const frBtn2 = document.getElementById('frBtn2') as HTMLElement;
        const usernameChangeText = document.getElementById('usernameChangeText') as HTMLElement;
        const usernameChangeInput = document.getElementById('usernameChangeInput') as HTMLInputElement;
        const submitChangeUsername = document.getElementById('submitChangeUsername') as HTMLElement;
        const setup2FABtn = document.getElementById('setup2FABtn') as HTMLButtonElement;
        const TwoFactorTitle = document.getElementById('TwoFactorTitle') as HTMLElement;
        const TwoFactorSubtitle = document.getElementById('TwoFactorSubtitle') as HTMLElement;
        const verificationCode = document.getElementById('verificationCode') as HTMLInputElement;
        const submitVerificationCode = document.getElementById('submitVerificationCode') as HTMLButtonElement;

        /*-------------------Home-------------------*/

        const initialWelcome = document.getElementById('initialWelcome') as HTMLElement;
        const infoOne = document.getElementById('infoOne') as HTMLElement;
        const infoTwo = document.getElementById('infoTwo') as HTMLElement;
        const infoThree = document.getElementById('infoThree') as HTMLElement;
        const infoFour = document.getElementById('infoFour') as HTMLElement;
        const titleTwo = document.getElementById('titleTwo') as HTMLElement;
        const titleFour = document.getElementById('titleFour') as HTMLElement;
        const initialInstructions = document.getElementById('initialInstructions') as HTMLElement;
        const initialInstructions2 = document.getElementById('initialInstructions2') as HTMLElement;
        
        /*-------------------Local Game-------------------*/

        const startGameBtn = document.getElementById('startGameBtn') as HTMLButtonElement;
        const resetGameBtn = document.getElementById('resetGameBtn') as HTMLButtonElement;
        const iaGameBtn = document.getElementById('iaGameBtn') as HTMLButtonElement;

        /*-------------------Multiplayer-------------------*/

        const startMultiplayerBtn = document.getElementById('stopStartMultiplayerBtn') as HTMLButtonElement;
        const restartMultiplayerBtn = document.getElementById('restartMultiplayerBtn') as HTMLButtonElement;

        /*-------------------Torunament-------------------*/

        const createTour = document.getElementById('createTour') as HTMLButtonElement;
        const numPlayersLabel = document.querySelector('label[for="numPlayers"]') as HTMLLabelElement;
        const generateTournamentBtn = document.getElementById('generateTournamentBtn') as HTMLButtonElement;
        const tournamentWinner = document.getElementById('tournamentWinner') as HTMLElement;

        /*-------------------3D-------------------*/

        const winMsg = document.getElementById('winMsg') as HTMLElement;
        const closeWin = document.getElementById('closeWin') as HTMLElement;
        const activateScore = document.getElementById('activateScore') as HTMLButtonElement;
        const reset3dGame = document.getElementById('reset3dGame') as HTMLButtonElement;


        if (localStorage.getItem('lang') === 'en') {
            logoText.innerHTML = 'Welcome to PONG';
            neonSubtitle.innerHTML = 'REGISTER TO PLAY';
            email.placeholder = 'Your email';
            userName.placeholder = 'Your username';
            password.placeholder = 'Your password';
            loginEmail.placeholder = 'Your email or username';
            loginPassword.placeholder = 'Your password';
            usernameInput.placeholder = 'Your username';
            submit.innerHTML = 'Sign up';
            theresAccount.innerHTML = 'Already have an account?';
            goToLogin.innerHTML = 'Log in';
            oGoogle.innerHTML = 'or';
            loginTitle.innerHTML = 'Enter your data';
            submitLogin.innerHTML = 'Log in';
            goToRegister.innerHTML = 'Don\'t have an account? Register';
            usernameWelcome.innerHTML = 'Hello!';
            usernameText.innerHTML = 'Enter a username:';
            submitUsername.innerHTML = 'Save';

            /* ------------------------------------------------------------- */

            homePlay.innerHTML = 'Home';
            tourPlay.innerHTML = 'Tourny';
            logoutBtn.innerHTML = 'Log out';
            deleteAccountBtn.innerHTML = 'Delete account';
            optionsBtn.innerHTML = 'Options';
            changeUsernameBtn.innerHTML = 'Change username';
            changeLanguage.innerHTML = 'Change language';
            esBtn2.innerHTML = 'Spanish';
            enBtn2.innerHTML = 'English';
            frBtn2.innerHTML = 'French';
            usernameChangeText.innerHTML = 'Enter a new username:';
            usernameChangeInput.placeholder = 'New username';
            submitChangeUsername.innerHTML = 'Change';
            setup2FABtn.innerHTML = 'Enable 2FA';
            TwoFactorTitle.innerHTML = 'Two Factor Authentication';
            TwoFactorSubtitle.innerHTML = 'Enter the verification code sent to your email:';
            verificationCode.placeholder = 'Verification code';
            submitVerificationCode.innerHTML = 'Verify';

            /* ------------------------------------------------------------- */

            initialWelcome.innerHTML = 'Welcome!';
            infoOne.innerHTML = 'Play a game of pong in a 1vs1 or against other 3 players on the same keyboard. The best of 5 will be the winner.';
            infoTwo.innerHTML = 'Create a local tournament of up to 8 players, enter your names and play. Compete until there is only one winner.';
            infoThree.innerHTML = 'Experience Pong in the most immersive way. Adjust the distance and angle you want and enjoy the game from other perspectives.';
            infoFour.innerHTML = 'Turn on AI mode to play against the artificial intelligence. Perfect for practicing or if you don\'t have friends.';
            titleTwo.innerHTML = 'Tournament';
            titleFour.innerHTML = 'AI';
            initialInstructions.innerHTML = 'Explore different game modes and have fun either alone or with friends - choose your game mode and start playing!';
            initialInstructions2.innerHTML = 'Select the game mode of your choice at the top and play!';

            /* ------------------------------------------------------------- */
            
            startGameBtn.textContent = 'Start Game';
            resetGameBtn.innerHTML = 'Reset Game';
            iaGameBtn.innerHTML = 'Play vs IA'

            /* ------------------------------------------------------------- */

            startMultiplayerBtn.innerHTML = 'Start Game';
            restartMultiplayerBtn.innerHTML = 'Restart Game';

            /* ------------------------------------------------------------- */

            createTour.innerHTML = 'Create Tourny';
            numPlayersLabel.textContent = 'Number of players: ';
            generateTournamentBtn.innerHTML = 'Generate Tourny';
            tournamentWinner.innerHTML = 'Tournament Winner: ';

            /* ------------------------------------------------------------- */

           
            winMsg.innerHTML = 'You won';
            closeWin.innerHTML = 'Come back to 3D game';
            activateScore.innerHTML = 'Start Game';
            reset3dGame.innerHTML = 'Reset Game';

            /* ------------------------------------------------------------- */
        }
        else if (localStorage.getItem('lang') === 'fr') {
            logoText.innerHTML = 'Bienvenue à PONG';
            neonSubtitle.innerHTML = 'INSCRIVEZ-VOUS POUR JOUER';
            email.placeholder = 'Votre email';
            userName.placeholder = 'Votre nom d\'utilisateur';
            password.placeholder = 'Votre mot de passe';
            loginEmail.placeholder = 'Votre email ou nom d\'utilisateur';
            loginPassword.placeholder = 'Votre mot de passe';
            usernameInput.placeholder = 'Votre nom d\'utilisateur';
            submit.innerHTML = 'S\'inscrire';
            theresAccount.innerHTML = 'Vous avez déjà un compte?';
            goToLogin.innerHTML = 'Se connecter';
            oGoogle.innerHTML = 'ou';
            loginTitle.innerHTML = 'Entrez vos données';
            submitLogin.innerHTML = 'Se connecter';
            goToRegister.innerHTML = 'Vous n\'avez pas de compte? S\'inscrire';
            usernameWelcome.innerHTML = 'Bonjour!';
            usernameText.innerHTML = 'Entrez un nom d\'utilisateur:';
            submitUsername.innerHTML = 'Sauvegarder';

            /* ------------------------------------------------------------- */

            homePlay.innerHTML = 'Accueil';
            tourPlay.innerHTML = 'Tournoi';
            logoutBtn.innerHTML = 'Déconnexion';
            deleteAccountBtn.innerHTML = 'Supprimer le compte';
            optionsBtn.innerHTML = 'Options';
            changeUsernameBtn.innerHTML = 'Changer le nom d\'utilisateur';
            changeLanguage.innerHTML = 'Changer de langue';
            esBtn2.innerHTML = 'Espagnol';
            enBtn2.innerHTML = 'Anglais';
            frBtn2.innerHTML = 'Français';
            usernameChangeText.innerHTML = 'Entrez un nouveau nom d\'utilisateur:';
            usernameChangeInput.placeholder = 'Nouveau nom d\'utilisateur';
            submitChangeUsername.innerHTML = 'Changer';
            setup2FABtn.innerHTML = 'Activer 2FA';
            TwoFactorTitle.innerHTML = 'Authentification à deux facteurs';
            TwoFactorSubtitle.innerHTML = 'Entrez le code de vérification de votre application d\'authentification:';
            verificationCode.placeholder = 'Code de vérification';
            submitVerificationCode.innerHTML = 'Vérifier';

            /* ------------------------------------------------------------- */

            initialWelcome.innerHTML = 'Bienvenue!';
            infoOne.innerHTML = 'Jouez une partie de pong en 1vs1 ou contre d\'autres joueurs sur le même clavier. Le meilleur de 5 sera le gagnant.';
            infoTwo.innerHTML = 'Créez un tournoi local de jusqu\'à 8 joueurs, entrez vos noms et jouez. Compétitionnez jusqu\'à ce qu\'il ne reste qu\'un gagnant.';
            infoThree.innerHTML = 'Vivez l\'expérience Pong de la manière la plus immersive. Ajustez la distance et l\'angle que vous souhaitez et profitez du jeu sous d\'autres perspectives.';
            infoFour.innerHTML = 'Activez le mode IA pour jouer contre l\'intelligence artificielle. Parfait pour s\'entraîner ou si vous n\'avez pas d\'amis.';
            titleTwo.innerHTML = 'Tournoi';
            titleFour.innerHTML = 'IA';
            initialInstructions.innerHTML = 'Explorez différents modes de jeu et amusez-vous seul ou avec des amis - choisissez votre mode de jeu et commencez à jouer!';
            initialInstructions2.innerHTML = 'Sélectionnez le mode de jeu de votre choix en haut et jouez!';

            /* ------------------------------------------------------------- */
            
            startGameBtn.textContent = 'Démarrer le jeu';
            resetGameBtn.innerHTML = 'Réinitialiser le jeu';
            iaGameBtn.innerHTML = 'Jouer contre l\'IA';

            /* ------------------------------------------------------------- */

            startMultiplayerBtn.innerHTML = 'Démarrer le jeu';
            restartMultiplayerBtn.innerHTML = 'Redémarrer le jeu';

            /* ------------------------------------------------------------- */

            createTour.innerHTML = 'Créer un tournoi';
            numPlayersLabel.textContent = 'Nombre de joueurs: ';
            generateTournamentBtn.innerHTML = 'Générer le tournoi';
            tournamentWinner.innerHTML = 'Gagnant du tournoi: ';
            
            /*------------------------------------------------------------- */

          
            winMsg.innerHTML = 'Vous avez gagné';
            closeWin.innerHTML = 'Retourner au jeu 3D';
            activateScore.innerHTML = 'Démarrer le jeu';
            reset3dGame.innerHTML = 'Réinitialiser le jeu';

            /* ------------------------------------------------------------- */
        }
        else if (localStorage.getItem('lang') === 'es') {
            logoText.innerHTML = 'Bienvenido a PONG';
            neonSubtitle.innerHTML = 'REGISTRATE PARA JUGAR';
            email.placeholder = 'Tu correo electrónico';
            userName.placeholder = 'Tu nombre de usuario';
            password.placeholder = 'Tu contraseña';
            loginEmail.placeholder = 'Tu correo electrónico o usuario';
            loginPassword.placeholder = 'Tu contraseña';
            usernameInput.placeholder = 'Tu nombre de usuario';
            submit.innerHTML = 'Registrarse';
            theresAccount.innerHTML = '¿Ya tienes una cuenta?';
            goToLogin.innerHTML = 'Iniciar sesión';
            oGoogle.innerHTML = 'o';
            loginTitle.innerHTML = 'Introduce tus datos';
            submitLogin.innerHTML = 'Iniciar sesión';
            goToRegister.innerHTML = '¿No tienes cuenta? Registrate';
            usernameWelcome.innerHTML = '¡Hola!';
            usernameText.innerHTML = 'Introduce un nombre de usuario:';
            submitUsername.innerHTML = 'Guardar';

            /* ------------------------------------------------------------- */

            homePlay.innerHTML = 'Inicio';
            tourPlay.innerHTML = 'Torneo';
            logoutBtn.innerHTML = 'Cerrar sesión';
            deleteAccountBtn.innerHTML = 'Eliminar cuenta';
            optionsBtn.innerHTML = 'Opciones';
            changeUsernameBtn.innerHTML = 'Cambiar nombre de usuario';
            changeLanguage.innerHTML = 'Cambiar idioma';
            esBtn2.innerHTML = 'Español';
            enBtn2.innerHTML = 'Inglés';
            frBtn2.innerHTML = 'Francés';
            usernameChangeText.innerHTML = 'Introduce un nuevo nombre de usuario:';
            usernameChangeInput.placeholder = 'Nuevo nombre de usuario';
            submitChangeUsername.innerHTML = 'Cambiar';
            setup2FABtn.innerHTML = 'Habilitar 2FA';
            TwoFactorTitle.innerHTML = 'Autenticación de dos factores';
            TwoFactorSubtitle.innerHTML = 'Introduce el código de verificación enviado a tu correo:';
            verificationCode.placeholder = 'Código de verificación';
            submitVerificationCode.innerHTML = 'Verificar';

            /* ------------------------------------------------------------- */

            initialWelcome.innerHTML = '¡Bienvenid@!';
            infoOne.innerHTML = 'Juega una partida de pong en un 1vs1 o contra otros 3 jugadores en el mismo teclado. El mejor de 5 será el ganador.';
            infoTwo.innerHTML = 'Crea un torneo local de hasta 8 jugadores, introducir vuestros nombres y a jugar. Compite hasta que solo quede un ganador.';
            infoThree.innerHTML = 'Vive la experiencia Pong de la manera más inmersiva. Ajusta la distancia y el ángulo que quieras y disfruta del juego desde otras perspectivas.';
            infoFour.innerHTML = 'Activa el modo IA para jugar contra la inteligencia artificial. Perfecto para practicar o si no tienes amigos.';
            titleTwo.innerHTML = 'Torneo';
            titleFour.innerHTML = 'IA';
            initialInstructions.innerHTML = 'Explora distintos modos de juego y diviértete tanto en solitario como con amigos. ¡Elige tu modo de juego y empieza a jugar!';
            initialInstructions2.innerHTML = 'Selecciona el modo de juego que prefieras en la parte superior y ¡a jugar!';

            /* ------------------------------------------------------------- */

            startGameBtn.textContent = 'Iniciar Juego';
            resetGameBtn.innerHTML = 'Reiniciar Juego';
            iaGameBtn.innerHTML = 'Jugar contra IA'

            /* ------------------------------------------------------------- */

            startMultiplayerBtn.innerHTML = 'Iniciar Juego';
            restartMultiplayerBtn.innerHTML = 'Reiniciar Juego';

            /* ------------------------------------------------------------- */

            createTour.innerHTML = 'Crear Torneo';
            numPlayersLabel.textContent = 'Número de jugadores: ';
            generateTournamentBtn.innerHTML = 'Generar Torneo';
            tournamentWinner.innerHTML = 'Ganador del Torneo: ';

            /*------------------------------------------------------------- */

           
            winMsg.innerHTML = '¡Ganaste';
            closeWin.innerHTML = 'Volver al Juego 3D';
            activateScore.innerHTML = 'Iniciar Juego';
            reset3dGame.innerHTML = 'Reiniciar Juego';

            /* ------------------------------------------------------------- */
        }
    }
}

if (enBtn) {
    enBtn.addEventListener('click', () => {
        localStorage.setItem('lang', 'en');
        changeLanguage();
    });
}
if (enBtn2) {
    enBtn2.addEventListener('click', () => {
        localStorage.setItem('lang', 'en');
        changeLanguage();
    });
}

if (frBtn) {
    frBtn.addEventListener('click', () => {
        localStorage.setItem('lang', 'fr');
        changeLanguage();
    });
}
if (frBtn2) {
    frBtn2.addEventListener('click', () => {
        localStorage.setItem('lang', 'fr');
        changeLanguage();
    });
}

if (esBtn) {
    esBtn.addEventListener('click', () => {
        localStorage.setItem('lang', 'es');
        changeLanguage();
    });
}
if (esBtn2) {
    esBtn2.addEventListener('click', () => {
        localStorage.setItem('lang', 'es');
        changeLanguage();
    });
}

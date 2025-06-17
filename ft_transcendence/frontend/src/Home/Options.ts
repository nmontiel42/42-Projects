const goingBack = document.getElementById('goingBack') as HTMLButtonElement;
const changeUsername = document.getElementById('changeUsernameBtn') as HTMLButtonElement;
const changeLang = document.getElementById('changeLanguage') as HTMLButtonElement;
const setup2FABtn = document.getElementById('setup2FABtn') as HTMLButtonElement;

const goingBackLang = document.getElementById('goingBackLang') as HTMLButtonElement;
const langView = document.getElementById('selectLang') as HTMLElement;

const changeUsernameView = document.getElementById('changeUsernameView') as HTMLElement;
const submitChangeUsername = document.getElementById('submitChangeUsername') as HTMLButtonElement;
const usernameChangeInput = document.getElementById('usernameChangeInput') as HTMLInputElement;

const buttonsToAnimate = [
    document.getElementById('logoutBtn'),
    document.getElementById('deleteAccountBtn'),
    document.getElementById('optionsBtn'),
    document.getElementById('goingBack'),
    document.getElementById('changeUsernameBtn'),
    document.getElementById('ture'),
    document.getElementById('changeLanguage'),
    document.getElementById('setup2FABtn'),
    document.getElementById('selectLang'),
];

const langButtons = [
    document.getElementById('goingBackLang'),
    document.getElementById('esBtn'),
    document.getElementById('enBtn'),
    document.getElementById('frBtn')
];

buttonsToAnimate.forEach(button => {
    if (button) {
        button.classList.add('fade-transition');

        if (button.style.display === 'none') {
            button.classList.add('fade-out');
        } else {
            button.classList.add('fade-in');
        }
    }
});

langButtons.forEach(button => {
    if (button) {
        button.classList.add('fade-transition');
        if (button.style.display === 'none') {
            button.classList.add('fade-out');
        } else {
            button.classList.add('fade-in');
        }
    }
});

goingBack.addEventListener('click', () => {

    [setup2FABtn, changeLang, changeUsername, goingBack].forEach(btn => {
        btn.classList.remove('fade-in');
        btn.classList.add('fade-out');
    });

    setTimeout(() => {
        changeLang.style.display = 'none';
        changeUsername.style.display = 'none';
        goingBack.style.display = 'none';
        setup2FABtn.style.display = 'none';

        logoutBtn.style.display = 'block';
        deleteAccountBtn.style.display = 'block';
        optionsBtn.style.display = 'block';

        document.body.offsetHeight;

        [logoutBtn, deleteAccountBtn, optionsBtn].forEach(btn => {
            btn.classList.remove('fade-out');
            btn.classList.add('fade-in');
        });
    }, 300);
});

changeLang.addEventListener('click', () => {

    [setup2FABtn, changeLang, changeUsername, goingBack].forEach(btn => {
        btn.classList.remove('fade-in');
        btn.classList.add('fade-out');
    });

    if (langView && !langView.classList.contains('fade-transition')) {
        langView.classList.add('fade-transition');
        langView.classList.add('fade-out');
    }

    const langButtons = [
        goingBackLang,
        document.getElementById('esBtn'),
        document.getElementById('enBtn'),
        document.getElementById('frBtn')
    ];

    langButtons.forEach(btn => {
        if (btn && !btn.classList.contains('fade-transition')) {
            btn.classList.add('fade-transition');
            btn.classList.add('fade-out');
        }
    });

    setTimeout(() => {
        changeLang.style.display = 'none';
        changeUsername.style.display = 'none';
        goingBack.style.display = 'none';
        setup2FABtn.style.display = 'none';

        langView.style.display = 'block';

        langButtons.forEach(btn => {
            if (btn) btn.style.display = 'block';
        });

        document.body.offsetHeight;

        if (langView) {
            langView.classList.remove('fade-out');
            langView.classList.add('fade-in');
        }

        langButtons.forEach(btn => {
            if (btn) {
                btn.classList.remove('fade-out');
                btn.classList.add('fade-in');
            }
        });
    }, 300);
});

goingBackLang.addEventListener('click', () => {
    langButtons.forEach(btn => {
        if (btn) {
            btn.classList.remove('fade-in');
            btn.classList.add('fade-out');
        }
    });

    langView.classList.remove('fade-in');
    langView.classList.add('fade-out');

    setTimeout(() => {
        langView.style.display = 'none';

        changeLang.style.display = 'block';
        changeUsername.style.display = 'block';
        goingBack.style.display = 'block';
        setup2FABtn.style.display = 'block';

        document.body.offsetHeight;

        [setup2FABtn, changeLang, changeUsername, goingBack].forEach(btn => {
            btn.classList.remove('fade-out');
            btn.classList.add('fade-in');
        });
    }, 300);
});

changeUsername.addEventListener('click', () => {
    changeUsernameView.style.display = 'block';
    homeView.style.display = 'none';
});

submitChangeUsername.addEventListener('click', async (event) => {
    event.preventDefault();
    const newUsername = usernameChangeInput.value;

    const token = localStorage.getItem('authToken');
    if (!token) {
        console.error('No se encontró el token de autenticación');
        return;
    }

    try {
        const response = await fetch('https://localhost:3000/change-username', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                'Authorization': `Bearer ${token}`,
            },
            body: JSON.stringify({ username: newUsername }),
        });

        const responseData = await response.json();

        if (!response.ok) {
            throw new Error(responseData.error || 'Error desconocido');
        }

        changeUsernameView.style.display = 'none';
        homeView.style.display = 'block';

        const usernameDisplay = document.getElementById('usernameDisplay') as HTMLElement;
        usernameDisplay.textContent = newUsername;
    } catch (error) {
        console.error('Error en la solicitud:', error);
        if (error instanceof Error) {
            alert(error.message);
        } else {
            alert('An unknown error occurred');
        }
    }
});


setup2FABtn.addEventListener('click', async () => {
    try {
        if (is2FAEnabled) {
            if (await disable2FA()) {
                await setupTwoFactorAuthUI();
            }
        } else {
            if (await enable2FA()) {
                await setupTwoFactorAuthUI();
            }
        }
    } catch (error) {
        console.error('Error in 2FA button click handler:', error);
    }
});
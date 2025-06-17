async function handleGoogleLogin(response: any) {
    try {
        const googleToken = response.credential;
        if (!googleToken) {
            alert("Google token is missing.");
            return;
        }

        const backendResponse = await fetch('https://localhost:3000/google-login', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ token: googleToken }),
        });

        const data = await backendResponse.json();

        if (!data.token) {
            alert("Error: Google authentication failed");
            return;
        }

        if (data.requires2FA) {

            localStorage.setItem('tempToken', data.tempToken);
            localStorage.setItem('sessionInfo', data.sessionInfo);
            
            loginView.style.display = 'none';
            const twoFactorAuthView = document.getElementById('twoFactorAuthView');
            if (twoFactorAuthView) {

            navigate('/2fa', true);
            
            const verificationCodeInput = document.getElementById('verificationCode') as HTMLInputElement;
            if (verificationCodeInput) verificationCodeInput.focus();
            }
            
            const lang = localStorage.getItem("lang");
            if (lang == 'es') alert('Por favor, introduce el código de verificación enviado a tu email.');
            else if (lang == 'en') alert ('Please, enter the verification code sent to your email.');
            else if (lang == 'fr') alert ('Veuillez saisir le code de vérification qui vous a été envoyé par courrier électronique.');
            return;
        }

        if (data.userExists) {

            localStorage.setItem('user', JSON.stringify(data.user));
            localStorage.setItem('googleToken', googleToken);
            localStorage.setItem('authToken', data.token);
            const userUsername = data.user.username || "Usuario";
            const usernameDisplay = document.getElementById('usernameDisplay') as HTMLElement;

            usernameDisplay.textContent = userUsername;

            loginView.style.display = 'none';
            registerView.style.display = 'none';
            homeView.style.display = 'block';

            localStorage.setItem("session", "true");

            navigate('/home');

            usernameView.style.display = 'none';

            const randomAvatarId = Math.floor(Math.random() * 10) + 1;
            const randomAvatar = `../public/avatars/avatar${randomAvatarId}.png`;
            const profilePic = randomAvatar;
            userProfile.innerHTML = `<img src="${profilePic}" alt="User profile picture" />`;
        } else {
            
            localStorage.setItem('user', JSON.stringify(data.user));
            localStorage.setItem('googleToken', googleToken);
            localStorage.setItem('authToken', data.token);

            loginView.style.display = 'none';
            registerView.style.display = 'none';
            homeView.style.display = 'none';
            usernameView.style.display = 'block';
        }
    } catch (error) {
        console.error("Google Login Error:", error);
    }
}

document.addEventListener("DOMContentLoaded", () => {
    const usernameForm = document.getElementById('usernameForm') as HTMLFormElement;

    usernameForm.addEventListener('submit', async (event) => {
        event.preventDefault();

        const username = (document.getElementById('usernameInput') as HTMLInputElement).value;
        const token = localStorage.getItem('googleToken');

        if (!token) {
            alert('No auth token found');
            return;
        }

        const response = await fetch('https://localhost:3000/google-username', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                'Authorization': `Bearer ${token}`,
            },
            body: JSON.stringify({ username, token }),
        });

        if (response.ok) {
            const data = await response.json();
            localStorage.setItem('authToken', data.token);
            localStorage.setItem('user', JSON.stringify(data.user));
            localStorage.setItem("userPicture", JSON.stringify({ picture: data.picture }));

            usernameView.style.display = 'none';
            homeView.style.display = 'block';
            localStorage.setItem("session", "true");

            const userUsername = data.user.username || "Ping";
            const usernameDisplay = document.getElementById('usernameDisplay') as HTMLElement;

            usernameDisplay.textContent = userUsername;

            navigate('/home');

            const randomAvatarId = Math.floor(Math.random() * 10) + 1;
            const randomAvatar = `../public/avatars/avatar${randomAvatarId}.png`;

            const profilePic = randomAvatar;

            userProfile.innerHTML = `<img src="${profilePic}" alt="User profile picture" />`;
        } else {
            const lang = localStorage.getItem("lang");
            if (lang == 'es') alert('El nombre de usuario ya está en uso');
            else if (lang == 'en') alert('The username is already in use');
            else if (lang == 'fr') alert ('Le nom d\'utilisateur est déjà utilisé.');
        }
    });
});

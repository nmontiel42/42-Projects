const registerView = document.getElementById('registerView') as HTMLElement;
const loginView = document.getElementById('loginView') as HTMLElement;
const homeView = document.getElementById('homeView') as HTMLElement;
const usernameView = document.getElementById('usernameView') as HTMLElement;

const registerForm = document.getElementById('registerForm') as HTMLFormElement;
const loginForm = document.getElementById('loginForm') as HTMLFormElement;

const goToLoginButton = document.getElementById('goToLogin') as HTMLButtonElement;
const goToRegisterButton = document.getElementById('goToRegister') as HTMLButtonElement;

const submitUsername = document.getElementById('submitUsername') as HTMLButtonElement;

const profileImage = document.getElementById("profileImage") as HTMLImageElement;

document.addEventListener("DOMContentLoaded", () => {
  goToLoginButton.addEventListener('click', () => {
    registerView.style.display = 'none';
    loginView.style.display = 'block';
  });
});

goToRegisterButton.addEventListener('click', () => {
  loginView.style.display = 'none';
  registerView.style.display = 'block';
});

document.addEventListener("DOMContentLoaded", () => {
  const userData = localStorage.getItem("user");

  if (userData) {
    const user = JSON.parse(userData);
    profileImage.src = user.picture;
  }
});

registerForm.addEventListener('submit', async (event: Event) => {
  event.preventDefault();

  const email = (document.getElementById('email') as HTMLInputElement).value;
  const username = (document.getElementById('username') as HTMLInputElement).value;
  const password = (document.getElementById('password') as HTMLInputElement).value;

  try {
    const response = await fetch('https://localhost:3000/register', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ email, username, password }),
    });

    if (response.ok) {
      const data = await response.json();

      if (!data.token) {
        alert('Error: el backend no devolvió un token');
        return;
      }
      const randomAvatarId = Math.floor(Math.random() * 10) + 1;
      const randomAvatar = `../public/avatars/avatar${randomAvatarId}.png`;
      
      if (!data.picture) {
        data.user.picture = randomAvatar;
      }

      localStorage.setItem('authToken', data.token);
      localStorage.setItem('user', JSON.stringify(data.user));
      
      userProfile.innerHTML = `<img src="${data.user.picture}" alt="User profile picture" />`;
      
      const userUsername = localStorage.getItem('user') ? JSON.parse(localStorage.getItem('user') || '{}').username : 'Ping';
      const usernameDisplay = document.getElementById('usernameDisplay') as HTMLElement;

      usernameDisplay.textContent = userUsername;

      registerView.style.display = 'none';
      homeView.style.display = 'block';
      localStorage.setItem("session", "true");
      navigate('/home');
    } else {
      const lang = localStorage.getItem("lang");
      if (lang === 'es') alert('Error en el registro: el email o el nombre de usuario ya está en uso')
      else if(lang === 'en') alert('Error in registration: email or username is already in use');
      else if (lang == 'fr') alert ('Erreur d\'enregistrement : l\'email ou le nom d\'utilisateur est déjà utilisé')
    }
  } catch (error) {
    console.error('Error al registrar:', error);
  }
});

loginForm.addEventListener('submit', async (event: Event) => {
  event.preventDefault();

  const email = (document.getElementById('loginEmail') as HTMLInputElement).value;
  const password = (document.getElementById('loginPassword') as HTMLInputElement).value;

  try {
    const response = await fetch('https://localhost:3000/login', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ email, password }),
    });

    if (response.ok) {
      const data = await response.json();

      if (data.requires2FA) {

        localStorage.setItem('tempToken', data.tempToken);
        localStorage.setItem('sessionInfo', data.sessionInfo);
        
        loginView.style.display = 'none';
        const twoFactorAuthView = document.getElementById('twoFactorAuthView');
        if (twoFactorAuthView) {

          navigate('/2fa');
        
          const verificationCodeInput = document.getElementById('verificationCode') as HTMLInputElement;
          if (verificationCodeInput) verificationCodeInput.focus();
        }
        
        const lang = localStorage.getItem("lang");
        if (lang == 'es') alert('Por favor, introduce el código de verificación enviado a tu email.');
        else if (lang == 'en') alert('Please, enter the verification code sent to your email.');
        else if (lang == 'fr') alert ('Veuillez saisir le code de vérification qui vous a été envoyé par courrier électronique.');
        return; 
      }

      if (!data.picture) {
        const randomAvatarId = Math.floor(Math.random() * 10) + 1;
        data.picture = `../public/avatars/avatar${randomAvatarId}.png`;
      }

      localStorage.setItem('authToken', data.token);
      localStorage.setItem('user', JSON.stringify({
        ...data,
        picture: data.picture
      }));
      localStorage.setItem("session", "true");

      const userUsername = data.username || "Ping";
      const usernameDisplay = document.getElementById('usernameDisplay') as HTMLElement;
      usernameDisplay.textContent = userUsername;
      loginView.style.display = 'none';
      homeView.style.display = 'block';
      localStorage.setItem("session", "true");

      navigate('/home');

      const profileImage = document.getElementById('profileImage') as HTMLImageElement;
      if (profileImage) {
        profileImage.src = data.picture || "../public/avatars/avatar1.png";
      }
    } else {
      const errorData = await response.json();
      alert(`Error in login: ${errorData.error || 'Invalid credentials'}`);
    }
  } catch (error) {
    console.error('Error al iniciar sesión:', error);
  }
});

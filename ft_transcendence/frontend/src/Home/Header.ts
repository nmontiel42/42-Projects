const logoutBtn = document.getElementById('logoutBtn') as HTMLButtonElement;
const userProfile = document.getElementById('userProfile') as HTMLElement;
const confirmModal = document.getElementById('confirmModal') as HTMLElement;
const cancelBtn = document.getElementById('cancelBtn') as HTMLButtonElement;
const deleteAccountBtn = document.getElementById('deleteAccountBtn') as HTMLButtonElement;
const optionsBtn = document.getElementById('optionsBtn') as HTMLButtonElement;

const homePlay = document.getElementById('homePlay') as HTMLButtonElement;
const localPlay = document.getElementById('localPlay') as HTMLButtonElement;
const multiPlay = document.getElementById('multiPlay') as HTMLButtonElement;
const tourPlay = document.getElementById('tourPlay') as HTMLButtonElement;
const realPlay = document.getElementById('realPlay') as HTMLButtonElement;

const localPlayView = document.getElementById('localPlayView') as HTMLElement;
const multiPlayView = document.getElementById('multiPlayView') as HTMLElement;
const realPlayView = document.getElementById('realPlayView') as HTMLElement;
const initialView = document.getElementById('initialView') as HTMLElement;
const twoFactorAuthView = document.getElementById('twoFactorAuthView') as HTMLElement;

userProfile.addEventListener('click', (event) => {
  event.stopPropagation();
  confirmModal.style.display = 'block';
  requestAnimationFrame(() => {
    confirmModal.style.animation = 'fadeIn 0.3s forwards';
  });
});

logoutBtn.addEventListener('click', () => {
  localStorage.removeItem('authToken');
  localStorage.removeItem('user');
  homeView.style.display = 'none';
  loginView.style.display = 'block';
  registerView.style.display = 'none';
  confirmModal.style.display = 'none';
  tournamentBracket.style.display = 'none';
  localStorage.removeItem("session");
});

document.addEventListener('click', (event: MouseEvent) => {
  if (confirmModal.style.display === 'block') {
    const target = event.target as HTMLElement;
    const confirmModal = document.getElementById('confirmModal') as HTMLElement;
    const userProfile = document.getElementById('userProfile') as HTMLElement;

    setTimeout(() => {
      if (!confirmModal.contains(target) && target !== userProfile) {
        confirmModal.style.animation = 'fadeOut 0.3s forwards';
        confirmModal.addEventListener('animationend', () => {
          confirmModal.style.display = 'none';
          confirmModal.style.animation = 'none';
        }, { once: true });
      }
    }, 10);
  }
});

deleteAccountBtn.addEventListener('click', async () => {
  const token = localStorage.getItem('authToken');
  const user = JSON.parse(localStorage.getItem('user') || '{}');
  const response = await fetch('https://localhost:3000/delete-account', {
    method: 'DELETE',
    headers: {
      'Content-Type': 'application/json',
      'Authorization': `Bearer ${token}`,
    },
    body: JSON.stringify({ username: user.username }),
  });

  if (response.ok) {
    const lang = localStorage.getItem('lang') || 'es';
    if (lang === 'es') {
      alert('Cuenta eliminada exitosamente');
    } else if (lang === 'en') {
      alert('Account successfully deleted');
    } else if (lang === 'fr') {
      alert('Compte supprimé avec succès');
    }
    localStorage.removeItem('authToken');
    localStorage.removeItem('user');
    homeView.style.display = 'none';
    loginView.style.display = 'none';
    registerView.style.display = 'block';
    tournamentBracket.style.display = 'none';
    initialView.style.display = 'none';
    localStorage.removeItem("session");

  } else {
    alert('Hubo un error al eliminar la cuenta');
  }

  confirmModal.style.display = 'none';
});

optionsBtn.addEventListener('click', (event) => {

  [logoutBtn, deleteAccountBtn, optionsBtn].forEach(btn => {
    btn.classList.remove('fade-in');
    btn.classList.add('fade-out');
  });

  setTimeout(async () => {

    logoutBtn.style.display = 'none';
    deleteAccountBtn.style.display = 'none';
    optionsBtn.style.display = 'none';

    changeLang.style.display = 'block';
    changeUsername.style.display = 'block';
    goingBack.style.display = 'block';

    const is2FAEnabled = await check2FAStatus();

    if (is2FAEnabled) {
      setup2FABtn.className = 'bg-red-500 text-white px-4 py-2 rounded-lg w-full text-xs mb-2 hover:cursor-pointer hover:scale-105';
      const lang = localStorage.getItem('lang') || 'en';
      if (lang === 'es') setup2FABtn.innerText = 'Deshabilitar 2FA';
      else if (lang === 'en') setup2FABtn.innerText = 'Disable 2FA';
      else if (lang === 'fr') setup2FABtn.innerText = 'Désactiver 2FA';
    } else {
        setup2FABtn.className = 'bg-[#318ED6] text-white px-4 py-2 rounded-lg w-full text-xs mb-2 hover:cursor-pointer hover:scale-105';
        const lang = localStorage.getItem('lang') || 'en';
        if (lang === 'es') setup2FABtn.innerText = 'Habilitar 2FA';
        else if (lang === 'en') setup2FABtn.innerText = 'Enable 2FA';
        else if (lang === 'fr') setup2FABtn.innerText = 'Activer 2FA';
    }
    setup2FABtn.style.display = 'block';

    document.body.offsetHeight;

    [setup2FABtn, changeLang, changeUsername, goingBack].forEach(btn => {
      btn.classList.remove('fade-out');
      btn.classList.add('fade-in');
    });
  }, 300);
});

homePlay.addEventListener('click', () => {
  stopCountdown();
  localPlayView.style.display = 'none';
  multiPlayView.style.display = 'none';
  realPlayView.style.display = 'none';
  tournamentView.style.display = 'none';
  initialView.style.display = 'block';
  resetButtonLogic();
  resetGame3d();
  stopMultiplayer();
});

localPlay.addEventListener('click', () => {
  stopCountdown();
  localPlayView.style.display = 'block';
  iaGameBtn.style.display = 'block';
  multiPlayView.style.display = 'none';
  realPlayView.style.display = 'none';
  tournamentView.style.display = 'none';
  initialView.style.display = 'none';
  isTournament = false;
  resetButtonLogic();
  drawGame();
  resetGame3d();
  stopMultiplayer();
});

multiPlay.addEventListener('click', () => {
  stopCountdown();
  localPlayView.style.display = 'none';
  multiPlayView.style.display = 'block';
  realPlayView.style.display = 'none';
  tournamentView.style.display = 'none';
  initialView.style.display = 'none';
  resetButtonLogic();
  resetGame3d();
  startMultiplayer();
});

tourPlay.addEventListener('click', () => {
  stopCountdown();
  localPlayView.style.display = 'none';
  multiPlayView.style.display = 'none';
  realPlayView.style.display = 'none';
  tournamentView.style.display = 'block';
  initialView.style.display = 'none';
  resetButtonLogic();
  resetGame3d();
  stopMultiplayer();
});

realPlay.addEventListener('click', () => {
  stopCountdown();
  localPlayView.style.display = 'none';
  multiPlayView.style.display = 'none';
  realPlayView.style.display = 'block';
  tournamentView.style.display = 'none';
  initialView.style.display = 'none';
  resetGame3d();
  resetButtonLogic();
  stopMultiplayer();
});

twoFactorAuthView.addEventListener('click', () => {
  localPlayView.style.display = 'none';
  multiPlayView.style.display = 'none';
  realPlayView.style.display = 'none';
  tournamentView.style.display = 'none';
  initialView.style.display = 'none';
  twoFactorAuthView.style.display = 'block';
  resetButtonLogic();
  resetGame3d();
  stopMultiplayer();
});
const userName = document.getElementById('userName') as HTMLElement;
let is2FAEnabled = false;

document.addEventListener('DOMContentLoaded', () => {
    const twoFactorAuthForm = document.getElementById('twoFactorAuthForm');

    if (twoFactorAuthForm) {
        twoFactorAuthForm.addEventListener('submit', handleTwoFactorAuth);
    }

    setupTwoFactorAuthUI();

});

async function handleTwoFactorAuth(event: Event) {
    event.preventDefault();

    const verificationCodeInput = document.getElementById('verificationCode') as HTMLInputElement | null;
    if (!verificationCodeInput) return;

    const verificationCode = verificationCodeInput.value;
    const tempToken = localStorage.getItem('tempToken');

    if (!tempToken) {
        const lang = localStorage.getItem('lang') || 'en';
        if (lang === 'es') alert('Sesión expirada. Por favor, inicia sesión nuevamente.');
        else if (lang === 'en') alert('Session expired. Please log in again.');
        else if (lang === 'fr') alert('Session expirée. Veuillez vous reconnecter.');
        return;
    }

    try {
        const response = await fetch('https://localhost:3000/verify-2fa-login', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({
                verificationCode,
                tempToken
            }),
        });

        if (response.ok) {
            const data = await response.json();

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
            localStorage.removeItem('tempToken');

            hide2FAModal();

            const homeView = document.getElementById('homeView');
            const usernameDisplay = document.getElementById('usernameDisplay') as HTMLElement;
            const profileImage = document.getElementById('profileImage') as HTMLImageElement;

            if (homeView) homeView.style.display = 'block';
            if (usernameDisplay) usernameDisplay.textContent = data.username || "Usuario";
            if (profileImage) profileImage.src = data.picture;

            navigate('/home');
        } else {
            const lang = localStorage.getItem('lang') || 'en';
            if (lang === 'es') {
                alert('Código de verificación inválido. Por favor, intenta nuevamente.');
            } else if (lang === 'en') {
                alert('Invalid verification code. Please try again.');
            } else if (lang === 'fr') {
                alert('Code de vérification invalide. Veuillez réessayer.');
            }
        }
    } catch (error) {
        console.error('Error en verificación 2FA:', error);
        const lang = localStorage.getItem('lang') || 'en';
        if (lang === 'es') alert('Error al verificar el código. Por favor, intenta nuevamente.');
        else if (lang === 'en') alert('Error verifying the code. Please try again.');
        else if (lang === 'fr') alert('Erreur de vérification du code. Veuillez réessayer.');
    }
}

async function setupTwoFactorAuthUI() {

    try {

        is2FAEnabled = await check2FAStatus();

        if (!setup2FABtn) {
            console.error('2FA button not found');
            return;
        }

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

        const modalContent = document.getElementById('modalContent');
        if (modalContent) {
 
            const existingBtn = document.getElementById('setup2FABtn');
            if (existingBtn && existingBtn.parentNode) {
                existingBtn.parentNode.removeChild(existingBtn);
            }

            modalContent.appendChild(setup2FABtn);
        }
    } catch (error) {
        console.error('Error setting up 2FA UI:', error);
    }
}

function show2FAModal() {
    const modal = document.getElementById('twoFactorAuthView');
    if (modal) {

        modal.style.display = 'flex';

        setTimeout(() => {
            const input = document.getElementById('verificationCode') as HTMLInputElement;
            if (input) input.focus();
        }, 100);
    } else {
        console.error('Modal 2FA not found in the DOM');
    }
}

function hide2FAModal() {
    const modal = document.getElementById('twoFactorAuthView');
    if (modal) {
        modal.style.display = 'none';
    }
}

async function check2FAStatus(): Promise<boolean> {
    const token = localStorage.getItem('authToken');
    if (!token) {
        console.log('No auth token found for 2FA status check');
        return false;
    }

    const user = localStorage.getItem('user');
    if (!user) {
        console.log('No user data found for 2FA status check');
        return false;
    }
    const userData = JSON.parse(user);
    if (!userData.email) {
        console.log('No email found in user data for 2FA status check');
        return false;
    }

    try {
        const response = await fetch('https://localhost:3000/2fa-status', {
            method: 'POST',
            headers: {
                'Authorization': `Bearer ${token}`,
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ email: userData.email })
        });

        if (response.ok) {
            const data = await response.json();

            return data.enabled && data.status === 'active';
        } else {
            console.error('Error getting 2FA status:', response.status);
            return false;
        }
    } catch (error) {
        console.error('Error checking 2FA status:', error);
        return false;
    }
}

async function disable2FA(): Promise<boolean> {

    const is2FAEnabled = await check2FAStatus();
    if (is2FAEnabled) {
        let confirmation;

        const lang = localStorage.getItem('lang') || 'en';

        if (lang === 'es') confirmation = confirm('¿Estás seguro de que deseas deshabilitar la autenticación de dos factores? Esto hará que tu cuenta sea menos segura.');
        else if (lang === 'en')confirmation = confirm('Are you sure you want to disable two-factor authentication? This will make your account less secure.');
        else if (lang === 'fr') confirmation = confirm('Êtes-vous sûr de vouloir désactiver l\'authentification à deux facteurs ? Cela rendra votre compte moins sécurisé.');

        if (!confirmation) return false;

        const token = localStorage.getItem('authToken');
        if (!token) {
            alert('You must be logged in to disable 2FA');
            return false;
        }

        const user = localStorage.getItem('user');
        if (!user) {
            alert('No user data found. Please log in again.');
            return false;
        }
        const userData = JSON.parse(user);
        if (!userData.email) {
            alert('No email found in user data. Please log in again.');
            return false;
        }

        const email = userData.email;

        try {
            const response = await fetch('https://localhost:3000/disable-2fa', {
                method: 'POST',
                headers: {
                    'Authorization': `Bearer ${token}`,
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({ confirm: true, email: email })
            });

            if (response.ok) {
                const lang = localStorage.getItem('lang') || 'en';

                if (lang === 'es')alert('La autenticación de dos factores ha sido deshabilitada exitosamente.');
                else if (lang === 'en') alert('Two-factor authentication has been disabled successfully.');
                else if (lang === 'fr') alert('L\'authentification à deux facteurs a été désactivée avec succès.');

                return true;
            } else {

                try {
                    const errorData = await response.json();
                    alert(`Failed to disable 2FA: ${errorData.error || 'Unknown error'}`);
                } catch (e) {
                    alert(`Failed to disable 2FA. Status: ${response.status}`);
                }
                return false;
            }
        } catch (error) {
            console.error('Error disabling 2FA:', error);
            return false;
        }
    }
    return false;
}

async function enable2FA(): Promise<boolean> {

    const is2FAEnabled = await check2FAStatus();

    if (!is2FAEnabled) {
        let email;
        const lang = localStorage.getItem('lang') || 'en';

        if (lang === 'es') email = prompt('Por favor, ingresa tu correo electrónico para habilitar la autenticación de dos factores:');
        else if (lang === 'en') email = prompt('Please enter your email to enable two-factor authentication:');
        else if (lang === 'fr') email = prompt('Veuillez entrer votre e-mail pour activer l\'authentification à deux facteurs :');

        if (!email) return false;

        const token = localStorage.getItem('authToken');

        if (!token) {
            alert('You must be logged in to enable 2FA');
            return false;
        }

        try {
            const response = await fetch('https://localhost:3000/enroll-2fa', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'Authorization': `Bearer ${token}`,
                },
                body: JSON.stringify({ email: email }),
            });

            if (response.ok) {
                const data = await response.json();

                localStorage.setItem('2faSessionInfo', data.sessionInfo);

                let verificationCode;

                const lang = localStorage.getItem('lang') || 'en';

                if (lang === 'es')  verificationCode = prompt('Introduce el código de verificación enviado a tu correo electrónico:');
                else if (lang === 'en') verificationCode = prompt('Enter the verification code sent to your email:');
                else if (lang === 'fr')  verificationCode = prompt('Entrez le code de vérification envoyé à votre e-mail :');

                if (!verificationCode) return false;

                const verifyResponse = await fetch('https://localhost:3000/verify-2fa-enrollment', {
                    method: 'POST',
                    headers: {
                        'Content-Type': 'application/json',
                        'Authorization': `Bearer ${token}`,
                    },
                    body: JSON.stringify({
                        verificationCode,
                        sessionInfo: data.sessionInfo,
                        email
                    }),
                });

                if (verifyResponse.ok) {

                    const lang = localStorage.getItem('lang') || 'en';

                    if (lang === 'es') alert('La autenticación de dos factores ha sido habilitada exitosamente.');
                    else if (lang === 'en') alert('Two-factor authentication has been enabled successfully.');
                    else if (lang === 'fr') alert('L\'authentification à deux facteurs a été activée avec succès.');

                    return true;
                } else {
                    const errorData = await verifyResponse.json();
                    const lang = localStorage.getItem("lang");
                    if (lang == 'es') alert (`Error verificando el codigo: ${errorData.error ||'Error desconocido'}`);
                    else if (lang == 'en') alert(`Failed to verify the code: ${errorData.error || 'Unknown error'}`);
                    else if (lang == 'fr') alert(`Erreur de vérification du code: ${errorData.error || 'Erreur inconnue'}`);
                    return false;
                }
            } else {
                const errorData = await response.json();
                alert(`Failed to setup 2FA: ${errorData.error || 'Unknown error'}`);
                return false;
            }
        } catch (error) {
            console.error('Error setting up 2FA:', error);
            alert('Error setting up 2FA. Please try again.');
            return false;
        }
    }
    return false;
}
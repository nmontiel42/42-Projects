const routes: { [key: string]: string } = {
  "/": "registerView",
  "/login": "loginView",
  "/username": "usernameView",
  "/home1": "homeView",
  "/change-username": "changeUsernameView",
  "/local": "localPlayView",
  "/multi": "multiPlayView",
  "/tournament": "tournamentView",
  "/3d": "realPlayView",
  "/home": "initialView",
  "/2fa": "twoFactorAuthView"
};

function isLoggedIn(): boolean {
  return !!localStorage.getItem("session");
}

function navigate(path: string, replace = false) {
  const viewId = routes[path];

  const protectedRoutes = ["/local", "/multi", "/tournament", "/3d", "/home"];

  if (protectedRoutes.includes(path) && !isLoggedIn()) {
    alert("You must be logged in to access this section.");
    navigate("/login", true);
    return;
  }
  if (viewId) {
    Object.values(routes).forEach(id => {
      const element = document.getElementById(id);
      if (element) {
        if (id === viewId) {
          element.style.display = "block";
        } else {
          element.style.display = "none";
        }
      }
    });

    const isGameView = ["localPlayView", "multiPlayView", "tournamentView", "realPlayView", "initialView"].includes(viewId);
    const homeView = document.getElementById("homeView");
    if (homeView) homeView.style.display = isGameView ? "block" : (viewId === "homeView" ? "block" : "none");

    if (viewId === "localPlayView") {
      stopMultiplayer();
      stopCountdown();
      resetButtonLogic();
      drawGame();
    } else if (viewId === "multiPlayView") {
      startMultiplayer();
    } else if (viewId === "realPlayView") {
      stopCountdown();
      isPaused = true;
    }

    if (replace) {
      history.replaceState({ path }, "", path);
    } else {
      history.pushState({ path }, "", path);
    }
  }
}

window.addEventListener("popstate", (event) => {
  const path = event.state?.path || "/";
  navigate(path, true);
});

document.addEventListener("DOMContentLoaded", () => {
  document.getElementById("goToLogin")?.addEventListener("click", () => navigate("/login"));
  document.getElementById("goToRegister")?.addEventListener("click", () => navigate("/"));
  document.getElementById("changeUsernameBtn")?.addEventListener("click", () => navigate("/change-username"));
  document.getElementById("logoutBtn")?.addEventListener("click", () => navigate("/login"));
  document.getElementById("deleteAccountBtn")?.addEventListener("click", () => navigate("/"));
  document.getElementById("submitChangeUsername")?.addEventListener("click", (e) => {
    e.preventDefault();
    navigate("/home");
  });

  document.getElementById("homePlay")?.addEventListener("click", () => navigate("/home"));
  document.getElementById("localPlay")?.addEventListener("click", () => navigate("/local"));
  document.getElementById("multiPlay")?.addEventListener("click", () => navigate("/multi"));
  document.getElementById("tourPlay")?.addEventListener("click", () => navigate("/tournament"));
  document.getElementById("realPlay")?.addEventListener("click", () => navigate("/3d"));

  const currentPath = window.location.pathname;

  const protectedRoutes = ["/local", "/multi", "/tournament", "/3d", "/home", "/2fa"];
  if (protectedRoutes.includes(currentPath) && !isLoggedIn()) {
    navigate("/login", true);
  } else {
    const user = localStorage.getItem("user");
    const usernameDisplay = document.getElementById('usernameDisplay') as HTMLElement;
    if (user) {
        const userParsed = JSON.parse(user);
        if (!userParsed.picture) {
            const randomAvatarId = Math.floor(Math.random() * 10) + 1;
            const randomAvatar = `../public/avatars/avatar${randomAvatarId}.png`;
            const userProfile = document.getElementById("userProfile") as HTMLElement;
            userProfile.innerHTML = `<img src="${randomAvatar}" alt="User profile picture" />`;
        }
        usernameDisplay.textContent = userParsed.username || "Ping";
        navigate(currentPath, true);
    }
  }
});
function setTheme(theme) {
    document.documentElement.setAttribute("data-theme", theme);
    localStorage.setItem("theme", theme);
}

function toggleTheme() {
    if (localStorage.getItem("theme") == "light") {
        setTheme("dark");
    } else {
        setTheme("light");
    }
    return localStorage.getItem("theme");
}

window.onload = (event) => {
    if (localStorage.getItem("theme") != null)
        setTheme(localStorage.getItem("theme"));
    else toggleTheme();
}
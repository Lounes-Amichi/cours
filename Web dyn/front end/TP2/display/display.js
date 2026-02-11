/* Ne fonctionne pas car le script est appelé trop tôt : le reste de la page (notamment la popup) n'est pas encore chargé */
/* Solution 1 : déplacer ces balises <script> à la fin du <body> => Non satisfaisant car on ne devrait pas avoir de balises <script> en dehors des balises <head> */
/* Solution 2 : calculer la valeur de noeud à chaque clic sur un bouton (noeud devient une variable locale) => moyennement satisafaisant car on re-calcule la référence de la popup à chaque clic sur un bouton */
/* Solution 3 : on initialise noeud (variable globale) uniquement après la fin du chargemetn du <body> à l'aide de l'événément onload => c'est la meilleure solution */

// Délcarations (variables globales)
var noeud, bouton_afficher, bouton_cacher;

function init() {
  console.log("Ceci est un appel à init");
  // Initialisations de variables globales
  noeud = document.getElementById("popup");
  bouton_afficher = document.getElementById("bouton_afficher");
  bouton_cacher = document.getElementById("bouton_cacher");
  // En alternative au CSS :
  //bouton_cacher.style.display = "none";
}

// Afficher la popup et échanger les boutons
function afficher_popup() {
  console.log("fonction afficher_popup");
	noeud.style.display = "block";
	bouton_afficher.style.display = "none";
	bouton_cacher.style.display = "block";
}

// Cacher la popup et échanger les boutons
function cacher_popup() {
  console.log("fonction cacher_popup");
	noeud.style.display = "none";
	bouton_cacher.style.display = "none";
	bouton_afficher.style.display = "block";
}










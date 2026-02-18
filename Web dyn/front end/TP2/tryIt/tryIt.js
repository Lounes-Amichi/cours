/* 
casseChameau : camelCase : chaqueMotCommenceParUneMajuscule 

snake_case : casse_serpent : les_mots_sont_en_minuscules_separes_par_underscore
*/

var refTA = null;
var refVisuel = null;
var refCbAuto = null;
var refPopup = null;

var dataPopup = {
    "btnActu": "Cliquez ici pour mettre à jour le rendu en fonction du code.",
    "cbAuto": "Cochez cette case pour effectuer la mise à jour automatiquement",
    "lblAuto": "+cbAuto",
};

function init() {
    console.log("init");
    refTA = document.getElementById("taSaisie");
    refVisuel = document.getElementById("visuel");
    refCbAuto = document.getElementById("cbAuto");
    refPopup = document.getElementById("popup");
}

function actualize() {
    console.log("actualize");
    // lire à gauche 
    var contenu = refTA.value;
    console.log(contenu);

    // écrire à droite 
    refVisuel.innerHTML = contenu;
}

/*
  setTimeout(f_ref, delay)
  - f_ref : une référence à une fonction
  - delay : un délai en millisecondes
*/

// SI la case est cochée 
// => quelle propriété détermine l'état de cette case ? 
// Afficher sur la console l'objet représentant la référence vers la case 
// console.log(refCbAuto);
// DEpuis la console, écrire le nom de la référence suivi d'un point 
// ALORS mettre à jour 

// enregistrer la référence dans une variable globale et afficher l'onglet source de la console de débogage => Watch pour observer ses propriétés/valeurs 

// Cf. caniuse pour vérifier la pertinence de cette propriété 

function autoActualize() {
    console.log("autoActualize");
    if (refCbAuto.checked) {
        actualize();
        setTimeout(autoActualize, 2000);
    }
}

// Popup lors des survols 
// NB : attribut title possible dans chaque balise 

// On utilise la propagation des événements 
// Lors d'une propagation, il faut trouver l'élémént à l'origine de l'événement 
// On passe event en paramètre de la fonction 
// gestionnaire d'événement
function popin(contexte) {
    var txt;
    console.log("popin");
    //console.log(contexte);
    console.log(contexte.target.id);

    txt = dataPopup[contexte.target.id];
    if (txt !== undefined) {
        if (txt.startsWith('+')) {
            txt = dataPopup[txt.substring(1)];
        }
        refPopup.innerHTML = txt;
        refPopup.style.display = "block";
    }
}

function popout() {
    console.log("popout");
    refPopup.style.display = "none";
    refPopup.innerHTML = "";
}

function popmove(contexte) {
    console.log("popmove");
    if (contexte.clientX + 10 + 10 + 100 < document.body.clientWidth) {
        refPopup.style.left =
            (contexte.clientX + 10) + "px";
    } else {
        refPopup.style.left =
            (contexte.clientX - 100 - 20) + "px";
    }
    refPopup.style.top =
        (contexte.clientY + 10) + "px";
}

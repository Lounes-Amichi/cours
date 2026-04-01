<?php
session_start(); // rend accessible le tableau $_SESSION pour les données liées au cookie PHPSESSID reçu 

include_once "maLibUtils.php";	// Car on utilise la fonction valider()


// Lire var. de session 
tprint($_SESSION);

if (! valider("connecte","SESSION")) {
	// si user inconnu => redirection
	header("Location:form.php?msg=" . urlencode("il faut saisir login & passe"));
	die("");
}


?>

Mes identifiants et mots de passe 
id impots + passe
id bancaires + passe 













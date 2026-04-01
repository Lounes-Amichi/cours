<?php
session_start(); // rend accessible le tableau $_SESSION pour les données liées au cookie PHPSESSID reçu 

include_once "maLibSecurisation.php";
securiser("form.php?msg=" . urlencode("Il faut saisir login & passe")); 


?>

Mes identifiants et mots de passe 
id impots + passe
id bancaires + passe 













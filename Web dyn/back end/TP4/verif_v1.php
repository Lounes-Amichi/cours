<?php
session_start(); 
// Fait quoi ? 
// [si l'utilisateur n'était pas déjà connu donc n'avait pas déjà envoyé de cookie de session]
// 1) générer un id de session (unique) 
// 2) envoi d'un cookie PHPSESSID au client avec cet identifiant
// PHPSESSID=dkcrr8uvd4upjsvgabn07m5dc5

// [dans tous les cas]
// 3) rend accessible le tableau $_SESSION en lecture/écriture  

include_once "maLibUtils.php";
include_once "maLibForms.php";
include_once "modele.php";

// recup data (login, passe)
// verifier

if ($login=valider("login"))
if ($passe=valider("passe"))
if ($id = verifUserBdd($login,$passe)) {
	// Si OK : 
	// 1) enregistrer l'identité de l'user dans les var. de SESSION 
	$_SESSION["idUser"] = $id; 
	$_SESSION["connecte"] = 1; 
	
	// 2) redirection vers admin.php 
	header("Location:admin.php"); 
	die(""); // forcer l'arret du script 
}


// Si PB : 
// 1) incrémenter le compteur d'erreurs en var de session 
// 2) blacklist user si trop de tentatives
// 3) redirection vers form
header("Location:form.php?msg=" . urlencode("Connexion impossible")); 


?>

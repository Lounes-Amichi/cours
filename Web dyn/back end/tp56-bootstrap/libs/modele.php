<?php

/*
Dans ce fichier, on définit diverses fonctions permettant de récupérer des données utiles pour notre TP d'identification. Deux parties sont à compléter, en suivant les indications données dans le support de TP
*/


/********* PARTIE 1 : prise en main de la base de données *********/


// inclure ici la librairie faciliant les requêtes SQL
include_once("maLibSQL.pdo.php");

function listerUtilisateurs($classe = "both")
{
	// Cette fonction liste les utilisateurs de la base de données 
	// et renvoie un tableau d'enregistrements. 
	// Chaque enregistrement est un tableau associatif contenant les champs 
	// id,pseudo,blacklist,connecte,couleur

	// Lorsque la variable $classe vaut "both", elle renvoie tous les utilisateurs
	// Lorsqu'elle vaut "bl", elle ne renvoie que les utilisateurs blacklistés
	// Lorsqu'elle vaut "nbl", elle ne renvoie que les utilisateurs non blacklistés

	$SQL = "SELECT id,pseudo,blacklist,connecte,couleur FROM users"; 
	if ($classe == "bl") $SQL = $SQL . " WHERE blacklist=1";
	if ($classe == "nbl") $SQL .= " WHERE blacklist=0";
	return parcoursRs(SQLSelect($SQL)); 
	
}


function interdireUtilisateur($idUser)
{
	// cette fonction affecte le booléen "blacklist" à vrai pour l'utilisateur concerné
	$SQL = "UPDATE users SET blacklist=1 WHERE id='$idUser'"; 
	return SQLUpdate($SQL); 
}

function autoriserUtilisateur($idUser)
{
	// cette fonction affecte le booléen "blacklist" à faux pour l'utilisateur concerné 
	$SQL = "UPDATE users SET blacklist=0 WHERE id='$idUser'"; 
	return SQLUpdate($SQL); 
}

function verifUserBdd($login,$passe)
{
	// Vérifie l'identité d'un utilisateur 
	// dont les identifiants sont passes en paramètre
	// renvoie faux si user inconnu
	// renvoie l'id de l'utilisateur si succès

	$SQL="SELECT id FROM users WHERE pseudo='$login' AND passe='$passe'";

	return SQLGetChamp($SQL);
	// si on avait besoin de plus d'un champ
	// on aurait du utiliser SQLSelect
}


function isAdmin($idUser)
{
	// vérifie si l'utilisateur est un administrateur
	$SQL ="SELECT admin FROM users WHERE id='$idUser'";
	return SQLGetChamp($SQL); 
}

function isBlacklist($idUser)
{
	// vérifie si l'utilisateur est un blacklisté
	$SQL ="SELECT blacklist FROM users WHERE id='$idUser'";
	return SQLGetChamp($SQL); 
}

/********* PARTIE 2 *********/

function mkUser($pseudo, $passe,$admin=false,$couleur="black")
{
	// Cette fonction crée un nouvel utilisateur et renvoie l'identifiant de l'utilisateur créé
}

function connecterUtilisateur($idUser)
{
	// cette fonction affecte le booléen "connecte" à vrai pour l'utilisateur concerné 
}

function deconnecterUtilisateur($idUser)
{
	// cette fonction affecte le booléen "connecte" à faux pour l'utilisateur concerné 
}

function changerCouleur($idUser,$couleur="black")
{
	// cette fonction modifie la valeur du champ 'couleur' de l'utilisateur concerné
}

function changerPasse($idUser,$passe)
{
	// cette fonction modifie le mot de passe d'un utilisateur
}

function changerPseudo($idUser,$pseudo)
{
	// cette fonction modifie le pseudo d'un utilisateur
}

function promouvoirAdmin($idUser)
{
	// cette fonction fait de l'utilisateur un administrateur
}

function retrograderUser($idUser)
{
	// cette fonction fait de l'utilisateur un simple mortel
}


/********* PARTIE 3 *********/

function listerUtilisateursConnectes()
{
	// Liste les utilisteurs connectes
	$SQL = "SELECT id,pseudo,blacklist,connecte,couleur FROM users WHERE connecte=1"; 
	return parcoursRs(SQLSelect($SQL)); 
}

function listerConversations($mode="tout")
{
	// Liste toutes les conversations ($mode="tout")
	// OU uniquement celles actives  ($mode="actives"), ou inactives  ($mode="inactives")
	
	$SQL = "SELECT * FROM conversations"; 
	if ($mode == "actives") $SQL = $SQL . " WHERE active=1";
	if ($mode == "inactives") $SQL .= " WHERE active=0";
	return parcoursRs(SQLSelect($SQL)); 
}

function archiverConversation($idConversation)
{
	// rend une conversation inactive
	$SQL = "UPDATE conversations SET active=0 WHERE id='$idConversation'"; 
	return SQLUpdate($SQL);
}

function creerConversation($theme)
{
	// crée une nouvelle conversation et renvoie son identifiant
	$SQL = "INSERT INTO conversations(theme)  VALUES ('$theme')"; 
	return SQLInsert($SQL);
}

function reactiverConversation($idConversation)
{	
	// rend une conversation active
	$SQL = "UPDATE conversations SET active=1 WHERE id='$idConversation'"; 
	return SQLUpdate($SQL);

}

function supprimerConversation($idConv)
{
	// supprime une conversation et ses messages
	$SQL = "DELETE FROM messages WHERE idConversation='$idConv'";
	SQLDelete($SQL);
	
	$SQL = "DELETE FROM conversations WHERE id='$idConv'";
	SQLDelete($SQL);

	// NB : on aurait pu aussi demander à mysql de supprimer automatiquement
	// les messages lorsqu'une conversation est supprimée, 
	// en déclarant idConversation comme clé étrangère vers le champ id de la table 
	// des conversations et en définissant un trigger
}


function enregistrerMessage($idConversation, $idAuteur, $contenu)
{
	// Enregistre un message dans la base en encodant les caractères spéciaux HTML : <, > et & pour interdire les messages HTML
	// Pour éviter les injections XSS
	$contenu = htmlspecialchars($contenu);
	return SQLInsert("
	  INSERT INTO messages(idConversation, idAuteur, contenu)
	  VALUES ('$idConversation', '$idAuteur', '$contenu');
	");
}

function listerMessages($idConv,$format="asso")
{
	// Liste les messages de cette conversation, au format JSON ou tableau associatif
	// Champs à extraire : contenu, auteur, couleur 
	// en ne renvoyant pas les utilisateurs blacklistés
	
	// SELECT m.contenu, u.pseudo as auteur, u.couleur FROM messages m INNER JOIN users u ON m.idAuteur=u.id WHERE m.idConversation=1 AND u.blacklist=0
	$res = parcoursRs(SQLSelect("
	  SELECT
	    messages.contenu AS contenu,
	    users.pseudo AS auteur,
	    users.couleur AS couleur
	  FROM messages
	  JOIN users ON users.id = messages.idAuteur
	  WHERE messages.idConversation = '$idConv'
	    AND NOT users.blacklist
	  ORDER BY messages.id;
	"));
	if ($format == 'json') {
	  return json_encode($res);
	} else {
	  return $res;
	}
}

function listerMessagesFromIndex($idConv,$index)
{
	// Liste les messages de cette conversation, 
	// dont l'id est superieur à l'identifiant passé
	// Champs à extraire : contenu, auteur, couleur 
	// en ne renvoyant pas les utilisateurs blacklistés

}

function getConversation($idConv)
{	
	// Récupère les données de la conversation (theme, active)
	$res = parcoursRs(SQLSelect("
	  SELECT theme, active
	  FROM conversations
	  WHERE id ='$idConv';
	"));
	if (count($res) == 1) {
	  return $res;
  } else {
    return false;
  }
}








?>

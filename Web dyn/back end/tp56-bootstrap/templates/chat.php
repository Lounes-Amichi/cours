<?php

// Si la page est appelée directement par son adresse, on redirige en passant pas la page index
if (basename($_SERVER["PHP_SELF"]) != "index.php")
{
	header("Location:../index.php?view=chat&" . $_SERVER["QUERY_STRING"]);
	// Il faut renvoyer le reste de la chaine de requete... 
	// A SUIVRE : ne marche que pour requetes GET
	// Un appel à http://localhost/chatISIG/templates/chat.php?idConv=2
	// renvoie vers http://localhost/chatISIG/index.php?view=chat&idConv=2
	
	die("");
}

include_once("libs/modele.php");
include_once("libs/maLibUtils.php");
include_once("libs/maLibForms.php");


// On récupère l'id de la conversation à afficher, dans idConv
$idConv = valider("idConv");
if (!$idConv)
{
	// pas d'identifiant ! On redirige vers la page de choix de la conversation

	// NB : pose quelques soucis car on a déjà envoyé la bannière... 
	// Il y a opportunité d'écrire cette bannière plus tard si on la place en absolu
	header("Location:index.php?view=conversations"); 
	die("idConv manquant");
}

// On récupère les paramètres de la conversation
$conv = getConversation($idConv);

// Afficher le thème de la conversation courante
echo "<h2>" . $conv[0]['theme'] . "</h2>\n";

// TODO : intégrer une page qui se recharge toutes les 10 secondes ici
echo '<iframe
  width="300"
  height="200"
  src="messages.php?idConv=' . $idConv . '">
</iframe>';

// Si conversation active
// Si l'utilisateur connecté
// Afficher un formulaire permettant de poster un nouveau message 
if ($conv[0]['active'] &&
    valider('connecte', 'SESSION') &&
    !valider('blacklist', 'SESSION')) {
  mkForm('controleur.php');
    mkInput('hidden', 'idConv', $idConv);
    mkInput('text', 'contenu', '');
    mkInput('submit', 'action', 'Poster');
  endForm();
}
?>















<?php
// Ce fichier permet de tester les fonctions développées dans le fichier malibforms.php

// Si la page est appelée directement par son adresse, on redirige en passant pas la page index
if (basename($_SERVER["PHP_SELF"]) == "conversations.php")
{
	header("Location:../index.php?view=conversations");
	die("");
}

include_once("libs/modele.php"); // listes
include_once("libs/maLibUtils.php");// tprint
include_once("libs/maLibForms.php");// mkTable, mkLiens, mkSelect ...
include_once("libs/maLibSecurisation.php");

//phpinfo(); 
//die(""); 
securiser("?view=login&msg=" . urlencode("La page conversations nécessite d'être connecté")); 
// déclenche la création d'une entête de réponse !! 
// ceci ne fonctionne QUE parce que votre serveur apache bufferise !! 
// Erreur : headers already sent 

// Autre solution : directement afficher la vue login et pas la vue normale ! 

?>

<h1>Conversations du site</h1>

<h2>Liste des conversations actives</h2>

<?php
// Conversations actives sous forme de liens
$c = listerConversations("actives"); 
//tprint($c);
//mkTable($c); 
mkLiens($c, "theme", "id", "index.php?view=chat", "idConv");
?>

<h2>Liste des conversations inactives</h2>

<?php
// Conversations inactives sous forme de liens 
$c = listerConversations("inactives"); 
//mkTable($c); 
mkLiens($c, "theme", "id", "index.php?view=chat", "idConv");
?>


<?php

// Proposer des formulaires de gestion de conversations
if (valider('isAdmin', 'SESSION')) {
  echo "<hr />\n";
  echo "<h2>Gestion des conversations</h2>\n";
  $idConv = valider('idConv');
  $c = listerConversations(); 
  mkForm("controleur.php");
    mkSelect("idConv", $c, "id", "theme", $idConv); 
    mkInput("submit","action","Activer"); 
    mkInput("submit","action","Archiver"); 
    mkInput("submit","action","Supprimer"); 
  endForm(); 

  mkForm("controleur.php"); 
    mkInput("text","theme",""); 
    mkInput("submit","","Créer"); 
    mkInput("hidden","action","Nouvelle conversation"); 
  endForm(); 
}
?>
















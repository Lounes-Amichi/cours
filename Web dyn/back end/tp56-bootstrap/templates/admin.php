<?php
// Ce fichier permet de tester les fonctions développées dans le fichier controleur.php (première partie)

include_once "libs/modele.php"; 
include_once "libs/maLibForms.php"; 
include_once "libs/maLibUtils.php"; 

// Pas idéal car on a déjà affiché tout l'en-tête de la page
if (!valider('isAdmin', 'SESSION')) {
  header('Location: index.php?view=accueil');
  die('');
}

$idUser = valider("idUser");

?>

<h1>Administration du site</h1>

<h2>Liste des utilisateurs de la base </h2>

<?php

echo "liste des utilisateurs autorises de la base :"; 
$users = listerUtilisateurs("nbl");
//mkTable($users);
mkTable($users, array('id', 'pseudo', 'couleur') );
	
// utiliser le second argument pour n'afficher que 'pseudo', 'couleur', 'connecte' 
// dans cet ordre 

echo "<hr />";

echo "liste des utilisateurs non autorises de la base :"; 
$users = listerUtilisateurs("bl");
mkTable($users, array('id', 'pseudo', 'couleur') );
// utiliser le second argument pour n'afficher que 'pseudo', 'couleur', 'connecte' 
// dans cet ordre 
?>


<hr />

<h2>Changement de statut des utilisateurs</h2>


<?php

mkForm('controleur.php');
$users = listerUtilisateurs("both");

// blacklistEnrichi vaudra soit "interdit" soit "autorise"
/*
foreach ($users as $nextUser) {
	if ($nextUser["blacklist"]==1) 
		$nextUser["blacklistEnrichi"] = "interdit"; 
	else 
		$nextUser["blacklistEnrichi"] = "autorise"; 
}
*/

for ($i=0;$i<count($users);$i++) {
	$users[$i]["blacklistEnrichi"] = 
		($users[$i]["blacklist"]==1) ? "interdit" : "autorise";
	
	/*
	if ($users[$i]["blacklist"]==1) {
		$users[$i]["blacklistEnrichi"] = "interdit";
	} 
	else 
		$users[$i]["blacklistEnrichi"] = "autorise"; 
	*/
}

mkSelect("idUser[]",$users,"id","pseudo", $idUser, "blacklistEnrichi");
// améliorer pour que l'utilisateur qui vient d'être mis à jour 
// soit automatiquement sélectionné

mkInput("submit","action","Interdire");
mkInput("submit","action","Autoriser");
endForm(); 

?>


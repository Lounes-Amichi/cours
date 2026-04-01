<?php
// Ce fichier permet de tester les fonctions développées dans le fichier controleur.php (première partie)

include_once "modele.php"; 
include_once "maLibForms.php"; 
include_once "maLibUtils.php"; 

if ($idUser = valider("idUser"))
if ($action = valider("action")) {
	echo "$action / $idUser"; 
	switch($action) {
		case "Interdire": 
			interdireUtilisateur($idUser); 
		break; 
		case "Autoriser": 
			autoriserUtilisateur($idUser);
		break; 
	}
}

?>

<h1>Administration du site</h1>

<h2>Liste des utilisateurs de la base </h2>

<?php

echo "liste des utilisateurs autorises de la base :"; 
$users = listerUtilisateurs("nbl");
//mkTable($users);
mkTable($users, array('id', 'pseudo') );
	
// utiliser le second argument pour n'afficher que 'pseudo', 'couleur', 'connecte' 
// dans cet ordre 

echo "<hr />";

echo "liste des utilisateurs non autorises de la base :"; 
$users = listerUtilisateurs("bl");
mkTable($users);	
// utiliser le second argument pour n'afficher que 'pseudo', 'couleur', 'connecte' 
// dans cet ordre 
?>


<hr />

<h2>Changement de statut des utilisateurs</h2>


<?php

mkForm();
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

mkSelect("idUser",$users,"id","pseudo", $idUser, "blacklistEnrichi");
// améliorer pour que l'utilisateur qui vient d'être mis à jour 
// soit automatiquement sélectionné

mkInput("submit","action","Interdire");
mkInput("submit","action","Autoriser");
endForm(); 

?>


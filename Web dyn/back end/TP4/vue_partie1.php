<?php
// Ce fichier permet de tester les fonctions développées dans le fichier controleur.php (première partie)

include_once "modele.php"; 
include_once "maLibUtils.php";

// 1) récupérer les données
// Ici, on reçoit : idUser,action par la méthode GET 

// Warning: Undefined array key "action" in /var/www/html/B2/sujet_tp4_2016/vue_partie1.php on line 11

/*
if (isset($_GET["action"])) $action = $_GET["action"];
else $action=false; 
if (isset($_GET["idUser"])) $idUser = $_GET["idUser"];
else $idUser = false;
*/

// Ici on teste une affectation !
// la valeur d'une affectation, c'est la valeur affectée 

//$idUser = valider("idUser"); 
//$action = valider("action");
//if ($action && $idUser){

// il faut garantir que idUser soit toujours créé
// => On l'affecte en premier 
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

// 2) vérifier les données 
// NEVER TRUST USER INPUT !! 

// 3) exécuter les traitements 

// 4) préparer la réponse à renvoyer au nav. 


?>

<h1>Administration du site</h1>

<h2>Liste des utilisateurs de la base </h2>

<?php

echo "liste des utilisateurs autorises de la base :"; 
$users = listerUtilisateurs("nbl");

tprint($users);	// préférer un appel à mkTable($users);

echo "<hr />";

echo "liste des utilisateurs non autorises de la base :"; 
$users = listerUtilisateurs("bl");

tprint($users);	// préférer un appel à mkTable($users);
?>


<hr />

<h2>Changement de statut des utilisateurs</h2>

<form>
<!-- 
sans attribut action, les données sont envoyées à la page elle-même 
sans attribut method, les données sont envoyées par la méthode GET
idUser est envoyé par le menu déroulant 
action est envoyé par le bouton ayant servi à soumettre les données du formulaire 
-->

<select name="idUser">
<?php
$users = listerUtilisateurs("both");

// TODO : préselectionner le dernier utilisateur MANIPULE 
// Son id : $idUser 

foreach ($users as $dataUser)
{
	// L'id de l'utilisateur COURANT est $dataUser["id"]
	// <b>Warning</b>:  Undefined variable $idUser in <b>/var/www/html/B2/sujet_tp4_2016/vue_partie1.php</b> on line <b>87</b><br />

	if ($dataUser["id"] == $idUser) $sel = "selected";
	else $sel=""; 
	
	echo "<option $sel value=\"$dataUser[id]\">";
	echo  $dataUser["pseudo"];
	echo "</option>\n"; 
}
?>
</select>

<input type="submit" name="action" value="Interdire" />
<input type="submit" name="action" value="Autoriser" />
</form>

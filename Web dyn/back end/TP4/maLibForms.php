<?php


/*
Ce fichier définit diverses fonctions permettant de faciliter la production de mises en formes complexes : 
tableaux, formulaires, ...
*/

function mkLigneEntete($tabAsso,$listeChamps=false)
{
	// Fonction appelée dans mkTable, produit une ligne d'entête
	// contenant les noms des champs à afficher dans mkTable
	// Les champs à afficher sont définis à partir de la liste listeChamps 
	// si elle est fournie ou du tableau tabAsso
	echo "\n\t<tr>";
	if ($listeChamps) {
		for($i=0;$i<count($listeChamps);$i++) 
			echo "\n\t\t<th>$listeChamps[$i]</th>";
//	foreach( $listeChamps as $prochainChamp)
//		echo "\n\t\t<th>$prochainChamp</th>";
	} 
	else {
		// pas de listeChamps
		foreach( $tabAsso as $cle => $val) {
			echo "\n\t\t<th>$cle</th>";
		}
		
	
	}
	echo "\n\t</tr>";
}

function mkLigne($tabAsso,$listeChamps=false)
{
	// Fonction appelée dans mkTable, produit une ligne 
	// contenant les valeurs des champs à afficher dans mkTable
	// Les champs à afficher sont définis à partir de la liste listeChamps 
	// si elle est fournie ou du tableau tabAsso
	echo "\n\t<tr>";
	if ($listeChamps) {
		for($i=0;$i<count($listeChamps);$i++) 
			echo "\n\t\t<td>" . 
				$tabAsso[$listeChamps[$i]] . "</td>";
//	foreach( $listeChamps as $prochainChamp)
//		echo "\n\t\t<td>$tabAsso[$prochainChamp]</td>";
	} 
	else {
		// pas de listeChamps
		foreach( $tabAsso as $val) {
			echo "\n\t\t<td>$val</td>";
		}
		
	
	}
	echo "\n\t</tr>";
}

function mkTable($tabData,$listeChamps=false)
{
	// Produit un tableau affichant les données passées en paramètre
	// Si listeChamps est vide, on affiche toutes les données de $tabData
	// S'il est défini, on affiche uniquement les champs listés dans ce tableau, 
	// dans l'ordre du tableau
	
	if (count($tabData)==0) return; 
	
	echo "\n<table>"; 
	mkLigneEntete($tabData[0], $listeChamps);
	
	foreach($tabData as $prochainTabAsso) {
		mkLigne($prochainTabAsso,$listeChamps);
	} 
	echo "\n</table>"; 
	
}


function mkSelect($nomChampSelect, $tabData,$champValue, $champLabel,$selected=false,$champLabel2=false)
{

	echo "\n" . '<select name="' . $nomChampSelect . '">'; 
	foreach($tabData as $nextData) {
		if ($nextData[$champValue] == $selected) $sel="selected"; 
		else $sel=""; 
		
		echo "\n<option $sel value=\"$nextData[$champValue]\">"; 
		echo $nextData[$champLabel]; 
		if ($champLabel2) echo " - " . $nextData[$champLabel2]; 
		echo "</option>";
	}
	
	echo "\n</select>";


	// Produit un menu déroulant portant l'attribut name = $nomChampSelect
	// TNE: Si cette variable se termine par '[]', il faudra affecter l'attribut multiple à la balise select

	// Produire les options d'un menu déroulant à partir des données passées en premier paramètre
	// $champValue est le nom des cases contenant la valeur à envoyer au serveur
	// $champLabel est le nom des cases contenant les labels à afficher dans les options
	// $selected contient l'identifiant de l'option à sélectionner par défaut
	// si $champLabel2 est défini, il indique le nom d'une autre case du tableau 
	// servant à produire les labels des options
}

function mkForm($action="",$method="get")
{
	// Produit une balise de formulaire NB : penser à la balise fermante !!
	echo "\n<form action=\"$action\" method=\"$method\">"; 
}
function endForm()
{
	// produit la balise fermante
	echo "\n</form>"; 
}

function mkInput($type,$name,$value="")
{
	// Produit un champ formulaire
	echo "\n<input type=\"$type\" name=\"$name\" value=\"$value\">";
}

function mkRadioCb($type,$name,$value,$checked=false)
{
	// Produit un champ formulaire de type radio ou checkbox
	// Et sélectionne cet élément si le quatrième argument est vrai
	
	if ($checked) $c = "checked"; 
	else $c ="";
	
	echo "\n<input $c type=\"$type\" name=\"$name\" value=\"$value\">";
}
?>
















<?php
session_start(); 

include_once "maLibUtils.php";
include_once "maLibForms.php";

// si blacklist => php.net 

tprint($_SESSION); 
tprint($_SERVER); 

// recup message et affichage 
if ($msg = valider("msg")) {
	echo "<h3 style=\"color:red;\">$msg</h3>"; 
}

// création form 

mkForm("verif.php"); 
mkInput("text","login"); 
mkInput("password","passe");
mkInput("submit","", "OK");  
endForm(); 

?>

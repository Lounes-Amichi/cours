<?php

include_once "libs/maLibUtils.php";
include_once "libs/modele.php";

$idConv = valider('idConv', 'GET');

echo "<?xml version=\"1.0\" encoding=\"utf-8\" ?>";
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>	
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <meta http-equiv="refresh" content="10">
	<title>Chat'2i</title>
	<link rel="stylesheet" type="text/css" href="css/style.css">
	
	<script>
	  function init() {
	    window.scrollTo({
        left: 0,
        top: document.body.scrollHeight,
        behavior: "smooth"
      });
    }
	</script>

</head>

<body onload="init();">
<?php
// afficher les messages 
$messages = listerMessages($idConv, 'asso');
foreach ($messages as $m) {
  echo "<div style=\"color:" . $m['couleur'] . "\">[" .
    $m['auteur'] . "] " . $m['contenu'] . "</div>\n";
}
?>
</body>
</html>


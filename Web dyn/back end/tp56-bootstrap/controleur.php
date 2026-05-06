<?php
session_start();

  include_once "libs/maLibUtils.php";
  include_once "libs/maLibSQL.pdo.php";
  include_once "libs/maLibSecurisation.php"; 
  include_once "libs/modele.php"; 

  $qs = "";

  if ($action = valider("action"))
  {
    ob_start ();
    echo "Action = '$action' <br />";
    // ATTENTION : le codage des caractères peut poser PB si on utilise des actions comportant des accents... 
    // A EVITER si on ne maitrise pas ce type de problématiques

    /* TODO: A REVOIR !!
    // Dans tous les cas, il faut etre logue... 
    // Sauf si on veut se connecter (action == Connexion)

    if ($action != "Connexion") 
      securiser("login");
    */

    // Un paramètre action a été soumis, on fait le boulot...
    switch($action)
    {
      
      
      // Connexion //////////////////////////////////////////////////
      case 'Connexion' :
        // On verifie la presence des champs login et passe
        if ($login = valider("login"))
        if ($passe = valider("passe"))
        {
          // On verifie l'utilisateur, 
          // et on crée des variables de session si tout est OK
          // Cf. maLibSecurisation
          if (verifUser($login,$passe)) {
            // tout s'est bien passé, doit-on se souvenir de la personne ? 
            if (valider("remember")) {
              setcookie("login",$login , time()+60*60*24*30);
              setcookie("passe",$passe, time()+60*60*24*30);
              setcookie("remember",true, time()+60*60*24*30);
            } else {
              setcookie("login","", time()-3600);
              setcookie("passe","", time()-3600);
              setcookie("remember",false, time()-3600);
            }
          }
        }

        // On redirigera vers la page index automatiquement
      break;

      case 'logout' :
      case 'Logout' :
      case 'deconnexion' :
        // 1) traitement métier
        session_destroy(); 
        // 2) choix de la prochaine vue : on donne une valeur à $qs
        // qui est utilisée dans la création de l'entête de redirection 
        $qs = "?view=login&msg=" . urlencode("Merci & Au revoir !"); 
        
      break;

      // NEVER TRUST USER INPUT !!
      case 'Archiver' : 
        if (valider("isAdmin","SESSION"))
        if ($idConv = valider("idConv")) {
          archiverConversation($idConv);
        }
        $qs = "?view=conversations&idConv=$idConv"; 
      break;

      case 'Activer' : 
        if (valider("isAdmin","SESSION"))
        if ($idConv = valider("idConv")) {
          reactiverConversation($idConv);
        }
        $qs = "?view=conversations&idConv=$idConv";  
      break; 
      
      case 'Supprimer' :
        if (valider("isAdmin","SESSION"))
        if ($idConv = valider("idConv")) {
          supprimerConversation($idConv);
        }
        $qs = "?view=conversations";  
      break;

      case 'Nouvelle conversation' :
        if (valider("isAdmin","SESSION"))
        if ($theme = valider("theme")) {
          creerConversation($theme);
        }
        $qs = "?view=conversations";  
      break;

      case 'Poster' : 
        if (valider('connecte', 'SESSION') &&
            ($contenu = valider('contenu', 'GET')) &&
            ($idConv = valider('idConv', 'GET')) &&
            ($idUser = valider('idUser', 'SESSION'))) {
          // Vérifie que la conv est active
          $conv = getConversation($idConv);
          if ($conv && $conv[0]['active']) {
            enregistrerMessage($idConv, $idUser, $contenu);
            $qs = "?view=chat&idConv=$idConv";
          } else {
            $qs = "?view=conversations";
          }
        } else {
          $qs = "?view=conversations";
        }
      break;

      case "Interdire": 
        if (($idUser = valider("idUser")) &&
            valider('isAdmin', 'SESSION')) {
          foreach ($idUser as $u) {
            interdireUtilisateur($u);
          }
        }
        $qs = "?view=admin&idUser=$idUser";
      break; 

      case "Autoriser": 
        if (($idUser = valider("idUser")) &&
            valider('isAdmin', 'SESSION')) {
          foreach ($idUser as $u) {
            autoriserUtilisateur($u);
          }
        }
        $qs = "?view=admin&idUser=$idUser";
      break; 

    }

  }

  // On redirige toujours vers la page index, mais on ne connait pas le répertoire de base
  // On l'extrait donc du chemin du script courant : $_SERVER["PHP_SELF"]
  // Par exemple, si $_SERVER["PHP_SELF"] vaut /chat/data.php, dirname($_SERVER["PHP_SELF"]) contient /chat

  $urlBase = dirname($_SERVER["PHP_SELF"]) . "/index.php";
  // On redirige vers la page index avec les bons arguments

  header("Location:" . $urlBase . $qs);

  // On écrit seulement après cette entête
  ob_end_flush();
  
?>











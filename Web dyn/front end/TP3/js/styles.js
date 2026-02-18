/*
  - JSON.parse : analyser une chaîne pour créer un objet correspondant en mémoire
  - JSON.stringify : faire l'inverse
  var styles2 = styles; => cela produit une copie des références mais pas des objets !
  var styles2 = JSON.parse(JSON.stringify(styles)); => cela produit bien un clonage de l'objet et crée un deuxième objet indépendant
*/
var styles = JSON.parse("{\"designs\":[{\"name\":\"Une colonne\", \"href\":\"css/one-column.css\"},{\"name\":\"Deux colonnes\", \"href\":\"css/two-columns.css\"},{\"name\":\"Blocs\", \"href\":\"css/float-blocks.css\"}],\"themes\": [{\"name\":\"Noir &amp; blanc\", \"href\":\"css/nb.css\"},{\"name\":\"fluo\", \"href\":\"css/fluo.css\"},{\"name\":\"Green IT\", \"href\":\"css/green-it.css\"}]}");


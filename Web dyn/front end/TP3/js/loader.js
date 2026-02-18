
// a : un tableau
function OptionsFromJSON(a) {
  var txt = "", i, cur;
  
  for (i = 0; i < a.length; i++) {
    cur = a[i];
    txt += "<option value=\"" + cur.href +
      "\">" + cur.name + "</option>\n";
  }
  
  return txt;
}

function init() {
  console.log("Fonction init");
  console.log(styles);
  
  document.getElementById("design").innerHTML = OptionsFromJSON(styles.designs);
  
  document.getElementById("theme").innerHTML = OptionsFromJSON(styles.themes);
}

function changeDesign() {
  console.log("changeDesign");
  document.getElementById("designStyle").href = document.getElementById("design").value;
}

function changeTheme() {
  console.log("changeTheme");
  document.getElementById("themeStyle").href = document.getElementById("theme").value;
}











function fillData(data, mapping) {

		// personal : insérer les données dans des champs de même nom  
    // contact : utilisation de listes de descriptions  
   
   	// Langages, Loisirs : utiliser la fonction fillSimpleList
   	
   	// Compétences, Expériences, Formation, Projets : utiliser la fonction fillBlocks
}

function fillSimpleList(array, containerId) {
	var container = document.getElementById(containerId);
	for (var i = 0; i < array.length; i++) {
		var li = "<li>" + array[i] +  "</li>";
		container.innerHTML += li;
	}
}

function fillBlocks(array, containerId, formatter) {
	var container = document.getElementById(containerId);
	for (var i = 0; i < array.length; i++) {
		var div = "<div class=\"item\">" + formatter(array[i]) + "</div>";
		container.innerHTML += div;
	}
}


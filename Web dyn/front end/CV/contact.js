let contactForm = document.querySelector("#contact-form");
let GUI = document.querySelector("#contact-GUI");
let docBody = document.querySelector("#doc-body");

function toggleForm() { //active et désactive la visibilité du formulaire de création de tâches.
    GUI.classList.toggle("noDisplay");
    docBody.classList.toggle("noOverflow");
}

function formSubmit(event) { //récupère les données du formulaire pour la création de tâches.
    event.preventDefault();
    
    let nom = document.querySelector("#form-nom").value;
    let prenom = document.querySelector("#form-prenom").value;
    let email = document.querySelector("#form-email").value;
    let message = document.querySelector("#form-message").value;
    
    let contact = {
        "nom": nom,
        "prenom": prenom,
        "email": email,
        "message": message
    };

    console.log(JSON.stringify(contact));

    toggleForm();
    return false;
}
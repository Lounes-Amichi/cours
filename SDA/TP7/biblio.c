# include "biblio.h"

void init (T_Bibliotheque *ptrB) {
    ptrB->nbLivres=0; // ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB) {
    if (ptrB->nbLivres<CAPACITE_BIBLIO) { // reste t il de la place?
        saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
        ptrB->nbLivres++;
        return 1;
    }
    return 0;
}

int  afficherBibliotheque(const T_Bibliotheque *ptrB) {
    int i;
    if(ptrB->nbLivres==0)
        return 0;
    else {
        for(i=0;i<ptrB->nbLivres;i++) {
            afficherLivre(&(ptrB->etagere[i]));
        }
        return 1;
    }
}

int rechercherTitre(const T_Bibliotheque * ptrB, const char * titre) {
    int i, exemp = 0; // nombre d'exemplaires trouvés
    for (i = 0; i < ptrB->nbLivres; i++) {
        if (strcmp(ptrB->etagere[i].titre, titre) == 0) {
            exemp++;
            afficherLivre(&(ptrB->etagere[i]));
        }
    }
    return exemp;
}

int rechercherAuteur(const T_Bibliotheque * ptrB, const char * auteur) {
    int i, exemp = 0; // nombre d'exemplaires trouvés
    for (i = 0; i < ptrB->nbLivres; i++) {
        if (strcmp(ptrB->etagere[i].auteur, auteur) == 0) {
            afficherLivre(&(ptrB->etagere[i]));
            exemp++;
        }
    }
    return exemp;
}

int supprimerLivre(T_Bibliotheque *ptrB, const char * titre, const char *auteur)
{
    int i;
    for (i = 0; i < ptrB->nbLivres; i++) {
        if (strcmp(ptrB->etagere[i].titre, titre) == 0 && strcmp(ptrB->etagere[i].auteur, auteur) == 0) {
            ptrB->etagere[i] = ptrB->etagere[ptrB->nbLivres];
            ptrB->nbLivres--;
            return 0;
        }
    }
    return 1;
}
# include "biblio.h"

void init (T_Bibliotheque *ptrB) {
    ptrB->nbLivres=0; // ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque *ptrB) {
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

int supprimerLivre(T_Bibliotheque *ptrB, const char * code)
{
    int i;
    for (i = 0; i < ptrB->nbLivres; i++) {
        if (strcmp(ptrB->etagere[i].code, code) == 0) {
            ptrB->etagere[i] = ptrB->etagere[ptrB->nbLivres];
            ptrB->nbLivres--;
            return 0;
        }
    }
    return 1;
}

int emprunterLivre(T_Bibliotheque *ptrB, const char * code, const char * emp) {
    for (int i = 0; i < ptrB->nbLivres; i++) {
        if (strcmp(ptrB->etagere[i].code, code) == 0) {
            if (strcmp(ptrB->etagere[i].emprunteur, "") == 0) {
                strcpy((ptrB->etagere[i].emprunteur), emp);
            } else {
                return 1;
            }
        }
    }
    return 0;
}

void retournerLivre(T_Bibliotheque *ptrB, const char *code) {
    for (int i = 0; i < ptrB->nbLivres; i++) {
        if (strcmp(ptrB->etagere[i].code, code) == 0) {
            strcpy((ptrB->etagere[i].emprunteur), "");
        }
    }
}

void trierParTitre(T_Bibliotheque *ptrB)
{
    int i, j;
    T_livre tmp;

    for (i = 0; i < ptrB->nbLivres - 1; i++)
        for (j = i + 1; j < ptrB->nbLivres; j++)
        {
            if (strcmp(ptrB->etagere[i].titre, ptrB->etagere[j].titre) > 0)
            {
                tmp = ptrB->etagere[i];
                ptrB->etagere[i] = ptrB->etagere[j];
                ptrB->etagere[j] = tmp;
            }
        }
}

void trierParAuteur(T_Bibliotheque *ptrB)
{
    int i, j;
    T_livre tmp;

    for (i = 0; i < ptrB->nbLivres - 1; i++)
        for (j = i + 1; j < ptrB->nbLivres; j++)
        {
            if (strcmp(ptrB->etagere[i].auteur, ptrB->etagere[j].auteur) > 0)
            {
                tmp = ptrB->etagere[i];
                ptrB->etagere[i] = ptrB->etagere[j];
                ptrB->etagere[j] = tmp;
            }
        }
}

void trierParAnnee(T_Bibliotheque *ptrB)
{
    int i, j;
    T_livre tmp;

    for (i = 0; i < ptrB->nbLivres - 1; i++)
        for (j = i + 1; j < ptrB->nbLivres; j++)
        {
            if (ptrB->etagere[i].annee > ptrB->etagere[j].annee)
            {
                tmp = ptrB->etagere[i];
                ptrB->etagere[i] = ptrB->etagere[j];
                ptrB->etagere[j] = tmp;
            }
        }
}
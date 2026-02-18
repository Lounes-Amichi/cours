#include "livre.h"

void saisirLivre(T_livre * ptrL) {
    lireChaine("CODE :", (ptrL->code), MAX_TITRE);
    lireChaine("TITRE :", (ptrL->titre), MAX_TITRE);
    lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
    lireChaine("EDITEUR :", (ptrL->editeur), MAX_TITRE);
    lireInt("ANNEE :", (ptrL->annee));
}

void afficherLivre(const T_livre *ptrL) {
    afficherChaine("CODE :", (ptrL->code));
    printf(" - ");
    afficherChaine("TITRE :", (ptrL->titre));
    printf(" - ");
    afficherChaine("AUTEUR :", (ptrL->auteur));
    printf(" - ");
    afficherChaine("EDITEUR :", (ptrL->editeur));
    printf(" - ");
    afficherInt("ANNEE :", (ptrL->annee));
    printf("\n");
}
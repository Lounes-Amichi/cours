#include "livre.h"

void saisirLivre(T_livre * ptrL) {
    char temp[K_MaxAnn];
    lireChaine("CODE :", (ptrL->code), K_MaxCode);
    lireChaine("TITRE :", (ptrL->titre), K_MaxTit);
    lireChaine("AUTEUR :", (ptrL->auteur), K_MaxAut);
    lireChaine("EDITEUR :", (ptrL->editeur), K_MaxEdit);
    lireChaine("ANNEE :", temp, K_MaxAnn);
    ptrL->annee = atoi(temp);
    strcpy(ptrL->emprunteur, "");
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
    printf("ANNEE : %d", (ptrL->annee));
    printf(" - ");
    if (strcmp(ptrL->emprunteur, "") == 0)
        printf("Disponible");
    else
        printf("Emprunteur : %s", (ptrL->emprunteur));
    printf("\n");
}
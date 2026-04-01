// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"
#include "file.h"
#include <string.h>

void testFile(T_File *ptrF);
void testPile(T_Pile *P);
void permut(T_Pile *mapile, char *chaine);

#define passerAuPremierFils(adrP, E) empiler(adrP, E)
#define remonterAuPere(adrP, adrE) depiler(adrP, adrE)
#define passerAuFrereSuivant(adrP,adrE) depiler(adrP,adrE),empiler(adrP,1+(*adrE))
#define naPlusDeFrere(adrP, TailleChaine) sommet(adrP) == TailleChaine
#define noeudTerminal(adrP, TailleChaine) hauteur(adrP) == TailleChaine
#define rechercheTerminee(adrP) pilevide(adrP)

    int menu() {
    int choix;
    printf("\n\n\nSDA1 TP9");
    printf("\n\n\n1: tester mon fichier file.c");
    printf("\n2: tester mon fichier pile.c");
    printf("\n3: afficher et compter les permutations d'une chaine");
    printf("\n4: afficher et compter les solutions pour un échiquier");
    printf("\n0: QUITTER");
    printf("\nvotre choix ?\n> ");
    scanf("%d",&choix);
    return choix;
}

int main() {
    T_File mafile;
    T_Pile mapile;
    int chx;
    // int taille;
    char chaine[20];
    
    do {
        chx=menu();
        switch (chx) {
            case 1 :  
                //testez toutes vos fonctions par un jeu de test de votre choix
                testFile(&mafile); //TP9 partie 1 : à ecrire
                break;
                case 2 :
                //testez toutes vos fonctions par un jeu de test de votre choix
                testPile(&mapile); //TP9 partie 1 : à ecrire
                break; 
            case 3 : 
                printf("Saisir une chaine à permuter:\n> ");
                scanf("%s",chaine); //une chaine de longueur <=MAX
                permut(&mapile,chaine); //TP9 partie 2: ecrire permut
                break;
            case 4 : 
                //scanf("%d",&taille);//taille echiquier <=MAX
                //echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
                break;
        }
    } while(chx!=0);

    printf("\nau plaisir de vous revoir ...\n");
    return 0;
}

void testFile(T_File *ptrF) {
    initFile(ptrF);
    printf("taille de la file: %d\n", tailleFile(ptrF));
    printf("File vide: %d\n", fileVide(ptrF));
    printf("File pleine: %d\n", filePleine(ptrF));
    T_Elt elem;
    T_Elt elem2;
    for (int i = 1; i <= MAX; i++){
        elem = i;
        ajouter(ptrF, &elem);
    }
    printf("taille de la file: %d\n", tailleFile(ptrF));
    afficherFile(ptrF);
    printf("File vide: %d\n", fileVide(ptrF));
    printf("File pleine: %d\n", filePleine(ptrF));
    elem2 = premier(ptrF);
    printf("Premier element: %d\n", elem2);
    retirer(ptrF, &elem2);
    printf("Element retire: %d\n", elem2);
    retirer(ptrF, &elem2);
    printf("Element retire: %d\n", elem2);
    elem = 11;
    ajouter(ptrF, &elem);
    printf("taille de la file: %d\n", tailleFile(ptrF));
    afficherFile(ptrF);
    elem2 = premier(ptrF);
    printf("Premier element: %d\n", elem2);
}

void testPile(T_Pile *P) {
    initPile(P);
    printf("hauteur de la Pile: %d\n", hauteur(P));
    printf("Pile vide: %d\n", pilevide(P));
    printf("Pile pleine: %d\n", pilepleine(P));
    T_Elt elem;
    T_Elt elem2;
    for (int i = 1; i <= MAX; i++){
        elem = i;
        empiler(P, elem);
    }
    printf("hauteur de la pile: %d\n", hauteur(P));
    afficherPile(P);
    printf("hauteur de la pile: %d\n", hauteur(P));
    printf("Pile vide: %d\n", pilevide(P));
    printf("Pile pleine: %d\n", pilepleine(P));
    elem2 = sommet(P);
    printf("Sommet: %d\n", elem2);
    depiler(P, &elem2);
    printf("Element retire: %d\n", elem2);
    depiler(P, &elem2);
    printf("Element retire: %d\n", elem2);
    elem2 = sommet(P);
    printf("Sommet: %d\n", elem2);
    elem = 11;
    empiler(P, elem);
    printf("hauteur de la pile: %d\n", hauteur(P));
    afficherPile(P);
    elem2 = sommet(P);
    printf("Sommet: %d\n", elem2);
}


void afficherSolution(T_Pile *P, char *chaine) {
    for (int i = 0; i < hauteur(P); i++) {
        int index = P->Elts[i] - 1;
        printf("%c", chaine[index]);
    }
    printf(" ");
}

int pileValide(T_Pile *adrP) {
    if (pilevide(adrP) || adrP->nbElts == 1)
        return 1;

    T_Elt dernier = sommet(adrP);
    for (int i = 0; i < adrP->nbElts - 1; i++) {
        if (adrP->Elts[i] == dernier) {
            return 0;
        }
    }
    return 1;
}

void permut(T_Pile *mapile, char *chaine) {
    int taille = strlen(chaine);
    int nb_permutations = 0;
    T_Elt e;
    initPile(mapile);

    passerAuPremierFils(mapile, 1);
    do {
        while (pileValide(mapile)) {
            if (noeudTerminal(mapile, taille)) {
                afficherSolution(mapile, chaine);
                nb_permutations++;
                break;
            }
            else {
                passerAuPremierFils(mapile, 1);
            }
        }

        while (!rechercheTerminee(mapile) && naPlusDeFrere(mapile, taille)) {
            remonterAuPere(mapile, &e);
        }

        if (!rechercheTerminee(mapile))
        {
            passerAuFrereSuivant(mapile, &e);
        }

    } while (!rechercheTerminee(mapile));

    printf("\nIl y a %d permutations.\n", nb_permutations);
}
#include <stdio.h>
#define TAILLE 20

int main() {
    int T[TAILLE][TAILLE];
    int nby = 0;
    int nbx = 0;
    int error = 0;
    int i;
    int j;
    int comp;

    // Saisie des lignes
    do {
        if (error == 3) {
        	printf("3 saisies erronées, fin du programme. (Erreur 1)\n");
        	return 1;
	}
        printf("Combien de lignes voulez-vous saisir? (Entre 1 et %d)\n", TAILLE);
        scanf("%d", &nby);
        error++;
    } while (nby < 1 || nby > TAILLE);
    error = 0;
    do {
        printf("Combien de colonnes voulez-vous saisir? (Entre 1 et %d)\n", TAILLE);
        scanf("%d", &nbx);
        if (error == 3) return 1;
        error++;
    } while (nbx < 1 || nbx > TAILLE);

    // Saisie des valeurs du tableau
    for (i = 0; i < nby; i++) {
        for (j = 0; j < nbx; j++) {
            printf("Saisir la valeur de la matrice à (%d,%d):\n", j, i);
            scanf("%d", &comp);
            T[i][j] = comp;
        }
    }

    // Affichage du vecteur
    for (i = 0; i <nby; i++) {
        printf("V[%d]: ", i);
        for (j = 0; j<nbx; j++) {
            printf("%d     ", T[i][j]);
        }
        printf("\n");
    }
    return 0;
}

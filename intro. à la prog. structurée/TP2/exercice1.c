#include <stdio.h>
#define TAILLE 20

int main() {
    int T[TAILLE];
    int nb;
    int error = 0;
    int i = 0;
    int comp;

    // Saisie de la taille du vecteur
    do {
        printf("Combien de valeurs voulez-vous saisir? (Entre 1 et %d)\n", TAILLE);
        scanf("%d", &nb);
        error++;
        if (error == 3) return 1;
    } while (nb < 1 || nb > TAILLE);

    // Saisie des composantes du vecteur
    for (i; i < nb; i++) {
        printf("Saisir la composante %d du vecteur:\n", i);
        scanf("%d", &comp);
        T[i] = comp;
    }

    // Affichage du vecteur
    for (i = 0; i <nb; i++) {
        printf("V[%d] = %d\n", i, T[i]);
    }
    return 0;
}

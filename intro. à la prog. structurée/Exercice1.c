#include <stdio.h>

/* Remarque: ce programme pourrait être largement simplifié, il suffit de calculer le carré de n.
int main(){
  int n;
  if (n > 0) {
    printf("La somme des %d premiers entiers impairs est %d.\n", n, n*n);
  } else {
    printf("\a Erreur: n n'est pas positif (Code 1)\n");
    return 1;
  }
  return 0;
}
*/
int main(){
  int i, n, somme = 0; // valeur d'itération de la boucle, valeur max de la fonction, somme
  printf("Entrez une valeur entière positive:\n> ");
  scanf("%d", &n);
  if (n > 0) {
    for (i = 1; i < 2*n; i += 2) { // 2*n car i est incrémenté de 2 en 2.
      somme += i;
    }
    printf("La somme des %d premiers entiers impairs est %d.\n", n, somme);
  } else {
    printf("\a Erreur: n n'est pas positif (Code 1)\n");
    return 1;
  }
  return 0;
}

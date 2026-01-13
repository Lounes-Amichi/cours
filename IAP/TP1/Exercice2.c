#include <stdio.h>

int sommeDiv(int n) {
  int i, somme = 0;
  if(n > 0) {
    for (i = 1; i < n; i++) {
      if (n % i == 0) somme += i;
    }
  } else return 0;
  return somme;
}

int main(){
  int i, n;
  printf("Entrez une valeur entière positive:\n> ");
  scanf("%d", &n);
  if (n <= 0) {
    printf("\a Erreur: n n'est pas positif (Code 1)\n");
    return 1;
    }
  else {
    if (n < 6) {
      printf("Il n'existe aucun nombre parfait inférieur ou égal à %d\n", n); 
    } else {
      printf("Les nombres parfaits inférieurs ou égaux à %d sont:\n", n);
      for (i = 1; i < n+1; i++) {
        if (sommeDiv(i) == i) printf("%d\n", i);
      }
    }
  }
  return 0;
}

#include <stdio.h>
#include <string.h>

typedef int T_Elt; //TAD
// ou
//typedef char T_chaine[50];
//typedef T_chaine T_Elt; //TAD
// ou
// typedef char  T_Elt; //TAD


void saisirElt(T_Elt * e);
void afficherElt(T_Elt * e);
void affecterElt(T_Elt * d,T_Elt * s);
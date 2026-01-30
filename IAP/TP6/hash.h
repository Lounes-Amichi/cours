#include <stdio.h>
#include <string.h>
#include <ctype.h>
//#include <stdlib.h>


#define TAILLEMAX 50
#define MAX 200

typedef  int ENTIER_T;

typedef char NOM_T[TAILLEMAX];

typedef NOM_T   TABNOM_T[MAX];


//prototypes : 
ENTIER_T  hashcode(NOM_T,TABNOM_T );


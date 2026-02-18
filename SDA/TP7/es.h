#ifndef ES_H   //compilation conditionnelle
#define ES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *lire(char *lachaine,int nbMAXcaracAsaisir);
char *lireChaine(const char *nomChamps, char *chaine, int nbcarac);
void afficherChaine(const char * nomChamp, const char * valeur);
int lireInt(const char *nomChamps, int entier);
void afficherInt(const char *nomChamp, const int valeur);

#endif

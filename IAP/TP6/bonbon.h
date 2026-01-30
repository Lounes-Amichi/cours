/*********************************B2*************************************/
/* AUTEUR : AMICHI Lounès                                               */
/* DATE : 07/01/2026                                                    */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Entête du module bonbon	                        */
/* NOM FICHIER : bonbon.h                                               */
/************************************************************************/

#ifndef BONBON
#define BONBON

#include <stdio.h>
#include <string.h>

char * copierChaine(char * dest, const char * str);
int validerPreferences(const char * ch);
int rechercherSousChaine(const char * ch, const char * ssch);
int retirerSousChaine(char * ch, const char * ssch);
void afficherPortionsVendues(char * ch, char * noms[], char * prefs[], int montants[], int nbEnfants);

#define MAXCAR 100
typedef char Tchaine[MAXCAR+1];

#endif

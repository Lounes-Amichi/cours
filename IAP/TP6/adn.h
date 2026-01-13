/*********************************B2*************************************/
/* AUTEUR : AMICHI Lounès                                               */
/* DATE : 07/01/2026                                                    */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Entête du module adn		                        */
/* NOM FICHIER : adn.h	                                                */
/************************************************************************/

#ifndef ADN
#define ADN

#include <stdio.h>
#include <string.h>
#include <math.h>

int verifierComposition(const char * seq);
void compterNucleotides(const char seq[], int* countA, int* countT, int* countC, int* countG);
char nucleotideMajoritaire(const char * seq);

#define MAXCAR 100
typedef char Tchaine[MAXCAR+1];

#endif

/*********************************B2*************************************/
/* AUTEUR : AMICHI Lounès                                               */
/* DATE : 18/12/2025                                                    */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Bibliothèque de traitements sur les chaines            */
/* NOM FICHIER : chaine5.h                                              */
/************************************************************************/

#ifndef CHAINE_5
#define CHAINE_5

//includes
#include <stdio.h>
#include <string.h>
#include "chaine4.h"

//macros
#define VIDE(ch) ch[0] == '\0'
#define EGAL(a,b) !strcmp(a,b)

//prototypes
char * dernier(char * mot, const char * ch);
char * miroir(char * mirch, const char * ch);
char * saufdernier(char * debch, const char * ch);
int member(const char * ssch, const char * ch);
char * effacer(char * ch, const char * mot);

#endif

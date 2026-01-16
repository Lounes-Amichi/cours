/*********************************B2*************************************/
/* AUTEUR : AMICHI Lounès                                               */
/* DATE : 18/12/2025                                                    */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Bibliothèque de traitements sur les chaines            */
/* NOM FICHIER : chaine5.c                                              */
/************************************************************************/

#include "chaine5.h"

char * dernier(char * mot, const char * ch) {
	Tchaine aux; // pour éviter d'écraser mot à l'appel de premier
	strcpy(mot, ch); 
	while(!EGAL(mot, premier(aux, mot))) {
		saufpremier(mot, mot);
	}
	return mot;
}

char * miroir(char * mirch, const char * ch) {
	Tchaine aux, aux2; // aux2 protection d'écrasement
	strcpy(mirch, "");
    	strcpy(aux, ch); 
	while (!VIDE(aux)){
		strcpy(mirch, phrase(premier(aux2, aux), mirch));
		saufpremier(aux, aux);
	}
	return mirch;
}

char * saufdernier(char * debch, const char * ch) {
	Tchaine aux;
	strcpy(debch, ch);
	miroir(aux, debch);
	saufpremier(aux, aux);
	miroir(debch, aux);
	return debch;
}

int member(const char * ssch, const char * ch) {
	int i, j;
	for (i=0; ch[i]!='\0'; i++){
		if (ssch[0] == ch[i]){
			for (j=0; (ch[j+i]!='\0') && (ch[j+i]==ssch[j]); j++){
				if (ssch[j+1] == '\0') return 1;
			}
		}
	}
	return 0;
}

char * effacer(char * ch, const char * mot) {
	Tchaine aux, aux2; // aux2 protection d'écrasement
	strcpy(aux, ch);
	strcpy(ch, ""); 
	while (!VIDE(aux)){
		if (!EGAL(premier(aux2, aux), mot))
			strcpy(ch,phrase(ch, premier(aux2, aux)));
		saufpremier(aux, aux);
	}
    return ch;
}

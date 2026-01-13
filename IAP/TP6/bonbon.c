/*********************************B2*************************************/
/* AUTEUR : AMICHI Lounès                                               */
/* DATE : 07/01/2026                                                    */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Module bonbon			                        */
/* NOM FICHIER : bonbon.c                                               */
/************************************************************************/

#include "bonbon.h"

char * copierChaine(char * dst, const char * str) {
	strcpy(dst, str);
	return dst;
}

int validerPreferences(const char * ch) {
	int i;
	for (i = 0; ch[i] != '\0'; i++)
		if (ch[i] < 'a' || ch[i] > 'z')
			return 0;
	return 1;
}

int rechercherSousChaine(const char * ch, const char * ssch) {
	int i = 0;
	while (ch[i] != '\0') {
		int j = 0;
		while (ssch[j] != '\0' && ch[i + j] == ssch[j]) {
			j++;
		}
		if (ssch[j] == '\0') return i;
		i++;
	}
	return -1;
}

int retirerSousChaine(char * ch, const char * ssch) {
	int i, lench, lenss;
	int pos=rechercherSousChaine(ch,ssch);
	if(pos!=-1){
		int lenss = strlen(ssch);
		int lench = strlen(ch);
		for(i = pos; i<= lench + 1 - pos - lenss; i++)
			ch[i]=ch[i+lenss];
		return 1;
	}
	return 0;
}

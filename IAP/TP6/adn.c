/*********************************B2*************************************/
/* AUTEUR : AMICHI Lounès                                               */
/* DATE : 07/01/2026                                                    */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Module adn			                        */
/* NOM FICHIER : adn.c	                                                */
/************************************************************************/

#include "adn.h"

int verifierComposition(const char * seq) {
	int i;
	int len = strlen(seq);
	for (i=0; seq[i] !='\0'; i++){
		if (seq[i] != 'A' && seq[i] != 'T' && seq[i] != 'C' && seq[i] != 'G')
			return 0;
	}
	return 1;
}

void compterNucleotides(const char * seq, int* countA, int* countT, int* countC, int* countG) {
    int i = 0;
    while (seq[i] != '\0') {
        switch (seq[i]) {
            case 'A': countA++; break;
            case 'C': countC++; break;
            case 'T': countT++; break;
            case 'G': countG++; break;
        }
        i++;
    }
}

char nucleotideMajoritaire(const char * seq) {
	int nA=0, nC=0, nT=0, nG=0;
	compterNucleotides(seq,&nA,&nT,&nC,&nG);
	int maxi = fmax(fmax(nA,nC),fmax(nT,nG)); //utilisation de la bibliothèque math.h
	
	if (nA==maxi) return 'A';
	else
		if (nC==maxi) return 'C';
		else
			if (nT==maxi) return 'T';
			else return 'G';
}

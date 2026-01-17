/*********************************B2*************************************/
/* AUTEUR : AMICHI Lounès                                               */
/* DATE : 07/01/2026                                                    */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Module adn			                        */
/* NOM FICHIER : adn.c	                                                */
/************************************************************************/

#include "adn.h"

int verifierComposition(const char * seq) {
	int i = 0;
	int len = strlen(seq);
	while (seq[i] !='\0'){
		if (seq[i] != 'A' && seq[i] != 'T' && seq[i] != 'C' && seq[i] != 'G')
			return 0;
		i++;
	}
	return 1;
}

void compterNucleotides(const char * seq, int * countA, int * countT, int * countC, int * countG) {
    int i = 0;
    while (seq[i] != '\0') {
        if (seq[i] == 'A') (*countA)++;
        else if (seq[i] == 'T') (*countT)++;
        else if (seq[i] == 'C') (*countC)++;
        else if (seq[i] == 'G') (*countG)++;
        i++;
    }
}

char nucleotideMajoritaire(const char * seq) {
	int nA=0, nC=0, nT=0, nG=0;
	compterNucleotides(seq,&nA,&nT,&nC,&nG);
	int maxi = fmax(fmax(nA,nC),fmax(nT,nG)); //utilisation de la bibliothèque math.h
	
	if (nA==maxi) return 'A';
	else if (nC==maxi) return 'C';
	else if (nT==maxi) return 'T';
	else return 'G';
}

int verifierEquilibre(const char * seq) {
	int nA=0, nC=0, nT=0, nG=0;
	compterNucleotides(seq,&nA,&nT,&nC,&nG);
	return (nA == nC && nC == nT && nT == nG);
}

void calculerComplement(char * comp, const char * seq){
	int i = 0;
	while(seq[i] != '\0'){
		if(seq[i] == 'A') comp[i] = 'T';
		else if(seq[i] == 'T') comp[i] = 'A';
		else if(seq[i] == 'C') comp[i] = 'G';
		else if(seq[i] == 'G') comp[i] = 'C';
		else comp[i] = seq[i];
		i++;
	}
	comp[i] = '\0';
}

int estPalindromeADN(const char * seq){
	Tchaine comp, inverse;
	calculerComplement(comp, seq);
	
	int len = strlen(comp);
	for(int i=0; i<len; i++){
		inverse[i] = comp[len-1-i];
	}
	inverse[len] = '\0';
	
	return (strcmp(seq, inverse) == 0);
}

int plusLongue(char * result, char n, const char * seq){
	int max = 0, count = 0, start = 0, i = 0;
	while (seq[i] != '\0') {
		if (seq[i] != n)
			count++;	
		else {
			if (count > max) {
				max = count;
				start = i - count;
			}
		}
		i++;
	}
	for (i = start; i <= max; i++)
		result[i - start] = seq[i];
	result[max - start + 1] = '\0';
	return start;
}

void rotationSequence(char * seq, int pos) {
	Tchaine aux;
	int len = strlen(seq);
	int i = pos;
	strcpy(aux, seq + pos);
	for (i = 0; i < pos; i++) 
		aux[i + len - pos] = seq[i];
	aux[len] = '\0';
	strcpy(seq, aux);
}

void fusionSuperposition(char * result, const char * seq1, const char * seq2){
	int len1 = strlen(seq1);
	int len2 = strlen(seq2);
	int maxsuperpos = 0;
	
	for(int i = 1; i <= len1 && i <= len2; i++){
		if(strncmp(seq1 + len1 - i, seq2, i) == 0){
			maxsuperpos = i;
		}
	}
	
	strcpy(result, seq1);
	strcat(result, seq2 + maxsuperpos);
}

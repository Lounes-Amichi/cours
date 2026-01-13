/*********************************B2*************************************/
/* AUTEUR : AMICHI Lounès                                               */
/* DATE : 07/01/2026                                                    */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Fichier de test du module adn	                        */
/* NOM FICHIER : partie2.c                                              */
/************************************************************************/

#include "adn.h"

int main() {
	Tchaine chaine;
	int reponse;
	int nA=0, nC=0, nT=0, nG=0;

	
	// test verifierComposition
	strcpy(chaine, "ATCGTTAGC"); 
	reponse = verifierComposition(chaine);
	printf("\nreponse >>%d<<", reponse);
	strcpy(chaine, "ATBXCG"); 
	reponse = verifierComposition(chaine);
	printf("\nreponse >>%d<<", reponse);
	
	// test compterNucleotides
	strcpy(chaine, "ATCGTTAGC");
	compterNucleotides(chaine, &nA, &nT, &nC, &nG);
	printf("\ncompte A:%d T:%d C:%d G:%d",nA,nT,nC,nG);
	
	// test nucleotideMajoritaire
}

/*********************************B2*************************************/
/* AUTEUR : AMICHI Lounès                                               */
/* DATE : 07/01/2026                                                    */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Fichier de test du module adn	                        */
/* NOM FICHIER : partie2.c                                              */
/************************************************************************/

#include "adn.h"

int main() {
	Tchaine chaine, aux;
	int reponse;
	int nA=0, nC=0, nT=0, nG=0;

	
	// test verifierComposition
	strcpy(chaine, "ATCGTTAGC"); 
	reponse = verifierComposition(chaine);
	printf("\n'ATCGTTAGC' reponse >>%d<<", reponse);
	strcpy(chaine, "ATBXCG"); 
	reponse = verifierComposition(chaine);
	printf("\n'ATBXCG' reponse >>%d<<", reponse);
	
	// test compterNucleotides
	strcpy(chaine, "ATGCTACG");
	compterNucleotides(chaine, &nA, &nT, &nC, &nG);
	printf("\n'ATGCTACG' compte A:%d T:%d C:%d G:%d",nA,nT,nC,nG);
	
	// test nucleotideMajoritaire
	strcpy(chaine, "ATCGTTAGC");
	reponse = nucleotideMajoritaire(chaine);
	printf("\n'ATCGTTAGC' reponse >>%c<<", reponse);
	
	// test verifierEquilibre
	strcpy(chaine, "ATGCTACG");
	reponse = verifierEquilibre(chaine);
	printf("\n'ATGCTACG' reponse >>%d<<", reponse);
	strcpy(chaine, "ATGATGA");
	reponse = verifierEquilibre(chaine);
	printf("\n'ATGATGA' reponse >>%d<<", reponse);
	
	// test calculerComplement
	strcpy(chaine, "ATGCTACG");
	calculerComplement(aux, chaine);
	printf("\n'ATGCTACG' reponse >>%s<<", aux);
	
	//test estPalindromeADN
	strcpy(chaine, "ATGCAT");
	reponse = estPalindromeADN(chaine);
	printf("\n'ATGCAT' reponse >>%d<<", reponse);
	strcpy(chaine, "ATGGTA");
	reponse = estPalindromeADN(chaine);
	printf("\n'ATGGTA' reponse >>%d<<", reponse);	
	
	//test plusLongue
	strcpy(chaine, "ATGCGCTTAGCGT");
	reponse = plusLongue(aux, 'A', chaine);
	printf("\n'ATGCGCTTAGCGT' reponse >>%d<<, resultat >>%s<<", reponse, aux);
	
	//test rotationSequence
	strcpy(chaine, "ATGCATGC");
	rotationSequence(chaine, 3);
	printf("\n'ATGCATGC' reponse >>%s<<", chaine);
	
	//test fusionSuperposition
	strcpy(chaine, "ATGCGCG");
	fusionSuperposition(aux, chaine, "GCGTA");
	printf("\n'ATGCGCG' reponse >>%s<<", aux);
	
	printf("\n");
	return 0;
}

/*********************************B2*************************************/
/* AUTEUR : AMICHI Lounès                                               */
/* DATE : 07/01/2026                                                    */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Fichier de test du module 	                        */
/* NOM FICHIER : partie1.c	                                        */
/************************************************************************/

#include "bonbon.h"

int main(){
	Tchaine ch1, ch2;
	int reponse, i;
	char * noms[] = {"Enfant 1", "Enfant 2", "Enfant 3"};
	char * prefs[] = {"ababf", "axoa", "xyz"};
	int montants[] = {3, 5, 2};
	int nbEnfants = 3;
	
	strcpy(ch1, "ababfzaxoaaababff"); //exemple du cours
	
	// test copierChaine
	copierChaine(ch2, ch1);
	printf("\n Chaine copiee: >>%s<<", ch2);
	
	// test validerPreferences
	reponse = validerPreferences("abcd");
	printf("\nvalide : >>%d<<", reponse);
	reponse = validerPreferences("abWcd");
	printf("\nvalide : >>%d<<", reponse);
	reponse = validerPreferences("abcd,2");
	printf("\nvalide : >>%d<<", reponse);
	
	// test rechercherSousChaine
	reponse = rechercherSousChaine(ch1, "zax");
	printf("\nrecherche : >>%d<<", reponse);
	reponse = rechercherSousChaine(ch1, "ababf");
	printf("\nrecherche : >>%d<<", reponse);
	reponse = rechercherSousChaine(ch1, "aaa");
	printf("\nrecherche : >>%d<<", reponse);
	
	// test retirerSousChaine
	copierChaine(ch1, ch2); //recopie la chaine originale
	reponse = retirerSousChaine(ch1, "zax");
	printf("\nétat : >>%d<<, nouvelle chaine : >>%s<<", reponse, ch1);
	copierChaine(ch1, ch2);
	reponse = retirerSousChaine(ch1, "ababf");
	printf("\nétat : >>%d<<, nouvelle chaine : >>%s<<", reponse, ch1);
	copierChaine(ch1, ch2);
	reponse = retirerSousChaine(ch1, "xyz");
	printf("\nétat : >>%d<<, nouvelle chaine : >>%s<<", reponse, ch1);
	
	// test afficherPortionsVendues
	copierChaine(ch1, ch2);
	printf("\nChaine initiale: %s", ch1);

	for(i=0; i< nbEnfants; i++) {
		if(!validerPreferences(prefs[i])) {
			printf("\nPreference invalide pour %s", noms[i]);
		}
	}

	afficherPortionsVendues(ch2, noms, prefs, montants, nbEnfants);
	
	printf("\n");
	return 0;
}

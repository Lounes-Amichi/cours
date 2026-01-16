/*********************************B2*************************************/
/* AUTEUR : AMICHI Lounès                                               */
/* DATE : 07/01/2026                                                    */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Fichier de test du module 	                        */
/* NOM FICHIER : main.c	                                                */
/************************************************************************/

#include "bonbon.h"

int main(){
	Tchaine ch1, ch2;
	int reponse;
	
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
	
	printf("\n");
	return 0;
}

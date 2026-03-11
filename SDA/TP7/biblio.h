#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H

#include "livre.h"

#define CAPACITE_BIBLIO 20 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque
    int maxCode; //dernier code utilise pour un livre

} T_Bibliotheque;

//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercherTitre(const T_Bibliotheque * ptrB, const char * titre);
int rechercherAuteur(const T_Bibliotheque * ptrB, const char * auteur);
int supprimerLivre(T_Bibliotheque  *ptrB, const char * code);
int emprunterLivre(T_Bibliotheque *ptrB, const char *code, const char *emp);
void retournerLivre(T_Bibliotheque *ptrB, const char *code);
void trierParTitre(T_Bibliotheque *ptrB);
void trierParAuteur(T_Bibliotheque *ptrB);
void trierParAnnee(T_Bibliotheque *ptrB);

void lectureFichierTXT();
void sauvegarde(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);

#endif
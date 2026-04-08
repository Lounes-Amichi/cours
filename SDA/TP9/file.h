#include "es.h" 	 

#define MAX 10 

typedef struct {
    T_Elt Elts[MAX];  // stockage d'éléments de la case 0 à la case MAX-1
    int Tete;
    int Queue; 
} T_File;


void initFile(T_File *ptrF); //mettre Tete et Queue à -1
int retirer(T_File *ptrF, T_Elt *ptrE); // si pas vide, en tete de file, renvoie 0 si file vide sinon 1
int ajouter(T_File *ptrF, T_Elt *ptrE); // si espace libre, ajout en queue, revoie 0 si file pleine sinon 1
int fileVide(const T_File *ptrF); // qd Tete == 0
int filePleine(const T_File *ptrF); // qd MAX elts dans la file
T_Elt premier(T_File *ptrF); // valeur en tete de file
void afficherFile(T_File *ptrF);
int tailleFile(const T_File *ptrF);
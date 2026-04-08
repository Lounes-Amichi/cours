#include "file.h" 


void initFile(T_File *ptrF) { //mettre Tete et Queue à -1
    ptrF->Tete = -1;
    ptrF->Queue = -1;
}

int retirer(T_File *ptrF, T_Elt *ptrE) { //si pas vide, en tete de file
    if (fileVide(ptrF))
        return 0;
    else {
        *ptrE = ptrF->Elts[ptrF->Tete];
        ptrF->Tete = (ptrF->Tete + 1) % MAX;
        return 1;
    }
}

int ajouter(T_File *ptrF, T_Elt *ptrE) { // si espace libre, ajout en queue
    if (filePleine(ptrF))
        return 0;
    else {
        if (ptrF->Tete == -1) ptrF->Tete++;
        ptrF->Queue = (ptrF->Queue + 1) % MAX;
        ptrF->Elts[ptrF->Queue] = *ptrE;
        return 1;
    }
}

int fileVide(const T_File *ptrF) { // qd Tete == 0
    if (tailleFile(ptrF) == 0) return 1;
    else return 0;
}

int filePleine(const T_File *ptrF) { // qd MAX elts dans la file
    if (tailleFile(ptrF) == MAX) return 1;
    else return 0;
}

T_Elt premier(T_File *ptrF) { //valeur en tete de file
    T_Elt premier = ptrF->Elts[ptrF->Tete];
    return premier;
}

void afficherFile(T_File *ptrF) {
    T_Elt E_temp;
    printf("\nFile:");
    for (int i = 0; i < tailleFile(ptrF); i++)
    {
        retirer(ptrF, &E_temp);
        afficherElt(&E_temp);
        ajouter(ptrF, &E_temp);
    }
    printf("\n");
}

int tailleFile(const T_File *ptrF) { // retourne le nombre d'elements de la file
    if (ptrF->Tete == -1) 
        return 0;
    else if (ptrF->Queue >= ptrF->Tete)
        return ptrF->Queue - ptrF->Tete + 1;
    else
        return MAX - (ptrF->Tete - ptrF->Queue - 1); 
}
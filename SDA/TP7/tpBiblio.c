// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"

int menu() {
	int choix;
    // au programme du TP7 :
    printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
    printf("\n 2 - afficher tous les livres de la bibliotheque "); 
    printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
    printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
    printf("\n 5 - supprimer un livre de la bibliotheque");
    // si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec cote,editeur et annee)


    // au programme du TP8 :
    // ajouter le champ emprunteur à votre structure T_Livre
    /*
    printf("\n 6 - emprunter un livre de la bibliotheque");
    printf("\n 7 - restituer/rendre un livre de la bibliotheque");
    printf("\n 8 - trier les livres (par titre)");
    printf("\n 9 - trier les livres (par auteur)");
    printf("\n 10 - trier les livres (par annee)");
    */
    // si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
    // vous pourrez alors faire les menus 11,12,etc...
    // printf("\n 11- lister les livres disponibles "); 
    // printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
    // printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ") -- Ajouter des recherches par code/editeur/annee

    printf("\n 0 - QUITTER");
    printf("\n Votre choix : ");
    scanf("%d[^\n]",&choix);getchar();
    return choix;
}

int main() {
    int reponse,chx;
    T_Bibliotheque B;
    char titre[K_MaxTit];
    char auteur[K_MaxAut];
    init(&B);
    do {
        chx = menu();
        switch(chx) {
            case 1: reponse = ajouterLivre(&B);
                if (reponse==1)
                    printf("ajout reussi !!");
                else
                    printf("impossible d ajouter (bibliotheque pleine)");
                break;
            case 2: reponse=afficherBibliotheque(&B);
                if (reponse==0)	
                    printf("La bibliotheque est vide");
                break;
            case 3:
                lireChaine("Titre a rechercher: ", titre, K_MaxTit);
                reponse = rechercherTitre(&B, titre);
                if (reponse == 0)
                    printf("Le livre n'est pas present dans la bibliotheque.");
                else
                    printf("Il y a %d livre(s) avec le meme titre dans la bibliotheque.", reponse);
                break;
            case 4:
                lireChaine("Auteur a rechercher: ", auteur, K_MaxAut);
                reponse = rechercherAuteur(&B, auteur);
                if (reponse == 0)
                    printf("L'auteur n'a pas de livres dans la bibliotheque.");
                else
                    printf("Il y a %d livres du meme auteur dans la bibliotheque.", reponse);
                break;
            case 5:
                lireChaine("Titre du livre: ", titre, K_MaxTit);
                lireChaine("Auteur du livre: ", auteur, K_MaxAut);
                reponse = supprimerLivre(&B, titre, auteur);
                if (reponse == 0)
                    printf("Le livre a bien ete supprime de la bibliotheque.");
                else
                    printf("La suppression a echoue.");
                break;
            }
    } while(chx!=0);
    return 0;
}

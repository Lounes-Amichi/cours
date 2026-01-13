/*********************************B2*************************************/
/* AUTEUR : AMICHI Lounès                                               */
/* DATE : 18/12/2025                                                    */
/* VERSION : 1.0                                                        */
/* DESCRIPTION : Interpreteur de commande                               */
/* NOM FICHIER : tp5.c	                                                */
/************************************************************************/


//Includes
#include "chaine4.h"
#include "chaine5.h"

#define MAX 5

void menu();


int main()
{
 char cde[MAX] ; // permet de saisir une commande
 Tchaine s1,s2; // Chaines de caracteres
                 /*0   4   8   12  16  20  24  28  32  36  */
char liste_cdes[]="pre-sfp-phr-der-sfd-mir-mmb-eff-hlp-fin"; //Definie la liste des commandes de l'interpreteur
int termine=FAUX ;
int pos ; // variable correspondant a la position de "cde" dans "liste_cdes"

menu() ; // Affiche la liste des commandes (sorti de la boucle car il y a la commande hlp) 

do
{

//saisir la commande et calculer sa position dans la liste des commandes

printf("Opérations sur chaines: ");
scanf("%s", cde);
getchar();
pos = strpos(cde, liste_cdes);

switch (pos)
{
case 0 : //Commande premier (pre)
  printf("Tapez une premiere chaine de caracteres (s1): ");
  fgets(s1,MAXCAR,stdin);format(s1);
  printf("premier mot: '%s'\n", premier(s2,s1));
  break ;
  
case 4 : //Commande saufpremier (sfp)
  printf("Tapez une premiere chaine de caracteres (s1): ");
  fgets(s1,MAXCAR,stdin);format(s1);
  printf("Chaine sans le premier mot: '%s'\n", saufpremier(s2,s1));
  break ;  

case 8 : //Commande phrase (phr)
  printf("Tapez une premiere chaine de caracteres (s1): ");
  fgets(s1,MAXCAR,stdin);format(s1);
  printf("Tapez une deuxieme chaine de caracteres (s2): ");
  fgets(s2,MAXCAR,stdin);format(s2);
  printf("Chaines concatenees: '%s'\n", phrase(s1,s2));
  break ;

case 12 : //Commande dernier (der)
  printf("Tapez une premiere chaine de caracteres (s1): ");
  fgets(s1,MAXCAR,stdin);format(s1);
  printf("dernier mot: '%s'\n", dernier(s2,s1));
  
  break ;
  
case 16 : //Commande saufdernier (sfd)
  printf("Tapez une premiere chaine de caracteres (s1): ");
  fgets(s1,MAXCAR,stdin);format(s1);
  printf("Chaine sans le dernier mot: '%s'\n", saufdernier(s2,s1));
  break ;  
  
case 20: //Commande miroir (mir)
  printf("Tapez une premiere chaine de caracteres (s1): ");
  fgets(s1, MAXCAR,stdin);format(s1);
  printf("Miroir: '%s'\n", miroir(s2,s1));
  break ;  

case 24 : //Commande member (mmb)
  printf("Tapez une premiere chaine de caracteres [chaine principale] (s1): ");
  fgets(s1,MAXCAR,stdin);format(s1);
  printf("Tapez une deuxième chaine de caracteres [sous-chaine] (s2): ");
  fgets(s2,MAXCAR,stdin);format(s2);
  if (member(s2,s1)) printf("La chaine '%s' est contenue dans la chaine '%s'.\n", s2, s1);
  else printf("La chaine '%s' n'est pas contenue dans la chaine '%s'.\n", s2, s1);
  break ;  
  
case 28 : //Commande effacer (eff)
  printf("Tapez une premiere chaine de caracteres (s1): ");
  fgets(s1,MAXCAR,stdin);format(s1);
  printf("Tapez un mot à supprimer de la chaine: ");
  fgets(s2,MAXCAR,stdin);format(s2);
  printf("Chaine effacée: '%s'\n", effacer(s1, s2));
  break;
  
case 32 : menu();
break ;
case 36 : termine=VRAI ;
break ;
default : printf("\007Commande inconnue. Recommencez...\n") ;
}
}
while (!termine) ;

}

void menu()
{
	printf("\n===== MENU =====\n");
	printf("'pre'-> premier\n");
	printf("'sfp'-> saufpremier\n");
	printf("'phr'-> phrase\n");
	printf("'der'-> dernier\n");
	printf("'sfd'-> saufdernier\n");
	printf("'mir'-> miroir\n");
	printf("'mmb'-> member\n");
	printf("'eff'-> effacer\n");
	printf("'hlp'-> help\n");
	printf("'fin'-> quitter\n\n");
}

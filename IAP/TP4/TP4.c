/**********************************B2************************************/
/* NOM : AMICHI		PRENOM : Lounès		Groupe TP : B2		*/
/* DATE : 03/12/25							*/
/* FICHIER : TP4.c							*/
/* DESCRIPTION : Traitements sur une chaine de caracteres		*/
/************************************************************************/
//bibliothèques
#include <stdio.h>

//constantes
#define MAXCAR 80

//types
typedef char Tchaine[MAXCAR + 1]; //80 + 1 pour la sentinelle
typedef int Tposition;

//prototypes
char * lire_chaine(char * ch, const int taillemax);
void ecrire_chaine(char * ch, int retour_ligne);
char * affectation_chaine(char * dest, const char * source, const int taillemax);
int compare_chaine(const char * ch1, const char * ch2);
int longueur_chaine(const char * ch);
char * concatene_chaine(char * dest, const char * source);
char * min_chaine(char * ch);
char * trouve_car_chaine(char * ch, char car);
int trouve_sschaine(char * ch, const char * ss_chaine);
char* formater_chaine(char ch[]); 


//main
int main() {
    Tchaine ch1 = "";
    Tchaine ch2 = "";
    Tchaine straux = "";
    int run = 1;
    int opt;
    int aux;
    char chaux;

    do {
        printf("\n---Traitements sur les chaines de caractères---\n");
        printf("-1-Création d'une chaine---\n");
        printf("-2-Affichage d'une chaine---\n");
        printf("-3-Affectation de chaine---\n");
        printf("-4-Comparaison de chaine---\n");
        printf("-5-Longueur de chaine---\n");
        printf("-6-Concaténation de chaine---\n");
        printf("-7-Minusculer une chaine---\n");
        printf("-8-Rechercher une sous-chaine par caractère---\n");
        printf("-9-Rechercher une sous-chaine---\n");
        printf("-10-Formater une chaine---\n");
        printf("-0-Quitter---\n");
        printf("---Choisissez une option (0-10)---\n-->");
        
        scanf("%d", &opt);
        getchar(); // supression du RC

        switch (opt) {
            case 1:
                printf("\n\n---Création de chaine---\n");
                printf("Choisissez la chaine (1 ou 2)\n");
                scanf("%d", &aux);
                getchar(); // supression du RC
                printf("Saisir la chaine:\n-->");
                if (aux == 1) lire_chaine(ch1, MAXCAR);
                else lire_chaine(ch2, MAXCAR);
                break;

            case 2:
                printf("\n\n---Affichage d'une chaine---\n");
                printf("Choisissez la chaine (1 ou 2)\n");
                scanf("%d", &aux);
                getchar(); // supression du RC
                printf("-->");
                if (aux == 1) ecrire_chaine(ch1, 1);
                else ecrire_chaine(ch2, 1);
                break;

            case 3:
                printf("\n\n---Affectation de chaine---\n");
                printf("1: Ch1 <- Ch2\n");
                printf("2: Ch2 <- Ch1\n");
                scanf("%d", &aux);
                getchar(); // supression du RC

                if (aux == 1) affectation_chaine(ch1, ch2, MAXCAR);
                else affectation_chaine(ch2, ch1, MAXCAR);
                break;

            case 4:
                printf("\n\n---Comparaison de chaine---\n");
                aux = compare_chaine(ch1, ch2);
                printf("Résultat de la comparaison des deux chaines (ch1 <-> ch2) : %d\n", aux);
                break;

            case 5:
                printf("\n\n---Longueur de chaine---\n");
                printf("Choisir la chaine (1 ou 2)\n");
                scanf("%d", &aux);
                getchar(); // supression du RC
                if (aux == 1) printf("Longueur Ch1 : %d\n", longueur_chaine(ch1));
                else printf("Longueur Ch2 : %d\n", longueur_chaine(ch2));
                break;

            case 6:
                printf("\n\n---Concaténation de chaine---\n");
                printf("1: Ch1 = Ch1 + Ch2\n");
                printf("2: Ch2 = Ch2 + Ch1\n");
                scanf("%d", &aux);
                getchar(); // supression du RC

                if (aux == 1) concatene_chaine(ch1, ch2);
                else concatene_chaine(ch2, ch1);
                break;
            
            case 7:
            	printf("\n\n---Minusculer une chaine---\n");
                printf("Choisir la chaine (1 ou 2)\n");
                scanf("%d", &aux);
                getchar(); // supression du RC
            	if (aux == 1) {
            		min_chaine(ch1);
            		ecrire_chaine(ch1, 1);
            	}
                else {
                	min_chaine(ch2);
                	ecrire_chaine(ch2, 1);
                }
                break;
                
            case 8:
            	printf("\n\n---Rechercher une sous-chaine par caractère---\n");
                printf("Choisir la chaine (1 ou 2)\n");
                scanf("%d", &aux);
                getchar(); // supression du RC
                printf("Saisir le caractère à rechercher:\n");
                scanf("%c", &chaux);
                getchar(); // supression du RC
            	if (aux == 1) {
            		ecrire_chaine(trouve_car_chaine(ch1, chaux), 1);
            	}
                else {
                	ecrire_chaine(trouve_car_chaine(ch2, chaux), 1);
                }
            	break;
            
            case 9:
            	printf("\n\n---Rechercher une sous-chaine---\n");
                printf("Choisir la chaine (1 ou 2)\n");
                scanf("%d", &aux);
                getchar(); // supression du RC
                printf("Saisir la sous-chaine à rechercher:\n");
                lire_chaine(straux, MAXCAR);
            	if (aux == 1) {
            		printf("La position de la sous-chaine dans la chaine 1 est %d.\n", trouve_sschaine(ch1, straux));
            	}
                else {
                	printf("La position de la sous-chaine dans la chaine 2 est %d.\n", trouve_sschaine(ch2, straux));
                }
            	break;
            
            case 10:
				char rep;

				do {
					printf("Saisir une chaine mal formatee pouvant avoir plusieurs espaces et tabulations \n");
					printf(" en début, en fin et entres les mots : ");
					   	
					lire_chaine(straux,MAXCAR+1);
					if(longueur_chaine(straux) > 0)
						straux[longueur_chaine(straux)-1]='$';     
					
					printf("Chaine saisie :");
					ecrire_chaine(straux, 1);
					
					formater_chaine(straux);
					
					printf("Chaine formatee :");
					ecrire_chaine(straux, 1);
					
					printf("Voulez vous recommencer (o/n):");
					scanf("%c", &rep); 
					getchar(); 
					} while (rep == 'o' || rep == 'O');  
				
				printf("FIN PROGRAMME FORMATER CHAINE !!! \n");
				
            	break;
            
            case 0:
                run = 0;
                printf("Au revoir !\n");
                break;

            default:
                printf("Option invalide.\n");
        }
    } while (run);

    return 0;
}


/******************************************************************************************************/
/*Fonction : lire_chaine                                                                              */
/*Description : Lit une chaîne depuis l'entrée standard jusqu'à saut de ligne ou taille max           */
/*Entrées : ch (buffer de destination), taillemax (taille maximale du buffer)                         */
/*Sorties : ch (le buffer rempli avec la chaîne saisie terminée par '$')                              */
/*Retourne : Un pointeur sur le début de la chaîne (ch)                                               */
/******************************************************************************************************/
char * lire_chaine(char * ch, const int taillemax) {
    char c;
    int ccount = 0;
    while (ccount < taillemax) {
        c = getchar();
        if (c == '\n' || c == EOF) break;
        else {
            ch[ccount] = c;
            ccount ++;
        }
    }
    ch[ccount] = '$';
}

/******************************************************************************************************/
/*Fonction : ecrire_chaine                                                                            */
/*Description : Affiche une chaîne de caractères terminée par '$' sur la sortie standard              */
/*Entrées : ch (la chaîne à afficher), retour_ligne (booléen : 1 pour aller à la ligne, 0 sinon)      */
/*Sorties : Aucune (affichage écran uniquement)                                                       */
/*Retourne : Rien (void)                                                                              */
/******************************************************************************************************/
void ecrire_chaine(char * ch, int retour_ligne) {
    int i = 0;
    while (ch[i] != '$') {
        putchar(ch[i]);
        i++;
    }
    if (retour_ligne) printf("\n");
}

/******************************************************************************************************/
/*Fonction : affectation_chaine                                                                       */
/*Description : Copie le contenu de la chaîne source vers la chaîne destination                       */
/*Entrées : dest (chaîne de destination), source (chaîne à copier), taillemax (taille limite)         */
/*Sorties : dest (contient la copie de source)                                                        */
/*Retourne : Un pointeur sur la chaîne de destination                                                 */
/******************************************************************************************************/
char * affectation_chaine(char * dest, const char * source, const int taillemax) {
    int i = 0;
    for (i; source[i] != '$'; i++) dest[i] = source[i];
    dest[i] = '$';
}

/******************************************************************************************************/
/*Fonction : compare_chaine                                                                           */
/*Description : Compare deux chaînes de caractères lexicographiquement                                */
/*Entrées : ch1 (première chaîne), ch2 (deuxième chaîne)                                              */
/*Sorties : Aucune                                                                                    */
/*Retourne : 0 si égales, une valeur négative si ch1 < ch2, positive si ch1 > ch2                     */
/******************************************************************************************************/
int compare_chaine(const char * ch1, const char * ch2) {
    int i = 0;
    while (ch1[i] == ch2[i]) {
        if (ch1[i] == '$') return 0;
        i++;
    }
    return ch1[i] - ch2[i];    
}

/******************************************************************************************************/
/*Fonction : longueur_chaine                                                                          */
/*Description : Calcule le nombre de caractères dans la chaîne avant le délimiteur '$'                */
/*Entrées : ch (la chaîne dont on veut la longueur)                                                   */
/*Sorties : Aucune                                                                                    */
/*Retourne : La longueur de la chaîne (entier)                                                        */
/******************************************************************************************************/
int longueur_chaine(const char * ch) {
    int i = 0;
    while (ch[i] != '$') i++;
    return i;
}

/******************************************************************************************************/
/*Fonction : concatene_chaine                                                                         */
/*Description : Ajoute le contenu de la chaîne source à la fin de la chaîne destination               */
/*Entrées : dest (chaîne de destination et d'accueil), source (chaîne à ajouter)                      */
/*Sorties : dest (contient la concaténation des deux chaînes)                                         */
/*Retourne : Un pointeur sur la chaîne de destination                                                 */
/******************************************************************************************************/
char * concatene_chaine(char * dest, const char * source) {
    int i = 0, j = 0;
    while (dest[i] != '$') i++; // trouve la position de départ
    while (source[j] != '$') {
        dest[i] = source[j];
        i++;
        j++;
    }
    dest[i] = '$';
}

/******************************************************************************************************/
/*Fonction : min_chaine                                                                               */
/*Description : Convertit les lettres majuscules d'une chaîne en minuscules                           */
/*Entrées : ch (la chaîne à convertir)                                                                */
/*Sorties : ch (la chaîne modifiée avec les caractères en minuscules)                                 */
/*Retourne : Un pointeur sur la chaîne modifiée                                                       */
/******************************************************************************************************/
char * min_chaine(char * ch) {
    char diff = 'a' - 'A';
    int i = 0;
    while (ch[i] != '$') {
        if (65 <= ch[i] && ch[i] <= 90) ch[i] = ch[i] + diff;
        i++;
    }
}

/******************************************************************************************************/
/*Fonction : trouve_car_chaine                                                                        */
/*Description : Recherche la première occurrence d'un caractère dans la chaîne                          */
/*Entrées : ch (la chaîne où chercher), car (le caractère à trouver)                                  */
/*Sorties : Aucune                                                                                    */
/*Retourne : L'adresse du caractère trouvé, ou NULL si absent                                         */
/******************************************************************************************************/
char * trouve_car_chaine(char * ch, char car) {
    int i = 0;
    while (ch[i] != '$') {
        if (ch[i] == car) return &ch[i];
        i++;
    }
    return NULL;
}

/******************************************************************************************************/
/*Fonction : trouve_sschaine                                                                          */
/*Description : Recherche la position de départ d'une sous-chaîne dans la chaîne principale           */
/*Entrées : ch (chaîne principale), ss_chaine (motif à rechercher)                                    */
/*Sorties : Aucune                                                                                    */
/*Retourne : L'indice de la première occurrence (entier), ou -1 si non trouvée                        */
/******************************************************************************************************/
int trouve_sschaine(char * ch, const char * ss_chaine) {
    int i = 0;
    while (ch[i] != '$') {
        int j = 0;
        while (ss_chaine[j] != '$' && ch[i + j] == ss_chaine[j]) {
            j++;
        }
        if (ss_chaine[j] == '$') return i;
        i++;
    }
    return -1;
}

/***************************************************************************/
/* NOM FONCTION : formater_chaine                                         */
/* DESCRIPTION :  Realise le formatage d'une chaine en supprimant         */
/* les extra caracteres qu'elles contient aux extremites ou entre les mots */
/* Retourne :un pointeur sur la chaine formater                           */
/* Effets de bords : Saisie de la chaine a formatee au clavier            */
/* Paramètres en entree :  ch (la chaine a formater)                      */
/* Paramètres en sortie :  ch (la chaine formatee)                        */
/***************************************************************************/

char* formater_chaine(char ch[]) 
{
    char * ch2;  // Sert a parcourir la chaine a formater      
    int i=0;    // Compteur pour parcourir ch le tabeau ou l'on sauvegarde la chaine formatee
    int j=0;    // Compteur utiliser pour parcourir ch2 le tableau correspondant a la chaine a formater
    int state=0; // Defini l'état courant de l'automate a etats finis 
    
    ch2=ch; 
    
    while(ch2[j]) 
    {
        switch (state) 
        {
            case 0 :  // Hors mot
                if ((ch2[j]!=' ') && (ch2[j]!='\t') && (ch2[j]!=13) && (ch2[j]!=10)) 
                {
                    state=1;
                    ch[i]=ch2[j];
                    i++; 
                }    
                break;
                
            case 1 :    // Dans mot
                if ((ch2[j]!=' ') && (ch2[j]!='\t') && (ch2[j]!=13) && (ch2[j]!=10)) 
                {
                    ch[i]=ch2[j]; 
                    i++;
                } else {
                    ch[i]=' ';
                    i++;
                    state=0;
                }
                break; 
            default : printf("Cas impossible !!!\n\n");
        }
        
        /* Correction 11: Incrémentation de j pour avancer dans la boucle */
        j++; 
    }
    
    //Traitement de fin !!!
    if ((state==0) && (i>0) && (ch[i-1]==' ')) 
        ch[i-1]='\0'; 
    else ch[i]='\0';
    
    return ch;
}

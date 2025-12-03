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


//main
int main() {
    Tchaine ch1;
    Tchaine ch2;
    int run = 1;
    int opt;
    int aux;

    do {
        printf("\n---Traitements sur les chaines de caractères---\n");
        printf("-1-Création d'une chaine---\n");
        printf("-2-Affichage d'une chaine---\n");
        printf("-3-Affectation de chaine---\n");
        printf("-4-Comparaison de chaine---\n");
        printf("-5-Longueur de chaine---\n");
        printf("-6-Concaténation de chaine---\n");
        printf("-0-Quitter---\n");
        printf("---Choisissez une option (0-6)---\n-->");
        
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

//lire_chaine | remplace gets()
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

//ecrire_chaine | remplace puts()
void ecrire_chaine(char * ch, int retour_ligne) {
    int i = 0;
    while (ch[i] != '$') {
        putchar(ch[i]);
        i++;
    }
    if (retour_ligne) printf("\n");
}

//affectation_chaine | remplace strcpy()
char * affectation_chaine(char * dest, const char * source, const int taillemax) {
    int i = 0;
    for (i; source[i] != '$'; i++) dest[i] = source[i];
    dest[i] = '$';
}

//compare_chaine | remplace strcmp()
int compare_chaine(const char * ch1, const char * ch2) {
    int i =0, j = 0;
    while (ch1[i] != '$') i++;
    while (ch2[j] != '$') j++;
    return i - j;
}

//longueur_chaine | remplace strlen()
int longueur_chaine(const char * ch) {
    int i = 0;
    while (ch[i] != '$') i++;
    return i;
}

//concatene_chaine | remplace strcat()
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

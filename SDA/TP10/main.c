////////////////////////// TP10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prod.h"

int lireProchaineCommande() //pour lire l'int contenu dans nextFact
{
FILE *f;
int N;
f=fopen("nextFact","r");
fread(&N,sizeof(int),1,f);
fclose(f);
//printf("\n--->lu N=%d",N);
return N;
}

void convertirNenChaine4(int N,char *N4) //convertit l'int N en une chaine de 4 caracteres
{ // si N=1234 alors N4 sera égal à "1234"
int m,c,d,u;
char cm,cc,cd,cu;
m=N/1000;cm=48+m;
N%=1000;
c=N/100;cc=48+c;
N%=100;
d=N/10;cd=48+d;
u=N%10;
cu=48+u;
N4[0]=cm;N4[1]=cc;N4[2]=cd;N4[3]=cu;N4[4]='\0';
}

void rechercherProduit(char * ref, char * libelle, float * PU) {
    FILE * produits = NULL;
    produits = fopen("produits.txt", "rt");
    char prodRef[10];
    do {
        fscanf(produits, "%s %s %f", prodRef, libelle, PU);
        if (strcmp(prodRef, ref) == 0) {
            break;
        }
    } while (!feof(produits));
    fclose(produits);
}

void lireCommande(FILE * fic, char * ch4) {
    char nom[50];
    char ref[10];
    int qtt;
    fscanf(fic, "%s", nom);
    FILE * fact = NULL;
    char chemin[50];
    strcpy(chemin, "./factures/facture");
    strcat(chemin,ch4);
    strcat(chemin, ".txt");
    fact = fopen(chemin, "w");
    float PrixUnitaire;
    char libelle[50];

    do {
        fscanf(fic, "%s %d", ref, &qtt);
        // printf("\n%s %d", ref, qtt);
        rechercherProduit(ref, libelle, &PrixUnitaire);
        fprintf(fact, "\n->%d * %s (PU=%.2f€) = %.2f€", qtt, libelle, PrixUnitaire, qtt*PrixUnitaire);

    } while (!feof(fic));
    fclose(fact);
}

void lireLesCommandes() //cette fonction ouvre tous les fichiers commandeXXX.txt avec XXXX démarrant à N
{
FILE *ficCommande=NULL;
int FINI=0;
int N = lireProchaineCommande(); //numero de la premiere commande qui sera lue et traitee
char NNNN[5];
char nomCommande[29];

do //ce do while prend fin dès que fichier commandeXXXX.txt est absent 
	{
	strcpy(nomCommande,"./commandes/commande");
	convertirNenChaine4(N,NNNN); 
	//printf("\n==>%s<==",NNNN);
	ficCommande=NULL;
	strcat(nomCommande,NNNN);
	strcat(nomCommande,".txt");
	
	//printf("\n traitement de  %s",nomCommande);
	
	ficCommande=fopen(nomCommande,"rt");
	if (ficCommande!=NULL)
		{ // le fichier commandeNNNN.txt existe
			printf("\n fichier %s present",nomCommande);
			lireCommande(ficCommande, NNNN); // à vous de coder cette fonction lors de ce TP9
			fclose(ficCommande);
		}
	else
		{
			printf("\n toutes les commandes presentes ont ete traitees.\n");
			FILE *f=fopen("nextFact","w"); // on va ecrire la valeur de N dans enxtFact 
			// pour 
			fwrite(&N,1,sizeof(int),f);
			fclose(f);
			FINI=1;			
		}

	N++;
	}while(FINI==0);		

}

void rechercherStock(char * ref, int qtt, int * valide) {
    FILE * stock = NULL;
    FILE * stockb = NULL;
    stock = fopen("stock.txt", "rt");
    stockb = fopen("stockbis.txt", "w");
    int reste;
    char prodRef[10];
    while (!feof(stock)) {
        fscanf(stock, "%s %d", prodRef, &reste);
            if (strcmp(prodRef, ref) == 0) {
                reste = reste - qtt;
                if (reste < 0) {
                    reste = reste + qtt;
                    printf("Commande non satisfaite: stock insuffisant sur l'item ref:%s", ref);
                    *valide = 0;
                }
                else {
                    *valide = 1;
                }
            }
            fprintf(stockb, "%s %d\n", prodRef, reste);
    }
    fclose(stock);
    fclose(stockb);
    // system("mv stockbis.txt stock.txt");
}

void lireCommande2(FILE * fic, char * ch4) {
    char nom[50];
    char ref[10];
    int qtt;
    fscanf(fic, "%s", nom);
    FILE * fact = NULL;
    char chemin[50];
    strcpy(chemin, "./factures/facture");
    strcat(chemin,ch4);
    strcat(chemin, ".txt");
    fact = fopen(chemin, "w");
    float PrixUnitaire;
    char libelle[50];
    int valide;

    do {
        fscanf(fic, "%s %d", ref, &qtt);
        // printf("\n%s %d", ref, qtt);
        rechercherProduit(ref, libelle, &PrixUnitaire);
        rechercherStock(ref, qtt, &valide);
        if (!valide) qtt = 0;
        fprintf(fact, "\n->%d * %s (PU=%.2f€) = %.2f€", qtt, libelle, PrixUnitaire, qtt*PrixUnitaire);

    } while (!feof(fic));
    fclose(fact);
}

void lireLesCommandes2() //cette fonction ouvre tous les fichiers commandeXXX.txt avec XXXX démarrant à N
{
FILE *ficCommande=NULL;
int FINI=0;
int N = lireProchaineCommande(); //numero de la premiere commande qui sera lue et traitee
char NNNN[5];
char nomCommande[29];

do //ce do while prend fin dès que fichier commandeXXXX.txt est absent 
	{
	strcpy(nomCommande,"./commandes/commande");
	convertirNenChaine4(N,NNNN); 
	//printf("\n==>%s<==",NNNN);
	ficCommande=NULL;
	strcat(nomCommande,NNNN);
	strcat(nomCommande,".txt");
	
	//printf("\n traitement de  %s",nomCommande);
	
	ficCommande=fopen(nomCommande,"rt");
	if (ficCommande!=NULL)
		{ // le fichier commandeNNNN.txt existe
			printf("\n fichier %s present",nomCommande);
			lireCommande2(ficCommande, NNNN); // à vous de coder cette fonction lors de ce TP9
			fclose(ficCommande);
		}
	else
		{
			printf("\n toutes les commandes presentes ont ete traitees.\n");
			FILE *f=fopen("nextFact","w"); // on va ecrire la valeur de N dans enxtFact 
			// pour 
			fwrite(&N,1,sizeof(int),f);
			fclose(f);
			FINI=1;			
		}

	N++;
	}while(FINI==0);		

}

int main()
{
	//creation d un fichier d'un seul int nommé nextFact et contenant l'int 1
	// code à utiliser pour réinitialiser nextFact à 1 si besoin au cours du TP 
	
	FILE *f;int N=1;
	f=fopen("nextFact","w");
	fwrite(&N,1,sizeof(int),f);
	fclose(f);

	//PARTIE 1 du TP : sans Gestion de stock
	// lireLesCommandes(); //lecture de tous les fichiers commandeXXX.txt (fichiers non traités jusqu'ici)	
	

	//PARTIE 2 du TP : avec Gestion de stock
	//copiez coller votre travail précédent puis modifiez le  
	lireLesCommandes2(); 	

	return 0;
}

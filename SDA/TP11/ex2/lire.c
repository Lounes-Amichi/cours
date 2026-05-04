#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

typedef struct {
    char nom[100];
    int total_voix;
} T_Candidat;

T_Candidat liste_candidats[12];

int main(int argc , char *argv[])
{
    FILE *fic = NULL;
    FILE *fd=NULL; 
    int NC1=0,NC2=0;
    int som1=0,som2=0;
    char ch[100];
    char buffer[100];
    
    for (int i = 0; i < 12; i++)
    {
        strcpy(liste_candidats[i].nom, "");
        liste_candidats[i].total_voix = 0;
    }

    if (argc < 1) {
        printf("Erreur: Pas assez d'arguments\n");
        return 1;
    }
    if (argc > 2) {
        printf("Erreur: Trop d'arguments\n");
        return 1;
    }

    fic=fopen("resultatsTOUR1.txt","rt");    
    if (fic!=NULL)
    {
        
        do {   fscanf(fic,"%s ", ch); // printf("\n\n===>%s ",ch); 
            if (argc == 3) {
                if (strcmp(ch, argv[1]) == 0) { // Candidat 1 repéré
                    fscanf(fic, "%s ", buffer); // skip du prénom
                    fscanf(fic, "%d ", &NC1); // nb de voix
                    som1 += NC1;
                } else if (strcmp(ch, argv[2]) == 0) {
                    fscanf(fic, "%s ", buffer); // skip du prénom
                    fscanf(fic, "%d ", &NC2);   // nb de voix
                    som2 += NC2;
                }
            }
            if (argc == 2) {

                if (strcmp(ch, argv[1]) == 0) { // ville repérée
                    //skip des infos avant les candidats
                    for (int i = 0; i < 15; i++)
                        fscanf(fic, "%s", buffer);
                    
                    for (int i = 0; i < 12; i++)
                    {
                        fscanf(fic, "%s", buffer); // 1. skip N° Panneau
                        fscanf(fic, "%s", buffer); // 2. skip Sexe
                        fscanf(fic, "%s", ch);     // 3. Nom du candidat
                        fscanf(fic, "%s", buffer); // 4. skip Prénom
                        fscanf(fic, "%d", &NC1);   // 5. nb de voix
                        fscanf(fic, "%s", buffer); // 6. skip % Voix/Ins
                        fscanf(fic, "%s", buffer); // 7. skip % Voix/Exp

                        strcpy(liste_candidats[i].nom, ch);
                        liste_candidats[i].total_voix += NC1;
                    }
                }
            }
        }
        while(!feof(fic));
        
        
    system("date > ladate");
    fd=fopen("ladate","r");
    fgets(ch,99,fd);
    fclose(fd);
    printf("\n\n\n>>AMICHI, %s ",ch);         //remplacez par votre NOM
    fclose(fic);//fclose(ficint2);
    if (argc == 3)
        printf("----->%s = %d <->%s = %d\n", argv[1], som1, argv[2], som2);
    }
    if (argc == 2) {
        for (int i = 0; i< 12; i++)
            printf("------->%s = %d\n", liste_candidats[i].nom, liste_candidats[i].total_voix);
    }
    else printf("\n souci ! le fichier resultatsTOUR1.txt est introuvable.");
    
         
         
         
    return 0;
}
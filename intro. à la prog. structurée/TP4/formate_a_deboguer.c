/**********************************B2************************************/
/* NOM : AMICHI         PRENOM : Lounès         Groupe TP : B2        */
/* DATE : 03/12/25                                                    */
/* FICHIER : formate_a_deboguer.c                                     */
/* DESCRIPTION : Traitement de formatage d'une chaine de caracteres   */
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MAXCARS     50  /* Augmenté un peu car 8 est très court pour tester */

/* Correction 1: Suppression du point-virgule en trop à la fin du prototype */
char* formater_chaine(char ch[]); 

int main()
{
    char chaine_a_formater[MAXCARS+1]; 
    char rep;
    
    do
    {
        printf("Saisir une chaine mal formatee pouvant avoir plusieurs espaces et tabulations \n");
        printf(" en début, en fin et entres les mots : ");
        
        /* fgets lit l'entrée */
        fgets(chaine_a_formater,MAXCARS+1,stdin);
        
        /* Correction 2: Suppression du crochet ']' en trop */
        /* Note : vérification basique pour enlever le \n final de fgets */
        if(strlen(chaine_a_formater) > 0)
            chaine_a_formater[strlen(chaine_a_formater)-1]='\0';     
        
        printf("Chaine saisie : '%s' \n",chaine_a_formater);
        
        formater_chaine(chaine_a_formater);
        
        printf("Chaine formatee : '%s' \n",chaine_a_formater);
        
        printf("Voulez vous recommencer (o/n):");
        
        /* Correction 3: Ajout du '&' pour rep et d'un espace avant %c pour ignorer les blancs/buffer */
        scanf(" %c", &rep); 
        
        /* Correction 4: Nettoyage du buffer (le \n reste sinon et bloque le prochain fgets) */
        getchar(); 
    }
    /* Correction 5: Logique de la boucle (TANT QUE 'o' ou 'O') et syntaxe de comparaison (==) */
    while (rep == 'o' || rep == 'O');  
    
    printf("FIN PROGRAMME FORMATER CHAINE !!! \n");
    
    return EXIT_SUCCESS; 
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
/* Correction 6: Suppression du point-virgule qui empêchait la définition de la fonction */
char* formater_chaine(char ch[]) 
{
    /* Correction 7: ch2 doit être un pointeur pour faire ch2=ch. Un tableau [] vide est interdit */
    char *ch2;  // Sert a parcourir la chaine a formater      
    int i=0;    // Compteur pour parcourir ch le tabeau ou l'on sauvegarde la chaine formatee
    int j=0;    // Compteur utiliser pour parcourir ch2 le tableau correspondant a la chaine a formater
    /* Correction 8: Initialisation de state (sinon valeur aléatoire) */
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
                    /* Correction 9: Remplacement de == (comparaison) par = (affectation) */
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
        
        /* Correction 10: Incrémentation de j indispensable pour avancer dans la boucle */
        j++; 
    }
    
    //Traitement de fin !!!
    if ((state==0) && (i>0) && (ch[i-1]==' ')) 
        ch[i-1]='\0'; 
    else ch[i]='\0';
    
    return ch;
}

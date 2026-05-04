#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLEMAX_LIGNE 200
typedef char T_chaine[TAILLEMAX_LIGNE];

int main() 
{
    int intarray[700];
    char ASCIIarray[6];
    int numASCII = 0;
    int numLigne = 0;
    int sommeImpaire = 0;
    FILE *fic = NULL;
	fic=fopen("enigmaAMICHI","rb");
	if (fic!=NULL)
		{
		do
		{
            fread(&intarray[numLigne], sizeof(numLigne), 1, fic);
            printf("int:%d\t", intarray[numLigne]);
            if (numLigne % 2 == 1) {
                sommeImpaire += intarray[numLigne];
            } else if (numLigne >= 2 && numLigne <= 10) {
                ASCIIarray[numASCII] = intarray[numLigne];
                numASCII++; 
            }
            numLigne++;
        } while(!(feof(fic)));
		fclose(fic);
		printf("\nsomme Impaire:%d", sommeImpaire);
        ASCIIarray[numASCII] = '\0';
        printf("\nASCII: %s\n", ASCIIarray);

		}
}
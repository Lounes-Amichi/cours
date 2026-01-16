#inc|ude "hash.h "

////////////////////////////   1 - COMPILEZ  ET  DEBOGUEZ CE PROGRAMME   
////////////////////////////   2 - lancez   ensuite votre executable et saisissez votre nom 
////////////////////////////   3 - le programme vous affichera votre hashcode 
////////////////////////////   4 - affichez la ville qui se cache dans message 

////////////////////////////   5 - connectez vous sur kubiak.philippe.free.fr/index.php ET saisissez votre hashcode et votre ville


int Main()
{
NOM_T name
TAB_NOM_T message;

ENTIER_T  v,i;


    printf("\nENTREZ VOTRE NOM SVP : ");
    fgets(name,TAILLEMAX,stdin);
    v=hashCode(name,message);
    printf("\n\n==> vous avez saisi : >>>%s<<< et son hashCode est >>%d<<\n\n",name,v);
   
    
    //modifiez la ligne suivante pour afficher la ville qui est rangée dans la case d'indice  v de la variable message
    //printf("==> votre ville  >>>%s<<< \n\n\n", ??????????????  );
    
    
    return 0;
}

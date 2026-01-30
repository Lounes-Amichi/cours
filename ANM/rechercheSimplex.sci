function ListeDesSolutions=rechercheSimplex(m)

  taille= size(m);
  NL=taille(1,1); //nb de lignes de m : on a donc m-1 contraintes
  NC=taille(1,2); //nb de colonnes de m
  Ncont=NL-1 //nb de contraintes
  NVAR=NC-Ncont-1 //nb de variables (c est aussi le nb de grandeurs
//  considérées par le probleme posé)

  T=ones(1,NVAR)
  for i=2:NVAR
      T(1,i)=i;
  end
 
  P=perms(T);
  S=size(P)
  ListeDesSolutions=list()
  nbsol=0
  for k=1 : S(1,1) do
    printf("\nSIMULATION %d---------------",k);
    printf("\nappel de simplex avec :")
    disp(P(k,:))
    //TOUTES_LES_SOLUTIONS(k)=
    SS=simplex2(m,P(k,:))
    ListeDesSolutions($+1)=SS
    nbsol=nbsol+1
    disp(SS)
    printf("\n---------------------------------------------");
  end

    printf("\nBILAN : -------------------------------");
    M=list()
    
    numsol=1
    TROUVE=0
    while TROUVE==0 && numsol<S(1,1) do
    
    somme=0
    for i=2 : NVAR+1 
        somme=somme+ ListeDesSolutions(numsol)(1,i)*m(NL,i-1)
    end
      printf("\n--------------->>>>%d : %f et %f ",numsol,somme,ListeDesSolutions(numsol)(1,1))
                  
    if somme==ListeDesSolutions(numsol)(1,1) then //si c 'est une "BONNE" solution
    TROUVE=1
    //printf("\n <<%d>> ",numsol)
    M($+1)=numsol
    Maximum=ListeDesSolutions(numsol)(1,1)
    end    
    numsol=numsol+1
    end//while
    

    for k=numsol: S(1,1) do 
        if ListeDesSolutions(k)(1,1)>Maximum then
            
             somme=0
                    for i=2 : NVAR+1 
                        somme=somme+ ListeDesSolutions(k)(1,i)*m(NL,i-1)
                    end
                    if somme==ListeDesSolutions(k)(1,1) then //si c 'est une "BONNE" solution
                    M=list()
                        //printf("\n <<%d>> ",k   )
                    printf("\n-------------->>>>%d :  %f et %f ",k,somme,ListeDesSolutions(k)(1,1))
                        M($+1)=k
                    end  
            
            Maximum=ListeDesSolutions(k)(1,1)
        else if ListeDesSolutions(k)(1,1)==Maximum then
                 somme=0
                    for i=2 : NVAR+1 
                        somme=somme+ ListeDesSolutions(k)(1,i)*m(NL,i-1)
                    end
                    if somme==ListeDesSolutions(k)(1,1) then //si c 'est une "BONNE" solution
                        //printf("\n <<%d>> ",k)
                    printf("\n-------------->>>>%d :  %f et %f ",k,somme,ListeDesSolutions(k)(1,1))
                                            M($+1)=k
                    end    

             end
         
        end
    end //for
    
    printf("\n Il y a %d solution(s) : \n",size(M))
    for k=1: size(M) do 
        printf("-- simulation %d\n",M(k))
    end
endfunction

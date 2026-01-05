function SOL=simplex2(m,Tvar)
  
  taille= size(m);
  tailleT= size(Tvar);
  save_m=m; //pour memoriser m avant modification de m
  NL=taille(1,1); //nb de lignes de m : on a donc m-1 contraintes
  NC=taille(1,2); //nb de colonnes de m
  Ncont=NL-1 //nb de contraintes
  NVAR=NC-Ncont-1 //nb de variables (c est aussi le nb de grandeurs considérées par le probleme posé)
  memorisation=ones(NVAR,1)
  memorisation=-memorisation
  SOL=zeros(1,1+NVAR+NC)

  POURSUIVRE=1;
  etap=1;
 while(POURSUIVRE==1 & etap<=NVAR) do  
  
  printf("\n\n ETAPE %d",etap);
  
  // où est le max sur la derniere ligne
  lemax=m(NL,Tvar(1,etap))
  laColDuMax=Tvar(1,etap)

      printf("\n Maximisation sur la variable %d",laColDuMax)
      //printf("\n leMax = %f",lemax)
    // où est la contrainte la + forte
  laLigneDuMin=1
  if (m(1,laColDuMax)<>0) then
      lemin=m(1,NC)/m(1,laColDuMax)
      laLigneDuMin=1
  else
      lemin=0
  end
   for lign=2 : Ncont do
      if (m(lign,laColDuMax)<>0) then
          v=m(lign,NC)/m(lign,laColDuMax)
          if v>=0 then
              if lemin<0 then
                lemin=v
                laLigneDuMin=lign
              end
              if lemin>v then
            lemin=v
            laLigneDuMin=lign
              end
          end
      
      end
   end
      //printf("\n le minimum = %f",lemin)
      printf("\n Ligne de la contrainte la + forte = %d",laLigneDuMin)

  memorisation(laColDuMax,1)=laLigneDuMin
    
   D = m(laLigneDuMin,laColDuMax)
  for col=1 : NC do
        m(laLigneDuMin,col)=        m(laLigneDuMin,col) / D
  end

   for lig=1 : NL do
        if (lig<>laLigneDuMin) then
            for col=1 : NC do
                if (col<>laColDuMax) then
                    //printf("\n%f - %f * %f",m(lig,col) , m(lig,laColDuMax) ,m(laLigneDuMin,col));
                       m(lig,col)=m(lig,col) - m(lig,laColDuMax) * m(laLigneDuMin,col) 
                end
            end
     //printf("-->>%d ",lig);
    end
  end
   
   
for lig=1 : NL do
      if (lig<>laLigneDuMin) then
          m(lig,laColDuMax)=   0
      end
  end
  
  //affichage
printf("\n-->>m= ");
  disp(m)
  
// faut il poursuivre sur une autre  etape de calcul
// pour le savoir, il faut regarder s il reste des termes positifs dans l expression du critere à optimiser
POURSUIVRE=0;
for col=1 : NVAR do
    if (m(NL,col)>0) then
    POURSUIVRE=1;
    end
     
end

//reajustement des inconnues
// 
for i=1 : NVAR do
                 if (i<>laColDuMax)  then
                     if  (memorisation(i,1)==laLigneDuMin)   then
                     
                    memorisation(i,1)=-1
                    end
                 end
    end

//affichage final
      printf("\n La valeur MAX du critere à optimiser %f",abs(m(NL,NC)))
      SOL(1,1)=-m(NL,NC)
      for i=1 : NVAR do
                 if (memorisation(i,1)<>-1) then
                     printf("\n La variable %d vaut %f",i,m(memorisation(i,1),NC));
                     SOL(1,1+i)=m(memorisation(i,1),NC)
                 end
                 
    
    end

etap=etap+1;
end //while
printf("\n Fin du simplex pour : ")
disp(Tvar)
               

//stocks restants
for stock=1 : Ncont do
      cpt=0
      for i=1 : NVAR do
                 if (memorisation(i,1)<>-1) then
                    cpt=cpt+m(memorisation(i,1),NC)*save_m(stock,i)
                 end

    
    end
       printf("\n STOCK %d : il en reste %d",stock,save_m(stock,NC)-cpt);
       SOL(1,1+NVAR+stock)=save_m(stock,NC)-cpt;               
end





endfunction

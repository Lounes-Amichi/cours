function X=mcarre(points,degre)
    taille=size(points)
    nbpoints=taille(1,1)
    MC=zeros(degre+1,degre+1)
    MC(1,1)=nbpoints
    B=zeros(degre+1,1)
    
    //premiere ligne de MC
    for col=2 : degre+1  do
        S=0
        for i=1 : nbpoints  do
            S=S+points(i,1)^(col-1)
        end
        MC(1,col)=S
    end
    
        //dernière colonne
    for ligne=2 : degre+1 do
        S=0
        for i=1:nbpoints do
            S=S+points(i,1)^(degre+ligne-1)
        end
        MC(ligne,degre+1)=S
    end
    
    //propagation en bas à 
    for ligne=2 : degre+1 do
        for col=1 : degre do
            MC(ligne,col)=MC(ligne-1,col+1)
        end
    end
    
        //calcul de B
    for ligne=1 : degre+1 do
        S=0
        for i=1:taille(1,1) do
            S=S+points(i,2)*points(i,1)^(ligne-1)
        end
        B(ligne,1)=S
    end    
    disp(MC)
    disp(B)
 
    
    //résolution
    X=linsolve(MC,-B)
    
    //calcul d'erreur
    x=poly(0,'x')
    polmc=0
    for k=1:degre+1 do
        polmc=polmc+X(k,1)*x^(k-1)
    end


endfunction

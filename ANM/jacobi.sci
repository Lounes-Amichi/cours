function X1=jacobi(A,B,X0,eps)
    
    taille=size(A)  //taille est un tableau 1 ligne 2 colonnes
    dimension=taille(1,1)
    X1=zeros(dimension,1)
    ECART=zeros(dimension,1)
    
    norme=1+eps
    continu=1
    
    iter=0
    //while(norme>=eps)   do
    while(continu==1)   do
    for ligne=1:dimension do
        som=0
        for colonne=1:dimension do
            if ligne<>colonne then
                som=som+A(ligne,colonne)*X0(colonne,1)
            end
        end
     X1(ligne,1)=   ( B(ligne,1)-som )/A(ligne,ligne)
        
        
        
    end
    //critere quadratique
    S=0
    for i=1 : dimension do
        S=S+(X1(i,1)-X0(i,1)).^2
    end
    norme=sqrt(S) 
    //critere absolu
    for i=1 : dimension do
        ECART(i,1)=abs(X1(i,1)-X0(i,1))
    end
    continu=0
    
    for i=1 : dimension do
    printf("\nECART %E",ECART(i,1))
    end

    for i=1 : dimension do
        if ECART(i,1)>eps then
            continu=1
            printf("\n ===============ici : %d",i)
        end
    end
    
    
       
    iter=iter+1
    printf("\n iteration n°%d : \nX=",iter)
    
    for i=1 : dimension do
    printf("\n %1.25f",X1(i,1))
    end

X0=X1
    
end //while

printf("\n\n\nNOMBRE d iteration(s) total : %d",iter)
printf("\n\n===>>solution calculee :")
    printf("\n %1.35f",X1(1,1))
    printf("\n %1.35f",X1(2,1))
    printf("\n %1.35f",X1(3,1))
printf("\n\n\n")
endfunction







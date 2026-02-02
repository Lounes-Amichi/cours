function solutions=cramer(A,B)
    
   // disp(A)
   // disp(B)

    
    D=det(A);
//    printf("Delta= %f",D)
       
    if (D==0) then
        printf("\n pas de solution !! det(A)=0 ")
    else
    
    taille=size(A)  //renvoie un tableau 1 ligne 2 colonnes
    nblignes=taille(1,1)
    solutions=zeros(nblignes) //declare un vecteur rempli de 0
        
    
    for i=1:nblignes do
        Abis=A
        Abis(:,i)=B    
        //disp(Abis)
    
        deltai=det(Abis)
  //      printf("det= %d",deltai)
        solutions(i,1)=(deltai/D)
  //      printf("\nsolution n° %d = %f",i,(deltai/D))
    end //for
       
  end //if
    
endfunction

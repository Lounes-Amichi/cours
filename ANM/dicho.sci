function  alpha=dicho(f,a,b,eps)
    
    if (f(a)*f(b)>0) then
        printf("\n MAµUVAISES DONNES !!");
    else //ALGO
        m=a;
        i=1
        while(abs(f(m))>eps) do
        m=(a+b)/2
        if (f(a)*f(m)<0) then
            b=m;
        else
            a=m;
       end//if 2
       i=i+1
     end//while
    end //if 1
    alpha=m;
    printf("\n Apres %d  iterations ",i)
endfunction

function s=sec(f,a,b,eps)
s=0
if  f(a)*f(b)>0 then
    printf("\n MAUVAISES DONNEES, a ou b est mal choisi !!!!!")
else
    iter=0
    s=a-f(a)*(a-b)/(f(a)-f(b))
    while abs(f(s)) >eps
        if f(a)*f(s)<0 then
            b=s
        else
            a=s
        end
        s=a-f(a)*(a-b)/(f(a)-f(b))
        iter=iter+1
    end
    printf("\nApres %d iteration(s), la racine vaut : %.15f",iter,s)
end
endfunction

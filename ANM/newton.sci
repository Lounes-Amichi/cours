function x0=newton(f,x0,eps)

    iter=0
    deltaX=0.01
    while(  (abs(f(x0)))>=eps    ) do 
        x1=x0 - f(x0) / ( (f(x0+deltaX)-f(x0-deltaX)) / (2*deltaX)       )
        iter=iter+1
        x0=x1
    end //while
    printf("\n\n==>> alpha=%1.15f - |f(alpha)|=%1.15f - iter=%d\n\n",x0,abs(f(x0)),iter)


endfunction

function [C]=facCho(A)
// Factorisation de Cholesky de la matrice A
//
C=zeros(A);
C(1,1)=sqrt(A(1,1));
dimmat=size(A,’r’);
for i=2:dimmat
for j=1:i-1
C(i,j)=(A(i,j)-(C(i,1:j-1)*C(j,1:j-1)’))/C(j,j);
end
C(i,i)=sqrt(A(i,i)-(C(i,1:i-1)*C(i,1:i-1)’));
end
endfunction

function p=vdm(mp)
taille=size(mp)
nbpoints=taille(1,1)
A=ones(nbpoints,nbpoints)
B=ones(nbpoints,1)
for colonne=1 : nbpoints-1
	for ligne=1 : nbpoints
		A(ligne,colonne)=mp(ligne,1)^(nbpoints-colonne)
	end
end
disp(A)

for ligne = 1 : nbpoints
	B(ligne,1)=mp(ligne,2)
end
disp(B)

X= linsolve(A,-B)
x=poly(0,'x')
p=0
for i=1:nbpoints do
	p=p+X(i,1)*x^(nbpoints-i)
end
endfunction

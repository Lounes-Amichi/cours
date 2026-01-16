all : bonbon.o partie1 partie2

partie1 : bonbon.o main.c
	gcc bonbon.o main.c -o main.x

partie2 : adn.o partie2.c
	gcc adn.o partie2.c -lm -o partie2.x

bonbon.o : bonbon.c bonbon.h
	gcc -c bonbon.c -o bonbon.o
	
adn.o : adn.c adn.h
	gcc -c adn.c -lm -o adn.o

clean :
	rm *.o *.x

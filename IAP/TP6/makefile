##################################B2######################################
# AUTEUR : AMICHI Lounès						 #
# DATE : 07/01/2026							 #
# VERSION : 1.0								 #
# DESCRIPTION : règles de compilation					 #
# NOM FICHIER : makefile						 #
##########################################################################

all : partie1 partie2 hash

partie1 : bonbon.o partie1.c
	gcc bonbon.o partie1.c -o partie1.x

partie2 : adn.o partie2.c
	gcc adn.o partie2.c -lm -o partie2.x

hash : hash.o exo2Adebug.c
	gcc hash.o exo2Adebug.c -o hash.x

bonbon.o : bonbon.c bonbon.h
	gcc -c bonbon.c -o bonbon.o
	
adn.o : adn.c adn.h
	gcc -c adn.c -lm -o adn.o

clean :
	rm *.x bonbon.o adn.o

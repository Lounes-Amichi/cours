all: hello.exe hello_pseudo.exe hello_mr.exe

hello.exe: print.o println.o exercice1.c
	gcc print.o println.o exercice1.c -o hello.exe

print.o: print.h print.c
	gcc -c print.c -o print.o

println.o: println.h println.c
	gcc -c println.c -o println.o
	
hello_pseudo.exe: print.o println.o hello_pseudo.o hello_pseudo.c
	gcc print.o println.o hello_pseudo.c -o hello_pseudo.exe

hello_mr.exe: print.o println.o hello_pseudo.o hello_pseudo.c
	gcc print.o println.o hello_pseudo.o hello_pseudo.c -D'DEFAULT_NAME="GCC Stranger"' -o hello_mr.exe

menu: menu.c
	gcc menu.c -lncurses -o menu.exe

clean:
	rm *.o *.exe

#include "hello_pseudo.h"

#ifndef DEFAULT_NAME
#define DEFAULT_NAME "Stranger"
#endif	

int hello_pseudo(int argc, char *argv[]) {
	char name[50];
	if (argc > 1)
		strcpy(name, argv[1]);
	else {
		#ifdef DEFAULT_NAME
		strcpy(name, DEFAULT_NAME);
		#endif
	print("Hello, ");
	println(name);
	return 0;
	}
}

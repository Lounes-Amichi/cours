#define MAXCAR 80

#define vide(ch) ch[0] == '\0'
#define egal(a,b) !strcmp(a,b)

typedef char Tchaine[MAXCAR+1];

char * dernier(char * mot, const char * ch);

char * dernier(char * mot, const char * ch) {
	if (vide(saufpremier(ch))) {  // saufpremier retourne "" quand la chaine est vide ou contient un seul mot
		mot = "";
		return mot;
	} else {
		
	}
}

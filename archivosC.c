#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	// char* fgets(char *s , int n , FILE* f); leer cadena, lee n-1 coracter y lo almazena em el *s , 

	FILE *f;

	f = fopen("archivo1" , "wt+" );

	int c;

	while(c != ';'){

		c = getc(stdin);

		fputc( c , f);

	}


	return 0;
}
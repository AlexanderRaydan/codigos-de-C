#include <stdio.h>


	int columna(char caracter){

		if(caracter >= 'a' && caracter <= 'z')

			return 0;

		if (caracter >= '0' && caracter <= '9')

			return 1;

		if (caracter == ':')

			return 2;

		if (caracter == '=')

			return 3;

		if (caracter == '+' || caracter == '-')

			return 4;


		return 5;

	}


int  automata(char vec[]){

	int e = 0;

	int i = 0;

	int matris[9][6]={

	{1,2,4,8,5,8},

	{1,1,0,0,0,8},

	//{8,8,8,8,8,8,8},

	{8,2,4,4,4,8},

	//{8,8,8,8,8,8,8},

	{8,8,8,8,8,8},

	{8,8,8,7,8,8},

	{8,8,8,8,8,8},

	{8,8,8,8,8,8}

	//{8,8,8,8,8,8,8}


				};



while(vec[i]){

	e = matris[e][columna(vec[i])];

	printf("%c\n", vec[i]);

	printf("columna = " );

	printf("%d\n" ,columna(vec[i]));

	printf("valor de e = " );

	printf("%d\n", e );

	i++;

/*	if(e == 8){


		printf("no se reconoce la cadena , error en la posicion %i el caracter %c rompe todo ", i , vec[i-1]);
	
		return 0;

			}
			*/
		}


		if(e == 5 || e == 7 || e == 1 || e == 2)

			return 1;

		
		return 0;

}


int main(int argc, char const *argv[])
{

	int e = 0;

	char vec[]= ":=";

	e = automata(vec);

	printf("%d\n", e );


	return 0;
}
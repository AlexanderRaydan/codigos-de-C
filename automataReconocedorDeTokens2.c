#include <stdio.h>


int columna(char caracter){

		if(caracter >= 'a' && caracter <= 'z')

			return 0;

		if (caracter >= '0' && caracter <= '9')

			return 1;

		if (caracter == ':')

			return 3;

		if (caracter == '=')

			return 4;

		if (caracter == '+' || caracter == '-')

			return 2;

		if(caracter == ';')

			return 5;


		return 6;

	}

void sacarToken(int e){


	if(e == 2)

		printf("%s\n","<identificador>");

	if(e == 4)

		printf("%s\n","<digito>");

	if(e == 5)

		printf("%s\n","<signo>");

	if(e == 7)

		printf("%s\n","<igualdad>");

}


int  automata(char vec[]){

	int i = 0;

	int e = 0;

	int aux = 0;

	int matris[10][7]={

		{1,3,5,6,8,8,8}, //0

		{1,1,2,2,2,10,8},//1

		{0,0,0,0,0,8,8},//2

		{8,3,4,4,4,10,8},//3

		{0,0,0,0,0,8,8},//4

		{0,0,0,0,0,8,8},//5

		{8,8,8,8,7,8,8},//6

		{1,3,5,0,0,8,8},//7

		{8,8,8,8,8,8,8},//8

		{8,8,8,8,8,8,8} //9

	};


	while(vec[i]){

			e = matris[e][columna(vec[i])];

		if(e == 2){

		printf("%s\n","<identificador>");

		e = 0;

		aux = i;

		i--;

		}

		if(e == 4){

			printf("%s\n","<digito>");

			e = 0;

			aux = i;

			i--;
		}

		if(e == 5){

			printf("%s\n","<signo>");

			e = 0;

			aux = i+1;

		}

		if(e == 7){

			printf("%s\n","<igualdad>");

			e = 0;

			aux = i+1;

		}

		i++;

		if(e == 8){

			printf("no se reconoce la cadena , error en la posicion %i el caracter %c rompe todo ", i , vec[i-1]);		

			return 0;
		}

	}


	if(e == 10){


		if(vec[aux] >= '0' && vec[aux] <= '9')

			printf("%s\n", "<digito>");

		else

			printf("%s\n", "<identificador>" );

		return 1;

}


	return 0;

}


int main(int argc, char const *argv[])
{
	int e = 0;

	char vec[]= "3:=3+444-er3:=-34;";

	e = automata(vec);

	printf("%d\n", e );

	return 0;
}
#include <stdio.h>


int columna(char c){


	if(c =='+' || c == '-')

		return 0;

	if(c == '0')

		return 1;

	if(c >= '1' && c <= '9')

		return 2;

	return 3;

}

int pasarValor(char s[]){

	int i = 0;
	int numero = 0;


	if(s[0] != '+' && s[0] != '-')

		i = 0;

	else 

		i = 1;



		while(s[i]){

			numero = numero*10 + (s[i] - '0');

			i++;

		}

	if(s[0] == '-')

		return numero*-1;


	return numero;


}


int automata(char s[]){

	int matriz[5][4]={{2,1,3,4},{4,4,4,4},{4,4,3,4},{4,3,3,4},{4,4,4,4}};

	int i = 0;
	int e = 0;
	int numero = 0;

	if(s[0] == '0' && s[1] ){

				printf("%s\n", "el numero no puede empezar por cero" );

				return 0;
			}

			if(s[0] =='+' || s[0] == '-'){

				if(s[1] == '0' && s[2]){

					printf("%s\n", "el numero no puede empezar por cero, a menos que sea solamente el cero");

					return 0;
				}

					if(s[1] == '0' && !s[2]){

						printf("%s\n","se reconocio la cadena con exito");

						return 0;
					}
			}


		while(s[i]){

			e = matriz[e][columna(s[i])];

			i++;

			//printf("%d\n",e );

			if(e == 4){

				printf("%s","no se reconoce la cadena, error en la posicion ");
				printf("%i\n", i );
				printf("%s","el caracter ");
				printf("%c",s[i-1] );
				printf("%s\n"," no pertenece al tipo de dato" );

				return 0;
			}


		}

		i = 0;


		if(e == 1 || e == 3){

			numero = pasarValor(s);

			printf("%s\n","se reconocio la cadena con exito");


			return numero;
		}

		return 0;

}


int main(int argc, char const *argv[])

{
	
	char s[]= "+1245";


	printf("%i\n",automata(s));

	//printf("%c\n", 4[s]); //LOOOOOOO0000OOOOOOOOOO000000OOOOOOOLLLLLLLLL

		
	return 0;
}









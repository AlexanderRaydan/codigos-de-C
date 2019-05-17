#include <stdio.h>


	int columna(char c){

	if(c >= '0' && c <= '9')
		
		return 0;


	if(c == '+')

		return 1;


	if(c == '-')

		return 3;

	if(c == '*')

		return 2;
	

	return 4;

}
	
	int automata(char vec[]){

		int matriz[5][5]={{4,1,4,1,4},{2,4,4,4,4},{2,1,3,1,4},{2,4,4,1,4},{4,4,4,4,4}};

		int i = 0;
		int e = 0;
		int num1 = 0;
		int num2 = 0;
		int auxpos = 0;
		int auxneg = 0;
		int auxmulti = 1;
		int auxmulti2 = 0;
		bool negativo = false;
		bool signo = true;

		if(vec[0] != '+' && vec[0] != '-'){

			printf("%s\n", "la cadena tiene que empezar con un signo + o -" );

			return 0;
		}

		while(vec[i]){

			e = matriz[e][columna(vec[i])];

			i++;

			if(e == 4){


				printf("no se reconoce la cadena , error en la posicion %i el caracter %c rompe todo ", i , vec[i-1]);
			
				return 0;
			}
		}

		if (e != 2){

		 printf("no se reconoce la cadena , error en la posicion %i el caracter %c rompe todo ", i , vec[i-1]);

		return 0;


	}

	i = 0;

	
	while(vec[i]){


		if(vec[i] == '+' || vec[i] == '-'){

			if(vec[i] == '+')

				signo = true;
			 else

				signo = false;


				i++;
			

			while(vec[i] != '+' && vec[i] != '-' && vec[i] != '*' && vec[i]){

				num1= num1*10 + (vec[i] - '0');

				i++;
			}

			if(vec[i] != '*'){

				if(signo)

					auxpos +=  num1;

				else

					auxneg +=  num1;


				num1 = 0;

			}

			if(vec[i] == '*'){

				i++;


				if(signo)

					auxmulti = num1;
				else
					auxmulti = num1*(-1);


				num1 = 0;

				if(vec[i] == '-'){

					i++;
					negativo = true;

				}

				while(vec[i] != '+' && vec[i] != '-' && vec[i]){

					while(vec[i] != '+' && vec[i] != '-' && vec[i] != '*' && vec[i]){

						num2 = num2*10 + (vec[i] - '0');

						i++;
					}

					if(vec[i] == '*'){

						i++;

						if(vec[i] == '-'){

							i++;

							auxmulti = auxmulti*num2*(-1);


							} else {

								auxmulti = auxmulti*num2;
							}

						num2 = 0;

						} else {

							auxmulti = auxmulti * num2;
						}

					}


					if(negativo){

					auxmulti2 += auxmulti*(-1);

					} else 
					
					auxmulti2 += auxmulti;
	
			}


		}

	}

	return auxpos - auxneg + auxmulti2;
}


int main(int argc, char const *argv[])

{

	char vec[]="-4+4*3*-4*5-4";

	printf("%d\n", automata(vec));


	return 0;
}
|
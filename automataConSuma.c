#include <stdio.h>


	int columna(char c){


	if(c =='+' || c == '-')

		return 0;

	
	if(c >= '0' && c <= '9')

		return 1;

	return 2;

}
	
	int automata(char vec[]){

		int matriz[5][3]={{1,2,4},{4,2,4},{3,2,4},{4,2,4},{4,4,4}};

		int i=0;
		int e=0;
		int num=0;
		int num2=0;
		int auxpos=0;
		int auxneg=0;


		while(vec[i]){

			e = matriz[e][columna(vec[i])];

			i++;


			//printf("%d\n",e );

			if(e == 4){

				printf("%s","no se reconoce la cadena, error en la posicion ");
				printf("%i\n", i );
				printf("%s","el caracter ");
				printf("%c",vec[i-1] );
				printf("%s\n"," rompe todo" );

				return 0;
			}
		}

	
			i=0;

	
		while(vec[i]){



		if(vec[i]=='+'){

			i++;

				while(vec[i] != '+' && vec[i] != '-' && vec[i] ){

				num= num*10 + (vec[i] - '0');


				i++;

			}

			auxpos = auxpos + num;

			num=0;


		}
 
		if(vec[i]=='-' ){

			i++;

				while(vec[i] != '+' && vec[i] != '-' && vec[i]){

				num2 = num2 *10 + (vec[i] - '0');
		
				i++;
			
			}

			auxneg = auxneg + num2;

			num2=0;

		}

	}


		if(e==2)

			return auxpos - auxneg ;

		

		return 0;
	}



int main(int argc, char const *argv[])
{


	char vec[]="+564-678+65465+768765-97987";

	printf("%d\n", automata(vec));

	return 0;
}

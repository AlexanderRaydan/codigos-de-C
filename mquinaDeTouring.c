#include <stdio.h>


struct controlTuring
{
	char escribo;

	int voy; // 1 || -1

	int proxStado ;

};

int columna(char s){

if(s == 'a')

	return 0;

if(s == 'b')

	return 1;

if(s == 'c')

	return 2;

if(s == 'x')

	return 3;

if(s == 'y')

	return 4;

if(s == 'z')

	return 5;

if(s == ';')

	return 6;

return 7;

}

controlTuring fff = {'f' , 0 , 8};

controlTuring matriz[7][8]={
			
			//a         b        c            x             y           z       ;   8   8	

		{{'x',1,1} , 	fff	   , fff		, fff	 	, {'y',1,4},  fff         ,    fff	  , fff }, //0 

		{{'a',1,1} , {'y',1,2} , fff		, fff		, {'y',1,1},  fff         ,    fff    , fff }, // 1
 
		{fff 	   , {'b',1,2} , {'z',-1,3} , fff		, fff      ,  {'z',1,2}   ,    fff    , fff }, // 2

		{{'a',-1,3}, {'b',-1,3} ,    fff    , {'x',1,0} , {'y',-1,3} , {'z',-1,3},    fff 	  , fff }, // 3

		{fff		,   fff	   ,    fff  	,   fff		, {'y',1,4} , {'z',1,5}   ,    fff 	  , fff }, // 4

		{fff		,   fff		,   fff		,   fff		,   fff		, {'z',1,5}   , {';',1,6} , fff }, // 5

		{fff		,   fff		,   fff		,   fff		,   fff		,   fff		  ,    fff    ,   fff }, 	// 6


		}; 


//enum consumo{a,b,c,x,y,z};


int automata (char vec[]){



	int i=0;
	int e=0;

		while(vec[i]){

			controlTuring posicion = matriz[e][columna(vec[i])];

			e = posicion.proxStado;

			printf("%s\n","************************" );

			printf("columna: %i\n" , columna(vec[i]));

			printf("encuentro: %c\n", vec[i] );

			printf("lo que escribo: %c\n", posicion.escribo);
			
			printf("proxStado: %i\n" , e );

			printf("avanzo: %i\n", posicion.voy );

			printf("%s\n","************************" );


			vec[i] = posicion.escribo;

			i = i + posicion.voy;


			if(e == 8)
				return 0;

		}

		if(e == 6)
			return 1;

		else 
			return 0;

}

int main(int argc, char const *argv[])
{

	char vec[] = "aaaabbbbcccc;";	

	int e = automata(vec);

	printf("%i\n", e );


	return 0;
}
#include <stdio.h>


int *pasameUnpuntero(int *pun){

	*pun = 99;
	*(pun + 1) = 9600;
	*(pun + 2) = 200;
	*(pun + 3) = 300;
	*(pun + 4) = 400;


	return pun;

}

int main(int argc, char const *argv[])
{

	int x = 2;
	int y = 3;
	int z = 4;
	int u = 5;
	int v = 6;
	int t = 7;
	int paux = 0;

	y=++z;

	//scanf("%i",&x);


	printf("%i %i %i %i %i %i\n",x,y,z,u,v,t);


	int *puntero = NULL;

	puntero = &paux;

	printf("%s\n", "*******************" );

		*(puntero + 1) = 423;

		printf("%d\n", *(puntero + 1));


	printf("%s\n", "*******************" );

	printf("%d\n", *(puntero + 1));

	pasameUnpuntero(puntero);

	printf("%i\n", *(puntero + 1 ) );


	//printf("%d\n", *(puntero + 1) );


	 for (int i = 0; i < 5; ++i)
	 {
	 	printf("%i\n", *(puntero + i));
	 }


	 printf("%d\n", *(puntero + 1) );






	 // struc es la misma verga 

	 struct viendoStruct
	 {
	 	int vida;

	 	char caracteristica;

	 };


	 viendoStruct esele;

	 esele.vida = 3;

	 printf("%d\n", esele.vida);


	 struct lista
	 {
	 	int dato;

	 	lista *sigui;

	 }lista;


	return 0;
}

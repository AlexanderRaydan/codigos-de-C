#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct  Nodo{

		int info;

		struct Nodo *sigui;

	}Nodo;


typedef	struct Lista{

		Nodo *inicio;

	}Lista;


Nodo *crearNuevoNodo(int info ){

	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));

	nodo->info = info;

	nodo->sigui = NULL;

	return nodo;

}

void destruirNodo(Nodo *nodo){

	free(nodo);
}

	void insertarAlFinal(Lista *lista , int info){

		Nodo *newNodo = crearNuevoNodo(info);

		Nodo *paux = lista -> inicio;

		if(lista -> inicio == NULL){

			lista-> inicio = newNodo;

		} else {

			while(paux -> sigui){

				paux = paux -> sigui;
			}

			paux -> sigui = newNodo;

		}

	}


int main(int argc, char const *argv[])
{
	
	Lista *lista ;

	Nodo *nodoInicio;

	nodoInicio -> info = 1;

	nodoInicio -> sigui = NULL;

	lista -> inicio = nodoInicio;  // aqui es donde esta el peo

	//insertarAlFinal(lista , 2);

	return 0;
}
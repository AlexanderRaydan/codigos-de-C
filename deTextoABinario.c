#include <stdio.h>
int main(int argc, char const *argv[])
{

struct linea
    {
	int a;
	int b;    	
    };


    linea primera;

	int c = 0;

	FILE *f;
	FILE *p;

	f = fopen("binario" , "rb+");
	p = fopen("auchivo2" , "rt+");

	fscanf( p ,"%d %d" , &primera.a , &primera.b);

	//printf("%i\n %i\n", a , b);

	fwrite(&primera , sizeof(linea) , 1 , f );

	//fwrite(&b , sizeof(int) , 1 , f );
	fseek(f,0,SEEK_SET);

	linea aux;

	fread(&aux,sizeof(linea),1,f);
	
	printf("%d %d",aux.a , aux.b);
	
	//printf("%i\n", &a );


	return 0;
}
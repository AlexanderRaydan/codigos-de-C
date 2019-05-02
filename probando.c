#include <stdio.h>

int main()
{
  char *puntero[5];

  printf ("eseleeee manoooo" "\n");
  int x = 30;

  printf ("%i\n", x);

  int *p;
  int i = 0;
  int vec[] = { 1, 33, 3, 4, 5, 6 };

  p = vec;

  for (i = 0; i < 6; i++){
      
      printf ("dato vec[%i]: %i", i, *(p));
      printf ("\n");
      p++;

    }
  
}
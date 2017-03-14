#include <stdio.h>
#include <stdlib.h>

int subsuma(int c[], int sizeC,  int suma, int i, int sol[], int *size_sol) {

  if (i==sizeC) return suma==0;

  sol[(*size_sol)++] = c[i];
  if (subsuma(c,sizeC,suma-c[i],i+1,sol,size_sol)) return 1;

  (*size_sol)--;
  if (subsuma(c,sizeC,suma,i+1,sol,size_sol)) return 1;

  return 0;
}

int main() {

  int c[] = {1,-3,5,6};
  int size_c = 4;

  int * sol = (int *) malloc( size_c * sizeof(int) );
  int size_sol = 0;

  subsuma(c,5,8,0,sol,&size_sol);

  for (int i=0; i<size_sol; i++) {
    printf("%d ",sol[i]);
  }

  printf("\n");

  return 0;
}

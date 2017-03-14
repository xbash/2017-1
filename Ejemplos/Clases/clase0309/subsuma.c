#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int subsuma(int c[], int sizeC,  int suma, int i, int sol[]) {

  if (i==sizeC) return suma==0;

  sol[i] = 1;
  if (subsuma(c,sizeC,suma-c[i],i+1,sol)) return 1;

  sol[i] = 0;
  if (subsuma(c,sizeC,suma,i+1,sol)) return 1;

  return 0;
}


int leerMatriz(int mat[]) {
  char linea[300];
  int tam = 0;
  printf("Ingrese un numero por linea. Ingrese una linea vacía para terminar.\n");
  while (1) {
    fgets(linea,300,stdin);
    if (strcmp(linea,"\n") == 0) return tam;
    mat[tam++]=atoi(linea);
  }
  return -1;
}

int main() {

  int c[MAX];
  int tamA = leerMatriz(c);
  int * sol = (int *) malloc(tamA*sizeof(int));
  int suma_objetivo;

  printf("Ingresa suma objetivo:");
  scanf("%d", &suma_objetivo);

  if (subsuma(c,tamA,suma_objetivo,0,sol)) {
    printf("Solución: ");
    for (int i=0; i<tamA; i++) {
      if (sol[i]) printf("%d ",c[i]);
    }
    printf("\n");
  } else {
    printf("El problema no tiene solución.");
  }

  return 0;
}

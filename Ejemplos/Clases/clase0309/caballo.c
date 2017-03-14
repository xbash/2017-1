#include <stdio.h>
#include <stdlib.h>

int tamano = 6;

#define legal(i) (i >= 0 && i < tamano)

int delta[][2] = {{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};

int caballo(int i,int j,int cuenta, int ** tablero) {
  if (cuenta ==  tamano*tamano) return 1;
  for (int dirs=0; dirs<8;++dirs) {
    int nuevo_i = i + delta[dirs][0];
    int nuevo_j = j + delta[dirs][1];
    if (legal(nuevo_i) && legal(nuevo_j) && tablero[nuevo_i][nuevo_j]==0) {
      tablero[nuevo_i][nuevo_j] = cuenta+1;
      if (caballo(nuevo_i,nuevo_j,cuenta+1,tablero)) return 1;
      tablero[nuevo_i][nuevo_j] = 0;
    }
  }
  return 0;
}

int main() {
  int i,j;
  int **tablero;
  tablero = (int **) malloc(tamano*sizeof(int*));
  for (i=0; i< tamano;++i)
    tablero[i]=(int*) malloc(tamano*sizeof(int));

  for (i=0; i<tamano; ++i)
    for (j=0; j<tamano; ++j)
      tablero[i][j] = 0;

  tablero[0][0] = 1;
  caballo(0,0,1,tablero);

  for (i=0; i<tamano; ++i) {
    for (j=0; j<tamano; ++j)
      printf("%d ", tablero[i][j]);
    printf("\n");
  }

  for (i=0; i< tamano;++i)
    free(tablero[i]);
  free(tablero);
}



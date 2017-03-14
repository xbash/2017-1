#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define N 6
#define VOLUMEN 123

int utilidad[N];  // utilidad[i] es la utilidad del producto i
int volumen[N];  // volumen[i] es el volumen del producto i
int elegido[VOLUMEN+1]; // producto que maximiza la ecuación Opt(V) descrita en clases

int opt[VOLUMEN+1]; // valor de Opt(v)


int optimo(int vol) {
  int mejor=0;
  int i;

  elegido[vol]=-1;

  ////// completar

  return mejor;
}


int optimopd(int volumen_total) {
  int mejor=0;
  int i;

  elegido[volumen_total]=-1;
  opt[0]=0;
  int vol;
  ///// completar
  return opt[volumen_total];
}

int uniform(int min, int max) {
  return ((double)rand()/(RAND_MAX+1.0)) * (max-min+1) + min;
}

int main(int argc, char *argv[]) {
  int i;

  if (argc!=2) {
    printf("Uso: %s <\"rec\" o \"pdin\"> ",argv[0]);
    return 1;
  }

  for (i=0;i<N;i++) {
    volumen[i]=uniform(1,VOLUMEN/N);
    utilidad[i]=uniform(1,100);
    elegido[i]=-1;

    printf("producto %d: utilidad=%d vol=%d\n",i,utilidad[i],volumen[i]);
  }

  int opt;
  if (strcmp("rec",argv[1])==0)
    opt=optimo(VOLUMEN);
  else
    opt=optimopd(VOLUMEN);

  int volumen_restante=VOLUMEN;

  printf("optimo=%d\nitems:\n",opt);

  //  while (volumen_restante>=0 && elegido[volumen_restante]==-1) 
  // volumen_restante--;

  while (volumen_restante>0) {
    int item_elegido=elegido[volumen_restante];
    if (item_elegido==-1) break;
    printf("%d ",item_elegido);
    volumen_restante-=volumen[item_elegido];
  }
  printf("\n");
  return 0;
}



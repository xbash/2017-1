#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define N 30
#define VOLUMEN 30000
#define INFINITO 1000000

int utilidad[N];
int volumen[N];
int elegido[VOLUMEN+1][N];
int opt[VOLUMEN+1][N+1];


int optimo(int vol, int indice) {
  if (vol<0) return -INFINITO;
  if (indice==0||vol==0) return 0;
  int utilidad_incluido=utilidad[indice-1]+optimo(vol-volumen[indice-1],indice-1);
  int utilidad_no_incluido= optimo(vol,indice-1);
  if (utilidad_incluido>utilidad_no_incluido) {
    elegido[vol][indice-1]=1;
    return utilidad_incluido;
  } else {
    elegido[vol][indice-1]=0;
    return utilidad_no_incluido;
  }
}

int optimopd_aux(int vol, int indice) {
  if (vol<0) return -INFINITO;
  if (indice==0 || vol==0) return 0;
  return opt[vol][indice];
}

int optimopd(int volumen_total) {
  int vol,indice;
  for (vol=1;vol<=volumen_total;vol++)
    for (indice=1; indice<=N; indice++) {
      int utilidad_incluido=utilidad[indice-1]+optimopd_aux(vol-volumen[indice-1],indice-1);
      int utilidad_no_incluido= optimopd_aux(vol,indice-1);
      if (utilidad_incluido>utilidad_no_incluido) {
	elegido[vol][indice-1]=1;
	opt[vol][indice]=utilidad_incluido;
      } else {
	elegido[vol][indice-1]=0;
	opt[vol][indice]=utilidad_no_incluido;
      }
    }
  return opt[volumen_total][N];
}




int uniform(int min, int max) {
  return ((double)rand()/(RAND_MAX+1.0)) * (max-min+1) + min;
}

int main(int argc, char *argv[]) {
  int i;

  if (argc!=2) {
    printf("Uso: %s <rec o pdin>.",argv[0]);
    return 1;
  }

  for (i=0;i<N;i++) {
    volumen[i]=uniform(VOLUMEN/N,2*VOLUMEN/N);
    utilidad[i]=uniform(1,VOLUMEN);
    printf("producto %2d: utilidad=%2d vol=%2d\n",i,utilidad[i],volumen[i]);
  }

  int opt;
  if (strcmp("rec",argv[1])==0)
    opt=optimo(VOLUMEN,N);
  else
    opt=optimopd(VOLUMEN);

  printf("optimo=%d\nitems:\n",opt);

  int volumen_restante;
  for (volumen_restante=VOLUMEN, i=N-1; volumen_restante>0 && i>=0; --i) {
    if (elegido[volumen_restante][i]) {
      printf("%d ",i);
      volumen_restante-=volumen[i];
    }
  }
  printf("\nvolumen ocupado=%d",VOLUMEN-volumen_restante);
  printf("\n");
  return 0;
}



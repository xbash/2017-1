//Importo persona desde el archivo ".h"
#include "persona.h"

//Función que calcula el valor de felicidad de una distribución de cabañas dadas
int evaluar(int* estado, Persona** alumnos, int tamano){
  int suma = 0;
  int cabana;
  for (int i = 0; i < tamano; i++){
    cabana = estado[i];
    if (estado[alumnos[i] -> quiere] == cabana){
      suma += 1;
    }
    if (estado[alumnos[i] -> odia] == cabana){
      suma -= 1;
    }
  }
  return suma;
}

//Funcion recursiva que genera permutaciones sobre los posibles estados del problema
void generar_permutaciones(int* arreglo, int tamano, int i, int unos, int dos, int* mejor, int* valor, Persona** alumnos){
  //Caso base
  if (i == tamano){
    int val = evaluar(arreglo, alumnos, tamano);
    if (val > *valor){
      *valor = val;
      for (int j = 0; j < tamano; j++){
        mejor[j] = arreglo[j];
      }
    }
    return;
  }
  //Casos recursivos
  if (unos > 0){
    arreglo[i] = 1;
    generar_permutaciones(arreglo, tamano, i + 1, unos - 1, dos, mejor, valor, alumnos);
  }
  if (dos > 0){
    arreglo[i] = 2;
    generar_permutaciones(arreglo, tamano, i + 1, unos, dos - 1, mejor, valor, alumnos);
  }
}

//Función principal del programa
int main(int argc, char *argv[]) {

  //Compruebo que el input tenga todos los argumentos
  if (argc != 3){
    printf("Debes dar como input los path a los archivos a leer y escribir\n");
  }

  //Defino las variables de los primeros tres parámetros
  int n_alumnos;
  int t_cabana1;
  int t_cabana2;

  //Abro el archivo
  FILE* file = fopen(argv[1], "r");
  //Guardo los valores en las variables leyendo el archivo
  fscanf(file, "%i", &n_alumnos);
  fscanf(file, "%i", &t_cabana1);
  fscanf(file, "%i", &t_cabana2);

  //Creo el arreglo solución
  int estado[n_alumnos];
  //Lo inicializo con el primer posible estado del problema
  //[1,1,1...,2,2,2]
  for (int i = 0; i < t_cabana1; i++){
    estado[i] = 1;
  }
  for (int i = t_cabana1; i < n_alumnos; i++){
    estado[i] = 2;
  }

  //Leo a los alumnos en el archivo
  Persona** alumnos = malloc(sizeof(Persona*) * n_alumnos);
  //Defino las variables a usar
  Persona* alumno;
  int quiere;
  int odia;
  for (int i = 0; i < n_alumnos; i++){
    //Leo el archivo y creo a los alumnos
    fscanf(file, "%i", &quiere);
    fscanf(file, "%i", &odia);
    alumno = alumno_init(i, quiere, odia);
    alumnos[i] = alumno;
  }
  //Cierro el archivo
  fclose(file);

  //Creo un arreglo para guardar la mejor solución
  int mejor[n_alumnos];
  //Le asigno un valor menor al peor posible estado
  int valor = -1 * n_alumnos - 1;

  //Genero las permutaciones y le paso las variables mejor y estado para que guarde la mejor solución
  generar_permutaciones(estado, n_alumnos, 0, t_cabana1, t_cabana2, mejor, &valor, alumnos);

  //Escribo en el archivo de salida
  FILE* output = fopen(argv[2], "w");
  //itero sobre la solución
  for (int i = 0; i < n_alumnos; i++){
    if (mejor[i] == 1){
      fprintf(file,"%i ", i);
    }
  }
  fprintf(file,"\n");
  for (int i = 0; i < n_alumnos; i++){
    if (mejor[i] == 2){
      fprintf(file,"%i ", i);
    }
  }
  fprintf(file,"\n%i", valor);
  //Cierro el archivo
  fclose(output);

  //Libero la memoria pedida con malloc
  for (int i = 0; i < n_alumnos; i++){
    free(alumnos[i]);
  }
  free(alumnos);

  //Retorno 0, lo que significa que todo está bien
  return 0;
}

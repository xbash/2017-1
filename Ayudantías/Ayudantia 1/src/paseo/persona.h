//Si no se a definido AYU_PERSONA
#ifndef AYU_PERSONA
//Entonces define AYU_PERSONA
#define AYU_PERSONA

//Librería estandar de input y putput y estandar de C
#include <stdio.h>
#include <stdlib.h>

//Estructura de una persona (alumnos)
struct persona{
  //Contiene el id del alumno
  int id;
  //Contiene el id del alumno que odia
  int odia;
  //COntiene el id del alumno que quiere
  int quiere;
};

//Cambio el nombre de "struct persona" a "Persona"
typedef struct persona Persona;

//Defino la función constructora de alumno
Persona* alumno_init(int id, int quiere, int odia);

//Terminando de definir AYU_ALUMNO
#endif

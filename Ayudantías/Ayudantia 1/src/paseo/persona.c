//Llamo a persona.h
#include "persona.h"

//Creo la función constructora del alumno
Persona* alumno_init(int id, int quiere, int odia){

  //Le pido al sistema operativo memoria para una persona y guardo el puntero en "al"
  Persona* al = malloc(sizeof(Persona));
  //Inicializo las variables de la persona
  al -> id = id;
  al -> odia = odia;
  al -> quiere = quiere;
  //Retorno el puntero a la estructura creada
  return al;
}

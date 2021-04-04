#ifndef DICCIONARIO_H 
#define DICCIONARIO_H
#include "microprocesador.h"
#include "direccionamientos.h"
#include "instrucciones.h"



typedef void (*operacion_t)(moss6502_t *, instruccion_t *);
typedef void (*direccionamiento_t)(moss6502_t *, instruccion_t *);

typedef struct diccio diccionario_t;
void ejecutar_instruccion (moss6502_t* micro);


#endif 

#include "direccionamientos.h"

//FUNCIONES DIRECCIONAMIENTO
void implicito (moss6502_t *procesador, instruccion_t * instruccion){
}

void acumulador (moss6502_t *procesador, instruccion_t * instruccion){
    instruccion -> m = &(procesador -> a);
}

void inmediato (moss6502_t *procesador, instruccion_t * instruccion){
    instruccion -> m = &(procesador -> mem[(procesador -> pc)]);
    (procesador -> pc) ++;
}

void relativo (moss6502_t *procesador, instruccion_t * instruccion){
	uint8_t aux=~(procesador -> mem[procesador -> pc])+1;
	if (MASK_SIGN & (procesador -> mem[procesador -> pc])){
		instruccion->direccion= procesador->pc - aux + 1 ;
		procesador->pc++;
	}
	else {
		instruccion->direccion=procesador->pc + (procesador -> mem[procesador -> pc]) + 1 ;
		procesador->pc++;
	}
}
void absoluto (moss6502_t *procesador, instruccion_t * instruccion){
    instruccion -> direccion = (procesador -> mem[(procesador -> pc)+1] << 8) | procesador -> mem[procesador -> pc];
    (instruccion -> m) = &(procesador->mem[instruccion -> direccion]);
    (procesador -> pc) +=2;
}

void paginacero (moss6502_t *procesador, instruccion_t * instruccion){
	instruccion->direccion = procesador->mem[procesador->pc++];
	(instruccion -> m) = &(procesador->mem[instruccion -> direccion]);
}
void indirecta (moss6502_t *procesador, instruccion_t * instruccion){
	uint16_t aux= (procesador -> mem[(procesador -> pc)+1] << 8) | procesador -> mem[procesador -> pc];
	instruccion -> direccion = procesador-> mem [aux+1]<<8 | procesador->mem[aux];
	(instruccion -> m) = &(procesador->mem[instruccion -> direccion]);
	procesador -> pc+=2;
}

void indexabsoluto (moss6502_t *procesador, instruccion_t * instruccion){
    instruccion -> direccion = ((procesador -> mem[(procesador -> pc)+1] << 8) | procesador -> mem[procesador -> pc]) + procesador->x;
    (instruccion -> m) = &(procesador->mem[instruccion -> direccion]);
    (procesador -> pc) +=2;
}
void indeyabsoluto (moss6502_t *procesador, instruccion_t * instruccion){
    instruccion -> direccion = ((procesador -> mem[(procesador -> pc)+1] << 8) | procesador -> mem[procesador -> pc])+procesador->y;
    (instruccion -> m) = &(procesador->mem[instruccion -> direccion]);
    (procesador -> pc) +=2;
}
void paginax (moss6502_t *procesador, instruccion_t * instruccion){
	instruccion->direccion = (procesador->mem[procesador->pc]+procesador->x) & MASK_1BYTE;
	(instruccion -> m) = &(procesador->mem[instruccion -> direccion]);
	procesador->pc++;
}

void paginay (moss6502_t *procesador, instruccion_t * instruccion){
	instruccion->direccion = (procesador->mem[procesador->pc++]+procesador->y) & MASK_1BYTE;
	(instruccion -> m) = &(procesador->mem[instruccion -> direccion]);
}
void index_indirectax (moss6502_t *procesador, instruccion_t * instruccion){
	uint16_t aux = (procesador->mem[procesador->pc++]+procesador->x) & MASK_1BYTE;
	instruccion->direccion = procesador ->mem [aux+1] <<8 | procesador->mem [aux];
	(instruccion -> m) = &(procesador->mem[instruccion -> direccion]);
}
void indirecta_indexy  (moss6502_t *procesador, instruccion_t * instruccion){
	uint16_t aux = (procesador->mem[procesador->pc++]);
	instruccion->direccion = (procesador ->mem [aux+1] <<8 | procesador->mem [aux])+procesador->y ;
	(instruccion -> m) = &(procesador->mem[instruccion -> direccion]);
}



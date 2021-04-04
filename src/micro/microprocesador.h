#ifndef TDA_H
#define TDA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_ROM 65536

// ESTRUCTURAS

typedef struct instruccion{
    uint8_t codigo;     // Opcode.
    short ciclos;       // Cantidad de ciclos de la instrucción.
    uint8_t *m;         // Puntero al operando (registro o memoria).
    uint16_t direccion; // Dirección del operando (si corresponde).
}instruccion_t;

typedef struct {
    uint8_t a, x, y;    // Registros A, X e Y.
    uint16_t pc;        // Program counter.
    uint8_t status;     // Registro de status.
    uint8_t sp;         // Stack pointer.
    uint8_t *mem;       // Memoria.
    long ciclos;        // Cantidad de ciclos totales de ejecución.
    const char *log;    // Nombre del archivo log a utilizar. Si no existe se creará uno con ese nombre
}moss6502_t;



moss6502_t *crear_micro ();
void setear_log (moss6502_t *micro,const char * r);
bool destruir_micro (moss6502_t* micro);
bool cargar_rom (moss6502_t* micro,const char* archivo);
void reiniciar_micro (moss6502_t* micro);
bool escribir_log (const char *r,moss6502_t *micro);


#endif

#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include <stdint.h>
#include <stdio.h>

#include "manejo_status.h"
#include "microprocesador.h"

#define MASK_B7 0X80
#define MASK_B6 0x40
#define MASK_B4 0x10
#define MASK_B5 0x20
#define MASK_BIT0 0x01
#define MASK_BYTE 0X00FF
#define MASK_BAJA 0xFF

void adc (moss6502_t * procesador, instruccion_t * instruccion);
void and (moss6502_t * procesador, instruccion_t * instruccion);
void asl (moss6502_t * procesador, instruccion_t * instruccion);
void bcc (moss6502_t * procesador, instruccion_t * instruccion);
void bcs (moss6502_t * procesador, instruccion_t * instruccion);
void beq (moss6502_t * procesador, instruccion_t * instruccion);
void bit (moss6502_t * procesador, instruccion_t * instruccion);
void bmi (moss6502_t * procesador, instruccion_t * instruccion);
void bne (moss6502_t * procesador, instruccion_t * instruccion);
void bpl (moss6502_t * procesador, instruccion_t * instruccion);
void brk (moss6502_t * procesador, instruccion_t * instruccion);
void bvc (moss6502_t * procesador, instruccion_t * instruccion);
void bvs (moss6502_t * procesador, instruccion_t * instruccion);
void clc (moss6502_t * procesador, instruccion_t * instruccion);
void cld (moss6502_t * procesador, instruccion_t * instruccion);
void cli (moss6502_t * procesador, instruccion_t * instruccion);
void clv (moss6502_t * procesador, instruccion_t * instruccion);
void cmp (moss6502_t * procesador, instruccion_t * instruccion);
void cpx (moss6502_t * procesador, instruccion_t * instruccion);
void cpy (moss6502_t * procesador, instruccion_t * instruccion);
void dec(moss6502_t * procesador, instruccion_t * instruccion);
void dex (moss6502_t * procesador, instruccion_t * instruccion);
void dey(moss6502_t * procesador, instruccion_t * instruccion);
void eor (moss6502_t * procesador, instruccion_t * instruccion);
void inc (moss6502_t * procesador, instruccion_t * instruccion);
void interrupcion (moss6502_t * procesador, instruccion_t * instruccion);
void inx (moss6502_t * procesador, instruccion_t * instruccion);
void iny (moss6502_t * procesador, instruccion_t * instruccion);
void jmp (moss6502_t * procesador, instruccion_t * instruccion);
void jsr (moss6502_t * procesador, instruccion_t * instruccion);
void lda (moss6502_t * procesador, instruccion_t * instruccion);
void ldx (moss6502_t * procesador, instruccion_t * instruccion);
void ldy (moss6502_t * procesador, instruccion_t * instruccion);
void lsr (moss6502_t * procesador, instruccion_t * instruccion);
void nop (moss6502_t * procesador, instruccion_t * instruccion);
void ora(moss6502_t * procesador, instruccion_t * instruccion);
void pha (moss6502_t * procesador, instruccion_t * instruccion);
void php (moss6502_t * procesador, instruccion_t * instruccion);
void pla (moss6502_t * procesador, instruccion_t * instruccion);
void plp (moss6502_t * procesador, instruccion_t * instruccion);
void rol (moss6502_t * procesador, instruccion_t * instruccion);
void ror (moss6502_t * procesador, instruccion_t * instruccion);
void rti (moss6502_t * procesador, instruccion_t * instruccion);
void rts (moss6502_t * procesador, instruccion_t * instruccion);
void sbc (moss6502_t * procesador, instruccion_t * instruccion);
void sec(moss6502_t * procesador, instruccion_t * instruccion);
void sed(moss6502_t * procesador, instruccion_t * instruccion);
void sei(moss6502_t * procesador, instruccion_t * instruccion);
void sta (moss6502_t * procesador, instruccion_t * instruccion);
void stx (moss6502_t * procesador, instruccion_t * instruccion);
void sty (moss6502_t * procesador, instruccion_t * instruccion);
void tax (moss6502_t * procesador, instruccion_t * instruccion);
void tay (moss6502_t * procesador, instruccion_t * instruccion);
void tsx (moss6502_t * procesador, instruccion_t * instruccion);
void txa (moss6502_t * procesador, instruccion_t * instruccion);
void txs (moss6502_t * procesador, instruccion_t * instruccion);
void tya (moss6502_t * procesador, instruccion_t * instruccion);


#endif

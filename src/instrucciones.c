#include "instrucciones.h"


// FUNCIONES INSTRUCCIONES

void adc (moss6502_t * procesador, instruccion_t * instruccion){
    uint16_t aux =  procesador -> a + *instruccion -> m + get_status (&procesador->status,CARRY);
    set_carry (&procesador->status,aux);
    set_zero (&procesador->status,aux&MASK_BYTE);
    set_negative ((&procesador->status),aux);
    set_overflow(&procesador->status, procesador->a,*instruccion->m,aux);
    procesador -> a = aux;
}

void and (moss6502_t * procesador, instruccion_t * instruccion){
    procesador -> a &= *instruccion -> m;
    set_zero (&procesador->status,procesador -> a);
    set_negative ((&procesador->status),procesador -> a);
}

void asl (moss6502_t * procesador, instruccion_t * instruccion){
    uint16_t aux = (*instruccion  -> m) << 1;
    *instruccion  -> m = aux;
    set_carry (&procesador->status,aux);
    set_zero (&procesador->status,*instruccion -> m);
    set_negative ((&procesador->status),*instruccion -> m);
}

void bcc (moss6502_t * procesador, instruccion_t * instruccion){
    if (!get_status (&procesador->status,CARRY))
        procesador->pc = instruccion->direccion;
}

void bcs (moss6502_t * procesador, instruccion_t * instruccion){
    if (get_status (&procesador->status,CARRY))
     	procesador->pc = instruccion->direccion;
}

void beq (moss6502_t * procesador, instruccion_t * instruccion){
    if (get_status (&procesador->status,ZERO))
    	procesador->pc = instruccion->direccion;
}

void bit (moss6502_t * procesador, instruccion_t * instruccion){ 
    set_zero(&procesador->status,procesador->a & *instruccion->m);
    set_status(&procesador->status, NEGATIVE, MASK_B7 & *instruccion->m);
    set_status(&procesador->status, OVERFLOW, MASK_B6 & *instruccion->m);
}
void bmi (moss6502_t * procesador, instruccion_t * instruccion){
    if (get_status (&procesador->status,NEGATIVE))
        procesador->pc = instruccion->direccion;
}
void bne (moss6502_t * procesador, instruccion_t * instruccion){
    if (!get_status (&procesador->status,ZERO)){   
        procesador->pc = instruccion->direccion;}
}
void bpl (moss6502_t * procesador, instruccion_t * instruccion){
    if (!get_status (&procesador->status,NEGATIVE))
        procesador->pc = instruccion->direccion;
}

void brk (moss6502_t * procesador, instruccion_t * instruccion){ 
    procesador->mem[(0x01 <<8) | procesador->sp] = (procesador->pc+1) >>8;
    procesador->sp--;
    procesador->mem [(0x01 <<8) | procesador->sp] = (procesador->pc+1) & MASK_BAJA;
    procesador->sp--;
    procesador->mem[(0x01 <<8) | procesador->sp] = procesador->status | MASK_B4 | MASK_B5;
    set_status (&procesador->status,INTERRUPT_DISABLE,true);
    procesador->sp--;
    procesador->pc = ((procesador->mem[0xFFFF])<<8) | procesador->mem[0xFFFE];

}
void bvc (moss6502_t * procesador, instruccion_t * instruccion){
    if (!get_status (&procesador->status,OVERFLOW))
        procesador->pc = instruccion->direccion;
}   

void bvs (moss6502_t * procesador, instruccion_t * instruccion){
    if (get_status (&procesador->status,OVERFLOW))
        procesador->pc = instruccion->direccion;
}
void clc (moss6502_t * procesador, instruccion_t * instruccion){
    set_status (&procesador->status,CARRY,false);
}
void cld (moss6502_t * procesador, instruccion_t * instruccion){
    set_status (&procesador->status,DECIMAL,false);
}
void cli (moss6502_t * procesador, instruccion_t * instruccion){
    set_status (&procesador->status,INTERRUPT_DISABLE,false);
}
void clv (moss6502_t * procesador, instruccion_t * instruccion){
    set_status (&procesador->status,OVERFLOW,false);
}

void cmp (moss6502_t * procesador, instruccion_t * instruccion){
    set_status (&procesador->status,CARRY,procesador->a >= *instruccion->m);
    set_status (&procesador->status,ZERO,procesador->a == *instruccion->m);
    set_status ((&procesador->status),NEGATIVE,procesador->a < *instruccion->m);
}

void cpx (moss6502_t * procesador, instruccion_t * instruccion){
    set_status (&procesador->status,CARRY,procesador->x >= *instruccion->m);
    set_status (&procesador->status,ZERO,procesador->x == *instruccion->m);
    set_status ((&procesador->status),NEGATIVE,procesador->x < *instruccion->m);
}
void cpy (moss6502_t * procesador, instruccion_t * instruccion){
    set_status (&procesador->status,CARRY,procesador->y >= *instruccion->m);
    set_status (&procesador->status,ZERO,procesador->y == *instruccion->m);
    set_status ((&procesador->status),NEGATIVE,procesador->y < *instruccion->m);
}

void decrementar_aux(moss6502_t * procesador,uint8_t *aux){
	(*aux) --;
	set_zero (&procesador->status,*aux);
    set_negative (&procesador->status,*aux); 
}
void dec(moss6502_t * procesador, instruccion_t * instruccion){
	decrementar_aux (procesador,instruccion -> m);
}
void dex (moss6502_t * procesador, instruccion_t * instruccion){
	decrementar_aux (procesador,&procesador -> x);
}
void dey(moss6502_t * procesador, instruccion_t * instruccion){ 
    decrementar_aux (procesador,&procesador -> y);
}

void eor (moss6502_t * procesador, instruccion_t * instruccion){
    procesador -> a ^= *instruccion -> m;
    set_zero (&procesador->status,procesador -> a);
    set_negative ((&procesador->status),procesador -> a);
}
void incrementar_aux(moss6502_t * procesador,uint8_t *aux){
    (*aux)++;
    set_zero (&procesador->status,*aux);
    set_negative ((&procesador->status),*aux); 
}
void inc (moss6502_t * procesador, instruccion_t * instruccion){
    incrementar_aux (procesador,instruccion -> m);
}
void interrupcion (moss6502_t * procesador, instruccion_t * instruccion){
	procesador->pc = procesador->mem[0xFFFB]<<8 | procesador ->mem[0xFFFA];
}
void inx (moss6502_t * procesador, instruccion_t * instruccion){
    incrementar_aux (procesador,&procesador->x);
}
void iny (moss6502_t * procesador, instruccion_t * instruccion){
    incrementar_aux (procesador,&procesador->y);
}
void jmp (moss6502_t * procesador, instruccion_t * instruccion){
    procesador -> pc = (instruccion -> direccion);
}

void jsr (moss6502_t * procesador, instruccion_t * instruccion){ 
    procesador->mem [(0x01 <<8) | procesador->sp]=(procesador->pc -1)>>8;
    procesador->sp--;
    procesador->mem [(0x01 <<8) | procesador->sp]=(procesador->pc -1) & MASK_BAJA;
    procesador->sp--;
    procesador -> pc = (instruccion -> direccion);
}

void load_auxiliar (instruccion_t * instruccion,moss6502_t * procesador, uint8_t * aux){
	*aux = *(instruccion -> m);
	set_zero (&procesador->status,*aux);
    set_negative ((&procesador->status),*aux);
}
void lda (moss6502_t * procesador, instruccion_t * instruccion){
    load_auxiliar (instruccion, procesador,&procesador -> a);
}
void ldx (moss6502_t * procesador, instruccion_t * instruccion){
    load_auxiliar (instruccion, procesador,&procesador -> x);
}
void ldy (moss6502_t * procesador, instruccion_t * instruccion){
	load_auxiliar (instruccion, procesador,&procesador -> y);
}
void lsr (moss6502_t * procesador, instruccion_t * instruccion){
    set_status (&procesador->status,CARRY,*instruccion->m & MASK_LSB);
    uint16_t aux = *instruccion->m >> 1;
    *instruccion  -> m = aux;
    set_zero (&procesador->status,*instruccion -> m);
    set_negative (&procesador->status,*instruccion -> m);
}
void nop (moss6502_t * procesador, instruccion_t * instruccion){
}
void ora(moss6502_t * procesador, instruccion_t * instruccion){
    procesador->a |= *instruccion->m;
    set_zero(&procesador->status,procesador->a);
    set_negative(&procesador->status, procesador->a);
}
void pha (moss6502_t * procesador, instruccion_t * instruccion){
    procesador->mem[(0x01 <<8) | procesador->sp]=procesador->a;
    procesador->sp--;
}
void php (moss6502_t * procesador, instruccion_t * instruccion){
    procesador->mem[(0x01 <<8) | procesador->sp]=procesador->status | MASK_B4 | MASK_B5;
    procesador->sp--;
}
void pla (moss6502_t * procesador, instruccion_t * instruccion){	
    procesador->a=procesador->mem[((0x01 <<8) | procesador->sp)+1];
    procesador->sp++;
    set_zero(&procesador->status,procesador->a);
    set_negative(&procesador->status, procesador->a);
}
void plp (moss6502_t * procesador, instruccion_t * instruccion){
	if (procesador->sp!=0xff){
   		procesador->status=(procesador->mem[((0x01 <<8) | procesador->sp)+1]) & (~MASK_B4) & (~MASK_B5);	
   	 	procesador->sp++;
   	 }
   	 else if(procesador->sp==0xff) {
   	 	procesador->sp=0x00;
   	 	procesador->status=(procesador->mem[((0x01 <<8) | procesador->sp)]) & (~MASK_B4) & (~MASK_B5);
   	 } 
   	
}
void rol (moss6502_t * procesador, instruccion_t * instruccion){
    rotate_left(&procesador->status,instruccion->m);
    set_negative (&procesador->status,*instruccion->m);
    set_zero (&procesador->status,*instruccion->m);
}
void ror (moss6502_t * procesador, instruccion_t * instruccion){
    rotate_right(&procesador->status,instruccion->m);
    set_negative (&procesador->status,*instruccion->m);
    set_zero (&procesador->status,*instruccion->m);
}
void rti (moss6502_t * procesador, instruccion_t * instruccion){
    procesador->status=procesador->mem[((0x01 <<8) | procesador->sp)+1] & (~MASK_B4) & (~MASK_B5);
    procesador->sp++;
    procesador->pc=(procesador->mem[((0x01 <<8) | procesador->sp)+1]) | (procesador->mem[((0x01 <<8) | procesador->sp)+2]<<8);
    procesador->sp+=2;
    set_status (&procesador->status,BREAK, false);
}

void rts (moss6502_t * procesador, instruccion_t * instruccion){
    procesador->pc=(procesador->mem[((0x01 <<8) | procesador->sp)+1]+1) | (procesador->mem[((0x01 <<8) | procesador->sp)+2]<<8);
    procesador->sp+=2;
}

void sbc (moss6502_t * procesador, instruccion_t * instruccion){
    uint8_t m_negada = ~(*instruccion->m);
    uint16_t aux =  procesador -> a + m_negada + get_status (&procesador->status,CARRY);
    set_carry (&procesador->status,aux);
    set_zero (&procesador->status,aux&MASK_BYTE);
    set_negative ((&procesador->status),aux);
    set_overflow(&procesador->status, procesador->a,m_negada,aux);
    procesador -> a = aux;
}


void sec(moss6502_t * procesador, instruccion_t * instruccion){
    set_status(&procesador->status,CARRY,true);
}
void sed(moss6502_t * procesador, instruccion_t * instruccion){
    set_status(&procesador->status,DECIMAL,true);
}
void sei(moss6502_t * procesador, instruccion_t * instruccion){
    set_status(&procesador->status,INTERRUPT_DISABLE,true);
}

void sta (moss6502_t * procesador, instruccion_t * instruccion){
    *instruccion -> m = procesador -> a;
}

void stx (moss6502_t * procesador, instruccion_t * instruccion){
    *instruccion -> m = procesador -> x;
}

void sty (moss6502_t * procesador, instruccion_t * instruccion){
    *instruccion -> m = procesador -> y;
}

void tax (moss6502_t * procesador, instruccion_t * instruccion){
    procesador->x=procesador->a;
    set_zero(&procesador->status,procesador->x);
    set_negative (&procesador->status,procesador->x);
}

void tay (moss6502_t * procesador, instruccion_t * instruccion){
    procesador->y=procesador->a;
    set_zero(&procesador->status,procesador->y);
    set_negative (&procesador->status,procesador->y);
}

void tsx (moss6502_t * procesador, instruccion_t * instruccion){
    procesador->x=procesador->sp;
    set_zero(&procesador->status,procesador->x);
    set_negative (&procesador->status,procesador->x);
}
void txa (moss6502_t * procesador, instruccion_t * instruccion){
    procesador->a= procesador->x;
    set_zero(&procesador->status,procesador->a);
    set_negative (&procesador->status,procesador->a);
}
void txs (moss6502_t * procesador, instruccion_t * instruccion){
	procesador->sp= procesador->x;
}

void tya (moss6502_t * procesador, instruccion_t * instruccion){
    procesador->a= procesador->y;
    set_zero(&procesador->status,procesador->a);
    set_negative (&procesador->status,procesador->a);
}



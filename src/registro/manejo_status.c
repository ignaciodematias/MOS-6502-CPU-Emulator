#include "manejo_status.h"

// FUNCIONES DE MANEJO DE STATUS
bool get_status(uint8_t *reg, flag_t flag){
    return (*reg & flag);
}
void set_status(uint8_t *reg, flag_t flag, bool status){
    if (status)
        *reg |= flag;
    else 
        *reg &= ~flag;
}
void set_zero(uint8_t *reg, uint8_t res){
    set_status (reg, ZERO, !res);
}
void set_negative(uint8_t *reg, uint8_t res){
    set_status (reg,NEGATIVE,res & MASK_SIGNO);
}
void set_carry(uint8_t *reg, uint16_t res){
    set_status (reg, CARRY, res & MASK_CARRY); 
}
void set_overflow(uint8_t *reg, uint8_t a, uint8_t b, uint8_t res){

    set_status (reg, OVERFLOW,(a & MASK_SIGNO) == (b & MASK_SIGNO) && (res & MASK_SIGNO) != (a & MASK_SIGNO));
}
// FUNCIONES DE DESPLAZAMIENTO

void rotate_left(uint8_t *reg, uint8_t *x){
    
    uint8_t aux = *x & MASK_MSB;
    
    *x <<= SHIFT_ROTATE; //queda en 0 el bit menos significativo
    
    if (*reg & MASK_LSB)
        *x |= MASK_LSB; 
    
    set_status (reg,CARRY,aux);
} 


void rotate_right(uint8_t *reg, uint8_t *x){

    uint8_t aux = *reg & MASK_LSB;

    set_status (reg, CARRY,*x & MASK_LSB);
    
    *x >>= SHIFT_ROTATE;
    
    if (aux) //El else no es necesario, setea en 0 despues del shift (trabajando con unsigned)
        *x |= MASK_MSB; 
}

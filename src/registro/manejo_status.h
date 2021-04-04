#ifndef EJ3_H
#define EJ3_H

#include <stdint.h>
#include <stdbool.h>
#define MASK_CARRY 0x100
#define MASK_MSB 0x80
#define MASK_SIGNO 0X80
#define SHIFT_ROTATE 1
#define MASK_LSB 0x01

typedef enum  {
    CARRY = 0x01,
    ZERO = 0x02,
    INTERRUPT_DISABLE = 0x04,
    DECIMAL = 0x08,
    BREAK = 0x10,
    OVERFLOW = 0x40,
    NEGATIVE = 0x80} flag_t;


bool get_status(uint8_t *reg, flag_t flag);
void set_status(uint8_t *reg, flag_t flag, bool status);
void set_zero(uint8_t *reg, uint8_t res);
void set_negative(uint8_t *reg, uint8_t res);
void set_carry(uint8_t *reg, uint16_t res);
void set_overflow(uint8_t *reg, uint8_t a, uint8_t b, uint8_t res);
void rotate_left(uint8_t *reg, uint8_t *x);
void rotate_right(uint8_t *reg, uint8_t *x);

#endif

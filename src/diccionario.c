#include "diccionario.h"


// DICCIONARIO
struct diccio {
    short ciclo;
    operacion_t  operacion;
    direccionamiento_t  direccionamiento;
};



//Separado por tipo de instruccion
diccionario_t diccionario [] = {
    [0x69]={2,adc,inmediato},
    [0x65]={3,adc,paginacero},
    [0x75]={4,adc,paginax},
    [0x6D]={4,adc,absoluto},
    [0x7D]={4,adc,indexabsoluto},
    [0x79]={4,adc,indeyabsoluto},
    [0x61]={6,adc,index_indirectax},
    [0x71]={5,adc,indirecta_indexy},
    
    [0x29]={2,and,inmediato},
    [0x25]={3,and,paginacero},
    [0x35]={4,and,paginax},
    [0x2D]={4,and,absoluto},
    [0x3D]={4,and,indexabsoluto},
    [0x39]={4,and,indeyabsoluto},
    [0x21]={6,and,index_indirectax},
    [0x31]={5,and,indirecta_indexy},
    
    [0x0A]={2,asl,acumulador},
    [0x06]={5,asl,paginacero},
    [0x16]={6,asl,paginax},
    [0x0E]={6,asl,absoluto},
    [0x1E]={7,asl,indexabsoluto},
   
    [0x90]={2,bcc,relativo},
    
    [0xB0]={2,bcs,relativo},
    
    [0xF0]={2,beq,relativo},

    [0x24]={3,bit,paginacero},
    [0x2C]={4,bit,absoluto},
    
    [0x30]={2,bmi,relativo},
    
    [0xD0]={2,bne,relativo},
    
    [0x10]={2,bpl,relativo},
    
    [0x00]={7,brk,implicito},
    
    [0x50]={2,bvc,relativo},

    [0x70]={2,bvs,relativo},
    
    [0X18]={2,clc,implicito},

    [0xD8]={2,cld,implicito},
    
    [0x58]={2,cli,implicito},
    
    [0xB8]={2,clv,implicito},
    
    [0xC9]={2,cmp,inmediato},
    [0xC5]={3,cmp,paginacero},
    [0xD5]={4,cmp,paginax},
    [0xCD]={4,cmp,absoluto},
    [0xDD]={4,cmp,indexabsoluto},
    [0xD9]={4,cmp,indeyabsoluto},
    [0xC1]={6,cmp,index_indirectax},
    [0xD1]={5,cmp,indirecta_indexy},
    
    [0xE0]={2,cpx,inmediato},
    [0xE4]={3,cpx,paginacero},
    [0xEC]={4,cpx,absoluto},
    
    [0xC0]={2,cpy,inmediato},
    [0xC4]={3,cpy,paginacero},
    [0xCC]={4,cpy,absoluto},

    [0xC6]={5,dec,paginacero},
    [0xD6]={6,dec,paginax},
    [0XCE]={6,dec,absoluto},
    [0xDE]={7,dec,indexabsoluto},
    
    [0xCA]={2,dex,implicito},
    
    [0x88]={2,dey,implicito},
    

    [0x49]={2,eor,inmediato},
    [0x45]={3,eor,paginacero},
    [0x55]={4,eor,paginax},
    [0x4D]={4,eor,absoluto},
    [0x5D]={4,eor,indexabsoluto},
    [0x59]={4,eor,indeyabsoluto},
    [0x41]={6,eor,index_indirectax},
    [0x51]={5,eor,indirecta_indexy},
    

    [0xE6]={5,inc,paginacero},
    [0xF6]={6,inc,paginax},
    [0xEE]={6,inc,absoluto},
    [0xFE]={7,inc,indexabsoluto},
    
    [0xE8]={2,inx,implicito},

    [0xC8]={2,iny,implicito},
    
    [0x4C]={3,jmp,absoluto},
    [0x6C]={5,jmp,indirecta},

    [0x20]={6,jsr,absoluto},
    
    [0xA9]={2,lda,inmediato},
    [0xA5]={3,lda,paginacero},
    [0xB5]={4,lda,paginax},
    [0xAD]={4,lda,absoluto},
    [0xBD]={4,lda,indexabsoluto},
    [0xB9]={4,lda,indeyabsoluto},
    [0xA1]={6,lda,index_indirectax},
    [0xB1]={5,lda,indirecta_indexy},
    
    [0xA2]={2,ldx,inmediato},
    [0xA6]={3,ldx,paginacero},
    [0xB6]={4,ldx,paginay},
    [0xAE]={4,ldx,absoluto},
    [0xBE]={4,ldx,indeyabsoluto},
    
    [0xA0]={2,ldy,inmediato},
    [0xA4]={3,ldy,paginacero},
    [0xB4]={4,ldy,paginax},
    [0xAC]={4,ldy,absoluto},
    [0xBC]={4,ldy,indexabsoluto},
    

    [0x4A]={2,lsr,acumulador},
    [0x46]={5,lsr,paginacero},
    [0x56]={6,lsr,paginax},
    [0x4E]={6,lsr,absoluto},
    [0x5E]={7,lsr,indexabsoluto},

    [0xEA]={2,nop,implicito},

    [0x09]={2,ora,inmediato},
    [0x05]={3,ora,paginacero},
    [0x15]={4,ora,paginax},
    [0x0D]={4,ora,absoluto},
    [0x1D]={4,ora,indexabsoluto},
    [0x19]={4,ora,indeyabsoluto},
    [0x01]={6,ora,index_indirectax},
    [0x11]={5,ora,indirecta_indexy},

    [0x48]={3,pha,implicito},
    
    [0x08]={3,php,implicito},
    
    [0x68]={4,pla,implicito},
    
    [0x28]={4,plp,implicito},

    [0x2A]={2,rol,acumulador},
    [0x26]={5,rol,paginacero},
    [0x36]={6,rol,paginax},
    [0x2E]={6,rol,absoluto},
    [0x3E]={7,rol,indexabsoluto},
    
    [0x6A]={2,ror,acumulador},
    [0x66]={5,ror,paginacero},
    [0x76]={6,ror,paginax},
    [0x6E]={6,ror,absoluto},
    [0x7E]={7,ror,indexabsoluto},
    
    [0x40]={6,rti,implicito},

    [0x60]={6,rts,implicito},

    [0xE9]={2,sbc,inmediato},
    [0xE5]={3,sbc,paginacero},
    [0xF5]={4,sbc,paginax},
    [0xED]={4,sbc,absoluto},
    [0xFD]={4,sbc,indexabsoluto},
    [0xF9]={4,sbc,indeyabsoluto},
    [0xE1]={6,sbc,index_indirectax},
    [0xF1]={5,sbc,indirecta_indexy},

    [0x38]={2,sec,implicito},
    
    [0xF8]={2,sed,implicito},
    
    [0x78]={2,sei,implicito},
    
    [0x85]={3,sta,paginacero},
    [0x95]={4,sta,paginax},
    [0x8D]={4,sta,absoluto},
    [0x9D]={5,sta,indexabsoluto},
    [0x99]={5,sta,indeyabsoluto},
    [0x81]={6,sta,index_indirectax},
    [0x91]={6,sta,indirecta_indexy},
    
    [0x86]={3,stx,paginacero},
    [0x96]={4,stx,paginay},
    [0x8E]={4,stx,absoluto},
    
    [0x84]={3,sty,paginacero},
    [0x94]={4,sty,paginax},
    [0x8C]={4,sty,absoluto},
    
    [0xAA]={2,tax,implicito},
    
    [0xA8]={2,tay,implicito},

    [0xBA]={2,tsx,implicito},
    [0x8A]={2,txa,implicito},
    [0x9A]={2,txs,implicito},

    [0x98]={2,tya,implicito},
};

void ejecutar_instruccion (moss6502_t* micro){
     if (micro->log!=NULL)
        escribir_log(micro->log,micro);
    uint8_t cod = (micro-> mem[micro->pc++]);
    instruccion_t instruccion = {
        .codigo = cod,
        .ciclos = diccionario [cod].ciclo
    };
    diccionario [cod].direccionamiento(micro, &instruccion);
    diccionario [cod].operacion(micro,&instruccion);
    micro -> ciclos += instruccion . ciclos;
}

#include "microprocesador.h"

//TDA

moss6502_t *crear_micro (){
    moss6502_t *micro = malloc (sizeof (moss6502_t));
    if (micro==NULL){
        fprintf (stderr,"Error de memoria\n");
        return NULL;
    }
    micro->sp= 0xFF;
    micro->mem=NULL;
    micro->a=0;
    micro->x=0;
    micro->y=0;
    micro->pc=0;
    micro->log=NULL;
    micro->status=0;

    return micro;
}

void setear_log (moss6502_t *micro,const char * r){
	micro->log=r;
} 

bool destruir_micro (moss6502_t* micro){
    free (micro->mem);
    free (micro);
    return true;
}

bool cargar_rom (moss6502_t* micro,const char* archivo){
    FILE *fi = fopen (archivo,"rb");
    if (fi==NULL ){
        fprintf(stderr,"Error: memoria ROM\n");
        return false;
    }
    
    micro->mem = malloc (MAX_ROM);

    if (micro->mem==NULL){
        fprintf(stderr, "Error memoria ROM\n");
        return false;
    }

    if (fread (micro->mem,sizeof(uint8_t),MAX_ROM,fi)!=MAX_ROM){
    	fprintf(stderr, "Error lectura\n");
    	return false;
    }

    micro->pc= micro->mem[0xFFFD]<<8 | micro->mem [0xFFFC];
    fclose (fi);
	return true;
}

void reiniciar_micro (moss6502_t* micro){
    micro->a=micro->x=micro->y=micro->pc=0;
    micro->sp= 0xFF;
    micro->mem = NULL;
    micro->log=NULL;
    micro->status=0;
}

bool escribir_log (const char *r,moss6502_t *micro){
    FILE *f = fopen (r,"a");
    if (f==NULL){
        fprintf(stderr, "Error archivo log\n");
        return false;
    }

    fprintf(f, "%04x %02x %02x %02x %02x %02x\n",micro->pc,micro->a,micro->x,micro->y,micro->status,micro->sp);
    
    fclose (f);
    return true;
}


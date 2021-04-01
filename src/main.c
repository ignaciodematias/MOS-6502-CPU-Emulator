#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "microprocesador.h"
#include "diccionario.h"

#define TAM_MEM 65536


int main (int argc, char *argv []){
 
    if (argc!=4 && argc!=6 && argc!=2){
        fprintf(stderr, "MAL USADO CLA\nNOTA: No se puede usar -halt y -ciclos al mismo tiempo\n");
        return 1;
    }
    moss6502_t *micro = crear_micro();
    if (micro==NULL){
        fprintf(stderr, "ERROR CREAR MICRO\n");
        return 1;
    }
   
    if(!cargar_rom(micro,argv[1])){
        fprintf(stderr, "ERROR CARGAR ROM\n");
        free (micro);
        return 1;
    }

    uint16_t instruccion=0;
    long ciclos=0;
    bool ciclo = false;
    bool halt=false;
    
    for(size_t i =0;i<argc;i++){
        if (!strcmp(argv[i],"-log")){
            char *r=argv[i+1];
            setear_log (micro,r);
            i++;
        }
        else if (!strcmp(argv[i],"-ciclos")){
            ciclos=atoi(argv[i+1]);
            ciclo=true;
            i++;
        }
        else if(!strcmp(argv[i],"-halt")){
            instruccion=atoi(argv[i+1]);
            halt=true;
            i++;
        }
    }
    if (halt){ //en decimal
    	while (1){
    		ejecutar_instruccion(micro);
    		if (micro->pc==instruccion){
    			ejecutar_instruccion (micro);
    			destruir_micro (micro);
    			return 0;
    		}
    	}
    }
    if(ciclo){
        while(micro->ciclos <= ciclos){
            ejecutar_instruccion(micro);
        }
    }
    else{        
        printf("Ejecuta hasta que haya una interrupción del usuario\n");//no se pasaron flags
        while(1){ 
            ejecutar_instruccion(micro);
        }
    }

    destruir_micro (micro);
    
    return 0;
}


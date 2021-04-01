PROGRAM=tp1
CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -g
LDFLAGS=-lm

all: $(PROGRAM)

$(PROGRAM):  main.o manejo_status.o microprocesador.o diccionario.o instrucciones.o direccionamientos.o
	$(CC) $(CFLAGS) $(LDFLAGS)  main.o manejo_status.o microprocesador.o  instrucciones.o direccionamientos.o diccionario.o  -o $(PROGRAM)


main.o: main.c microprocesador.h diccionario.h 
	$(CC) $(CFLAGS) -c main.c

manejo_status.o: manejo_status.c manejo_status.h
	$(CC) $(CFLAGS) -c manejo_status.c

microprocesador.o: microprocesador.c microprocesador.h 
	$(CC) $(CFLAGS) -c microprocesador.c

diccionario.o: diccionario.c diccionario.h microprocesador.h instrucciones.h direccionamientos.h
	$(CC) $(CFLAGS) -c diccionario.c 

instrucciones.o: instrucciones.c instrucciones.h manejo_status.h microprocesador.h 
	$(CC) $(CFLAGS) -c instrucciones.c


direccionamientos.o: direccionamientos.c direccionamientos.h manejo_status.h microprocesador.h 
	$(CC) $(CFLAGS) -c direccionamientos.c

clean:
	rm -vf *.o $(PROGRAM)
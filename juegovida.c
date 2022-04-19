

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "juegovida.h"

/* Tamaño del mundo fijo */
#define ANCHOMUNDO 39
#define ALTOMUNDO 20

/* Represenaciones de caracter para los estados de las celdas */
#define CAR_VIVO '#'
#define CAR_MUERTO '~'

/* Estados actuales del mundo */
static int mundo[ANCHOMUNDO][ALTOMUNDO];

/* Estados de celdas de la siguiente generación */
static int siguientesestados[ANCHOMUNDO][ALTOMUNDO];

/* Funcion a escribir para la Parte B del examen */
void inicializa_mundo_desde_archivo(const char * nombrearchivo) {
	/* PARA HACER: lee el estado del mundo desde un archivo con
	   el nombre "nombrearchivo". Asume que el archivo existe, es legible, y que
	   el caracter i'esimo de la linea j'esima (indexadas desde cero) describe
	   mundo[i][j] de acuerdo a los caracteres CAR_VIVO y
	   CAR_MUERTO

	   Asume que una linea no contiene más de 256 caracteres
	   (incluyendo el salto de linea). Si una linea no contiene caracteres
	   ANCHOMUNDO, las celdas que falten se presumen en estado MUERTO.
	   Igualmente, si el archivo no contiene lineas ALTOMUNDO,
	   las líneas sobrantes se presumen muertas.

	   Para los errores, imprime un mensaje de error útil y llama abort().

	   También es necesario igualar la siguiente generación a MUERTO
	 */
}

void salva_mundo_a_archivo(const char * nombrearchivo) {
	/* PARA HACER: escribe el estado del mundo en un archivo con
	   nombre "nombrearchivo". Asume que el archivo se puede crear, o si
	   el archivo existe, reescribe el archivo. El iésimo caracter
	   de la iésima linea (indexadas desde cero) describe mundo[i][j]
	   usando los caracteres CAR_VIVO y CAR_MUERTO

	   Este archivo debe poderse leer usando la función
	   inicializa_mundo_desde_archivo(filename) que esta arriba; puede usarse
	   la función para continuar un juego después.
	 */
}
/* No deberías tener necesidad de editar nada bajo esta línea */

/* iguala el mundo a un patrón precodificado, e iguala
   todas las celdas en la siguiente generación a MUERTO */
void inicializa_mundo(void) {
	int i, j;

	for (i = 0; i < ANCHOMUNDO; i++)
		for (j = 0; j < ALTOMUNDO; j++)
			mundo[i][j] = siguientesestados[i][j] = MUERTO;
	/* patrón "nave" */
	mundo[1][2] = VIVO;
	mundo[3][1] = VIVO;
	mundo[3][2] = VIVO;
	mundo[3][3] = VIVO;
	mundo[2][3] = VIVO;
}

int obtiene_ancho_mundo(void) {
	return ANCHOMUNDO;
}

int obtiene_alto_mundo(void) {
	return ALTOMUNDO;
}

int obtiene_estado_celda(int x, int y) {
	if (x < 0 || x >= ANCHOMUNDO || y < 0 || y >= ALTOMUNDO)
		return MUERTO;
	return mundo[x][y];
}

void configura_estado_celda(int x, int y, int estado) {
	if (x < 0 || x >= ANCHOMUNDO || y < 0 || y >= ALTOMUNDO) {
		fprintf(stderr,"Error: las coordenadas (%d,%d) son invalidas.\n", x, y);
		abort();
	}
	siguientesestados[x][y] = estado;
}

void finalizar_evolucion(void) {
	int x, y;
	for (x = 0; x < ANCHOMUNDO; x++) {
		for (y = 0; y < ALTOMUNDO; y++) {
			mundo[x][y] = siguientesestados[x][y];
			siguientesestados[x][y] = MUERTO;
		}
	}
}

void salida_mundo(void) {
	char mundostr[2*ANCHOMUNDO+2];
	int i, j;

	mundostr[2*ANCHOMUNDO+1] = '\0';
	mundostr[0] = '+';
	for (i = 1; i < 2*ANCHOMUNDO; i++)
		mundostr[i] = '-';
	mundostr[2*ANCHOMUNDO] = '+';
	puts(mundostr);
	for (i = 0; i <= 2*ANCHOMUNDO; i+=2)
		mundostr[i] = '|';
	for (i = 0; i < ALTOMUNDO; i++) {
		for (j = 0; j < ANCHOMUNDO; j++)
			mundostr[2*j+1] = mundo[j][i] == VIVO ? CAR_VIVO : CAR_MUERTO;
		puts(mundostr);
	}
	mundostr[0] = '+';
	for (i = 1; i < 2*ANCHOMUNDO; i++)
		mundostr[i] = '-';
	mundostr[2*ANCHOMUNDO] = '+';
	puts(mundostr);
}

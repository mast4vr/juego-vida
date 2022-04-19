



#ifndef JUEGOVIDA_H_
#define JUEGOVIDA_H_

/* state constants */
#define MUERTO 0
#define VIVO 1

/* Inicializaci�n del mundo -- configura al mundo, todas las celdas
   Se inicializan a MUERTO O VIVO; todas las celdas de la siguiente
   generaci�n se inicializan a MUERTO */
void inicializa_mundo(void);

/* Retorna el ancho (x) y alto (y) del mundo */
int obtiene_ancho_mundo(void);
int obtiene_alto_mundo(void);

/* Retorna el estado (MUERTO o VIVO) de la celda en (x,y);
   Las coordenadas van de  x = 0,...,ancho-1 y
   y = 0,...,alto-1; retorna MUERTO para celdas fuera de
   este intervalo */
int obtiene_estado_celda(int x, int y);

/* Configura el estado (MUERTO o VIVO) para la celda en (x, y) en
   la siguiente generaci�n; el intervalo de coordenadas es el mismo que en
   obtiene_estado_celda(); llama a abort() si se especifican coordenadas
   inv�lidas */
void configura_estado_celda(int x, int y, int estado);

/* actualiza el estado del mundo a la siguiente generaci�n e
   iguala los estados de la siguiente generaci�n a MUERTO */
void finalizar_evolucion(void);

/* Imprime el estado actual del mundo a la consola */
void salida_mundo(void);

/* funciones a programarse para la Parte B del examen */
void inicializa_mundo_desde_archivo(const char * nombrearchivo);
void salva_mundo_a_archivo(const char * nombrearchivo);

#endif /* JUEGOVIDA_H_ */

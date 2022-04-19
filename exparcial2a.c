
/* Archivo de cabecera juegovida.h tiene las funciones que se utilizaran en este programa. */
#include "juegovida.h"



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUM_GENERACIONES 50 //numero de generaciones que va contener el programa


/* Esta funcion  fija el estado de todas
   los bloques en la siguiente generacion y llama a la funcion
   terminar_evolucion() para actualizar el estado actual
   del mundo a la siguiente generacion */
void siguiente_generacion(void); //prototipo funcion siguiente_generacion

int obtener_siguiente_estado(int x, int y); //prototipo de funcion obtener_siguiente_estado

//calcula el numero de vecinos vivos para la celda (x,y)

int num_vecinos(int x, int y); //prototipo de funcion num_vecinos

int main(void)  //funcion principal
{
	int cont;
	inicializa_mundo();  //lamada a la funcion inicializa_mundo
	
	for (cont=0;cont< NUM_GENERACIONES;cont++) //el ciclo for permite que el juego se ejecute 50 veces y realizando los prov¿cesos que estan en dicho bucle
	{
		siguiente_generacion(); //llamada de funcion a siguiente generacion devuelve el estado del mundo cada vez que se complete un ciclo
		
		salida_mundo();
	}
	salida_mundo();
	return 0;
}

void siguiente_generacion(void) {
	
	for (int x = 0; x < obtiene_ancho_mundo(); x++){
		for (int y = 0; y < obtiene_alto_mundo(); y++){
			configura_estado_celda(x,y,obtener_siguiente_estado(x,y));		
		}	
	}
	finalizar_evolucion(); //finaliza la evolucion o este ciclo
}



int obtener_siguiente_estado(int x, int y) {

	int estado = num_vecinos(x,y); //hace una igualacion variable entero a la funcion
	
	if(obtiene_estado_celda(x,y))
	{
	switch(estado){ //estructura switch anidada 
      case 2:
      return VIVO;
       break;
        case 3:
         return VIVO;
             break;	
             }
		return MUERTO; //devuelve estado muerto
	} 
	else{
		
	switch(estado){  //estructura switch anidada al else 
      case 3:
      return VIVO;
       break;
        case 6:
         return VIVO;
             break;	
             }
		return MUERTO;
	}

}


int num_vecinos(int x, int y) { //parametros x y y que pasan a esta funcion

	int v_viv = 0; //referencia a los vecinos independientemente del estado en el cual se encuentren
		int  a;
    	int  b;
    
   for(a=x-1;a<=x+1;a++)
   {                   //estas estructura for anidadas simulan a la matriz y van analizando celda por celda para contar los vecinos
		for(int b=y-1;b<=y+1;b++)
		{
			if((a!=x) || (b!=y))
			{                   
				if(obtiene_estado_celda(a,b))
				{
					v_viv++;
				}
		     	}
	    	}
	}
	
	
	
	return v_viv;					
}

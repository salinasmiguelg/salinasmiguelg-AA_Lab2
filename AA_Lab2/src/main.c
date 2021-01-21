#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"../incl/estructuras.h"
#include"../incl/archivo.h"
#include"../incl/goloso.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Maximiliano Araya Poblete
// 20.467.583-K
// Miguel Salinas González.
// 20.215.515-4
// Labotario II "Algoritmo Goloso" 
// ALGORITMOS Y AVANZADOS
// 19-1-2021
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



// CONSIDERACIONES:
// Los basurales (centros de acopio) que representan en una Struct que contiene su distancia al centro  y las toneladas de basura que contiene, para generar las combinaciones 
// se crea una struct "movimiento" que contiene el basural del cual se movera la basura (inicial) y el basural al que se lleva (final) ademas 
// se agrega el costo de este traslado (este costo no tiene agregada la subencion del gobierno). 
// En cada iteracion se generan las combinaciones de los basurales, se escoge aquella de menor costo, se lleva a cabo el movimiento de  
// la basura y se actualizan los basurales, luego estas iteraciones se repiten hasta que el numero de basurales con basura se reduzca al numero 
// solicitado (numero de incineradores), los movimientos que se llevan a cabo se guardan en una lista de movimientos "salida".
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




int main(int argc, char *argv[]){
	//////////////tomar tiempo 
	clock_t tiempo_inicio, tiempo_final;
    double segundos;
    tiempo_inicio = clock();
    //////////////////////////

	if (argc!=2){
    	printf("\nEntrada invalida.\n");
    	printf("La entrada debe tener el siguente formato:\n");
    	printf("--->   ejemplo.exe nombreArchivo.txt\n");
    	return 0;
    }

	int largo;//cantidad de basurales
	int in; // cantidad incineradores
	int subsidio;



	//crea arreglo de basurales
	basural *b = lectura(argv[1],&largo,&in,&subsidio);

	
	goloso(b,largo,in,subsidio); // n^3
	
	
	free(b);

	//////////////////////mostrar tiempo.
	tiempo_final = clock();
    segundos = (double)(tiempo_final - tiempo_inicio);
    // printf("%f",segundos);
    ////////////////////////////////////
	printf("\nEl algoritmo se ha ejecutado con exito, favor revisar el archivo de salida ;)\n");
	return 0;
}
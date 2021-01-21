#ifndef ARCHIVO_H
#define ARCHIVO_H
#include"estructuras.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// OBJETIVO: Lee un archivo de entrada txt, para así retornar con un arreglo de basurales con la distancia y su cantidad de basura en toneladas.
// ENTRADAS: Entero por referencia donde se guardan la cantidad de basurales totales, entero por referencia donde se guardan la cantidad de incineradores totales y entero por referencia donde se guardan la cantidad del subsidio.
// SALIDA: Un arreglo con los basurales correspondientes y su información.
basural* lectura(char* nombre,int* basurales, int* incineradores, int* subsidio);

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// OBJETIVO: Ayudar en la función de debug del código, mostrando por pantalla el estado de los basurales en cuestión.
// ENTRADAS: Un arreglo de basurales, el largo de este arreglo.
// SALIDA: Muestra por pantalla el estado de los basurales.
void printCurrent(basural* b, int largo);

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// OBJETIVO: Escribir un archivo con el estado final después de ejecutar el algoritmo.
// ENTRADAS: Un arreglo de movimientos con la salida final del algoritmo, un arreglo de basurales con sus estados finales, la cantidad de basurales, la cantidad de incineradores y el valor del subsidio.
// SALIDA: Genera un archivo salida.out que contiene los estados finales posterior a ejecutar el algoritmo.
void escribirSalida(movimiento* salida,basural* basurales, int largo, int in, int subsidio);
#endif
#ifndef GOLOSO_H
#define GOLOSO_H
#include"estructuras.h"
#include"archivo.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// OBJETIVO: Crear un nuevo dato con la estructura de movimiento.
// ENTRADAS: Valor entero respectivo al inicio, valor entero respectivo al final y valor entero respectivo al coste del transporte de inicio a final.
// SALIDA: Un dato con un movimiento nuevo.
movimiento nuevoMov(int inicial, int final, int costo);

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// OBJETIVO: Determinar el movimiento de menor costo dentro de un arreglo.
// ENTRADAS: Un arreglo m con los movimientos realizados y el largo del movimiento en cuestión.
// SALIDA: 
movimiento baratisimo(movimiento * m, int largo);

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// OBJETIVO: Para cierta lista de basurales saca todas las combinaciones y retorna las menores.
// ENTRADAS: Un arreglo de basurales, el largo del arreglo, la cantidad de basurales movidos, un arreglo de movimientos con los estados de salida.
// SALIDA: Un arreglo de movimiento con las menores combinaciones.
movimiento * menores(basural * b, int largo, int movidos, movimiento* salida);

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// OBJETIVO: Recibe un movimiento y los basurales, lleva a cabo el movimiento, ósea Mueve la basura.
// ENTRADAS: Un arreglo de basurales b, un movimiento en concreto m y el largo del arreglo.
// SALIDA: Retorna un arreglo con los basurales actualizados.
basural * tomarMovimiento(basural *b, movimiento m, int largo);

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// OBJETIVO: Divide en subproblemas, obteniendo la opción óptima para cada iteración.
// ENTRADAS: Un arreglo de basurales, el largo de éste, ósea la cantidad total de basurales, la cantidad de incineradores y el valor numérico del subsidio.
// SALIDA: Dentro se utiliza la escritura de archivo, que genera un archivo txt de salida con los datos finales junto con los movimientos.
void goloso(basural * b,int largo, int in, int subsidio);

#endif
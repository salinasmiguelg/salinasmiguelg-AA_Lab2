#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct centroDeAcopio{
    int distancia; // se almacena la distancia asociada al basural.
    int cantidadBasura; // si es 0 se considera que ya se movio la basura de ahí.
}basural;

typedef struct trasladoACentroAcopio{
    int inicial; // donde se inicia el movimiento.
    int final; // donde finaliza el movimiento.
    int costo; // el costo asociado a realizar el movimiento.
}movimiento;
#endif
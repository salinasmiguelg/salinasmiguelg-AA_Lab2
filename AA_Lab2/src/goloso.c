#include<stdio.h>
#include<stdlib.h>
#include"../incl/archivo.h"
#include"../incl/goloso.h"

movimiento nuevoMov(int inicial, int final, int costo){
	movimiento nuevo;
	nuevo.inicial=inicial;
	nuevo.final=final;
	nuevo.costo=costo;
	return nuevo;
}

movimiento baratisimo(movimiento * m, int largo){
	movimiento nuevo;
	nuevo=m[0];
	for (int i = 1; i < largo; ++i) // n
	{
		if (nuevo.costo>=m[i].costo)
		{
			nuevo=m[i];
		}
	}
	return nuevo;
}

movimiento * menores(basural * b, int largo, int movidos, movimiento* salida){
	int iter=0; //iterador grande para basural actual
	int otroIteradorMas=0;
	int asig;   //iterador menor 
	int cal;    // auxiliar para calculos

	movimiento * aux=(movimiento*)malloc(sizeof(movimiento)*(largo-movidos-1)); //arreglo de movimientos aux, se usa para cada basural
	movimiento * menor=(movimiento*)malloc(sizeof(movimiento)*(largo-movidos)); //arreglo de movimientos guarda el mas barato de cada basural

	while(iter<largo){ // n
		asig=0; // se reinicia en 0
		if(b[iter].cantidadBasura!=0){

			for (int i = 0; i < largo; i++) // para cada basural  // n
			{
				if (i!=iter) // que no sea el basural actual
				{	
                    if (b[i].cantidadBasura != 0)
                    {
                    	cal=abs(b[iter].distancia-b[i].distancia)*b[iter].cantidadBasura; //se calcula la formula sin tomar en cuenta la subencion
						aux[asig]=nuevoMov(b[iter].distancia,b[i].distancia,cal); // se guarda un movimiento del actual a cada otro basural
						asig++;

                    }
					
				}


			}
			menor[otroIteradorMas]=baratisimo(aux,largo-movidos-1);  // n ; de los movimientos calculados se halla el menor y se guarda
			otroIteradorMas++;

		}
		iter++;


	}
	return menor;

}

basural * tomarMovimiento(basural *b, movimiento m, int largo){
	int indexInicial;
	int indexFinal;
	

	for (int i = 0; i < largo; ++i)
	{
		if (b[i].distancia==m.final)
		{
			indexFinal=i;
			break;
		}
	}
	for (int i = 0; i < largo; ++i)
	{
		if (b[i].distancia==m.inicial)
		{
			indexInicial=i;
			break;
		}
	}
	

	b[indexFinal].cantidadBasura=b[indexFinal].cantidadBasura + b[indexInicial].cantidadBasura;
	b[indexInicial].cantidadBasura=0;

	
	
	return b;
}

void goloso(basural * b,int largo, int in, int subsidio){
	movimiento aux; //aux que guarda el menor de los menores de una iteracion
	int numeroIter=largo-in;
	movimiento * salida=(movimiento*)malloc(sizeof(movimiento)*numeroIter); // guarda los axiliares, salida, todos los menores
	movimiento * menor; // guarda la lista de menores de una iteracion

	for (int i = 0; i < numeroIter; ++i) // por cada 
	{
		#ifdef DEBUG
		printCurrent(b,largo);
		#endif
		menor=menores(b,largo,i,salida);// n^2
		aux=baratisimo(menor, largo-i); // n ; consigue el menor de los menores
		#ifdef DEBUG
		printf("\nPasan de %d -> a %d un total de: %d toneladas\n",aux.inicial,aux.final, aux.costo ); //muestra en pantalla el menor de menores
		#endif
		salida[i]=aux; // guarda el menor de menores en la salida
		b=tomarMovimiento(b,aux,largo); //mueve la basura a de un sentro a otro y el inicial se saca de "b" pues queda vacio
		



	}
	escribirSalida(salida,b,largo,in,subsidio);
	free(menor);
	free(salida);
}
#include<stdio.h>
#include<stdlib.h>
#include"../incl/archivo.h"

basural* lectura(char* nombre, int* basurales, int* incineradores, int* subsidio){
	FILE* archivo = fopen(nombre,"r");
	fscanf(archivo, "%d %d %d\n",basurales,incineradores,subsidio);
	basural* ret = (basural*)malloc(sizeof(basural)*(*basurales));
	basural aux;
	for (int i = 0; i < *basurales; ++i){
		fscanf(archivo,"%d %d",&aux.distancia,&aux.cantidadBasura);
		ret[i] = aux;
	}
	return ret;
}


void printCurrent(basural* b, int largo){
	printf("\n");
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("Basurales:\n");
	for (int i = 0; i < largo; ++i)
	{
		printf("*Basural %d:\n",b[i].distancia);
		printf("   distancia: %d\n",b[i].distancia);
		printf("   toneladas basura: %d\n",b[i].cantidadBasura);
	}
}

void escribirSalida(movimiento* salida,basural* basurales, int largo, int in, int subsidio){
	int largoMov = largo - in;
	float costoTotal = 0;
	float aux;

	FILE* archivo = fopen("salida.out","w");
	for (int i = 0; i < largoMov; ++i){
		fprintf(archivo, "%d->%d\n",salida[i].inicial, salida[i].final);
		costoTotal = costoTotal + salida[i].costo;
	}
	aux  = costoTotal * (1- (1/((float)subsidio)) ) ;
	for (int i = 0; i < largoMov; ++i){
		for (int j = 0; j < largo; ++j){
			if (salida[i].final == basurales[j].distancia){
				fprintf(archivo,"Centro %d: %d toneladas\n",salida[i].final,basurales[j].cantidadBasura);
			}
		}
	}
	fprintf(archivo, "Costo: %f",aux);
}
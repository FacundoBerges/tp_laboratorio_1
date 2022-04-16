/*
 * Validaciones.c
 *
 *  Created on: Apr 16, 2022
 *      Author: Facundo Berges
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"

// *********	Ingreso de datos	*********


int IngresarKM(void)
{
	int kmIngresados;
	int min = 0;
	int max = 16000;

	printf("Ingrese cantidad de kilometros: ");
	fflush(stdin);
	scanf("%d", &kmIngresados);
	while(ValidarKM(kmIngresados, min, max)){
		printf("ERROR. Ingrese cantidad de kilometros (mayor a %d y menor a %d): ", min, max);
		fflush(stdin);
		scanf("%d", &kmIngresados);
	}

	return kmIngresados;
}


float IngresarPrecio(char lineaAerea[])
{
	float precioIngresado;

	printf("Ingrese precio de la linea aerea %s: ", lineaAerea);
	scanf("%f", &precioIngresado);
	while(precioIngresado < 0){
		printf("ERROR. Ingrese precio de la linea %s (mayor a 0): ", lineaAerea);
		scanf("%f", &precioIngresado);
	}

	return precioIngresado;
}


int ValidarKM(int numero, int min, int max)
{
	int retorno = -1;
	if(numero >= min && numero <= max)
	{
		retorno = 0;
	}

	return retorno;
}

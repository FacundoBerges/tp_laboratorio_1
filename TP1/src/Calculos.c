/*
 * Calculos.c
 *
 *  Created on: Apr 16, 2022
 *      Author: Facundo Berges
 */

#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"

// *********	Calculo de datos	*********

void CalcularCostos(float precioBase, float descuento, float interes, float precioBTC, int kilometros, float* pPrecioConDescuento, float* pPrecioConInteres, float* pPrecioConBitCoin, float* pPrecioPorKM)
{
	if(pPrecioConDescuento != NULL && pPrecioConInteres != NULL && pPrecioConBitCoin != NULL && pPrecioPorKM != NULL)
	{
		*pPrecioConDescuento = precioBase - (precioBase*descuento);
		*pPrecioConInteres = precioBase + (precioBase*interes);
		*pPrecioConBitCoin = precioBase / precioBTC;
		*pPrecioPorKM = precioBase / kilometros;
	}
}


void CalcularDiferenciaPrecios(float precio1, float precio2, float* pDiferenciaPrecio)
{
	int aux;

	if(pDiferenciaPrecio != NULL)
	{
		if(precio1 < precio2)
		{
			aux = precio1;
			precio1 = precio2;
			precio2 = aux;
		}

		*pDiferenciaPrecio = precio1 - precio2;
	}
}

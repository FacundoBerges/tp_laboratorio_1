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
		*pPrecioConDescuento = CalcularDescuento(precioBase, descuento);
		*pPrecioConInteres = CalcularInteres(precioBase, interes);
		*pPrecioConBitCoin = CalcularBTC(precioBase, precioBTC);
		*pPrecioPorKM = CalcularPrecioUnitario(precioBase, kilometros);
	}
}

float CalcularDescuento(float precio, float descuento)
{
	float precioDescuento;

	precioDescuento = precio - (precio * descuento);

	return precioDescuento;
}

float CalcularInteres(float precio, float interes)
{
	float precioInteres;

	precioInteres = precio + (precio * interes);

	return precioInteres;
}

float CalcularBTC(float precio, float precioBitcoin)
{
	float precioEnBitC;

	precioEnBitC = precio / precioBitcoin;

	return precioEnBitC;
}


float CalcularPrecioUnitario(float precio, int kms)
{
	float precioPorKM;

	precioPorKM = precio / kms;

	return precioPorKM;
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

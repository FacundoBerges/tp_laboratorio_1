#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int qtyPassengers = -1;
	int qtyHeader;

	char bufferId[8];
	char bufferName[64];
	char bufferLastname[64];
	char bufferPrice[16];
	char bufferFlycode[8];
	char bufferTypePassenger[16];
	char bufferFlightStatus[16];
	Passenger* pPassenger = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		qtyPassengers = 0;

		qtyHeader = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferLastname, bufferPrice, bufferFlycode, bufferTypePassenger, bufferFlightStatus);	// Lectura del encabezado

		while(!feof(pFile))
		{
			if( fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferLastname, bufferPrice, bufferFlycode, bufferTypePassenger, bufferFlightStatus) == qtyHeader)
			{
				pPassenger = Passenger_newParametros(bufferId, bufferName, bufferLastname, bufferPrice, bufferFlycode, bufferTypePassenger, bufferFlightStatus);

				if(pPassenger != NULL)
				{
					if(ll_add(pArrayListPassenger, pPassenger) == 0)
					{
						qtyPassengers++; // pasajero agregado
					}
				}
			}
		}
	}

    return qtyPassengers;
}


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int qtyPassengers = -1;
	Passenger* pPassenger = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fread((Passenger*) pPassenger, sizeof(Passenger), 1, pFile); // lectura fantasma de encabezado

		qtyPassengers = 0;

		while(!feof(pFile))
		{
			pPassenger = Passenger_new();

			if(	pPassenger != NULL &&
				fread((Passenger*) pPassenger, sizeof(Passenger), 1, pFile)	)
			{
				if(ll_add(pArrayListPassenger, pPassenger) == 0)
				{
					qtyPassengers++; // pasajero agregado
				}
			}
			else
			{
				break;
			}
		}
	}

    return qtyPassengers;
}

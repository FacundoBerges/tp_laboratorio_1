/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "TypePassenger.h"
#include "StatusFlight.h"
#include "../inc/LinkedList.h"


Passenger* Passenger_new()
{
	Passenger* pPassenger = (Passenger*) malloc(sizeof(Passenger));

	return pPassenger;
}



Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* priceStr, char* flycodeStr, char* tipoPasajeroStr, char* statusFlightStr)
{
	int idAux;
	int typePassengerId;
	int statusFlightId;
	float priceAux;
	Passenger* pPassenger = Passenger_new();

	if(pPassenger != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && priceStr != NULL && flycodeStr != NULL && tipoPasajeroStr != NULL && statusFlightStr != NULL)
	{
		idAux = atoi(idStr);
		priceAux = atof(priceStr);

		TypePassenger_getIdByName(tipoPasajeroStr, &typePassengerId);	// Obtengo los IDs de las cadenas de caracteres
		StatusFlight_getIdByName(statusFlightStr, &statusFlightId);

		if(	Passenger_setId(pPassenger, idAux) == -1 ||
			Passenger_setNombre(pPassenger, nombreStr) == -1 ||
			Passenger_setApellido(pPassenger, apellidoStr) == -1 ||
			Passenger_setPrecio(pPassenger, priceAux) == -1 ||
			Passenger_setCodigoVuelo(pPassenger, flycodeStr) == -1 ||
			Passenger_setTipoPasajero(pPassenger, typePassengerId) == -1 ||
			Passenger_setFlightStatus(pPassenger, statusFlightId) == -1	)
		{
			Passenger_delete(pPassenger);
			pPassenger = NULL;
		}
	}

	return pPassenger;
}



void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}



int Passenger_setId(Passenger* this, int id)
{
	int rtn = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		rtn = 0;
	}

	return rtn;
}


int Passenger_getId(Passenger* this, int* id)
{
	int rtn = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		rtn = 0;
	}

	return rtn;
}



int Passenger_setNombre(Passenger* this, char* nombre)
{
	int rtn = -1;

	if(this != NULL && nombre != NULL && strlen(nombre) > 1 && strlen(nombre) < 49)
	{
		strcpy(this->nombre, "");
		strcpy(this->nombre, nombre);
		rtn = 0;
	}

	return rtn;
}


int Passenger_getNombre(Passenger* this, char* nombre)
{
	int rtn = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, "");
		strcpy(nombre, this->nombre);
		rtn = 0;
	}

	return rtn;
}



int Passenger_setApellido(Passenger* this, char* apellido)
{
	int rtn = -1;

	if(this != NULL && apellido != NULL && strlen(apellido) > 1 && strlen(apellido) < 49)
	{
		strcpy(this->apellido, "");
		strcpy(this->apellido, apellido);
		rtn = 0;
	}

	return rtn;
}


int Passenger_getApellido(Passenger* this, char* apellido)
{
	int rtn = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, "");
		strcpy(apellido, this->apellido);
		rtn = 0;
	}

	return rtn;
}



int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int rtn = -1;

	if(this != NULL && codigoVuelo != NULL && strlen(codigoVuelo) <= 8)
	{
		strcpy(this->codigoVuelo, "");
		strcpy(this->codigoVuelo, codigoVuelo);
		rtn = 0;
	}

	return rtn;
}


int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int rtn = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, "");
		strcpy(codigoVuelo, this->codigoVuelo);
		rtn = 0;
	}

	return rtn;
}



int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
	int rtn = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		rtn = 0;
	}

	return rtn;
}


int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero)
{
	int rtn = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		rtn = 0;
	}

	return rtn;
}



int Passenger_setFlightStatus(Passenger* this, int flightStatus)
{
	int rtn = -1;

	if(this != NULL && flightStatus > 0)
	{
		this->estatusVuelo = flightStatus;
		rtn = 0;
	}

	return rtn;
}


int Passenger_getFlightStatus(Passenger* this, int* flightStatus)
{
	int rtn = -1;

	if(this != NULL && flightStatus != NULL)
	{
		*flightStatus = this->estatusVuelo;
		rtn = 0;
	}

	return rtn;
}



int Passenger_setPrecio(Passenger* this, float precio)
{
	int rtn = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		rtn = 0;
	}

	return rtn;
}


int Passenger_getPrecio(Passenger* this, float* precio)
{
	int rtn = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		rtn = 0;
	}

	return rtn;
}




int listAllPassengers(LinkedList* pArrayListPassenger)
{
	int rtn = -2;
	int len;
	int i;
	Passenger* auxPassenger = NULL;

	len = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL && len > 0)
	{
		rtn = 0;

		printf("%3s\t%15s\t%15s\t%8s\t%15s\t%10s\t%15s\n\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "TIPO PASAJERO", "CODIGO", "ESTATUS");

		for(i = 0; i < len; i++)
		{
			auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

			if(auxPassenger != NULL)
			{
				if(showPassenger(auxPassenger) == 0)
				{
					rtn++;
				}
			}
		}
	}

	return rtn;
}


int showPassenger(Passenger* aPassenger)
{
	int rtn = -1;

	int auxId;
	int auxTypePassengerId;
	int auxStatusFlightId;
	float auxPrice;
	char auxName[50];
	char auxLastname[50];
	char auxFlycode[8];
	char auxTypePassengerName[20];
	char auxStatusFlightName[20];

	if(aPassenger != NULL)
	{
		if(	Passenger_getId(aPassenger, &auxId) == 0 &&
			Passenger_getNombre(aPassenger, auxName) == 0 &&
			Passenger_getApellido(aPassenger, auxLastname) == 0 &&
			Passenger_getPrecio(aPassenger, &auxPrice) == 0 &&
			Passenger_getTipoPasajero(aPassenger, &auxTypePassengerId) == 0 &&
			Passenger_getCodigoVuelo(aPassenger, auxFlycode) == 0 &&
			Passenger_getFlightStatus(aPassenger, &auxStatusFlightId) == 0 &&
			TypePassenger_getNameById(auxTypePassengerId, auxTypePassengerName) == 0 &&
			StatusFlight_getNameById(auxStatusFlightId, auxStatusFlightName) == 0)
		{
			printf("%4d\t%15s\t%15s\t%10.2f\t%15s\t%10s\t%15s\n", auxId, auxName, auxLastname, auxPrice, auxTypePassengerName, auxFlycode, auxStatusFlightName);
			rtn = 0;
		}
	}

	return rtn;
}



int Passenger_getIndexById(LinkedList* pArrayListPassenger, int id)
{
	int rtn = -1;
	int i;
	int idAux;
	int len = ll_len(pArrayListPassenger);
	Passenger* pPassenger = NULL;

	if(pArrayListPassenger != NULL && id > 0 && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			pPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

			if(pPassenger != NULL)
			{
				Passenger_getId(pPassenger, &idAux);

				if(idAux == id)
				{
					rtn = i;
					break;
				}
			}
		}
	}

	return rtn;
}



int Passenger_compareById(void* p1, void* p2)
{
	int rtn = 0;
	int auxId1;
	int auxId2;
	Passenger* aPassenger = NULL;
	Passenger* anotherPassenger = NULL;

	if(p1 != NULL && p2 != NULL)
	{
		aPassenger = (Passenger*) p1;
		anotherPassenger = (Passenger*) p2;

		if(	Passenger_getId(aPassenger, &auxId1) == 0 &&
			Passenger_getId(anotherPassenger, &auxId2) == 0)
		{
			if(auxId1 > auxId2)
			{
				rtn = 1;
			}
			else
			{
				if(auxId1 < auxId2)
				{
					rtn = -1;
				}
			}
		}
	}

	return rtn;
}


int Passenger_compareByName(void* p1, void* p2) // Unboxing
{
	int rtn = -1;
	char auxName1[50];
	char auxName2[50];
	Passenger* aPassenger = NULL;
	Passenger* anotherPassenger = NULL;

	if(p1 != NULL && p2 != NULL)
	{
		aPassenger = (Passenger*) p1;
		anotherPassenger = (Passenger*) p2;

		if(	Passenger_getNombre(aPassenger, auxName1) == 0 &&
			Passenger_getNombre(anotherPassenger, auxName2) == 0)
		{
			rtn = stricmp(auxName1, auxName2);
		}
	}

	return rtn;
}


int Passenger_compareByLastname(void* p1, void* p2)
{
	int rtn = -1;
	char auxLastName1[50];
	char auxLastName2[50];
	Passenger* aPassenger = NULL;
	Passenger* anotherPassenger = NULL;

	if(p1 != NULL && p2 != NULL)
	{
		aPassenger = (Passenger*) p1;
		anotherPassenger = (Passenger*) p2;

		if(	Passenger_getApellido(aPassenger, auxLastName1) == 0 &&
			Passenger_getApellido(anotherPassenger, auxLastName2) == 0)
		{
			rtn = stricmp(auxLastName1, auxLastName2);
		}
	}

	return rtn;
}


int Passenger_compareByPrice(void* p1, void* p2)
{
	int rtn = 0;
	float auxPrice1;
	float auxPrice2;
	Passenger* aPassenger = NULL;
	Passenger* anotherPassenger = NULL;

	if(p1 != NULL && p2 != NULL)
	{
		aPassenger = (Passenger*) p1;
		anotherPassenger = (Passenger*) p2;

		if(	Passenger_getPrecio(aPassenger, &auxPrice1) == 0 &&
			Passenger_getPrecio(anotherPassenger, &auxPrice2) == 0)
		{
			if(auxPrice1 > auxPrice2)
			{
				rtn = 1;
			}
			else
			{
				if(auxPrice1 < auxPrice2)
				{
					rtn = -1;
				}
			}
		}
	}

	return rtn;
}


int Passenger_compareByTypePassenger(void* p1, void* p2)
{
	int rtn = 0;
	int auxIdTypePass1;
	int auxIdTypePass2;
	Passenger* aPassenger = NULL;
	Passenger* anotherPassenger = NULL;

	if(p1 != NULL && p2 != NULL)
	{
		aPassenger = (Passenger*) p1;
		anotherPassenger = (Passenger*) p2;

		if(	Passenger_getTipoPasajero(aPassenger, &auxIdTypePass1) == 0 &&
			Passenger_getTipoPasajero(anotherPassenger, &auxIdTypePass2) == 0)
		{
			if(auxIdTypePass1 > auxIdTypePass2)
			{
				rtn = 1;
			}
			else
			{
				if(auxIdTypePass1 < auxIdTypePass2)
				{
					rtn = -1;
				}
			}
		}
	}

	return rtn;
}



int Passenger_compareByFlycode(void* p1, void* p2)
{
	int rtn = -1;
	char auxFlycode1[8];
	char auxFlycode2[8];
	Passenger* aPassenger = NULL;
	Passenger* anotherPassenger = NULL;

	if(p1 != NULL && p2 != NULL)
	{
		aPassenger = (Passenger*) p1;
		anotherPassenger = (Passenger*) p2;

		if(	Passenger_getCodigoVuelo(aPassenger, auxFlycode1) == 0 &&
			Passenger_getCodigoVuelo(anotherPassenger, auxFlycode2) == 0)
		{
			rtn = stricmp(auxFlycode1, auxFlycode2);
		}
	}

	return rtn;
}



int Passenger_compareByFlightStatus(void* p1, void* p2)
{
	int rtn = 0;
	int auxIdFlightStatus1;
	int auxIdFlightStatus2;
	Passenger* aPassenger = NULL;
	Passenger* anotherPassenger = NULL;

	if(p1 != NULL && p2 != NULL)
	{
		aPassenger = (Passenger*) p1;
		anotherPassenger = (Passenger*) p2;

		if(	Passenger_getFlightStatus(aPassenger, &auxIdFlightStatus1) == 0 &&
			Passenger_getFlightStatus(anotherPassenger, &auxIdFlightStatus2) == 0)
		{
			if(auxIdFlightStatus1 > auxIdFlightStatus2)
			{
				rtn = 1;
			}
			else
			{
				if(auxIdFlightStatus1 < auxIdFlightStatus2)
				{
					rtn = -1;
				}
			}
		}
	}

	return rtn;
}




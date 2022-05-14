/*
 * ArrayPassenger.c
 *
 *  Created on: May 8, 2022
 *      Author: Facundo
 */

#include <stdio.h>
//#include <stdio_ext.h>	// para linux
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "ArrayTypePassenger.h"
#include "ArrayFlight.h"
#include "inputs.h"

#define ID_INICIAL 1000

#define QTY_NAME 51
#define QTY_TYPE 21
#define QTY_CODE 10
#define MAX_PRICE 1000000000.00

//flight status
#define ACTIVO 1
#define ATRASADO 2
#define SUSPENDIDO 3


//#define stricmp strcmp	// para linux
//#define fflush __fpurge	// para linux


static int idIncremental = ID_INICIAL;
/**
 * @fn int obtenerIAlbum()
 * @brief funcion static que incrementa el ID estatico de la biblioteca.
 *
 * @return retorna el ID incrementado en 1.
 */
static int getId();
static int getId()
{
	return idIncremental++;
}


int initPassengers(sPassenger* list, int len)
{
	int ret = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}

		ret = 0;
	}

	return ret;
}


int cargarDatos(sPassenger* list, int len, sTypePassenger* typesOfPassenger, int typesLen, sFlightStatus* statusFlights, int statusLen)
{
	int ret = -1;
	int retName;
	int retLastname;
	int retPrice;
	int retFlycode;
	int retTypePassenger;
	int retFlightStatus;
	int retries = 3;

	int nextId;
	char name[QTY_NAME];
	char lastName[QTY_NAME];
	char flycode[QTY_CODE];
	int typePassenger;
	int statusFlight;
	float price;

	system("cls");

	if(list != NULL && len > 0 && typesOfPassenger != NULL && typesLen > 0 && statusFlights != NULL && statusLen > 0)
	{
		printf("\n\n\t\t\tALTA\n\n");
		retName = getString("Ingrese nombre: ", name, QTY_NAME, retries);
		if(retName != -1 && esSoloLetras(name) )
		{
			retLastname = getString("Ingrese apellido: ", lastName, QTY_NAME, retries);
			if(retLastname != -1 && esSoloLetras(lastName) )
			{
				retPrice = pedirNumFlotante("Ingrese precio: ", 0.0, MAX_PRICE, &price, retries);
				if(retPrice != -1 && price > 0)
				{
					retFlycode = getString("Ingrese codigo de vuelo: ", flycode, QTY_CODE, retries);
					if(retFlycode != -1 && esAlfaNumerico(flycode))
					{
						if(printAllTypePassengers(typesOfPassenger, typesLen, "\n\n\t\tCLASES DE VUELOS\n") != -1)
						{
							retTypePassenger = getInt("\nIngrese clase de vuelo de pasaje: ", 0, typesLen+1, retries);
							if(retTypePassenger != -1)
							{
								typePassenger = getTypePassengerByIndex(typesOfPassenger, retTypePassenger-1);
								if(typePassenger != -1)
								{
									if(printAllStatusFlights(statusFlights, statusLen, "\n\n\t\tSTATUS DEL VUELO\n") != -1)
									{
										fflush(stdin);
										retFlightStatus = getInt("\nIngrese estatus correspondiente del vuelo: ", 0, statusLen+1, retries);
										if(retFlightStatus != -1)
										{
											statusFlight = getFlightStatusByIndex(statusFlights, retFlightStatus-1);
											if(statusFlight != -1)
											{
												nextId = getId();
												ret = addPassenger(list, len, nextId, name, lastName, price, typePassenger, flycode, statusFlight); // if everythings ok
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

	}

	return ret;
}


int addPassenger(sPassenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight)
{
	int ret = -1;
	int freePosition;

	if(list != NULL && len > 0 && name != NULL && lastName != NULL && price > 0 && flycode != NULL)
	{
		freePosition = emptyPassenger(list, len);

		if(freePosition >= 0)
		{
			list[freePosition].id = id;
			strcpy(list[freePosition].name, name);
			strcpy(list[freePosition].lastname, lastName);
			list[freePosition].price = price;
			strcpy(list[freePosition].flycode, flycode);
			list[freePosition].typePassenger = typePassenger;
			list[freePosition].statusFlight = statusFlight;
			list[freePosition].isEmpty = FALSE;

			ret = 0;
		}
	}

	return ret;
}


int modifyPassenger(sPassenger* list, int len, sTypePassenger* typesPassenger, int typesLen, sFlightStatus* statusFlights, int statusLen)
{
	int ret = -1;
	int passengerId;
	int passengerIndex;
	int auxOption;

	if(list != NULL && len > 0 && typesPassenger != NULL && typesLen > 0 && statusFlights != NULL && statusLen > 0)
	{
		system("cls");
		printf("\n\n\t\t\tMODIFICAR\n\n");
		sortPassengersById(list, len, UP);
		printAllPassengers(list, len, typesPassenger, typesLen, statusFlights, statusLen);

		passengerId = getInt("\nIngrese codigo de dato a modificar: ", ID_INICIAL-1, ID_INICIAL+len+1, 3);
		passengerIndex = findPassengerById(list, len, passengerId);
		if(passengerId != -1 && passengerIndex > -1 && list[passengerIndex].isEmpty == FALSE)
		{
			printf("\n\nPasajero a modificar:\n\n");
			printAPassenger(list[passengerIndex], typesPassenger, typesLen, statusFlights, statusLen);

			auxOption = getInt("\n\n- 1. Nombre\n- 2. Apellido\n- 3. Precio\n- 4. Tipo de pasajero\n- 5. Codigo de vuelo\n\nIngrese opcion a modificar: ", 0, 6, 3);

			switch(auxOption)
			{
				case 1:
					if(modifyName(list, list[passengerIndex].name, passengerIndex) == 0)
					{
						ret = 0;
					}
					else
					{
						ret = -2; // Error al intentar modificar.
					}
					break;
				case 2:
					if(modifyName(list, list[passengerIndex].lastname, passengerIndex) == 0)
					{
						ret = 0;
					}
					else
					{
						ret = -2; // Error al intentar modificar.
					}
					break;
				case 3:
					if(modifyPrice(list[passengerIndex].price, passengerIndex, list) == 0)
					{
						ret = 0;
					}
					else
					{
						ret = -2; // Error al intentar modificar.
					}
					break;
				case 4:
					if(modifyTypePassenger(list, passengerIndex, list[passengerIndex].typePassenger, typesPassenger, typesLen) == 0)
					{
						ret = 0;
					}
					else
					{
						ret = -2; // Error al intentar modificar.
					}
					break;
				case 5:
					if(modifyFlycode(list, list[passengerIndex].flycode, passengerIndex) == 0)
					{
						ret = 0;
					}
					else
					{
						ret = -2; // Error al intentar modificar.
					}
					break;
				default:
					printf("\n\nOpcion ingresada invalida. Volviendo al menu principal.\n\n");
					ret = -3; // opcion de submenu se quedo sin reintentos
					break;
			}
		}
	}

	system("pause");

	return ret;
}


int removePassengersMenu(sPassenger* list, int len, sTypePassenger* typesPassenger, int typesLen, sFlightStatus* statusFlights, int statusLen)
{
	int ret = -1;
	int passengerId;
	int passengerIndex;
	char respuesta[QTY_NAME];

	if(list != NULL && len > 0 && typesPassenger != NULL && typesLen > 0 && statusFlights != NULL && statusLen > 0)
	{
		system("cls");
		printf("\n\n\t\t\tBAJA\n\n");
		sortPassengersById(list, len, UP);
		printAllPassengers(list, len, typesPassenger, typesLen, statusFlights, statusLen);

		passengerId = getInt("\nIngrese codigo de pasajero a eliminar: ", ID_INICIAL-1, ID_INICIAL+len+1, 3);
		passengerIndex = findPassengerById(list, len, passengerId);
		if(passengerId != -1 && passengerIndex > -1 && list[passengerIndex].isEmpty == FALSE)
		{
			printf("\n\nPasajero a dar de baja:\n\n");
			printAPassenger(list[passengerIndex], typesPassenger, typesLen, statusFlights, statusLen);

			if(getString("\nEscriba 'si' si desea dar de baja el album: ", respuesta, 3, 3) == 0 && stricmp(respuesta, "si") == 0)
			{
				removePassenger(list, len, passengerId);
				ret = 0; //retorno ok
			}
		}
	}

	return ret;
}



int reportPassenger(sPassenger* list, int len, sTypePassenger* typesPassenger, int typesLen, sFlightStatus* statusFlights, int statusLen)
{
	int ret = -1;
	int auxOption;
	int auxOrder = 0;

	if(list != NULL && len > 0 && typesPassenger != NULL && typesLen > 0 && statusFlights != NULL && statusLen > 0)
	{
		system("cls");
		printf("\n\n\t\t\tINFORMES\n\n");
		auxOption = getInt("\n- 1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n- 2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n- 3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.\n\nIngrese opcion a informar: ", 0, 4, 3);
		if(auxOption != 2)
		{
			auxOrder = getInt("\n\t\t\tORDENAR\n\n- 1. Descendente.\n- 2. Ascendente.\n\nIngrese opcion: ", 0, 3, 3);
		}

		if(auxOrder != -1)
		{
			auxOrder = auxOrder-1;

			switch(auxOption)
			{
				case 1:
					if(sortPassengers(list, len, auxOrder) == 0)
					{
						printAllPassengers(list, len, typesPassenger, typesLen, statusFlights, statusLen);
						ret = 0;
					}
					else
					{
						ret = -2; // Error al intentar informar.
					}
					break;
				case 2:
					if(reportAverages(list, len) == 0)
					{
						ret = 0;
					}
					else
					{
						ret = -2; // Error al intentar informar.
					}
					break;
				case 3:
					if(sortPassengersByCode(list, len, auxOrder) == 0 && filterPassengerByStatus(list, len, typesPassenger, typesLen, statusFlights, statusLen) > 0)
					{
						ret = 0;
					}
					else
					{
						ret = -2; // Error al intentar informar.
					}
					break;
				default:
					ret = -3; // opcion de submenu se quedo sin reintentos
					break;
			}
		}

	}

	system("pause");

	return ret;
}


int altaForzada(sPassenger* list, int len, sTypePassenger* typesPassenger, sFlightStatus* statusFlights)
{
	int ret = -1;
	int i;
	int idForzados[5];

	if(list != NULL && len > 0 && typesPassenger != NULL && statusFlights != NULL)
	{
		system("cls");

		for(i = 0; i < 5; i++)
		{
			idForzados[i] = getId();
		}

		printf("\n\n\t\t\tCARGA FORZADA DE DATOS\n\n");
		printf("\n\nCargando...\n\n");

		addPassenger(list, len, idForzados[0], "Juan Carlos", "Martinez", 165343.26, typesPassenger[0].id, "FAS0GR8", statusFlights[2].id);
		addPassenger(list, len, idForzados[1], "Martin", "Perez", 156432.37, typesPassenger[1].id, "1GS68FE1F", statusFlights[1].id);
		addPassenger(list, len, idForzados[2], "Luciana", "Alvarez", 98461.91, typesPassenger[2].id, "4G6SR8VE", statusFlights[0].id);
		addPassenger(list, len, idForzados[3], "Raul", "Perez", 12073.78, typesPassenger[2].id, "FT8974NHF", statusFlights[2].id);
		addPassenger(list, len, idForzados[4], "Camila", "Martinez", 52156.60, typesPassenger[1].id, "J98YK7U8", statusFlights[0].id);

		ret = 0;
	}

	return ret;
}


int emptyPassenger(sPassenger* list, int len)
{
	int ret = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty)
			{
				ret = i;
				break;
			}
		}
	}

	return ret;
}


int findPassengerById(sPassenger* list, int len, int id)
{
	int ret = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].id == id)
			{
				ret = i;
				break;
			}
		}
	}

	return ret;
}


int removePassenger(sPassenger* list, int len, int id)
{
	int ret = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].id == id && !(list[i].isEmpty))
			{
				list[i].isEmpty = TRUE;
				ret = 0;
				break;
			}
		}
	}

	return ret;
}



int sortPassengers(sPassenger* list, int len, int order)
{
	int ret = -1;
	int i, j;

	if(list != NULL && len > 0 && order > -1 && order < 2)
	{
		for(i = 0; i < len-1; i++)
		{
			for(j = i+1; j < len; j++)
			{
				if( (order == DOWN && ( (strcmp(list[i].lastname, list[j].lastname) < 0) || ((strcmp(list[i].lastname, list[j].lastname) == 0) && list[i].typePassenger > list[j].typePassenger)) ) || (order == UP && ( (strcmp(list[i].lastname, list[j].lastname) > 0)   || ((strcmp(list[i].lastname, list[j].lastname) == 0) && list[i].typePassenger < list[j].typePassenger)) ) )
				{
					swapPassengers(list, i, j);
				}
			}
		}

		ret = 0;
	}

	return ret;
}


int printAllPassengers(sPassenger* list, int length, sTypePassenger* typePassengers, int typesLen, sFlightStatus* FlightsStatus, int statusLen)
{
	int ret = -1;
	int i;

	if(list != NULL && length > 0 && typePassengers != NULL && typesLen > 0 && FlightsStatus != NULL && statusLen > 0)
	{
		printf("\n\n%s\t%20s\t%20s\t%10s\t%15s\t%20s\t%10s\n\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO DE VUELO", "TIPO DE PASAJERO", "ESTATUS");
		printf("-------------------------------------------------------------------------------------------------------------------------------------\n\n");


		for(i = 0; i < length; i++)
		{
			if( list[i].isEmpty != TRUE) // If occupied.
			{
				printAPassenger(list[i], typePassengers, typesLen, FlightsStatus, statusLen);
			}
		}

		ret = 0;
	}

	return ret;
}


void printAPassenger(sPassenger aPassenger, sTypePassenger* typePassengers, int typesLen, sFlightStatus* FlightsStatus, int statusLen)
{
	char typePassName[QTY_TYPE];
	char flightStatusName[QTY_TYPE];

	if(typePassengers != NULL && FlightsStatus != NULL && typesLen > 0 && statusLen > 0)
	{
		if( getTypePassengerName(aPassenger.typePassenger, typePassengers, typesLen, typePassName) == 0 && getFlightStatusName(aPassenger.statusFlight, FlightsStatus, statusLen, flightStatusName) == 0)
		{
			printf("%d\t%20s\t%20s\t$ %.2f\t%10s\t%20s\t%10s\n",	aPassenger.id,
																	aPassenger.name,
																	aPassenger.lastname,
																	aPassenger.price,
																	aPassenger.flycode,
																	typePassName,
																	flightStatusName	);
		}
	}
}


int sortPassengersByCode(sPassenger* list, int len, int order)
{
	int ret = -1;
	int i, j;

	if(list != NULL && len > 0 && order > -1 && order < 2)
	{
		for(i = 0; i < len-1; i++)
		{
			for(j = i+1; j < len; j++)
			{
				if( (order == UP && strcmp(list[i].flycode, list[j].flycode) > 0) || (order == DOWN && strcmp(list[i].flycode, list[j].flycode) < 0))
				{
					swapPassengers(list, i, j);
				}
			}
		}

		ret = 0;
	}

	return ret;
}


int filterPassengerByStatus(sPassenger* list, int len, sTypePassenger* typePassengers, int typesLen, sFlightStatus* FlightsStatus, int statusLen)
{
	int ret = -1;
	int i;

	if(list != NULL && typePassengers != NULL && FlightsStatus != NULL && len > 0 && typesLen > 0 && statusLen > 0)
	{
		printf("\n\n%s\t%20s\t%20s\t%10s\t%15s\t%20s\t%10s\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO DE VUELO", "TIPO DE PASAJERO", "ESTATUS");
		printf("-------------------------------------------------------------------------------------------------------------------------------------\n\n");

		ret = 0;

		for(i = 0; i < len; i++)
		{
			if(list[i].statusFlight == ACTIVO)
			{
				printAPassenger(list[i], typePassengers, typesLen, FlightsStatus, statusLen);
				ret++;
			}
		}
	}

	return ret;
}


int sortPassengersById(sPassenger* list, int len, int order)
{
	int ret = -1;
	int i, j;

	if(list != NULL && len > 0 && order > -1 && order < 2)
	{
		for(i = 0; i < len-1; i++)
		{
			for(j = i+1; j < len; j++)
			{
				if( (order == UP && list[i].id > list[j].id) || (order == DOWN && list[i].id < list[j].id) )
				{
					swapPassengers(list, i, j);
				}
			}
		}

		ret = 0;
	}

	return ret;
}


int swapPassengers(sPassenger* list, int PassengerA, int PassengerB)
{
	int ret = -1;
	sPassenger auxPassenger;

	if(list != NULL)
	{
		auxPassenger = list[PassengerA];
		list[PassengerA] = list[PassengerB];
		list[PassengerB] = auxPassenger;

		ret = 0;
	}

	return ret;
}


int findOccupied(sPassenger* list, int len)
{
	int ret = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(!(list[i].isEmpty)) // If occupied.
			{
				ret = 0;
				break;
			}
		}
	}

	return ret;
}



int modifyName(sPassenger* list, char actualName[], int index)
{
	int ret = -1;
	char auxName[QTY_NAME];
	int retString;

	if(actualName != NULL && list != NULL && index >= 0)
	{
		printf("\nNombre actual: %s\n", actualName);

		retString = getString("Ingrese nuevo: ", auxName, QTY_NAME, 3);
		if (retString != -1 && esSoloLetras(auxName))
		{
			strcpy(list[index].name, auxName);
			ret = 0;
		}
	}

	return ret;
}


int modifyLastName(sPassenger* list, char actualLastName[], int index)
{
	int ret = -1;
	char auxName[QTY_NAME];
	int retString;

	if(actualLastName != NULL && list != NULL && index >= 0)
	{
		printf("\nApellido actual: %s\n", actualLastName);

		retString = getString("Ingrese nuevo: ", auxName, QTY_NAME, 3);
		if (retString != -1 && esSoloLetras(auxName))
		{
			strcpy(list[index].lastname, auxName);
			ret = 0;
		}
	}

	return ret;
}


int modifyPrice(float actualPrice, int index, sPassenger* list)
{
	int ret = -1;
	float auxFloat;
	int retFloat;

	if(actualPrice > 0 && list != NULL && index >= 0)
	{
		printf("\nPrecio actual: %.2f\n", actualPrice);

		retFloat = pedirNumFlotante("Ingrese nuevo importe: ", 0.0, MAX_PRICE, &auxFloat, 3);
		if (retFloat != -1)
		{
			list[index].price = auxFloat;
			ret = 0;
		}
	}

	return ret;
}



int modifyTypePassenger(sPassenger* list, int index, int actualTypePassId, sTypePassenger* typePassenger, int typeLen)
{
	int ret = -1;
	char typePassengerName[QTY_NAME];
	int retTypePass;

	if(actualTypePassId > 0 && list != NULL && index >= 0 && typePassenger != NULL && typeLen > 0)
	{
		if(getTypePassengerName(actualTypePassId, typePassenger, typeLen, typePassengerName) == 0)
		{
			printf("\nTipo de pasajero actual: %s\n", typePassengerName);
		}
		if(printAllTypePassengers(typePassenger, typeLen, "\n\t\tCLASES DE VUELOS\n") != -1)
		{
			retTypePass = getInt("\nIngrese tipo de pasajero (por numero): ", 0, typeLen+1, 3);
			if(retTypePass != -1)
			{
				list[index].typePassenger = getTypePassengerByIndex(typePassenger, retTypePass);
				ret = 0;
			}
		}
	}

	return ret;
}


int modifyFlycode(sPassenger* list, char actualCode[], int index)
{
	int ret = -1;
	char auxName[QTY_NAME];
	int retString;

	if(actualCode != NULL && list != NULL && index >= 0)
	{
		printf("\nCodigo de vuelo actual: %s\n", actualCode);

		retString = getString("Ingrese nuevo: ", auxName, QTY_CODE, 3);
		if (retString != -1 && esAlfaNumerico(auxName))
		{
			strcpy(list[index].flycode, auxName);
			ret = 0;
		}
	}

	return ret;
}


int reportAverages(sPassenger* list, int len)
{
	int ret = -1;
	int activeQty;
	int contadorSuperiorAlPromedio;
	float totalDeImportes = 0;
	float importesSuperiorPromedio = 0;
	float importeProm;

	if(list != NULL && len > 0)
	{
		activeQty = countOccupied(list, len);
		if(activeQty != -1 && calcularTotalImportes(list, len, &totalDeImportes, 0) != -1)
		{
			calcularPromedio(totalDeImportes, activeQty, &importeProm);
			contadorSuperiorAlPromedio = calcularTotalImportes(list, len, &importesSuperiorPromedio, importeProm);
			printf("\n\n\nTotal de los pasajes: $ %.2f\nPromedio de pasajes: $ %.2f\nCantidad de pasajeros que superan el promedio: %d.\n\n", totalDeImportes, importeProm, contadorSuperiorAlPromedio);
			ret = 0;
		}
	}

	return ret;
}


int countOccupied(sPassenger* list, int len)
{
	int ret = -1;
	int i;

	if(list != NULL && len > 0)
	{
		ret = 0;

		for(i = 0; i < len; i++)
		{
			if(!(list[i].isEmpty)) // If occupied.
			{
				ret++;
			}
		}
	}

	return ret;
}


int verifyOccupied(sPassenger* list, int indexPosition)
{
	int retorno = -1;

	if(list != NULL && indexPosition >= 0)
	{
		if( !(list[indexPosition].isEmpty) )
		{
			retorno = indexPosition;
		}
	}

	return retorno;
}


int calcularTotalImportes(sPassenger* list, int len, float* pTotalImportes, float importeMinimo)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		retorno = 0;
		for(i = 0; i < len; i++)
		{
			if(verifyOccupied(list, i) != -1 && list[i].price > importeMinimo)
			{
				*pTotalImportes += list[i].price;
				retorno++;
			}
		}
	}

	return retorno;
}


int calcularPromedio(float numTotal, int cantidad, float* promedio)
{
	int ret = -1;

	if(promedio != NULL && cantidad != 0)
	{
		*promedio = numTotal / cantidad;
		ret = 0;
	}

	return ret;
}

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

#define ID_INICIAL 1

#define QTY_NAME 51
#define QTY_TYPE 21
#define QTY_CODE 10
#define MAX_PRICE 100000000.00

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
			list[i].id = 0;
			strcpy(list[i].name, "");
			strcpy(list[i].lastname, "");
			list[i].price = 0;
			strcpy(list[i].flycode, "");
			list[i].typePassenger = 0;
			list[i].statusFlight = 0;
			list[i].isEmpty = TRUE;
		}

		ret = 0;
	}

	return ret;
}


int cargarDatos(sPassenger* list, int len, sTypePassenger* typesOfPassenger, int typesLen, sFlightStatus* statusFlights, int statusLen, int* qtyPassengers)
{
	int ret = -1;
	int auxTypePassenger;
	int auxFlightStatus;
	int retries = 2;

	int nextId;
	char name[QTY_NAME];
	char lastName[QTY_NAME];
	char flycode[QTY_CODE];
	int typePassenger;
	int statusFlight;
	float price;


	if(list != NULL && len > 0 && typesOfPassenger != NULL && typesLen > 0 && statusFlights != NULL && statusLen > 0)
	{
		system("cls");
		printf("\n\n\t\t\tALTA\n\n");

		if(utn_getStringLetras(name, sizeof(name), "Ingrese nombre: ", "Error. Nombre invalido (solo debe contener letras). ", retries) == 0)
		{
			if(utn_getStringLetras(lastName, sizeof(lastName), "Ingrese apellido: ", "Error. Apellido invalido (solo debe contener letras). ", retries) == 0)
			{
				if(utn_getNumeroFloat(&price, "Ingrese precio: ", "Error. ", 0.01, MAX_PRICE, retries) == 0)
				{
					if(utn_getStringAlphaNum(flycode, sizeof(flycode), "Ingrese codigo de vuelo: ", "Error. Codigo invalido (solo debe contener letras y numeros). ", retries) == 0)
					{
						printAllTypePassengers(typesOfPassenger, typesLen, "\n\n\t\tCLASES DE VUELOS\n");
						if(utn_getNumeroInt(&auxTypePassenger, "\nIngrese clase de vuelo de pasaje (por numero): ", "Error. ", 1, typesLen, retries) == 0)
						{
							typePassenger = getTypePassengerByIndex(typesOfPassenger, auxTypePassenger-1);

							if(typePassenger != -1)
							{
								printAllStatusFlights(statusFlights, statusLen, "\n\n\t\tSTATUS DEL VUELO\n");
								if(utn_getNumeroInt(&auxFlightStatus, "\nIngrese estatus correspondiente del vuelo (por numero): ", "Error. ", 1, statusLen, retries) == 0)
								{
									statusFlight = getFlightStatusByIndex(statusFlights, auxFlightStatus-1);

									if(statusFlight != -1)
									{
										nextId = getId();
										ret = addPassenger(list, len, nextId, name, lastName, price, typePassenger, flycode, statusFlight);

										if(ret == 0)
										{
											*qtyPassengers += 1;
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

		if(utn_getNumeroInt(&passengerId, "\nIngrese codigo de pasajero a modificar: ", "Error. El codigo ingresado no es un codigo valido. ", ID_INICIAL, ID_INICIAL+len, 2) == 0)
		{
			passengerIndex = findPassengerById(list, len, passengerId);

			if(passengerIndex >= 0 && list[passengerIndex].isEmpty == FALSE)
			{
				printf("\n\nPasajero a modificar:\n\n");
				printAPassenger(list[passengerIndex], typesPassenger, typesLen, statusFlights, statusLen);

				printf("\n\n- 1. Nombre\n- 2. Apellido\n- 3. Precio\n- 4. Tipo de pasajero\n- 5. Codigo de vuelo\n\n");
				if(utn_getNumeroInt(&auxOption, "\nIngrese opcion a modificar: ", "\nOpcion ingresada invalida.", 1, 5, 2) == 0)
				{
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
							if(modifyLastName(list, list[passengerIndex].lastname, passengerIndex) == 0)
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
		}
	}

	return ret;
}


int removePassengersMenu(sPassenger* list, int len, sTypePassenger* typesPassenger, int typesLen, sFlightStatus* statusFlights, int statusLen, int* qtyPassengers)
{
	int ret = -1;
	int passengerId;
	int passengerIndex;
	char respuesta;

	if(list != NULL && len > 0 && typesPassenger != NULL && typesLen > 0 && statusFlights != NULL && statusLen > 0)
	{
		system("cls");
		printf("\n\n\t\t\tBAJA\n\n");
		sortPassengersById(list, len, UP);
		printAllPassengers(list, len, typesPassenger, typesLen, statusFlights, statusLen);

		if(utn_getNumeroInt(&passengerId, "\nIngrese codigo de pasajero a eliminar: ", "Error. El codigo ingresado no es un codigo valido. ", ID_INICIAL, ID_INICIAL+len, 2) == 0)
		{
			passengerIndex = findPassengerById(list, len, passengerId);

			if(passengerIndex > -1 && list[passengerIndex].isEmpty == FALSE)
			{
				printf("\n\nPasajero a dar de baja:\n\n");
				printAPassenger(list[passengerIndex], typesPassenger, typesLen, statusFlights, statusLen);

				if(	utn_getCharacterLower(&respuesta, "\nDesea 'S' si desea dar de baja el pasajero, u otro caracter para cancelar: ", "Error. Debe ingresar un caracter (S/N): ", 'a', 'z', 2) == 0 &&
					respuesta == 's')
				{
					ret = removePassenger(list, len, passengerId);

					if(ret == 0)
					{
						*qtyPassengers -= 1;
					}
				}
			}
		}
	}

	return ret;
}



int reportPassenger(sPassenger* list, int len, sTypePassenger* typesPassenger, int typesLen, sFlightStatus* statusFlights, int statusLen)
{
	int ret = -1;
	int auxOption;
	int auxOrder;
	int rtnOrder = 0;

	if(list != NULL && len > 0 && typesPassenger != NULL && typesLen > 0 && statusFlights != NULL && statusLen > 0)
	{
		system("cls");
		printf("\n\n\t\t\tINFORMES\n\n\n- 1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n- 2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n- 3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.\n\n");

		if(utn_getNumeroInt(&auxOption, "Ingrese opcion a informar: ", "Error, opcion invalida.", 1, 3, 2) == 0)
		{
			if(auxOption != 2)
			{
				printf("\n\t\t\tORDENAR\n\n- 0. Descendente.\n- 1. Ascendente.\n\n");
				rtnOrder = utn_getNumeroInt(&auxOrder, "Ingrese opcion: ", "Error, opcion invalida.", 0, 1, 2);
			}

			if(rtnOrder == 0)
			{
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
	}

	return ret;
}


int altaForzada(sPassenger* list, int len, sTypePassenger* typesPassenger, sFlightStatus* statusFlights, int* qtyPassengers)
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

		addPassenger(list, len, idForzados[0], "Mariela", "Gomez", 20000.00, typesPassenger[0].id, "AA200", statusFlights[0].id);
		addPassenger(list, len, idForzados[1], "Juan Pablo", "Martinez", 30000.00, typesPassenger[1].id, "LA201", statusFlights[0].id);
		addPassenger(list, len, idForzados[2], "Mauro", "Gomez", 18000.00, typesPassenger[2].id, "AA200", statusFlights[0].id);
		addPassenger(list, len, idForzados[3], "Yolanda", "Alberdi", 32000.00, typesPassenger[0].id, "LA200", statusFlights[0].id);
		addPassenger(list, len, idForzados[4], "Fabio", "Benitez", 45000.00, typesPassenger[1].id, "AA220", statusFlights[1].id);

		*qtyPassengers += 5;
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
			if(list[i].isEmpty == TRUE)
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

	if(list != NULL && id > 0)
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
			if(list[i].id == id && list[i].isEmpty == FALSE)
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
				if( (order == DOWN && ( (strcmp(list[i].lastname, list[j].lastname) < 0) || ((strcmp(list[i].lastname, list[j].lastname) == 0) && list[i].typePassenger < list[j].typePassenger)) ) ||
					(order == UP && ( (strcmp(list[i].lastname, list[j].lastname) > 0)   || ((strcmp(list[i].lastname, list[j].lastname) == 0) && list[i].typePassenger > list[j].typePassenger)) ) )
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
		printf("\n\n%4s\t%20s\t%20s\t%10s\t%15s\t%20s\t%10s\n\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO DE VUELO", "TIPO DE PASAJERO", "ESTATUS");
		printf("-------------------------------------------------------------------------------------------------------------------------------------\n\n");

		for(i = 0; i < length; i++)
		{
			if( list[i].isEmpty == FALSE) // If occupied.
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
			printf("%04d\t%20s\t%20s\t$ %.2f\t%10s\t%20s\t%10s\n",	aPassenger.id,
																	aPassenger.name,
																	aPassenger.lastname,
																	aPassenger.price,
																	aPassenger.flycode,
																	typePassName,
																	flightStatusName);
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
				if( (order == UP && strcmp(list[i].flycode, list[j].flycode) > 0) ||
					(order == DOWN && strcmp(list[i].flycode, list[j].flycode) < 0)	)
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
		ret = 0;
		printf("\n\n%s\t%20s\t%20s\t%10s\t%15s\t%20s\t%10s\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO DE VUELO", "TIPO DE PASAJERO", "ESTATUS");
		printf("-------------------------------------------------------------------------------------------------------------------------------------\n\n");

		for(i = 0; i < len; i++)
		{
			if(list[i].statusFlight == ACTIVO && list[i].isEmpty == FALSE)
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
	int i;
	int j;

	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		for(i = 0; i < len-1; i++)
		{
			for(j = i+1; j < len; j++)
			{
				if( (order == UP && list[i].id > list[j].id) ||
					(order == DOWN && list[i].id < list[j].id) )
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

	if(list != NULL && list[PassengerA].isEmpty == FALSE && list[PassengerB].isEmpty == FALSE)
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
			if( list[i].isEmpty == FALSE) // If occupied.
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

	if(actualName != NULL && list != NULL && index >= 0)
	{
		printf("\nNombre actual: %s\n", actualName);

		if(utn_getStringLetras(auxName, sizeof(auxName), "Ingrese nuevo nombre: ", "Error. ", 2) == 0)
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

	if(actualLastName != NULL && list != NULL && index >= 0)
	{
		printf("\nApellido actual: %s\n", actualLastName);

		if(utn_getStringLetras(auxName, sizeof(auxName), "Ingrese nuevo apellido: ", "Error. ", 2) == 0)
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

	if(actualPrice > 0 && list != NULL && index >= 0)
	{
		printf("\nPrecio actual: %.2f\n", actualPrice);

		if(utn_getNumeroFloat(&auxFloat, "Ingrese nuevo importe: ", "Error. ", 0.01, MAX_PRICE, 2) == 0)
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
	int auxTypePass;

	if(actualTypePassId > 0 && list != NULL && index >= 0 && typePassenger != NULL && typeLen > 0)
	{
		if(getTypePassengerName(actualTypePassId, typePassenger, typeLen, typePassengerName) == 0)
		{
			printf("\nTipo de pasajero actual: %s\n", typePassengerName);
		}

		printAllTypePassengers(typePassenger, typeLen, "\n\t\tCLASES DE VUELOS\n");
		if(utn_getNumeroInt(&auxTypePass, "\nIngrese tipo de pasajero (por numero): ", "Error. ", 1, typeLen, 2) == 0)
		{
			list[index].typePassenger = getTypePassengerByIndex(typePassenger, auxTypePass-1);
			ret = 0;
		}
	}

	return ret;
}


int modifyFlycode(sPassenger* list, char actualCode[], int index)
{
	int ret = -1;
	char auxName[QTY_CODE];

	if(actualCode != NULL && list != NULL && index >= 0)
	{
		printf("\nCodigo de vuelo actual: %s\n", actualCode);

		if(utn_getStringAlphaNum(auxName, sizeof(auxName), "Ingrese nuevo codigo de vuelo: ", "Error. ", 2) == 0)
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
			if( list[i].isEmpty == FALSE ) // If occupied.
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
		if( list[indexPosition].isEmpty == FALSE )
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

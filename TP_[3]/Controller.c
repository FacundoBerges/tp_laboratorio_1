#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "TypePassenger.h"
#include "StatusFlight.h"
#include "Controller.h"
#include "parser.h"
#include "inputs.h"



/**
 * @fn int getID(int*)
 * @brief	obtiene ID del archivo nextId.bin o asigna el ID 1001 en caso de no existir archivo
 *
 * @param id	id a asignar.
 * @return	0 si se leyo el archivo, -1 ERROR
 */
static int getID(int* id);
static int getID(int* id)
{
	int rtn = -1;
	FILE* pFileID = NULL;

	if(id != NULL)
	{
		*id = 1001; // Si no esta creado el archivo utiliza el ID 1001 como primer ID
		pFileID = fopen("nextId.bin", "rb");

		if(pFileID != NULL)
		{
			fread(id, sizeof(int), 1, pFileID);
			rtn = 0;
		}

		fclose(pFileID);
	}

	return rtn;
}


/**
 * @fn int saveID(int)
 * @brief 	guarda el siguiente ID a ser asignado.
 *
 * @param id	id actual.
 * @return	0 si se pudo actualizar archivo, -1 ERROR
 */
static int saveID(int id);
static int saveID(int id)
{
	int rtn = -1;
	FILE* pFileID = NULL;

	id++;

	pFileID = fopen("nextId.bin", "wb");

	if(pFileID != NULL)
	{
		fwrite(&id, sizeof(int), 1, pFileID);	// Escribo el siguiente ID en el archivo nextId.bin
		rtn = 0;
	}

	fclose(pFileID);

	return rtn;
}





int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	FILE* pFile = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "r");

		if(pFile != NULL)
		{
			rtn = parser_PassengerFromText(pFile, pArrayListPassenger);
		}

		fclose(pFile);
	}

    return rtn;
}



int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	FILE* pFile = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "rb");

		if(pFile != NULL)
		{
			rtn = parser_PassengerFromBinary(pFile, pArrayListPassenger);
		}

		fclose(pFile);
	}

	return rtn;
}



int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;

	int auxId = 0;
	int auxTypePassengerId = 0;
	int auxStatusFlightId = 0;
	float auxPrice = 0;
	char auxName[50];
	char auxLastname[50];
	char auxFlycode[8];
	Passenger* auxPassenger = NULL;

	if(pArrayListPassenger != NULL)
	{
		system("cls");
		printf("\n\n\t\t\tALTA DE PASAJERO\n\n");

		auxPassenger = Passenger_new();

		if(auxPassenger != NULL)
		{
			rtn = -4;	// Predeterminado Si se agotaron los reintentos de ingresos de datos.

					/*			obtencion de datos 			*/
			if(utn_getStringLetras(auxName, sizeof(auxName), "\nIngrese nombre: ", "Error.", 2) == 0)
			{
				if(utn_getStringLetras(auxLastname, sizeof(auxLastname), "\nIngrese apellido: ", "Error.", 2) == 0)
				{
					if(utn_getNumeroFloat(&auxPrice, "\nIngrese precio: ", "Error.", 0.00001, 1000000000, 2) == 0)
					{
						showTypePassenger();
						if(utn_getNumeroInt(&auxTypePassengerId, "\nIngrese tipo de pasajero (por numero): ", "Error.", 1, 3, 2) == 0)
						{
							if(utn_getStringAlphaNum(auxFlycode, sizeof(auxFlycode), "\nIngrese codigo de vuelo: ", "Error. Maximo 7 Caracteres. ", 2) == 0)
							{
								showFlightStatus();
								if(utn_getNumeroInt(&auxStatusFlightId, "\nIngrese estatus de vuelo (por numero): ", "Error.", 1, 4, 2) == 0)
								{
									getID(&auxId); // Obtengo el siguiente ID de archivo binario, si no existe se crea con el ID 1001
									saveID(auxId);

									if(	Passenger_setId(auxPassenger, auxId) == 0 &&
										Passenger_setNombre(auxPassenger, auxName) == 0 &&
										Passenger_setApellido(auxPassenger, auxLastname) == 0 &&
										Passenger_setPrecio(auxPassenger, auxPrice) == 0 &&
										Passenger_setTipoPasajero(auxPassenger, auxTypePassengerId) == 0 &&
										Passenger_setCodigoVuelo(auxPassenger, auxFlycode) == 0 &&
										Passenger_setFlightStatus(auxPassenger, auxStatusFlightId) == 0	)
									{
										if(ll_add(pArrayListPassenger, auxPassenger) == 0)
										{
											rtn = 0;		// Si se pudieron conseguir todos los datos y se anadio correctamente en el array.
										}
									}
									else
									{
										rtn = -2;	// Error al setear datos.
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			rtn = -3;	// No se consiguio espacio en memoria para un nuevo pasajero.
		}
	}

    return rtn;
}




int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;

	int idAux;
	int maxId;
	int index;
	int len = ll_len(pArrayListPassenger);
	int auxInt;
	int option;
	char auxFlycode[8];
	char auxString[50];
	float auxPrice;
	Passenger* auxPassenger = NULL;

	if(pArrayListPassenger != NULL && len > 0)
	{
		system("cls");
		printf("\n\n\t\t\tMODIFICAR DATOS DE PASAJERO\n\n");

		ll_sort(pArrayListPassenger, Passenger_compareById, 1); // Ordeno por ID.
		listAllPassengers(pArrayListPassenger);	// Muestro la lista de pasajeros actual.

		auxPassenger = (Passenger*) ll_get(pArrayListPassenger, len-1);
		Passenger_getId(auxPassenger, &maxId); // Traigo el ultimo pasajero de la lista y busco su ID.
		printf("\n");

		if(	auxPassenger != NULL && utn_getNumeroInt(&idAux, "Ingrese ID de pasajero a modificar: ", "Error. El ID ingresado no es valido. ", 1, maxId, 2) == 0)
		{
			index = Passenger_getIndexById(pArrayListPassenger, idAux);

			if(index != -1)
			{
				auxPassenger = ll_get(pArrayListPassenger, index);

				if(auxPassenger != NULL)
				{
					printf("\n\nPasajero a modificar:\n");
					printf("\n%3s\t%15s\t%15s\t%8s\t%15s\t%10s\t%15s\n\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "TIPO PASAJERO", "CODIGO", "ESTATUS");
					showPassenger(auxPassenger);

					printf("\n\n1. Modificar Nombre.\n2. Modificar Apellido.\n3. Modificar Precio.\n4. Modificar Tipo de pasajero.\n5. Modificar Codigo de vuelo\n6. Modificar Estatus de vuelo.\n0. Volver al menu principal.\n\n");

					if(utn_getNumeroInt(&option, "Ingrese dato a modificar: ", "Error. ", 0, 6, 2) == 0)
					{
						printf("\n");
						switch(option)
						{
							case 1:
								if(utn_getStringLetras(auxString, sizeof(auxString), "Ingrese nuevo nombre: ", "\nError... ", 2) == 0 && Passenger_setNombre(auxPassenger, auxString) == 0)
								{
									rtn = 0;
								}
								break;
							case 2:
								if(utn_getStringLetras(auxString, sizeof(auxString), "Ingrese nuevo apellido: ", "\nError... ", 2) == 0 && Passenger_setApellido(auxPassenger, auxString) == 0)
								{
									rtn = 0;
								}
								break;
							case 3:
								if(utn_getNumeroFloat(&auxPrice, "Ingrese nuevo precio: ", "\nError... ", 0.00001, 1000000000, 2) == 0 && Passenger_setPrecio(auxPassenger, auxPrice) == 0)
								{
									rtn = 0;
								}
								break;
							case 4:
								showTypePassenger();
								if(utn_getNumeroInt(&auxInt, "Ingrese tipo de pasajero (por numero): ", "\nError. ", 1, 3, 2) == 0 && Passenger_setTipoPasajero(auxPassenger, auxInt) == 0)
								{
									rtn = 0;
								}
								break;
							case 5:
								if(utn_getStringAlphaNum(auxFlycode, sizeof(auxFlycode), "Ingrese nuevo codigo de vuelo: ", "\nError... ", 2) == 0 && Passenger_setCodigoVuelo(auxPassenger, auxFlycode) == 0)
								{
									rtn = 0;
								}
								break;
							case 6:
								showFlightStatus();
								if(utn_getNumeroInt(&auxInt, "Ingrese nuevo estatus de vuelo (por numero): ", "\nError. ", 1, 4, 2) == 0 && Passenger_setFlightStatus(auxPassenger, auxInt) == 0)
								{
									rtn = 0;
								}
								break;
							case 0:
								printf("\nCancelando Modificacion...\n");
								rtn = -2; //modificacion cancelada
								break;
							default:
								printf("\nOpcion ingresada invalida.\n");
								break;
						}
					}
					else
					{
						rtn = -3;	//	Se acabaron los reintentos de ingresar opciones
					}
				}
				else
				{
					rtn = -4; //	Error al conseguir datos del pasajero
				}
			}
			else
			{
				rtn = -5;	// Error a conseguir pasajero segun ID ingresado.
			}
		}
		else
		{
			rtn = -6; //	No se consiguio informacion del ultimo pasajero ordenado por ID o se acabaron reintentos de ingreso de ID.
		}
	}

    return rtn;
}




int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;

	int idAux;
	int maxId;
	int index;
	int len = ll_len(pArrayListPassenger);
	char confirm;
	Passenger* auxPassenger = NULL;

	if(pArrayListPassenger != NULL && len > 0)
	{
		system("cls");
		printf("\n\n\t\t\tBAJA DE PASAJERO\n\n");

		ll_sort(pArrayListPassenger, Passenger_compareById, 1);	// Orden por ID asc.
		listAllPassengers(pArrayListPassenger);	// lista de pasajeros

		auxPassenger = (Passenger*) ll_get(pArrayListPassenger, len-1);
		Passenger_getId(auxPassenger, &maxId); // Traigo el ultimo pasajero de la lista y busco su ID.
		printf("\n");

		if(auxPassenger != NULL)
		{
			if(utn_getNumeroInt(&idAux, "Ingrese ID de pasajero a eliminar: ", "Error. El ID ingresado no es valido. ", 1, maxId, 2) == 0)
			{
				index = Passenger_getIndexById(pArrayListPassenger, idAux);

				if(index != -1)
				{
					auxPassenger = (Passenger*) ll_get(pArrayListPassenger, index);

					if(auxPassenger != NULL)
					{
						printf("\n\nPasajero a dar de baja:\n");
						printf("\n%3s\t%15s\t%15s\t%8s\t%15s\t%10s\t%15s\n\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "TIPO PASAJERO", "CODIGO", "ESTATUS");
						showPassenger(auxPassenger);
						utn_getCharacterLower(&confirm, "\nDesea dar de baja el empleado seleccionado? ('S' para confirmar, otra letra para cancelar): ", "\nError.", 'a', 'z', 2);
						fflush(stdin);

						if(confirm == 's')
						{
							ll_remove(pArrayListPassenger, index);
							Passenger_delete(auxPassenger);
							rtn = 0; // baja exitosa.
						}
						else
						{
							rtn = -2; //baja cancelada
						}
					}
					else
					{
						rtn = -3;	// Error al conseguir datos de pasajero
					}
				}
				else
				{
					rtn = -4;	// ID ingresado no se encuentra dado de alta
				}
			}
			else
			{
				rtn = -5;	//	Se agotaron reintentos de ingreso de ID
			}
		}
		else
		{
			rtn = -6;	// No se pudo traer datos de ultimo pasajero de la lista
		}
	}

    return rtn;
}




int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;

	if(pArrayListPassenger != NULL)
	{
		system("cls");
		printf("\n\n\t\t\t\t\tLISTA DE PASAJEROS\n\n");

		rtn = listAllPassengers(pArrayListPassenger);
	}

    return rtn;
}





int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int option;
	int order;

	if(pArrayListPassenger != NULL)
	{
		system("cls");
		printf("\n\n\t\t\t\t\tORDENAR LISTA DE PASAJEROS\n\n1. Ordenar por ID.\n2. Ordenar por Nombre.\n3. Ordenar por Apellido.\n4. Ordenar por Precio.\n5. Ordenar por Tipo de pasajero.\n6. Ordenar por Codigo de vuelo\n7. Ordenar por Estatus de vuelo.\n8. Volver al menu principal.\n\n");

		if(utn_getNumeroInt(&option, "Ingrese una opcion: ", "Opcion ingresada invalida.\n", 1, 8, 2) == 0)
		{
			if(option >= 1 && option <= 7)
			{
				if(utn_getNumeroInt(&order, "Ingrese orden (1. Ascendente / 0. Descendente): ", "Error.\n", 0, 1, 2) == 0)
				{
					printf("\n\nOrdenando pasajeros...\n");
				}
				else
				{
					rtn = -3;	// Se agotaron los reintentos
				}
			}
			else
			{
				rtn = -2;	// Se cancelo ordenamiento
			}

			if(rtn != -3)
			{
				switch(option)
				{
					case 1:
						rtn = ll_sort(pArrayListPassenger, Passenger_compareById, order);
						break;
					case 2:
						rtn = ll_sort(pArrayListPassenger, Passenger_compareByName, order);
						break;
					case 3:
						rtn = ll_sort(pArrayListPassenger, Passenger_compareByLastname, order);
						break;
					case 4:
						rtn = ll_sort(pArrayListPassenger, Passenger_compareByPrice, order);
						break;
					case 5:
						rtn = ll_sort(pArrayListPassenger, Passenger_compareByTypePassenger, order);
						break;
					case 6:
						rtn = ll_sort(pArrayListPassenger, Passenger_compareByFlycode, order);
						break;
					case 7:
						rtn = ll_sort(pArrayListPassenger, Passenger_compareByFlightStatus, order);
						break;
					case 8:
						printf("\nCancelando Ordenamiento...\n");
						break;
					default:
						printf("\nOpcion ingresada invalida.\n");
						break;
				}
			}
		}
		else
		{
			rtn = -4;	// Se agotaron los reintentos
		}
	}

    return rtn;
}



int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int len = ll_len(pArrayListPassenger);
	int i;
	Passenger* auxPassenger = NULL;
	FILE* pFile = NULL;

	int auxId;
	int auxTypePassengerId;
	int auxStatusFlightId;
	float auxPrice;
	char auxName[50];
	char auxLastname[50];
	char auxFlycode[8];
	char auxTypePassengerName[20];
	char auxStatusFlightName[20];

	if(path != NULL && pArrayListPassenger != NULL && len > 0)
	{
		pFile = fopen(path, "w");

		if(pFile != NULL)
		{

			fprintf(pFile, "id,name,lastname,price,flycode,typePassenger,statusFlight\n"); // header

			for(i = 0; i < len; i++)
			{
				auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

				if(auxPassenger != NULL)
				{
					if(	Passenger_getId(auxPassenger, &auxId) == 0 &&
						Passenger_getNombre(auxPassenger, auxName) == 0 &&
						Passenger_getApellido(auxPassenger, auxLastname) == 0 &&
						Passenger_getPrecio(auxPassenger, &auxPrice) == 0 &&
						Passenger_getCodigoVuelo(auxPassenger, auxFlycode) == 0 &&
						Passenger_getTipoPasajero(auxPassenger, &auxTypePassengerId) == 0 &&
						Passenger_getFlightStatus(auxPassenger, &auxStatusFlightId) == 0 &&
						TypePassenger_getNameById(auxTypePassengerId, auxTypePassengerName) == 0 &&
						StatusFlight_getNameById(auxStatusFlightId, auxStatusFlightName) == 0)
					{
						fprintf(pFile, "%d,%s,%s,%f,%s,%s,%s\n", auxId, auxName, auxLastname, auxPrice, auxFlycode, auxTypePassengerName, auxStatusFlightName);
						rtn = 0;
					}
				}
			}
		}

		fclose(pFile);
	}

    return rtn;
}



int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int len;
	int i;
	Passenger* auxPassenger = NULL;
	FILE* pFile = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "wb");

		if(pFile != NULL)
		{
			len = ll_len(pArrayListPassenger);

			for(i = 0; i < len; i++)
			{
				auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

				if(auxPassenger != NULL)
				{
					fwrite(auxPassenger, sizeof(Passenger), 1, pFile);
					rtn = 0;
				}
			}
		}

		fclose(pFile);
	}

	return rtn;
}


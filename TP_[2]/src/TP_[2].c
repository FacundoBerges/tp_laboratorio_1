/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Facundo Hector Berges
 Version     : 1.0
 Copyright   :
 Description : Trabajo Practico Nro 2 - Laboratorio 1 - 1er cuatrimestre, 2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "ArrayTypePassenger.h"
#include "ArrayFlight.h"
#include "inputs.h"

#define MAX_PASSENGER 2000
#define MAX_TYPE_PASSENGER 3
#define MAX_FLIGHT_STATUS 3


int main(void) {
	setbuf(stdout, NULL);

	char confirm = 'n';
    int option;
    int cantCargados = 0;

	sPassenger passengers[MAX_PASSENGER];
	sTypePassenger typePassenger[MAX_TYPE_PASSENGER] = {	{101, "ECONOMICA"},
															{102, "EJECUTIVA"},
															{103, "PRIMERA CLASE"}	};
	sFlightStatus flightStatus[MAX_FLIGHT_STATUS] = {	{1, "ACTIVO"},
														{2, "ATRASADO"},
														{3, "SUSPENDIDO"}	};

	initPassengers(passengers, MAX_PASSENGER);

	do
	{
		fflush(stdin);
		printf("\n\n\t\t\tADMINISTRADOR DE PASAJES AEREOS\n\n1. ALTAS\n2. MODIFICAR\n3. BAJA\n4. INFORMAR\n5. CARGA FORZADA DE DATOS\n6. SALIR\n\n");
		utn_getNumeroInt(&option, "Ingrese una opcion: ", "Error. (opciones 1 a 5, o 6 para salir). ", 1, 6, 2);

		switch(option)
		{
			case 1:
				if(cargarDatos(passengers, MAX_PASSENGER, typePassenger, MAX_TYPE_PASSENGER, flightStatus, MAX_FLIGHT_STATUS, &cantCargados) == 0)
				{
					printf("\n\nAlta exitosa!!\n");
				}
				else
				{
					printf("\n\nError al cargar datos... volviendo al menu.\n");
				}
				break;
			case 2:
				if(cantCargados != 0)
				{
					if(modifyPassenger(passengers, MAX_PASSENGER, typePassenger, MAX_TYPE_PASSENGER, flightStatus, MAX_FLIGHT_STATUS) == 0)
					{
						printf("\n\nModificacion exitosa!!\n");
					}
					else
					{
						printf("\n\nError al modificar datos... volviendo al menu.\n");
					}
				}
				else
				{
					printf("\n\nAntes de ingresar a las modificaciones, debe cargar datos!! --- [Error, no se encuentran datos cargados]\n");
				}
				break;
			case 3:
				if(cantCargados != 0)
				{
					if(removePassengersMenu(passengers, MAX_PASSENGER, typePassenger, MAX_TYPE_PASSENGER, flightStatus, MAX_FLIGHT_STATUS, &cantCargados) == 0)
					{
						printf("\n\nPasajero dado de baja correctamente!!\n");
					}
					else
					{
						printf("\nEl pasajero no se ha dado de baja... volviendo al menu.\n");
					}
				}
				else
				{
					printf("\n\nAntes de ingresar a las bajas, debe cargar datos!! --- [Error, no se encuentran datos cargados]\n");
				}
				break;
			case 4:
				if(cantCargados != 0)
				{
					if(reportPassenger(passengers, MAX_PASSENGER, typePassenger, MAX_TYPE_PASSENGER, flightStatus, MAX_FLIGHT_STATUS) != 0)
					{
						printf("\nError al generar informes... volviendo al menu.\n");
					}
				}
				else
				{
					printf("\n\nAntes de ingresar a los informes, debe cargar datos!! --- [Error, no se encuentran datos cargados]\n");
				}
				break;
			case 5:
				if(altaForzada(passengers, MAX_PASSENGER, typePassenger, flightStatus, &cantCargados) == 0)
				{
					printf("\n\nCargar de datos forzada correctamente!!\n");
				}
				else
				{
					printf("\nError al cargar datos de manera forzada... volviendo al menu.\n");
				}
				break;
			case 6:
				utn_getCharacterLower(&confirm, "Esta seguro que desea salir del programa? (S/N): ", "\nVolviendo al menu principal...\n\n", 'a', 'z', 0);
				break;
			default:
				printf("\nOpcion invalida. Volviendo al menu.\n");
				break;
		}

	} while (confirm != 's');

	printf("\n\nSaliendo del programa...\n\n");
	system("pause");

	return EXIT_SUCCESS;
}

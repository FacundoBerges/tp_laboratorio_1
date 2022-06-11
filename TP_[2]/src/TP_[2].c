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

	int option;
	int arrayCargado;

	sTypePassenger typePassenger[MAX_TYPE_PASSENGER] = {	{101, "ECONOMICA"},
															{102, "EJECUTIVA"},
															{103, "PRIMERA CLASE"}	};
	sFlightStatus flightStatus[MAX_FLIGHT_STATUS] = {	{1, "ACTIVO"},
														{2, "ATRASADO"},
														{3, "SUSPENDIDO"}	};
	sPassenger passengers[MAX_PASSENGER];

	initPassengers(passengers, MAX_PASSENGER);


	do
	{
		system("cls");
		arrayCargado = findOccupied(passengers, MAX_PASSENGER);
		option = printMenu("\n\t\t\tADMINISTRADOR DE PASAJES AEREOS\n\n1. ALTAS\n2. MODIFICAR\n3. BAJA\n4. INFORMAR\n5. CARGA FORZADA DE DATOS\n0. SALIR\n\n", 4);
		fflush(stdin);

		switch(option)
		{
			case 1:
				if(cargarDatos(passengers, MAX_PASSENGER, typePassenger, MAX_TYPE_PASSENGER, flightStatus, MAX_FLIGHT_STATUS) == 0)
				{
					printf("\n\nAlta exitosa!!\n");
				}
				else
				{
					printf("\n\nError al cargar datos... volviendo al menu.\n");
				}
				system("pause");
				break;
			case 2:
				if(arrayCargado == 0)
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
				system("pause");
				break;
			case 3:
				if(arrayCargado == 0)
				{
					if(removePassengersMenu(passengers, MAX_PASSENGER, typePassenger, MAX_TYPE_PASSENGER, flightStatus, MAX_FLIGHT_STATUS) == 0)
					{
						printf("\n\nPasajero dado de baja correctamente!!\n");
					}
					else
					{
						printf("El pasajero no se ha dado de baja... volviendo al menu.\n");
					}
				}
				else
				{
					printf("\n\nAntes de ingresar a las bajas, debe cargar datos!! --- [Error, no se encuentran datos cargados]\n");
				}
				system("pause");
				break;
			case 4:
				if(arrayCargado == 0)
				{
					if(reportPassenger(passengers, MAX_PASSENGER, typePassenger, MAX_TYPE_PASSENGER, flightStatus, MAX_FLIGHT_STATUS) != 0)
					{
						printf("Error al generar informes... volviendo al menu.\n");
					}
				}
				else
				{
					printf("\n\nAntes de ingresar a los informes, debe cargar datos!! --- [Error, no se encuentran datos cargados]\n");
				}
				system("pause");
				break;
			case 5:
				if(altaForzada(passengers, MAX_PASSENGER, typePassenger, flightStatus) != -1)
				{
					printf("\n\nCargar de datos forzada correctamente!!\n");
				}
				else
				{
					printf("Error al cargar datos de manera forzada... volviendo al menu.\n");
				}
				system("pause");
				break;
			case 0:
				printf("\n\nSaliendo del programa...\n");
				break;
			default:
				printf("\nOpcion invalida. Volviendo al menu.\n");
				system("pause");
				break;
		}
	} while (option != 0);

	system("pause");

	return EXIT_SUCCESS;
}

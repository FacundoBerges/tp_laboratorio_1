/*
 * Informes.c
 *
 *  Created on: Apr 16, 2022
 *      Author: Facundo Berges
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Informes.h"
#include "Inputs.h"
#include "Calculos.h"


// *********	Funciones de muestra de datos	*********

void MostrarMenu(void){
	char opcionIngresada;
	char opcionSubMenu;
	char salir;
	int flagContinuar;
	int flagKilometros;
	int flagAerolineas;
	int flagLatam;
	int flagCalculos;
	int kilometrosIngresados;
	float precioBaseAerolineas;
	float precioBaseLatam;
	float descuentoDebito;
	float diferenciaPreciosLatamAerolineas;
	float interesCredito;
	float precioBTCAerolineas;
	float precioBTCLatam;
	float precioCredAerolineas;
	float precioCredLatam;
	float precioDebAerolineas;
	float precioDebLatam;
	float precioPorKilometroAerolineas;
	float precioPorKilometroLatam;
	float precioPorBTC;

	flagContinuar = 1;
	flagKilometros = 0;
	flagAerolineas = 0;
	flagLatam = 0;
	flagCalculos = 0;
	kilometrosIngresados = 0;
	precioBaseAerolineas = 0;
	precioBaseLatam = 0;
	descuentoDebito = 0.10;
	interesCredito = 0.25;
	precioPorBTC = 4753767.31;

	setbuf(stdout, NULL);

	do {

		system("cls");
		printf("CALCULADORA DE VUELOS AEREOS\n\n\n");
		MostrarOpcionesMenu(kilometrosIngresados, precioBaseAerolineas, precioBaseLatam);
		printf("Ingrese una opcion: ");
		fflush(stdin);
		scanf("%c", &opcionIngresada);
		printf("\n");

		switch(opcionIngresada){
			case '1':
				system("cls");
				kilometrosIngresados = IngresarKM();
				if(kilometrosIngresados != 0){
					flagKilometros = 1;
				}
				else
				{
					flagKilometros = 0;
					flagCalculos = 0;
				}
				break;
			case '2':
				system("cls");
				printf("A. Precio vuelo Aerolineas.\n");
				printf("B. Precio vuelo Latam.\n");
				printf("C. Salir\n\n");
				printf("Ingrese una opcion: ");
				fflush(stdin);
				scanf("%c", &opcionSubMenu);
				opcionSubMenu = toupper(opcionSubMenu);
				while(opcionSubMenu != 'A' && opcionSubMenu != 'B' && opcionSubMenu != 'C')
				{
					printf("\nERROR. La opcion ingresada no es valida. Ingrese opcion (A o B, o C para volver al menu principal): ");
					fflush(stdin);
					scanf("%c", &opcionSubMenu);
					opcionSubMenu = toupper(opcionSubMenu);
				}
				printf("\n\n");
				if(opcionSubMenu == 'A')
				{
					precioBaseAerolineas = IngresarPrecio("Aerolineas Argentinas");
					if(precioBaseAerolineas != 0)
					{
						flagAerolineas = 1;
					}
					else
					{
						flagAerolineas = 0;
						flagCalculos = 0;
					}
				}
				else if(opcionSubMenu == 'B')
				{
					precioBaseLatam = IngresarPrecio("Latam");
					if(precioBaseLatam != 0){
						flagLatam = 1;
					}
					else
					{
						flagLatam = 0;
						flagCalculos = 0;
					}
				}
				break;
			case '3':
				system("cls");
				if(flagKilometros && flagAerolineas && flagLatam)
				{
					printf("Realizando calculos.\n");
					CalcularCostos(precioBaseAerolineas, descuentoDebito, interesCredito, precioPorBTC, kilometrosIngresados, &precioDebAerolineas, &precioCredAerolineas, &precioBTCAerolineas, &precioPorKilometroAerolineas);
					CalcularCostos(precioBaseLatam, descuentoDebito, interesCredito, precioPorBTC, kilometrosIngresados, &precioDebLatam, &precioCredLatam, &precioBTCLatam, &precioPorKilometroLatam);
					CalcularDiferenciaPrecios(precioBaseAerolineas, precioBaseLatam, &diferenciaPreciosLatamAerolineas);
					flagCalculos = 1;
					system("pause");
				}
				else if(!flagKilometros && !flagAerolineas && !flagLatam)
				{
					printf("No se ingresaron datos en kilometros ni precios de las aerolineas.\n");
					system("pause");
				}
				else if(!flagKilometros)
				{
					printf("No se ingresaron cantidad de kilometros.\n");
					system("pause");
				}
				else if(!flagAerolineas || !flagLatam)
				{
					printf("No se ingreso precio de Aerolineas o Latam.\n");
					system("pause");
				}
				fflush(stdin);
				break;
			case '4':
				system("cls");
				if(flagCalculos)
				{
					InformarResultados(kilometrosIngresados, precioBaseAerolineas, precioDebAerolineas, precioCredAerolineas, precioBTCAerolineas, precioPorKilometroAerolineas, precioBaseLatam, precioDebLatam, precioCredLatam, precioBTCLatam, precioPorKilometroLatam, diferenciaPreciosLatamAerolineas);
					system("pause");
				}
				else
				{
					printf("Antes de mostrar los informes se deben realizar los calculos (opcion 3).\n");
				}

				if(!flagKilometros && !flagAerolineas && !flagLatam)
				{
					printf("No se ingresaron datos en kilometros ni precios de las aerolineas.\n");
					system("pause");
				}
				else if(!flagKilometros)
				{
					printf("No se ingresaron cantidad de kilometros.\n");
					system("pause");
				}
				else if(!flagAerolineas || !flagLatam)
				{
					printf("No se ingreso precio de Aerolineas o Latam.\n");
					system("pause");
				}

				break;
			case '5':
				InformarCargaForzada(7090, 162965.00, 159339.00, descuentoDebito, interesCredito, precioPorBTC);
				system("cls");
				break;
			case '6':
				system("cls");
				printf("\nDesea salir del programa? (S/N): ");
				fflush(stdin);
				scanf("%c", &salir);
				salir = tolower(salir);
				while(salir != 's' && salir != 'n'){
					printf("\nERROR. La opcion ingresada no es valida. Desea salir del programa? (S/N): ");
					fflush(stdin);
					scanf("%c", &salir);
					salir = tolower(salir);
				}
				if(salir == 's'){
					flagContinuar = 0;
				}
				break;
			default:
				printf("ERROR. La opcion ingresada no es valida. Reingrese una opcion (opciones 1 a 6).\n");
				break;
		}

	} while (flagContinuar);

	printf("\n\nCerrando programa...\n");
	system("pause");
}


void MostrarOpcionesMenu(int kilometros, float precioAerolineas, float precioLatam)
{
	printf("1. Ingresar Kilometros: (KM = %d)\n", kilometros);
	printf("2. Ingresar Precio de Vuelos: (Aerolineas = $ %.2f, Latam = $ %.2f)\n", precioAerolineas, precioLatam);
	printf("3. Calcular todos los costos: \n");
	printf("4. Informar Resultados \n");
	printf("5. Carga forzada de datos \n");
	printf("6. Salir \n\n");
}


void InformarResultados(int kms, float precioLinea1, float precioDebitoLinea1, float precioCreditoLinea1, float precioBTCLinea1, float precioUnitarioLinea1, float precioLinea2, float precioDebitoLinea2, float precioCreditoLinea2, float precioBTCLinea2, float precioUnitarioLinea2, float diferenciaDePrecios)
{
	printf("KMs Ingresados: %d km\n\n", kms);
	InformarLineaAerea("Aerolineas", precioLinea1, precioDebitoLinea1, precioCreditoLinea1, precioBTCLinea1, precioUnitarioLinea1);
	printf("\n\n");
	InformarLineaAerea("Latam", precioLinea2, precioDebitoLinea2, precioCreditoLinea2, precioBTCLinea2, precioUnitarioLinea2);
	printf("\n\n");
	printf("La diferencia de precio es: $ %.2f\n\n", diferenciaDePrecios);
}


void InformarLineaAerea(char lineaAerea[], float precio, float precioDebito, float precioCredito, float precioBTC, float precioUnitario)
{
	printf("Precio %s: $%.2f\n", lineaAerea, precio);
	printf("a) Precio con tarjeta de debito: $ %.2f\n", precioDebito);
	printf("b) Precio con tarjeta de credito: $ %.2f\n", precioCredito);
	printf("c) Precio pagando con bitcoin: %f BTC\n", precioBTC);
	printf("d) Mostrar precio unitario: $ %.2f", precioUnitario);
}


void InformarCargaForzada(int kms, float precioLinea1, float precioLinea2, float descuento, float interes, float precioBitcoin)
{
	float precioDebito1;
	float precioDebito2;
	float precioCredito1;
	float precioCredito2;
	float precioBTC1;
	float precioBTC2;
	float precioUnitario1;
	float precioUnitario2;
	float diferenciaPrecio;

	CalcularCostos(precioLinea1, descuento, interes, precioBitcoin, kms, &precioDebito1, &precioCredito1, &precioBTC1, &precioUnitario1);
	CalcularCostos(precioLinea2, descuento, interes, precioBitcoin, kms, &precioDebito2, &precioCredito2, &precioBTC2, &precioUnitario2);
	CalcularDiferenciaPrecios(precioLinea1, precioLinea2, &diferenciaPrecio);
	system("cls");
	InformarResultados(kms, precioLinea1, precioDebito1, precioCredito1, precioBTC1, precioUnitario1, precioLinea2, precioDebito2, precioCredito2, precioBTC2, precioUnitario2, diferenciaPrecio);
	printf("\n\n");
	system("pause");
}

/*
 ============================================================================
 Name        : TP1.c
 Author      : Facundo Hector Berges
 Version     : 0.8.23
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int IngresarKM(void);
float IngresarPrecio(char lineaAerea[]);
void MostrarMenu(void);
void MostrarOpcionesMenu(int kilometros, float precioAerolineas, float precioLatam);



int main(void) {

	MostrarMenu();

	return EXIT_SUCCESS;
}



// *********	Funciones de muestra de datos	*********

void MostrarMenu(void){
	char opcionIngresada;
	char salir;
	int flagContinuar;
	int flagKilometros;
	int flagAerolineas;
	int flagLatam;
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
				break;
			case '2':
				system("cls");
				precioBaseAerolineas = IngresarPrecio("Aerolineas Argentinas");
				precioBaseLatam = IngresarPrecio("LATAM");
				if(precioBaseAerolineas != 0){
					flagAerolineas = 1;
				}
				if(precioBaseLatam != 0){
					flagLatam = 1;
				}
				break;
			case '3':
				system("cls");

				break;
			case '4':
				system("cls");

				break;
			case '5':
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
				while(opcionIngresada < '1' || opcionIngresada > '6'){
					printf("ERROR. La opcion ingresada no es valida. Reingrese una opcion (opciones 1 a 6): ");
					fflush(stdin);
					scanf("%c", &opcionIngresada);
				}
				break;
		}

	} while (flagContinuar == 1);

	printf("\n\nCerrando programa...\n");
	system("pause");
}

void MostrarOpcionesMenu(int kilometros, float precioAerolineas, float precioLatam){
	printf("1. Ingresar Kilómetros: (KM = %d)\n", kilometros);
	printf("2. Ingresar Precio de Vuelos: (Aerolineas = $ %.2f, Latam = $ %.2f)\n", precioAerolineas, precioLatam);
	printf("3. Calcular todos los costos: \n");
	printf("4. Informar Resultados \n");
	printf("5. Carga forzada de datos \n");
	printf("6. Salir \n\n");
}



// *********	Ingreso de datos	*********

int IngresarKM(void){
	int kmIngresados;

	printf("Ingrese cantidad de kilometros: ");
	scanf("%d", &kmIngresados);
	while(kmIngresados < 1){
		printf("ERROR. Ingrese cantidad de kilometros (mayor a 0): ");
		scanf("%d", &kmIngresados);
	}

	return kmIngresados;
}

float IngresarPrecio(char lineaAerea[]){
	float precioIngresado;

	printf("Ingrese precio de la linea aerea %s: ", lineaAerea);
	scanf("%f", &precioIngresado);
	while(precioIngresado < 1){
		printf("ERROR. Ingrese precio de la linea %s (mayor a 0): ", lineaAerea);
		scanf("%f", &precioIngresado);
	}

	return precioIngresado;
}



// *********	Calculo de datos	*********


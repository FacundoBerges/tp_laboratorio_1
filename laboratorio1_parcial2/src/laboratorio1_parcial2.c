/*
1. 	Realizar un programa que lea un archivo .csv (cuyo nombre se pasa como parámetro por
	línea de comandos), con los datos de equipos de cómputo, guardándolos en un
	linkedList de entidades eComputer.

2.	Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio
	idTipo, de manera ascendente.

3.	Imprimir por pantalla los datos de las computadoras. En lugar de idTipo, se deberá
	imprimir dependiendo el caso: 1=>DESKTOP; 2=>LAPTOP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Computer.h"
#include "inputs.h"


int controller_loadFromText(char* path , LinkedList* pArrayList);
int parser_FromText(FILE* pFile , LinkedList* pArrayList);
int controller_List(LinkedList* pArrayList);
int listAll(LinkedList* pArrayList);
int showOne(eComputer* aComputer);
int controller_Map(LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);


int main(void)
{
	setbuf(stdout, NULL);

	char confirm = 'n';
	int option;
	char fileName[64];
	int flagLoadedFromText = 0;
	int flagMapped = 0;

	LinkedList* listaComputadoras = ll_newLinkedList();

	if(listaComputadoras != NULL)
	{
		do
		{
			system("cls");
			printf("\n\n\n\t\t\tMENU DE OPCIONES\n\n\n1. Cargar archivo '.csv'\n2. Ordenar lista.\n3. Mostrar lista.\n4. Aumentar precios de lista.\n5. Guardar archivo con precios actualizados.\n6. Salir.\n\n");
			utn_getNumeroInt(&option, "Ingrese una opcion: ", "(opciones 1 a 6). ", 1, 6, 2);

			switch(option)
			{
				case 1:
					if(utn_getStringArchivo(fileName, sizeof(fileName), "Ingrese nombre del archivo: ", "Error... nombre invalido (solo letras y numeros). ", 3) == 0)
					{
						if(controller_loadFromText(fileName, listaComputadoras) > 0)
						{
							printf("\nDatos de archivo '%s' cargados correctamente!!\n", fileName);
							flagLoadedFromText = 1;
						}
						else
						{
							printf("\nError al cargar datos desde archivo '%s'.\n", fileName);
						}
					}
					else
					{
						printf("\nSe agotaron reintentos de ingreso de nombre de archivo... volviendo al menu\n");
					}

					break;
				case 2:
					if(flagLoadedFromText)
					{
						if(ll_sort(listaComputadoras, Computer_compareByIdTipo, 1) == 0)
						{
							printf("\nComputadoras ordenadas correctamente!!\n");
						}
						else
						{
							printf("\nError al ordenar la lista.\n");
						}
					}
					else
					{
						printf("\nAntes de ordenar una lista debe cargar un archivo.\n");
					}
					break;
				case 3:
					if(flagLoadedFromText)
					{
						if(controller_List(listaComputadoras) == -1)
						{
							printf("\nError al mostrar la lista.\n");
						}
					}
					else
					{
						printf("\nAntes de mostrar una lista debe cargar un archivo.\n");
					}
					break;
				case 4:
					if(flagLoadedFromText)
					{
						if(controller_Map(listaComputadoras) == 0)
						{
							printf("\nPrecios incrementados correctamente.\n");
							flagMapped = 1;
						}
						else
						{
							printf("\nError al aumentar precios de la lista.\n");
						}
					}
					else
					{
						printf("\nAntes de aumentar los precios de una lista debe cargar un archivo.\n");
					}
					break;
				case 5:
					if(flagLoadedFromText && flagMapped)
					{
						if(controller_saveAsText("mapeado.csv", listaComputadoras) == 0)
						{
							printf("\nArchivo guardado correctamente como 'mapeado.csv'!\n");
						}
						else
						{
							printf("\nError. No se pudo guardar el archivo!!\n");
						}
					}
					else
					{
						printf("\nAntes de guardar los datos debe cargar un archivo y aumentar los precios!! (No se encuentran datos cargados para guardar)\n");
					}
					break;
				case 6:
					utn_getCharacterLower(&confirm, "Esta seguro que desea salir del programa? (S/N): ", "\nVolviendo al menu principal...\n\n", 'a', 'z', 0);
					if(confirm == 's')
					{
						printf("\n\nSaliendo del programa...\n\n");
					}
					break;
				default:
					printf("\n\nOpcion Ingresada invalida (opciones 1 a 10)\n");
					break;
			}

			printf("\nPulse 'Enter' para continuar...\n\n");
			fflush(stdin);
			getc(stdin);

		} while(confirm != 's');

		ll_deleteLinkedList(listaComputadoras);
	}

	return EXIT_SUCCESS;
}



int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	int rtn = -1;
	FILE* pFile = NULL;

	if(path != NULL && pArrayList != NULL)
	{
		pFile = fopen(path, "r");

		if(pFile != NULL)
		{
			rtn = parser_FromText(pFile, pArrayList);
		}

		fclose(pFile);
	}

    return rtn;
}


int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
	int qty = -1;
	int qtyHeader;

	char bufferId[8];
	char bufferDesc[512];
	char bufferPrice[16];
	char bufferIdType[8];

	eComputer* pComputer = NULL;

	if(pFile != NULL && pArrayList != NULL)
	{
		qty = 0;

		qtyHeader = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferDesc, bufferPrice, bufferIdType);	// Lectura del encabezado

		while(!feof(pFile))
		{
			if( fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferDesc, bufferPrice, bufferIdType) == qtyHeader)
			{
				pComputer = Computer_newParam(bufferId, bufferDesc, bufferPrice, bufferIdType);

				if(pComputer != NULL)
				{
					if(ll_add(pArrayList, pComputer) == 0)
					{
						qty++; // Computadora agregada
					}
				}
			}
		}
	}

    return qty;
}


int controller_List(LinkedList* pArrayList)
{
	int rtn = -1;

	if(pArrayList != NULL)
	{
		system("cls");
		printf("\n\n\t\t\t\t\tLISTA DE COMPUTADORAS\n\n");

		rtn = listAll(pArrayList);
	}

    return rtn;
}



int listAll(LinkedList* pArrayList)
{
	int rtn = -2;
	int len;
	int i;
	eComputer* pComputer = NULL;

	len = ll_len(pArrayList);

	if(pArrayList != NULL && len > 0)
	{
		rtn = 0;

		printf("%3s\t%40s\t\t\t\t\t\t\t\t%10s\t%8s\n\n", "ID", "DESCRIPCION", "PRECIO", "TIPO");

		for(i = 0; i < len; i++)
		{
			pComputer = (eComputer*) ll_get(pArrayList, i);

			if(pComputer != NULL)
			{
				if(showOne(pComputer) == 0)
				{
					rtn++;
				}
			}
		}
	}

	return rtn;
}


int showOne(eComputer* aComputer)
{
	int rtn = -1;

	int auxId;
	int auxTypeId;
	float auxPrice;
	char auxDescr[512];
	char auxTypeName[16];

	if(aComputer != NULL)
	{
		if(	Computer_getId(aComputer, &auxId) == 0 &&
			Computer_getDesc(aComputer, auxDescr) == 0 &&
			Computer_getPrecio(aComputer, &auxPrice) == 0 &&
			Computer_getIdTipo(aComputer, &auxTypeId) == 0 &&
			Computer_getNombreTipoPorId(auxTypeId, auxTypeName) == 0)
		{
			printf("%4d\t%-100s\t $ %.2f\t%8s\n", auxId, auxDescr, auxPrice, auxTypeName);
			rtn = 0;
		}
	}

	return rtn;
}


int controller_Map(LinkedList* pArrayList)
{
	int rtn = -1;

	if(pArrayList != NULL)
	{
		rtn = ll_map(pArrayList, Computer_incrementarPrecioPorTipo);
	}

    return rtn;
}


int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	int rtn = -1;
	int len = ll_len(pArrayList);
	int i;
	eComputer* pComputer = NULL;
	FILE* pFile = NULL;

	int auxId;
	int auxTypeId;
	float auxPrice;
	char auxDescrip[512];
	//char auxTypeName[16];

	if(path != NULL && pArrayList != NULL && len > 0)
	{
		pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			fprintf(pFile, "id,descripcion,precio,idTipo\n"); // header

			for(i = 0; i < len; i++)
			{
				pComputer = (eComputer*) ll_get(pArrayList, i);

				if(pComputer != NULL)
				{
					if(	Computer_getId(pComputer, &auxId) == 0 &&
						Computer_getDesc(pComputer, auxDescrip) == 0 &&
						Computer_getPrecio(pComputer, &auxPrice) == 0 &&
						Computer_getIdTipo(pComputer, &auxTypeId) == 0 )//&& Computer_getNombreTipoPorId(auxTypeId, auxTypeName) == 0)
					{
						fprintf(pFile, "%d,%s,%f,%d\n", auxId, auxDescrip, auxPrice, auxTypeId);
						rtn = 0;
					}
				}
			}
		}

		fclose(pFile);
	}

    return rtn;
}

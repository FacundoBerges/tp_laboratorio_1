/*
 ============================================================================
 Name        : laboratorio1_recupParcial2.c
 Author      : Facundo Berges
 Version     :
 Copyright   : 
 Description :

	1) Realizar un programa que lea un archivo .csv (cuyo nombre se pasa como parámetro por línea de comandos),
	con los datos de los participantes del torneo de TETRIS, guardándolos en un linkedList de entidades eParticipante.

	2) Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio score, de manera descendente.

	3) Imprimir por pantalla los datos de los participantes. En lugar de idCategoria, se deberá imprimir dependiendo el caso: 1=>MENOR; 2=>MAYOR.

	4) Desarrollar la función ll_filter en la biblioteca linkedList, la cual recibirá la lista y una función. La función ll_filter ejecutará la función recibida como parámetro por cada ítem de la lista, generando una nueva lista que contendrá solamente los participantes de un idCategoria determinado.

	5) Generar el archivo de salida filtrado.csv conteniendo la lista del ítem anterior.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Participante.h"
#include "inputs.h"


int controller_loadFromText(char* path , LinkedList* pArrayList);
int parser_FromText(FILE* pFile , LinkedList* pArrayList);
int controller_List(LinkedList* pArrayList);
int listAll(LinkedList* pArrayList);
int showOne(eParticipante* pParticipante);
int controller_saveAsText(char* path , LinkedList* pArrayList);


int main(void) {
	setbuf(stdout, NULL);

	char confirm = 'n';
	int option;
	int filterOption;
	char fileName[128];
	int flagLoadedFromText = 0;
	int flagFiltered = 0;

	LinkedList* listaParticipantes = ll_newLinkedList();
	LinkedList* listaFiltrada;

	if(listaParticipantes != NULL)
	{
		do
		{
			system("cls");
			printf("\n\n\n\t\t\tMENU DE OPCIONES\n\n\n1. Cargar archivo '.csv'\n2. Ordenar lista.\n3. Mostrar lista.\n4. Filtrar lista.\n5. Guardar archivo con lista filtrada.\n6. Salir.\n\n");

			utn_getNumeroInt(&option, "Ingrese una opcion: ", "(opciones 1 a 6). ", 1, 6, 2);

			switch(option)
			{
				case 1:
					if(utn_getStringArchivo(fileName, sizeof(fileName), "Ingrese nombre del archivo: ", "Error... nombre invalido (solo letras, numeros, _, -, .). ", 3) == 0)
					{
						if(controller_loadFromText(fileName, listaParticipantes) > 0)
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
						if(ll_sort(listaParticipantes, eParticipante_compararPorScore, 0) == 0)
						{
							printf("\nParticipantes ordenados por puntaje descendente correctamente!!\n");
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
						if(controller_List(listaParticipantes) == -1)
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
					if(utn_getNumeroInt(&filterOption, "\n-----FILTRAR POR CATEGORIA-----\n\n1. Filtrar por menor.\n2. Filtrar por mayor.\n", "Opcion ingresada incorrecta...", 1, 2, 2) == 0)
					{
						switch(filterOption)
						{
						case 1:
							printf("\nFiltrando lista por categoria MENOR.\n");
							listaFiltrada = ll_filter(listaParticipantes, eParticipante_esMenor);
							flagFiltered = 1;
							break;
						case 2:
							printf("\nFiltrando lista por categoria MAYOR.\n");
							listaFiltrada = ll_filter(listaParticipantes, eParticipante_esMayor);
							flagFiltered = 1;
							break;
						default:
							printf("\nSe agotaron los reintentos.\n");
							break;
						}

					}
					else
					{
						printf("\nSe agotaron los reintentos.\n");
					}

					break;
				case 5:
					if(flagLoadedFromText && flagFiltered)
					{
						if(controller_saveAsText("filtrado.csv", listaFiltrada) == 0)
						{
							printf("\nArchivo guardado correctamente como 'filtrado.csv'!\n");
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
					printf("\n\nOpcion Ingresada invalida (opciones 1 a x)\n");
					break;
			}

			printf("\nPulse 'Enter' para continuar...\n\n");
			fflush(stdin);
			getc(stdin);

		} while(confirm != 's');

		ll_deleteLinkedList(listaParticipantes);
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
	char bufferNombre[128];
	char bufferEdad[4];
	char bufferIdCat[8];
	char bufferScore[8];

	eParticipante* pParticipante = NULL;

	if(pFile != NULL && pArrayList != NULL)
	{
		qty = 0;

		qtyHeader = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferEdad, bufferIdCat, bufferScore);	// Lectura del encabezado

		while(!feof(pFile))
		{
			if( fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferEdad, bufferIdCat, bufferScore) == qtyHeader)
			{
				pParticipante = eParticipante_newParametros(bufferId, bufferNombre, bufferEdad, bufferIdCat, bufferScore);

				if(pParticipante != NULL)
				{
					if(ll_add(pArrayList, pParticipante) == 0)
					{
						qty++; // Participante agregado
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
		printf("\n\n\t\t\t\t\tLISTA DE PARTICIPANTES\n\n");

		rtn = listAll(pArrayList);
	}

    return rtn;
}


int listAll(LinkedList* pArrayList)
{
	int rtn = -2;
	int len;
	int i;
	eParticipante* pParticipante = NULL;

	len = ll_len(pArrayList);

	if(pArrayList != NULL && len > 0)
	{
		rtn = 0;

		printf("%3s\t%15s\t\t\t%3s\t%8s\t%6s\n\n", "ID", "NOMBRE", "EDAD", "CATEGORIA", "SCORE");

		for(i = 0; i < len; i++)
		{
			pParticipante = (eParticipante*) ll_get(pArrayList, i);

			if(pParticipante != NULL)
			{
				if(showOne(pParticipante) == 0)
				{
					rtn++;
				}
			}
		}
	}

	return rtn;
}


int showOne(eParticipante* pParticipante)
{
	int rtn = -1;

	int auxId;
	char auxNombre[128];
	int auxEdad;
	int auxCatId;
	int auxScore;
	char auxCategoria[16];

	if(pParticipante != NULL)
	{
		if(	eParticipante_getId(pParticipante, &auxId) == 0 &&
			eParticipante_getNombre(pParticipante, auxNombre) == 0 &&
			eParticipante_getEdad(pParticipante, &auxEdad) == 0 &&
			eParticipante_getCategId(pParticipante, &auxCatId) == 0 &&
			eParticipante_getScore(pParticipante, &auxScore) == 0 &&
			eParticipante_getCategoriaPorId(auxCatId, auxCategoria) == 0)
		{

			printf("%4d\t%-30s\t%3d\t%8s\t%6d\n", auxId, auxNombre, auxEdad, auxCategoria, auxScore);
			rtn = 0;
		}
	}

	return rtn;
}



int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	int rtn = -1;
	int len = ll_len(pArrayList);
	int i;
	eParticipante* pParticipante = NULL;
	FILE* pFile = NULL;

	int auxId;
	char auxNombre[128];
	int auxEdad;
	int auxCatId;
	int auxScore;

	if(path != NULL && pArrayList != NULL && len > 0)
	{
		pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			fprintf(pFile, "id,nombre,edad,idCategoria,score\n"); // header

			for(i = 0; i < len; i++)
			{
				pParticipante = (eParticipante*) ll_get(pArrayList, i);

				if(pParticipante != NULL)
				{
					if(	eParticipante_getId(pParticipante, &auxId) == 0 &&
						eParticipante_getNombre(pParticipante, auxNombre) == 0 &&
						eParticipante_getEdad(pParticipante, &auxEdad) == 0 &&
						eParticipante_getCategId(pParticipante, &auxCatId) == 0 &&
						eParticipante_getScore(pParticipante, &auxScore) == 0)
					{
						fprintf(pFile, "%d,%s,%d,%d,%d\n", auxId, auxNombre, auxEdad, auxCatId, auxScore);
						rtn = 0;
					}
				}
			}
		}

		fclose(pFile);
	}

    return rtn;
}

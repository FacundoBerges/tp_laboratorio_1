#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

	char confirm = 'n';
    int option;
    int rtn;
    int flagLoadedFromText = 0;
    int flagLoadedFromBinary = 0;
    int flagSavedFile = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    if(listaPasajeros != NULL)
    {
		do
		{
		    fflush(stdin);
		    system("cls");
		    printf("\n\n\n\t\t\tMENU DE PASAJEROS\n\n\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n3. Alta de pasajero\n4. Modificar datos de pasajero\n5. Baja de pasajero\n6. Listar pasajeros\n7. Ordenar pasajeros\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n10. Salir\n\n");
		    utn_getNumeroInt(&option, "Ingrese una opcion: ", "(opciones 1 a 10). ", 1, 10, 2);

			switch(option)
			{
				case 1:
					if(!flagLoadedFromText && !flagLoadedFromBinary)
					{
						rtn = controller_loadFromText("data.csv", listaPasajeros);

						if(rtn > 0)
						{
							printf("\nPasajeros de archivo 'data.csv' cargados correctamente!!\n");
							flagLoadedFromText = 1;
						}
						else
						{
							printf("\nError al cargar pasajeros desde archivo 'data.csv'.\n");
						}
					}
					else
					{
						if(flagLoadedFromBinary && !flagLoadedFromText)
						{
							printf("\nYa se cargo un archivo en modo binario!\n");
						}
						else
						{
							printf("\nYa se cargo un archivo en modo texto!\n");
						}
					}
					break;
				case 2:
					if(!flagLoadedFromText && !flagLoadedFromBinary)
					{
						rtn = controller_loadFromBinary("data.bin", listaPasajeros);

						if(rtn > 0)
						{
							printf("\nPasajeros de archivo 'data.bin' cargados correctamente!!\n");
							flagLoadedFromBinary = 1;
						}
						else
						{
							printf("\nError al cargar pasajeros desde archivo 'data.bin'.\n");
						}
					}
					else
					{
						if(flagLoadedFromBinary && !flagLoadedFromText)
						{
							printf("\nYa se cargo un archivo en modo binario!\n");
						}
						else
						{
							printf("\nYa se cargo un archivo en modo texto!\n");
						}
					}
					break;
				case 3:
					rtn = controller_addPassenger(listaPasajeros);

					if(rtn == 0)
					{
						printf("\nPasajero dado de alta correctamente!!\n");
					}
					else if(rtn == -1 || rtn == -2)
					{
						printf("\nError al dar de alta pasajero... volviendo al menu!!\n");
					}
					else if(rtn == -3)
					{
						printf("\nError al dar de alta pasajero, no hay espacio suficiente para cargar mas datos... volviendo al menu!!\n");
					}
					break;
				case 4:
					if(flagLoadedFromText || flagLoadedFromBinary || ll_len(listaPasajeros) > 0)
					{
						rtn = controller_editPassenger(listaPasajeros);

						switch(rtn)
						{
							case 0:
								printf("\nDatos de pasajero modificados correctamente!!\n");
								break;
							case -1:
								printf("\nError con datos de los pasajeros... volviendo al menu!!\n");
								break;
							case -2:
								printf("\nModificacion cancelada... volviendo al menu!!\n");
								break;
							case -3:
								printf("\nIntento de ingreso de opcion agotados... volviendo al menu!!\n");
								break;
							case -4:
								printf("\nError al buscar datos de pasajero... volviendo al menu!!\n");
								break;
							case -5:
								printf("\nError. El ID ingresado no se encuentra habilitado... volviendo al menu!!\n");
								break;
							case -6:
								printf("\nError. Se agotaron los reintentos al ingresar ID... volviendo al menu!!\n");
								break;
							default:
								break;
						}
					}
					else
					{
						printf("\nAntes de modificar datos de pasajeros debe cargar datos desde un archivo o agregar pasajeros!!\n");
					}
					break;
				case 5:
					if(flagLoadedFromText || flagLoadedFromBinary || ll_len(listaPasajeros) > 0)
					{
						rtn = controller_removePassenger(listaPasajeros);

						switch(rtn)
						{
							case 0:
								printf("\nPasajero dado de baja correctamente!!\n");
								break;
							case -1:
								printf("\nError con datos de los pasajeros... volviendo al menu!!\n");
								break;
							case -2:
								printf("\nBaja cancelada... volviendo al menu!!\n");
								break;
							case -3:
								printf("\nError al buscar datos de pasajero... volviendo al menu!!\n");
								break;
							case -4:
								printf("\nError. El ID ingresado no se encuentra habilitado... volviendo al menu!!\n");
								break;
							case -5:
								printf("\nError. Se agotaron los reintentos al ingresar ID... volviendo al menu!!\n");
								break;
							case -6:
								printf("\nError al buscar datos de pasajero... volviendo al menu!!\n");
								break;
							default:
								break;
						}
					}
					else
					{
						printf("\nAntes de dar de baja pasajeros debe cargar datos desde un archivo o agregar pasajeros!!\n");
					}
					break;
				case 6:
					if(flagLoadedFromText || flagLoadedFromBinary || ll_len(listaPasajeros) > 0)
					{
						rtn = controller_ListPassenger(listaPasajeros);

						if(rtn == 0)
						{
							printf("\nNo hay pasajeros cargados para listar.\n\n");
						}
						else if(rtn == -1 || rtn == -2)
						{
							printf("\nError al listar pasajeros.\n\n");
						}
					}
					else
					{
						printf("\nAntes de listar pasajeros debe cargar datos desde un archivo o agregar pasajeros!!\n");
					}
					break;
				case 7:
					if(flagLoadedFromText || flagLoadedFromBinary || ll_len(listaPasajeros) > 0)
					{
						rtn = controller_sortPassenger(listaPasajeros);

						switch(rtn)
						{
							case 0:
								printf("\nPasajeros Ordenados correctamente!!\n");
								break;
							case -1:
								printf("\nError con datos de los pasajeros... volviendo al menu!!\n");
								break;
							case -2:
								printf("\nOrdenamiento cancelado... volviendo al menu!!\n");
								break;
							case -3:
								printf("\nError. Se agotaron los reintentos al ingresar opcion en el menu de ordenamiento... volviendo al menu!!\n");
								break;
							case -4:
								printf("\nError. Se agotaron los reintentos al ingresar opcion en el menu de ordenamiento... volviendo al menu!!\n");
								break;
							default:
								break;
						}
					}
					else
					{
						printf("\nAntes de ordenar pasajeros debe cargar datos desde un archivo o agregar pasajeros!!\n");
					}
					break;
				case 8:
					if(flagLoadedFromText || flagLoadedFromBinary || ll_len(listaPasajeros) > 0)
					{
						rtn = controller_saveAsText("data.csv", listaPasajeros);

						if(rtn == 0)
						{
							printf("\nArchivo guardado correctamente como 'data.csv'!\n");
							flagSavedFile = 1;
						}
						else
						{
							printf("\nError. No se pudo guardar el archivo!!\n");
						}
					}
					else
					{
						printf("\nAntes de guardar los datos debe cargar un archivo o agregar pasajeros!! (No se encuentran datos cargados para guardar)\n");
					}
					break;
				case 9:
					if(flagLoadedFromText || flagLoadedFromBinary || ll_len(listaPasajeros) > 0)
					{
						rtn = controller_saveAsBinary("data.bin", listaPasajeros);

						if(rtn == 0)
						{
							printf("\nArchivo guardado correctamente como 'data.bin'!\n");
							flagSavedFile = 1;
						}
						else
						{
							printf("\nError. No se pudo guardar el archivo!!\n");
						}
					}
					else
					{
						printf("\nAntes de guardar los datos debe cargar un archivo!! (No se encuentran datos cargados para guardar)\n");
					}
					break;
				case 10:
					if(flagSavedFile)
					{
						utn_getCharacterLower(&confirm, "Esta seguro que desea salir del programa? (S/N): ", "\nVolviendo al menu principal...\n\n", 'a', 'z', 0);
						if(confirm == 's')
						{
							printf("\n\nSaliendo del programa...\n\n");
						}
					}
					else
					{
						printf("\n\nAntes de salir del programa debe guardar los datos en algun archivo!!\n\n");
					}
					break;
				default:
					printf("\n\nOpcion Ingresada invalida (opciones 1 a 10)\n");
					break;
			}

		} while(confirm != 's');

		ll_deleteLinkedList(listaPasajeros);
    }

    return 0;
}


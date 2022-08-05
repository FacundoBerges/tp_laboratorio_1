/*
 ============================================================================
 Name        : programacion1_parcial2.c
 Author      : Facundo Berges
 Version     : 1.0
 Copyright   : 
 Description : PROGRAMACION I - PARCIAL 2

 1. (4 puntos) Crear un array de caracteres (con vocales y consonantes)
 en memoria dinámica y una función que reciba dicho array.
 La función deberá ajustar el tamaño del array a la cantidad consonantes que haya
 en el mismo quedándose únicamente con los elementos que cumplan
 con dicha característica. Ej: (perro)->(prr)

 2. (4 Puntos) Elija 5 de los siguientes conceptos (mas el obligatorio)
 y realice un párrafo en donde se pueda observar la relación
 entre los conceptos (No realizar definiciones del estilo copy-paste)

 3.  (2 Puntos) Crear una función que guarde en un archivo binario el
 contenido del array generado en el punto 1. Leerlo en otra función y mostrarlo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int ajustarArray(char* arrayDeCaracteres);

int saveAsBin(char* path, char* arrayChar);
int LoadFromBin(char* path, char* arrayChar);


int main(void)
{
	setbuf(stdout, NULL);
	char* arrayCaracteres = (char*) malloc(sizeof(char) * 10);

	strcpy(arrayCaracteres, "HolaMundo");

	// Ejercicio 1:
	printf("%s\n", arrayCaracteres);
	ajustarArray(arrayCaracteres);
	printf("%s\n", arrayCaracteres);

	/* Ejercicio 2:

	Palabras: Free / Constructor / Puntero / Malloc / Memoria dinamica

	Un constructor es un tipo de funcion que se encarga de buscar espacio en memoria dinamica de una variable.
	Se utiliza generalmente para buscar espacios de estructuras en memoria y devuelve como retorno
	un puntero a la misma, ya sea apuntando a nulo o al espacio encontrado. Para ello utilizamos
	la funcion malloc, casteando previamente al tipo de dato que queremos reservar.
	Antes de finalizar el programa, el programador se debe acordar de liberar espacio en memoria del elemento
	construido utilizando la funcion 'free()' que recibe como parametro el puntero a la memoria a ser liberada.


	 */

	// Ejercicio 3:
	saveAsBin("ArrayCaracteres.bin", arrayCaracteres);
	LoadFromBin("ArrayCaracteres.bin", arrayCaracteres);

	if(arrayCaracteres != NULL)
	{
		printf("\n\n%s\n", arrayCaracteres);

		free(arrayCaracteres);
	}

	return EXIT_SUCCESS;
}


// Ejercicio 1
int ajustarArray(char* arrayDeCaracteres)
{
	int rtn = -1;
	int len;
	int i;
	int consonantes = 0;
	char* arrayAux = (char*) malloc(sizeof(char) * sizeof(arrayDeCaracteres));

	if(arrayDeCaracteres != NULL)
	{
		len = strlen(arrayDeCaracteres);

		for(i = 0; i < len; i++)
		{
			if(	tolower(*(arrayDeCaracteres+i)) != 'a' &&
				tolower(*(arrayDeCaracteres+i)) != 'e' &&
				tolower(*(arrayDeCaracteres+i)) != 'i' &&
				tolower(*(arrayDeCaracteres+i)) != 'o' &&
				tolower(*(arrayDeCaracteres+i)) != 'u')
			{
				*(arrayAux+consonantes) = *(arrayDeCaracteres+i);
				consonantes++;
			}

		}

		strcpy(arrayDeCaracteres, arrayAux);
		arrayDeCaracteres = (char*) realloc(arrayDeCaracteres, consonantes);

		rtn = 0;
	}

	return rtn;
}


// Ejercicio 3
int saveAsBin(char* path, char* arrayChar)
{
	int rtn = -1;
	FILE *pFile = NULL;

	if(path != NULL && arrayChar != NULL)
	{
		pFile = fopen(path, "wb");

		if(pFile != NULL)
		{
			fwrite(arrayChar, (sizeof(char) * sizeof(arrayChar)), 1, pFile);
			rtn = 0;
		}

		fclose(pFile);
	}

	return rtn;
}

int LoadFromBin(char* path, char* arrayChar)
{
	int rtn = -1;
	char* auxArray = NULL;
	FILE *pFile = NULL;

	if(path != NULL && arrayChar != NULL)
	{
		pFile = fopen(path, "rb");

		if(pFile != NULL)
		{
			fread(auxArray, (sizeof(char) * 1024), 1, pFile);
			arrayChar = (char*) realloc(auxArray, sizeof(auxArray));
			rtn = 0;
		}

		fclose(pFile);
	}

	return rtn;
}





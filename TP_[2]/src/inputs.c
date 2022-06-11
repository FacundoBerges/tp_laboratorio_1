/*
 * inputs.c
 *
 *  Created on: Apr 30, 2022
 *      Author: Facundo
 */


#include <stdio.h>
//#include <stdio_ext.h>	// para linux
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

#define OPTION 2

#define RETRIES 3


//#define fflush __fpurge	// para linux


static int myGets(char* str, int len);
static int getInt(int *pResult);
static int esNumericoInt(char str[]);
static int getFloat(float *pResult);
static int esNumericoFloat(char str[]);


/**
 * @fn int myGetS(char*, int)
 * @brief
 *
 * @param str
 * @param len
 * @return
 */
static int myGets(char* str, int len)
{
	int rtn = -1;

	fflush(stdin);
	if(str != NULL && len > 0 && fgets(str, len, stdin) == str)
	{
		if(str[strlen(str)-1] == '\n')
		{
			str[strlen(str)-1] = '\0';
		}

		rtn = 0;
	}

	return rtn;
}


/**
 * @fn int getInt(int*)
 * @brief
 *
 * @param pResult
 * @return
 */
static int getInt(int *pResult)
{
	int rtn = -1;
	char buffer[64];

	if(pResult != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esNumericoInt(buffer) )
		{
			*pResult = atoi(buffer);
			rtn = 0;
		}
	}

	return rtn;
}






int utn_getNumeroInt(int* pResult, char* msge, char* errorMsge, int min, int max, int retries)
{
	int rtn = -1;
	int bufferInt;

	if(pResult != NULL && msge != NULL && errorMsge != NULL && min <= max && retries >= 0)
	{
		do
		{
			printf("%s", msge);

			if( getInt(&bufferInt) == 0 && bufferInt >= min && bufferInt <= max)
			{
				*pResult = bufferInt;
				rtn = 0;
				break;
			}
			else
			{
				printf("%s", errorMsge);
				retries--;
			}
		} while(retries >= 0);
	}

	return rtn;
}




/**
 * @fn int getFloat(float*)
 * @brief
 *
 * @param pResult
 * @return
 */
static int getFloat(float *pResult)
{
	int rtn = -1;
	char buffer[64];

	if(pResult != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esNumericoFloat(buffer) )
		{
			*pResult = atof(buffer);
			rtn = 0;
		}
	}

	return rtn;
}



int utn_getNumeroFloat(float* pResult, char* msge, char* errorMsge, float min, float max, int retries)
{
	int rtn = -1;
	int bufferFloat;

	if(pResult != NULL && msge != NULL && errorMsge != NULL && min <= max && retries >= 0)
	{
		do
		{
			printf("%s", msge);

			if( getFloat(&bufferFloat) == 0 && bufferFloat >= min && bufferFloat <= max)
			{
				*pResult = bufferFloat;
				rtn = 0;
				break;
			}
			else
			{
				printf("%s", errorMsge);
				retries--;
			}
		} while(retries >= 0);
	}

	return rtn;
}











/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------INPUT----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
int printMenu(char message[], int qtyOptions)
{
	char auxOption[1];
	int option = -1;

	if(message != NULL && qtyOptions > 0)
	{
		printf("%s", message);
		if(getString("Ingrese una opcion: ", auxOption, OPTION, RETRIES) != -1)
		{
			cambiarString_Entero(auxOption, &option);
		}
	}

	return option;
}*/


int getString(char message[], char cadena[], int len, int retries)
{
	int ret = -1;
	char auxString[len];

	if(message != NULL && cadena != NULL && len > 0 && retries >= 0)
	{
		do
		{
			printf("%s", message);
			fflush(stdin);
			scanf("%[^\n]", auxString);

			if(strlen(auxString) < len)
			{
				strcpy(cadena, "\0");
				strcpy(cadena, auxString);
				ret = 0;
				break;
			}
			else
			{
				printf("Error. El dato ingresado supera el tamanio permitido (%d caracteres). ", len);
				retries--;
			}
		} while(retries >= 0);
	}

	return ret;
}

/*
int getInt(char mensaje[], int limiteMenor, int limiteMayor, int reintentos)
{
	int numIngresado;
	float auxFloat;

	if(mensaje != NULL && limiteMenor <= limiteMayor)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &auxFloat);
			numIngresado = auxFloat;

			if((auxFloat - numIngresado == 0) && numIngresado > limiteMenor && numIngresado < limiteMayor)
			{
				break;
			}
			else
			{
				printf("Error. El dato ingresado no es valido, debe ingresar dentro del rango %d - %d. ", limiteMenor, limiteMayor);
				reintentos--;
				numIngresado = limiteMenor-1;
			}
		} while(reintentos >= 0);
	}

	return numIngresado;
}*/


/*
int pedirNumFlotante(char mensaje[], float limiteMenor, float limiteMayor, float* pNumeroFlotante, int reintentos)
{
	int retorno = -1;
	float auxFloat;

	if(mensaje != NULL && limiteMenor <= limiteMayor)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &auxFloat);

			if(auxFloat > limiteMenor && auxFloat < limiteMayor)
			{
				*pNumeroFlotante = auxFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("Error. El dato ingresado no es valido. ");
				reintentos--;
			}
		} while(reintentos >= 0);
	}

	return retorno;
}*/

/*
int cambiarString_Entero(char cadena[], int* pEntero)
{
	int retorno = -1;

	if(esNumericoInt(cadena))
	{
		*pEntero = atoi(cadena);
		retorno = 0;
	}

	return retorno;
}*/

/*
int cambiarString_Float(char cadena[], float* pFlotante)
{
	int retorno = -1;

	if(esNumericoFloat(cadena))
	{
		*pFlotante = atof(cadena);
		retorno = 0;
	}

	return retorno;
}*/


int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);

			if((scanf("%c", &bufferChar) == 1) && bufferChar >= minimo && bufferChar <= maximo)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------VALIDACIONES------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @fn int esNumericoInt(char[])
 * @brief
 *
 * @param str
 * @return
 */
static int esNumericoInt(char str[])
{
	int retorno = 1;
	int i=0;

	if(str != NULL && strlen(str) > 0)
	{

		while(str[i] != '\0')
		{
			if(i == 0 && (str[i] == '-' || str[i] == '+'))
			{
				continue;
			}

			if(str[i] < '0' || str[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}

	return retorno;
}


/**
 * @fn int esNumericoFloat(char[])
 * @brief
 *
 * @param str
 * @return
 */
static int esNumericoFloat(char str[])
{
	int rtn = 1;
	int i = 0;
	int contadorPunto = 0;

	if(str != NULL && strlen(str) > 0)
	{
		while(str[i] != '\0')
		{
			if(i == 0 && (str[i] == '-' || str[i] == '+'))
			{
				continue;
			}

			if((str[i] < '0' || str[i] > '9'))
			{
				if(str[i] == '.' && contadorPunto == 0)
				{
					contadorPunto++;
				}
				else
				{
					rtn = 0;
					break;
				}
			}
			i++;
		}
	}

	return rtn;
}


int esSoloLetras(char str[])
{
	int retorno = 1;
	int i=0;
	while(str[i] != '\0')
	{
	   if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
	   {
		   retorno = 0;
           break;
	   }
	   i++;
	}
	return retorno;
}


int esAlfaNumerico(char str[])
{
	int retorno = 1;
	int i = 0;
    while(str[i] != '\0')
    {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
       {
           retorno = 0;
           break;
       }
       i++;
    }

    return retorno;
}


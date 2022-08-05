/*
 * inputs.c
 *
 *  Created on: Apr 30, 2022
 *      Author: Facundo
 */


#include <stdio.h>
//#include <stdio_ext.h>	// para linux
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "inputs.h"

#define OPTION 2

#define RETRIES 3


//#define fflush __fpurge	// para linux


static int myGets(char* str, int len);

static int getInt(int* pResult);
static int esNumericoInt(char str[]);

static int getFloat(float *pResult);
static int esNumericoFloat(char str[]);

static int getStringLetras(char *pResult, int len);
static int esSoloLetras(char str[]);

static int getStringArchivo(char *pResult, int len);
static int esArchivo(char str[]);

static int getStringAlphaNum(char *pResult, int len);
static int esAlfaNumerico(char str[]);




/**
 * @fn int myGetS(char*, int)
 * @brief	obtiene datos ingresados por teclado de forma segura.
 *
 * @param str	puntero a char donde colocar los datos ingresados
 * @param len	longitud del array
 * @return	0 si se ingreso el dato o -1 si hubo error (puntero NULL, len igual o menor a 0, o error al obtener el dato)
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


/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------INTEGER--------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/**
 * @fn int getInt(int*)
 * @brief	obtiene un dato, verifica que lo ingresado sea un numerico entero y lo parsea con atoi
 *
 * @param pResult	puntero donde colocar el resultado parseado
 * @return	0 si el dato ingresado es numero entero, -1 si error
 */
static int getInt(int* pResult)
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


/**
 * @fn int esNumericoInt(char[])
 * @brief	verifica que el string recibido sea unicamente un numero entero.
 *
 * @param str	cadena de caracteres a analizar.
 * @return		1 si la cadena es numerica entera o 0 si no lo es.
 */
static int esNumericoInt(char str[])
{
	int retorno = 1;
	int i = 0;

	if(str != NULL && strlen(str) > 0)
	{
		while(str[i] != '\0')
		{
			if(i == 0 && (str[i] == '-' || str[i] == '+'))
			{
				i++;
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


/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------FLOAT--------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/**
 * @fn int getFloat(float*)
 * @brief	obtiene un dato, verifica que lo ingresado sea un numerico flotante y lo parsea con atof
 *
 * @param pResult	puntero donde colocar el resultado parseado
 * @return	0 si el dato ingresado es numero flotante, -1 si error
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


/**
 * @fn int esNumericoFloat(char[])
 * @brief	verifica que el string recibido sea unicamente un numero flotante.
 *
 * @param str 	cadena de caracteres a analizar.
 * @return		1 si la cadena es numerica flotante o 0 si no lo es.
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
				i++;
				continue;
			}

			if(str[i] < '0' || str[i] > '9')
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


int utn_getNumeroFloat(float* pResult, char* msge, char* errorMsge, float min, float max, int retries)
{
	int rtn = -1;
	float bufferFloat;

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
/*-----------------------------------------------------------------------------STRING-------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/**
 * @fn int getStringLetras(char*)
 * @brief	obtiene un dato, verifica que lo ingresado sea una cadena de caracteres letras y espacios
 *
 * @param pResult	puntero donde colocar el resultado en caso que sean solo letras y espacios intermedios
 * @return	0 si el dato ingresado es cadena char, -1 si error
 */
static int getStringLetras(char *pResult, int len)
{
	int rtn = -1;
	char buffer[64];

	if(pResult != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esSoloLetras(buffer) && strlen(buffer) < len)
		{
			strncpy(pResult, buffer, len);
			rtn = 0;
		}
	}

	return rtn;
}


/**
 * @fn int esSoloLetras(char[])
 * @brief 	verifica que el string recibido sea unicamente alfabetico con espacios.
 *
 * @param str	cadena de caracteres a analizar.
 * @return		1 si la cadena es solo letras y o espacios o 0 si no lo es.
 */
static int esSoloLetras(char str[])
{
	int rtn = 1;
	int i = 0;

	if(str != NULL)
	{
		while(str[i] != '\0')
		{
		   if( (i == 0 && str[i] == ' ') || ( (str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') ) )
		   {
			   rtn = 0;
			   break;
		   }
		   i++;
		}
	}


	return rtn;
}


int utn_getStringLetras(char* pArrayChar, int maxChar, char* msge, char* errorMsge, int retries)
{
	int rtn = -1;
	char buffer[64];

	if(pArrayChar != NULL && msge != NULL && errorMsge != NULL  && retries >= 0 && buffer != NULL)
	{
		do
		{
			printf("%s", msge);

			if( getStringLetras(buffer, sizeof(buffer)) == 0 && strlen(buffer) < maxChar && strlen(buffer) > 0)
			{
				strcpy(pArrayChar, buffer);
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



/* Nombre de archivo */


static int getStringArchivo(char *pResult, int len)
{
	int rtn = -1;
	char buffer[64];

	if(pResult != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esArchivo(buffer) && strlen(buffer) < len)
		{
			strncpy(pResult, buffer, len);
			rtn = 0;
		}
	}

	return rtn;
}


static int esArchivo(char str[])
{
	int rtn = 1;
	int i = 0;

    while(str[i] != '\0')
    {
       if( (i == 0 && str[i] == ' ') || ( (str[i] != ' ') && (str[i] != '-') && (str[i] != '_') && (str[i] != '.') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') ) )
       {
    	   rtn = 0;
           break;
       }
       i++;
    }

    return rtn;
}


int utn_getStringArchivo(char* pArrayChar, int maxChar, char* msge, char* errorMsge, int retries)
{
	int rtn = -1;
	char buffer[64];

	if(pArrayChar != NULL && msge != NULL && errorMsge != NULL  && retries >= 0 && buffer != NULL)
	{
		do
		{
			printf("%s", msge);
			fflush(stdin);
			if( getStringArchivo(buffer, sizeof(buffer)) == 0 && strlen(buffer) < maxChar && strlen(buffer) > 0)
			{
				strcpy(pArrayChar, buffer);
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



/* Alfanumerico */

/**
 * @fn int getStringAlphaNum(char*)
 * @brief	obtiene un dato, verifica que lo ingresado sea una cadena de caracteres alfanumerica
 *
 * @param pResult	puntero donde colocar el resultado en caso que sean solo letras y numeros
 * @return	0 si el dato ingresado es cadena char, -1 si error
 */
static int getStringAlphaNum(char *pResult, int len)
{
	int rtn = -1;
	char buffer[32];

	if(pResult != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esAlfaNumerico(buffer) && strlen(buffer) < len)
		{
			strncpy(pResult, buffer, len);
			rtn = 0;
		}
	}

	return rtn;
}


/**
 * @fn int esAlfaNumerico(char[])
 * @brief	verifica que el string recibido sea unicamente alfanumerico con espacios.
 *
 * @param str	puntero donde colocar el resultado en caso que sean solo letras, numeros y espacios intermedios
 * @return		0 si el dato ingresado es cadena char, -1 si error
 */
static int esAlfaNumerico(char str[])
{
	int rtn = 1;
	int i = 0;

    while(str[i] != '\0')
    {
       if( (i == 0 && str[i] == ' ') || ( (str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') ) )
       {
    	   rtn = 0;
           break;
       }
       i++;
    }

    return rtn;
}


int utn_getStringAlphaNum(char* pArrayChar, int maxChar, char* msge, char* errorMsge, int retries)
{
	int rtn = -1;
	char buffer[32];

	if(pArrayChar != NULL && msge != NULL && errorMsge != NULL  && retries >= 0 && buffer != NULL)
	{
		do
		{
			printf("%s", msge);
			fflush(stdin);
			if( getStringAlphaNum(buffer, sizeof(buffer)) == 0 && strlen(buffer) < maxChar && strlen(buffer) > 0)
			{
				strcpy(pArrayChar, buffer);
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
/*----------------------------------------------------------------------------CHAR----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/



int utn_getCharacterLower(char* pResult, char* msge, char* errorMsge, char min, char max, int retries)
{
	int rtn = -1;
	char bufferChar;

	if(pResult != NULL && msge != NULL && errorMsge != NULL && min <= max && retries >= 0)
	{
		do
		{
			printf("%s", msge);
			fflush(stdin);

			if((scanf("%c", &bufferChar) == 1) && tolower(bufferChar) >= min && tolower(bufferChar) <= max)
			{
				*pResult = bufferChar;
				rtn = 0;
				break;
			}
			else
			{
				printf("%s", errorMsge);
				retries--;
			}
		}while(retries >= 0);
	}

	return rtn;
}


/*
 * inputs.h
 *
 *  Created on: Apr 30, 2022
 *      Author: Facundo
 */

#ifndef INPUTS_H_
#define INPUTS_H_


/**
 * @fn int utn_getNumeroInt(int*, char*, char*, int, int, int)
 * @brief 		obtiene ingreso de datos en formato cadena de caracteres y lo transforma a numero entero en caso que corresponda
 *
 * @param pResult		puntero a int donde colocar datos ingresados
 * @param msge			mensaje a mostrar
 * @param errorMsge		Mensaje a mostrar en caso de error
 * @param min			num minimo aceptado
 * @param max			num maximo aceptado
 * @param retries		cantidad de reintentos
 * @return		0 if ok, -1 if error (null pointers, no more retries)
 */
int utn_getNumeroInt(int* pResult, char* msge, char* errorMsge, int min, int max, int retries);


/**
 * @fn int utn_getNumeroFloat(float*, char*, char*, float, float, int)
 * @brief 		obtiene ingreso de datos en formato cadena de caracteres y lo transforma a flotante en caso que corresponda
 *
 * @param pResult		puntero a float donde colocar datos ingresados
 * @param msge			mensaje a mostrar
 * @param errorMsge		Mensaje a mostrar en caso de error
 * @param min			num minimo aceptado
 * @param max			num maximo aceptado
 * @param retries	cantidad de reintentos
 * @return		0 if ok, -1 if error (null pointers, no more retries)
 */
int utn_getNumeroFloat(float* pResult, char* msge, char* errorMsge, float min, float max, int retries);


/**
 * @fn int utn_getStringLetras(char*, int, char*, char*, int)
 * @brief 	obtiene ingreso de datos en formato cadena de caracteres de solo letras y espacios
 *
 * @param pArrayChar	puntero a char donde colocar datos ingresados
 * @param maxChar		max cantidad de caracteres
 * @param msge			mensaje a mostrar
 * @param errorMsge		Mensaje a mostrar en caso de error
 * @param retries		cantidad de reintentos
 * @return			0 if ok, -1 if error (null pointers, no more retries)
 */
int utn_getStringLetras(char* pArrayChar, int maxChar, char* msge, char* errorMsge, int retries);


/**
 * @fn int utn_getStringLetras(char*, int, char*, char*, int)
 * @brief 	obtiene ingreso de datos en formato cadena de caracteres de solo letras y espacios
 *
 * @param pArrayChar	puntero a char donde colocar datos ingresados
 * @param maxChar		max cantidad de caracteres
 * @param msge			mensaje a mostrar
 * @param errorMsge		Mensaje a mostrar en caso de error
 * @param retries		cantidad de reintentos
 * @return			0 if ok, -1 if error (null pointers, no more retries)
 */
int utn_getStringArchivo(char* pArrayChar, int maxChar, char* msge, char* errorMsge, int retries);


/**
 * @fn int utn_getStringAlphaNum(char*, int, char*, char*, int)
 * @brief 	obtiene ingreso de datos en formato cadena de caracteres de solo letras, numeros y espacios
 *
 * @param pArrayChar	puntero a char donde colocar datos ingresados
 * @param maxChar		max cantidad de caracteres
 * @param msge			mensaje a mostrar
 * @param errorMsge		Mensaje a mostrar en caso de error
 * @param retries		cantidad de reintentos
 * @return		0 if ok, -1 if error (null pointers, no more retries)
 */
int utn_getStringAlphaNum(char* pArrayChar, int maxChar, char* msge, char* errorMsge, int retries);


/**
 * @fn int utn_getCharacter(char*, char*, char*, char, char, int)
 * @brief 	obtiene ingreso de datos en formato char
 *
 * @param pResult		puntero a char donde colocar datos ingresados
 * @param msge			mensaje a mostrar
 * @param errorMsge		Mensaje a mostrar en caso de error
 * @param min			num minimo aceptado
 * @param max			num maximo aceptado
 * @param retries		cantidad de reintentos
 * @return		0 if ok, -1 if error (null pointers, no more retries)
 */
int utn_getCharacterLower(char* pResult, char* msge, char* errorMsge, char min, char max, int retries);



#endif /* INPUTS_H_ */

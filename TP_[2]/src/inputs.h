/*
 * inputs.h
 *
 *  Created on: Apr 30, 2022
 *      Author: Facundo
 */

#ifndef INPUTS_H_
#define INPUTS_H_


/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------INPUT----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/**
 * @fn int printMenu(char[], int)
 * @brief  prints a string menu and receive the number of total options, returns input option
 *
 * @param message  menu to print.
 * @param qtyOptions  options quantity
 * @return Return (-1) if Error [No more retries, Invalid length or NULL pointer] - (0 or another option) if Ok
 */
int printMenu(char message[], int qtyOptions);


/**
 * @fn int getString(char[], char[], int, int)
 * @brief  Pide una cadena en array auxiliar y en caso de que no supere el tamanio permitido lo copia en array original
 *
 * @param char* puntero a mensaje a mostrar para pedir ingreso de datos.
 * @param char* puntero a cadena donde colocar datos en caso correcto.
 * @param int tamanio permitido de la cadena.
 * @param int cantidad de reintentos a efectuar
 * @return devuelve 0 si se ingreso string correctamente o -1 si hubo error al realizar la tarea.
 */
int getString(char mensaje[], char cadena[], int tamanio, int reintentos);

/**
 * @fn int pedirNumEntero(char[], int, int,)
 * @brief Pide un numero entero y devuelve el nro ingresado.
 *
 * @param mensaje  	mensaje a mostrar para solicitar nro.
 * @param limiteMenor 	menor numero posible.
 * @param limiteMayor 	mayor numero posible.
 * @param reintentos 	cantidad de reintentos.
 * @return devuelve el nro ingresado si se ingreso correctamente o el limiteMenor-1 si se agotaron los reintentos.
 */
int getInt(char mensaje[], int limiteMenor, int limiteMayor, int reintentos);

/**
 * @fn int pedirNumFlotante(char[], int, int, float*, int)
 * @brief funcion para pedir numero flotante entre 2 rangos determinados.
 *
 * @param mensaje	mensaje a mostrar para solicitar nro.
 * @param limiteMenor	menor numero posible.
 * @param limiteMayor 	mayor numero posible.
 * @param pNumeroFlotante	puntero a numero flotante donde colocar el resultado en caso correcto.
 * @param reintentos	cantidad de reintentos.
 * @return	devuelve 0 si se ingreso string correctamente o -1 si hubo error al realizar la tarea.
 */
int pedirNumFlotante(char mensaje[], float limiteMenor, float limiteMayor, float* pNumeroFlotante, int reintentos);

/**
 * @brief Cambia una cadena de string a entero y lo asigna como valor en la direccion recibida.
 * @param char* puntero a cadena a cambiar.
 * @param int* puntero a entero donde asignar el valor cambiado.
 * @return devuelve 0 si se realizo la asignacion o -1 si hubo error al realizar la tarea.
 *
 */
int cambiarString_Entero(char cadena[], int* pEntero);

/**
 * @fn int cambiarString_Float(char[], float*)
 * @brief Cambia una cadena de string a flotante y lo asigna como valor en la direccion recibida.
 *
 * @param cadena puntero a cadena a cambiar.
 * @param pFlotante puntero a flotante donde asignar el valor cambiado.
 * @return devuelve 0 si se realizo la asignacion o -1 si hubo error al realizar la tarea.
 *
 */
int cambiarString_Float(char cadena[], float* pFlotante);


/**
 * @brief funcion que sirve para pedir un caracter al usuario y chequear que se encuentre entre un maximo y un minimo,
 * brindando cantidad de reintentos y recibiendo adicionalmente mensaje a mostrar para pedir el caracter y mensaje de error en caso fallido.
 *
 * @param pResultado	Puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto.
 * @param mensaje		Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola.
 * @param mensajeError	Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
 * @param minimo		Valor mínimo admitido (inclusive).
 * @param maximo		Valor máximo admitido (inclusive).
 * @param reintentos	Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
 * @return		0 si se realizo correctamente el ingreso de caracter o -1 si se acabaron los intentos.
 *
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------VALIDACIONES------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Verifica si el valor recibido es numero entero.
 * @param str Array con la cadena a ser analizada
 * @return 1 si es númerico y 0 si no lo es
 *
 */
int esNumericoInt(char str[]);

/**
 * @fn int esNumericoFloat(char[])
 * @brief Verifica si el valor recibido es numero flotante.
 *
 * @param str Array con la cadena a ser analizada.
 * @return 1 si es númerico y 0 si no lo es.
 */
int esNumericoFloat(char str[]);


/**
 * @brief Verifica si el valor recibido contiene solo letras y números
 * @param str Array con la cadena a ser analizada
 * @return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]);

/**
 * @brief Verifica si el valor recibido contiene solo letras
 * @param str Array con la cadena a ser analizada
 * @return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

#endif /* INPUTS_H_ */

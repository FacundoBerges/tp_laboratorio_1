/*
 * Validaciones.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Facundo Berges
 */

#ifndef INPUTS_H_
#define INPUTS_H_


/// @brief Funcion para validar kilometros ingresados. permite ingresar valores de 0 a 16.000, maximo aproximado a realizar en un vuelo comercial.
/// No permite la salida del usuario hasta que no se ingrese un valor entre esos numeros, ambos incluidos.
///
/// @return Retorna los kilometros ingresados.
int IngresarKM(void);


/// @brief recibe un numero ingresado y valida que se encuentre dentro del minimo y maximo recibido.
///
/// @param numero	numero a verificar.
/// @param min		numero limite minimo.
/// @param max		numero limite maximo.
/// @return 0 si se encuentra dentro de los numeros limite minimo y maximo (incluidos) o -1 si no se encuentra dentro de los limites.
int ValidarKM(int numero, int min, int max);


/// @brief Funcion para validar precio ingresado. Verifica que el monto ingresado no sea menor a $ 0 y lo devuelve.
/// No permite la salida del usuario hasta que no se ingrese un valor mayor o igual a 0.
///
/// @param lineaAerea	Nombre de la linea aerea a solicitar precio.
/// @return				Precio ingresado de la aerolinea.
float IngresarPrecio(char lineaAerea[]);

#endif /* INPUTS_H_ */

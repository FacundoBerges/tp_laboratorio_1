/*
 * Calculos.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Facundo Berges
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_


/// @brief Funcion que calcula el valor a aplicar segun los descuentos e intereses.
///
/// @param precioBase			Precio ingresado de la aerolinea.
/// @param descuento			Descuento a aplicar.
/// @param interes				Interes a aplicar.
/// @param precioBTC			Valor del bitcoin.
/// @param kilometros			Kilometros para calcular el precio unitario por km realizado.
/// @param pPrecioConDescuento	Puntero donde aplicar el descuento.
/// @param pPrecioConInteres	Puntero donde aplicar el interes.
/// @param pPrecioConBitCoin	Puntero donde aplicar el precio con bitcoin calculado.
/// @param pPrecioPorKM			Puntero donde colocar el precio por kilometro.
void CalcularCostos(float precioBase, float descuento, float interes, float precioBTC, int kilometros, float* pPrecioConDescuento, float* pPrecioConInteres, float* pPrecioConBitCoin, float* pPrecioPorKM);


/// @brief Funcion que calcula el precio con descuento aplicado. Recibe precio base y descuento a aplicar y devuelve el calculo realizado.
///
/// @param precio		Precio base.
/// @param descuento	Descuento a aplicar.
/// @return				Precio con descuento aplicado.
float CalcularDescuento(float precio, float descuento);


///	@brief Funcion que calcula el precio con interes aplicado. Recibe precio base e interes a aplicar y devuelve el calculo realizado.
///
/// @param precio	Precio Base.
/// @param interes	Interesa aplicar.
/// @return			Precio con interes aplicado.
float CalcularInteres(float precio, float interes);


/// @brief Funcion que calcula el precio pasado a moneda bitcoin. Recibe precio base y valor de criptomoneda y devuelve el calculo realizado.
///
/// @param precio			Precio Base.
/// @param precioBitcoin	Precio de cotizacion BTC.
/// @return					Precio en valor Bitcoin.
float CalcularBTC(float precio, float precioBitcoin);


/// @brief Funcion que calcula el precio por cada kilometro. Recibe precio base y cantidad de kilometros y devuelve el precio individual por cada kilometro.
///
/// @param precio	Precio base.
/// @param kms		cantidad de kilometros.
/// @return			Valor de precio por cada kilometro.
float CalcularPrecioUnitario(float precio, int kms);


/// @brief Funcion para calcular la diferencia entre precios de 2 aerolineas.
///
/// @param precio1				Precio 1er aerolinea.
/// @param precio2				Precio 2da aerolinea.
/// @param pDiferenciaPrecio	Puntero donde colocar la diferencia de precio.
void CalcularDiferenciaPrecios(float precio1, float precio2, float* pDiferenciaPrecio);

#endif /* CALCULOS_H_ */

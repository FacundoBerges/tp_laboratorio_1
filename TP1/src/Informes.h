/*
 * Informes.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Facundo Berges
 */

#ifndef INFORMES_H_
#define INFORMES_H_

///@brief Interactua con el menu de opciones mostrado en MostrarOpcionesMenu(). Funcion que se relaciona con todas las demas funciones del programa.
///
void MostrarMenu(void);

///	@brief Muestra el menu de opciones del menu, recibe como parametro los montos de lineas aereas ingresados y la cantidad de kilometros
///
/// @param kilometros		cantidad de km ingresados (por defecto es 0)
/// @param precioAerolineas	precio ingresado de aerolineas (por defecto es 0)
/// @param precioLatam		precio ingresado de latam (por defecto es 0)
void MostrarOpcionesMenu(int kilometros, float precioAerolineas, float precioLatam);

/// @brief Informa los datos ingresados. Recibe como parametros los kilometros, precios calculados de las lineas aereas e invoca a la funcion InformarLineaAerea() para mostrar la informacion individual de cada aerolinea.
///
/// @param kms						Cantidad de kilometros ingresados.
/// @param precioLinea1				precio ingresado de primer linea aerea.
/// @param precioDebitoLinea1		precio de primer linea aerea con descuento aplicado por pagar con debito.
/// @param precioCreditoLinea1		precio de primer linea aerea con interes aplicado por pagar con credito.
/// @param precioBTCLinea1			precio de primer linea aerea convertido a pagar con bitcoin.
/// @param precioUnitarioLinea1		precio por kilometro de la primer linea aerea.
/// @param precioLinea2				precio ingresado de segunda linea aerea.
/// @param precioDebitoLinea2		precio de segunda linea aerea con descuento aplicado por pagar con debito.
/// @param precioCreditoLinea2		precio de segunda linea aerea con interes aplicado por pagar con credito.
/// @param precioBTCLinea2			precio de segunda linea aerea convertido a pagar con bitcoin.
/// @param precioUnitarioLinea2		precio por kilometro de la segunda linea aerea.
/// @param diferenciaDePrecios		diferencia de precios entre ambas lineas aereas
void InformarResultados(int kms, float precioLinea1, float precioDebitoLinea1, float precioCreditoLinea1, float precioBTCLinea1, float precioUnitarioLinea1, float precioLinea2, float precioDebitoLinea2, float precioCreditoLinea2, float precioBTCLinea2, float precioUnitarioLinea2, float diferenciaDePrecios);

/// @brief Informa los datos ingresados de una linea aerea individual. Recibe como parametros nombre de la linea aerea y los precios ya calculados para mostrarlos en pantalla.
///
/// @param lineaAerea		String con nombre de la aerolinea a mostrar.
/// @param precio			Precio estandar.
/// @param precioDebito		Precio con descuento aplicado.
/// @param precioCredito	Precio con interes aplicado.
/// @param precioBTC		Precio a pagar en Bitcoin.
/// @param precioUnitario	Valor del precio por kilometro.
void InformarLineaAerea(char lineaAerea[], float precio, float precioDebito, float precioCredito, float precioBTC, float precioUnitario);

/// @brief Informa de manera forzada datos harcodeados para mostrar el programa. Recibe como parametros los km y precios harcodeados e invoca a las funciones de la biblioteca "calculos.h"
/// para luego mostrar la informacion calculada en pantalla.
///
/// @param kms				kilometros
/// @param precioLinea1		precio de aerolinea 1.
/// @param precioLinea2		precio de aerolinea 2.
/// @param descuento		descuento a aplicar.
/// @param interes			interes a aplicar.
/// @param precioBitcoin	Precio del bitcoin.
void InformarCargaForzada(int kms, float precioLinea1, float precioLinea2, float descuento, float interes, float precioBitcoin);



#endif /* INFORMES_H_ */

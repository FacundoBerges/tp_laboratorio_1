/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "../inc/LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	int estatusVuelo;
}Passenger;


/**
 * @fn Passenger Passenger_new*()
 * @brief 	default constructor
 *
 * @return	returns a pointer to Passenger or NULL if error
 */
Passenger* Passenger_new();


/**
 * @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
 * @brief	constructor con parametros string. Setea datos en un nuevo pasajero y devuelve puntero al mismo
 *
 * @param idStr		id de pasajero
 * @param nombreStr		nombre del pasajero
 * @param apellidoStr		apellido del pasajero
 * @param priceStr		precio de pasajero
 * @param flycodeStr	codigo de vuelo del pasajero
 * @param tipoPasajeroStr	ID tipo de pasajero
 * @param statusFlight	id tipo de vuelo
 * @return	retorna puntero a pasajero si se pudo crear correctamente o puntero a NULL en caso de error
 */
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* priceStr, char* flycodeStr, char* tipoPasajeroStr, char* statusFlight);


/**
 * @fn void Passenger_delete(Passenger*)
 * @brief  deletes a passenger
 *
 * @param this	pointer to passenger to delete
 */
void Passenger_delete(Passenger* this);


/**
 * @fn int Passenger_setId(Passenger*, int)
 * @brief 	sets a passenger ID
 *
 * @param this	pointer to passenger to set ID
 * @param id	ID to set
 * @return	returns 0 if ok or -1 if ERROR (null pointer or invalid ID)
 */
int Passenger_setId(Passenger* this, int id);

/**
 * @fn int Passenger_getId(Passenger*, int*)
 * @brief	Gets a passengers ID
 *
 * @param this	pointer to passenger to set ID
 * @param id	pointer to int where put ID
 * @return	returns 0 if ok or -1 if ERROR (null pointer)
 */
int Passenger_getId(Passenger* this, int* id);


/**
 * @fn int Passenger_setNombre(Passenger*, char*)
 * @brief 	sets a passenger name
 *
 * @param this	pointer to passenger to set name
 * @param nombre	name to set
 * @return	returns 0 if ok or -1 if ERROR (null pointers)
 */
int Passenger_setNombre(Passenger* this, char* nombre);

/**
 * @fn int Passenger_getNombre(Passenger*, char*)
 * @brief 	Gets a passengers name
 *
 * @param this	pointer to passenger to set name
 * @param nombre	pointer to char where put name
 * @return	returns 0 if ok or -1 if ERROR (null pointer)
 */
int Passenger_getNombre(Passenger* this, char* nombre);


/**
 * @fn int Passenger_setApellido(Passenger*, char*)
 * @brief 	sets a passenger lastname
 *
 * @param this	pointer to passenger to set lastname
 * @param nombre	lastname to set
 * @return	returns 0 if ok or -1 if ERROR (null pointers)
 */
int Passenger_setApellido(Passenger* this, char* apellido);

/**
 * @fn int Passenger_getApellido(Passenger*, char*)
 * @brief 	Gets a passengers lastname
 *
 * @param this	pointer to passenger to set lastname
 * @param nombre	pointer to char where put lastname
 * @return	returns 0 if ok or -1 if ERROR (null pointer)
 */
int Passenger_getApellido(Passenger* this, char* apellido);


/**
 * @fn int Passenger_setCodigoVuelo(Passenger*, char*)
 * @brief	sets a passenger flycode
 *
 * @param this	pointer to passenger to set flycode
 * @param codigoVuelo	flycode to set
 * @return	returns 0 if ok or -1 if ERROR (null pointers)
 */
int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);

/**
 * @fn int Passenger_getCodigoVuelo(Passenger*, char*)
 * @brief	gets a passenger flycode
 *
 * @param this	pointer to passenger to set flycode
 * @param codigoVuelo	pointer to char where put flycode
 * @return	returns 0 if ok or -1 if ERROR (null pointer)
 */
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);


/**
 * @fn int Passenger_setTipoPasajero(Passenger*, int)
 * @brief 	sets a passenger type
 *
 * @param this	pointer to passenger to set type
 * @param tipoPasajero	type to set
 * @return	returns 0 if ok or -1 if ERROR (null pointer, invalid type)
 */
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);

/**
 * @fn int Passenger_getTipoPasajero(Passenger*, int*)
 * @brief	gets a passenger type
 *
 * @param this	pointer to passenger to set type
 * @param tipoPasajero	pointer to int where to put type
 * @return	returns 0 if ok or -1 if ERROR (null pointer)
 */
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);


/**
 * @fn int Passenger_setFlightStatus(Passenger*, int)
 * @brief 	sets a passenger flightStatus
 *
 * @param this	pointer to passenger to set flight status
 * @param flightStatus	status to set
 * @return	returns 0 if ok or -1 if ERROR (null pointer, invalid status)
 */
int Passenger_setFlightStatus(Passenger* this, int flightStatus);

/**
 * @fn int Passenger_getFlightStatus(Passenger*, int*)
 * @brief 	gets a passenger flightStatus
 *
 * @param this	pointer to passenger to set flight status
 * @param flightStatus	pointer to int where to put status
 * @return	returns 0 if ok or -1 if ERROR (null pointer)
 */
int Passenger_getFlightStatus(Passenger* this, int* flightStatus);


/**
 * @fn int Passenger_setPrecio(Passenger*, float)
 * @brief 	sets a passenger price
 *
 * @param this	pointer to passenger to set price
 * @param precio	price to set
 * @return	returns 0 if ok or -1 if ERROR (null pointer)
 */
int Passenger_setPrecio(Passenger* this, float precio);

/**
 * @fn int Passenger_getPrecio(Passenger*, float*)
 * @brief	gets a passenger price
 *
 * @param this	pointer to passenger to set price
 * @param precio	pointer to float where to put price
 * @return	returns 0 if ok or -1 if ERROR (null pointer)
 */
int Passenger_getPrecio(Passenger* this, float* precio);


/**
 * @fn int Passenger_getPosition(LinkedList*, int*)
 * @brief 	gets a passenegr position from a passenger array
 *
 * @param pArrayListPassenger	passenger array
 * @param id	id to get position
 * @return	returns passenger position index, or -1 if ERROR
 */
int Passenger_getIndexById(LinkedList* pArrayListPassenger, int id);


/**
 * @fn int listAllPassengers(LinkedList*)
 * @brief	muestra en pantalla la lista de todos los pasajeros cargados
 *
 * @param pArrayListPassenger	lista de pasajeros a mostrar
 * @return	cantidad de pasajeros en lista, -1 si hubo error al traer datos de un pasajero, -2 error en puntero a lista de pasajeros
 */
int listAllPassengers(LinkedList* pArrayListPassenger);


/**
 * @fn int showPassenger(Passenger*)
 * @brief 	shows a passenger data on screen.
 *
 * @param aPassenger	passenger to show.
 * @return	returns 0 if ok or -1 if ERROR (null pointer or error showing passenger)
 */
int showPassenger(Passenger* aPassenger);


/**
 * @fn int Passenger_compareById(void*, void*)
 * @brief 	compara 2 pasajeros por sus IDs
 *
 * @param p1	puntero a void donde se encuentra un pasajero
 * @param p2	puntero a void donde se encuentra otro pasajero
 * @return	1 si el ID del primer pasajero es mayor al 2do, -1 si el ID del primer pasajero es menor al 2do, 0 si tienen el mismo ID
 */
int Passenger_compareById(void* p1, void* p2);

/**
 * @fn int Passenger_compareByName(void*, void*)
 * @brief 	Compara 2 pasajeros por sus nombres
 *
 * @param p1	puntero a void donde se encuentra un pasajero
 * @param p2	puntero a void donde se encuentra otro pasajero
 * @return	retorna la comparacion de los strings de los nombres de ambos pasajeros, -1 si error
 */
int Passenger_compareByName(void* p1, void* p2);

/**
 * @fn int Passenger_compareByLastname(void*, void*)
 * @brief 	Compara 2 pasajeros por sus apellidos
 *
 * @param p1	puntero a void donde se encuentra un pasajero
 * @param p2	puntero a void donde se encuentra otro pasajero
 * @return	retorna la comparacion de los strings de los apellidos de ambos pasajeros, -1 si error
 */
int Passenger_compareByLastname(void* p1, void* p2);

/**
 * @fn int Passenger_compareByPrice(void*, void*)
 * @brief 	Compara 2 pasajeros por sus precios
 *
 * @param p1	puntero a void donde se encuentra un pasajero
 * @param p2	puntero a void donde se encuentra otro pasajero
 * @return	1 si el precio del primer pasajero es mayor al 2do, -1 si el precio del primer pasajero es menor al 2do, 0 si tienen el mismo precio
 */
int Passenger_compareByPrice(void* p1, void* p2);

/**
 * @fn int Passenger_compareByTypePassenger(void*, void*)
 * @brief 	Compara 2 pasajeros por sus ID de tipo de pasajero
 *
 * @param p1	puntero a void donde se encuentra un pasajero
 * @param p2	puntero a void donde se encuentra otro pasajero
 * @return	1 si el ID del primer pasajero es mayor al 2do, -1 si el ID del primer pasajero es menor al 2do, 0 si tienen el mismo ID
 */
int Passenger_compareByTypePassenger(void* p1, void* p2);

/**
 * @fn int Passenger_compareByFlycode(void*, void*)
 * @brief 	Compara 2 pasajeros por sus codigos de vuelo
 *
 * @param p1	puntero a void donde se encuentra un pasajero
 * @param p2	puntero a void donde se encuentra otro pasajero
 * @return	retorna la comparacion de los strings de los codigos de vuelo de ambos pasajeros, -1 si error
 */
int Passenger_compareByFlycode(void* p1, void* p2);

/**
 * @fn int Passenger_compareByFlightStatus(void*, void*)
 * @brief 	Compara 2 pasajeros por sus ID de estatus de vuelo
 *
 * @param p1	puntero a void donde se encuentra un pasajero
 * @param p2	puntero a void donde se encuentra otro pasajero
 * @return	1 si el ID del primer pasajero es mayor al 2do, -1 si el ID del primer pasajero es menor al 2do, 0 si tienen el mismo ID
 */
int Passenger_compareByFlightStatus(void* p1, void* p2);




#endif /* PASSENGER_H_ */

/*
 * ArrayPassenger.h
 *
 *  Created on: May 8, 2022
 *      Author: Facundo
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "ArrayTypePassenger.h"
#include "ArrayFlight.h"


#define QTY_NAME 51
#define QTY_CODE 10

#define TRUE 1
#define FALSE 0

#define UP 1
#define DOWN 0


typedef struct
{
	int id;
	char name[QTY_NAME];
	char lastname[QTY_NAME];
	float price;
	char flycode[QTY_CODE];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} sPassenger;




/**
 * @fn int initPassengers(sPassenger*, int)
 * @brief  To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array.
 *
 * @param list  list sPassenger* Pointer to array of passenger.
 * @param len  len int Array lenght.
 * @return  int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initPassengers(sPassenger* list, int len);


/**
 * @fn int cargarDatos(sPassenger*, int, sTypePassenger*, int, sFlightStatus*, int)
 * @brief  carga datos y si los datos son validos los pasa a addPassenger para que sean adheridos al array
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @param typesPassenger  Pointer to array of type of passenger.
 * @param typesLen	Array lenght.
 * @param statusFlights  Pointer to array of flight status.
 * @param statusLen	 Array lenght.
 * @return Return (-1) if Error [Invalid length or NULL pointer or invalid data] - (0) if Ok
 */
int cargarDatos(sPassenger* list, int len, sTypePassenger* typesOfPassenger, int typesLen, sFlightStatus* statusFlights, int statusLen, int* qtyPassengers);


/**
 * @fn int addPassenger(sPassenger*, int, int, char[], char[], float, int, char[], int)
 * @brief  add in a existing list of passengers the values received as parameters.
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @param id int  passenger id.
 * @param name[] char  passenger name.
 * @param lastName[] char  passenger lastname.
 * @param price float  passenger price.
 * @param typePassenger int  type of passenger.
 * @param flycode[] char  passenger flycode.
 * @param statusFlight int  statusId
 * @return int  Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addPassenger(sPassenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight);


/**
 * @fn int modifyPassenger(sPassenger*, int, sTypePassenger*, int, sFlightStatus*, int)
 * @brief  modifies a name, lastname, price, typePassenger or flycode
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @param typesPassenger  Pointer to array of type of passenger.
 * @param typesLen	Array lenght.
 * @param statusFlights  Pointer to array of flight status.
 * @param statusLen	 Array lenght.
 * @return  Return (-1) if Error [Invalid length or NULL pointer or couldnt modify] - (0) if Ok
 */
int modifyPassenger(sPassenger* list, int len, sTypePassenger* typesPassenger, int typesLen, sFlightStatus* statusFlights, int statusLen);


/**
 * @fn int reportPassenger(sPassenger*, int, sTypePassenger*, int, sFlightStatus*, int)
 * @brief  print informs about passengers info
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @param typesPassenger  Pointer to array of type of passenger.
 * @param typesLen	Array lenght.
 * @param statusFlights  Pointer to array of flight status.
 * @param statusLen	 Array lenght.
 * @return  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int reportPassenger(sPassenger* list, int len, sTypePassenger* typesPassenger, int typesLen, sFlightStatus* statusFlights, int statusLen);



/**
 * @fn int removePassengersMenu(sPassenger*, int, sTypePassenger*, int, sFlightStatus*, int)
 * @brief  prints all non-empty passengers and remove by asking an ID.
 *
 * @param list  sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @param typesPassenger  Pointer to array of type of passenger.
 * @param typesLen	Array lenght.
 * @param statusFlights  Pointer to array of flight status.
 * @param statusLen	 Array lenght.
 * @return  Return (-1) if Error [Invalid length or NULL pointer or couldnt remove] - (0) if Ok
 */
int removePassengersMenu(sPassenger* list, int len, sTypePassenger* typesPassenger, int typesLen, sFlightStatus* statusFlights, int statusLen, int* qtyPassengers);


/**
 * @fn int altaForzada(sPassenger*, int, sTypePassenger*, sFlightStatus*)
 * @brief  fuerza la carga de 5 datos hardcodeados en un array de pasajeros
 *
 * @param list  sPassenger*  Pointer to array of passenger.
 * @param len  Array lenght.
 * @param typesPassenger  Pointer to array of type of passenger.
 * @param statusFlights  Pointer to array of flight status.
 * @return Return (-1) if Error [Invalid length or NULL pointer or couldnt remove] - (0) if Ok
 */
int altaForzada(sPassenger* list, int len, sTypePassenger* typesPassenger, sFlightStatus* statusFlights, int* qtyPassengers);



/**
 * @fn int emptyPassenger(sPassenger*, int)
 * @brief  return empty array position when find.
 *
 * @param list sPassenger* Pointer to array of passenger.
 * @param len int Array lenght.
 * @return  int  Return (-1) if Error [Invalid length or NULL pointer or without free space] - (empty array position) if Ok
 */
int emptyPassenger(sPassenger* list, int len);


/**
 * @fn int findPassengerById(sPassenger*, int, int)
 * @brief find a Passenger by Id and returns the index position in array.
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @param id int  passenger id to look for.
 * @return int  Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
 */
int findPassengerById(sPassenger* list, int len, int id);


/**
 * @fn int removePassenger(sPassenger*, int, int)
 * @brief  Remove a Passenger by Id (put isEmpty Flag in 1)
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @param id int  passenger id to look for.
 * @return int  Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
 */
int removePassenger(sPassenger* list, int len, int id);


/**
 * @fn int sortPassengers(sPassenger*, int, int)
 * @brief  Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @param order int  [1] indicate UP - [0] indicate DOWN
 * @return int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortPassengers(sPassenger* list, int len, int order);



/**
 * @fn int printAllPassengers(sPassenger*, int, sTypePassenger*, int, sFlightStatus*, int)
 * @brief  print the content of passengers array
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param length int  Array lenght.
 * @param typesPassenger  Pointer to array of type of passenger.
 * @param typesLen	Array lenght.
 * @param statusFlights  Pointer to array of flight status.
 * @param statusLen	 Array lenght.
 * @return int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printAllPassengers(sPassenger* list, int length, sTypePassenger* typePassengers, int typesLen, sFlightStatus* FlightsStatus, int statusLen);



/**
 * @fn void printAPassenger(sPassenger, sTypePassenger*, int, sFlightStatus*, int)
 * @brief  prints a passenger.
 *
 * @param aPassenger  passenger to print.
 * @param typesPassenger  Pointer to array of type of passenger.
 * @param typesLen	Array lenght.
 * @param statusFlights  Pointer to array of flight status.
 * @param statusLen	 Array lenght.
 */
void printAPassenger(sPassenger aPassenger, sTypePassenger* typePassengers, int typesLen, sFlightStatus* FlightsStatus, int statusLen);


/**
 * @fn int sortPassengersByCode(sPassenger*, int, int)
 * @brief  Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @param order int  [1] indicate UP - [0] indicate DOWN
 * @return int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortPassengersByCode(sPassenger* list, int len, int order);


/**
 * @fn int filterPassengerByStatus(sPassenger*, int, sTypePassenger*, int, sFlightStatus*, int)
 * @brief Filters a passenger array by status (only print passengers with flight status ACTIVE
 *
 * @param list  sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @param typesPassenger  Pointer to array of type of passenger.
 * @param typesLen	Array lenght.
 * @param statusFlights  Pointer to array of flight status.
 * @param statusLen	 Array lenght.
 * @return int  Return (-1) if Error [Invalid length or NULL pointer] - (0) no passengers with active status - (qty of passengers with status ACTIVO) if Ok
 */
int filterPassengerByStatus(sPassenger* list, int len, sTypePassenger* typePassengers, int typesLen, sFlightStatus* FlightsStatus, int statusLen);



/**
 * @fn int sortPassengersById(sPassenger*, int, int)
 * @brief  Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @param order int  [1] indicate UP - [0] indicate DOWN
 * @return int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortPassengersById(sPassenger* list, int len, int order);



/**
 * @fn int swapPassengers(sPassenger*, int, int)
 * @brief  Swaps two passengers from an array of passengers.
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param PassengerA int  first position to swap.
 * @param PassengerB int  second position to swap.
 * @return int  Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int swapPassengers(sPassenger* list, int PassengerA, int PassengerB);


/**
 * @fn int findOccupied(sPassenger*, int)
 * @brief  looks for an occupied place from a passenger's array.
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @return int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int findOccupied(sPassenger* list, int len);


/**
 * @fn int modifyName(sPassenger*, char[], int, char*)
 * @brief  modifies name if data is alpha only
 *
 * @param list  sPassenger*  Pointer to array of passenger.
 * @param actualName  pointer to actual name
 * @param index  index position in array
 * @return  Return (-1) if Error [Invalid length or NULL pointer or no more retries] - (0) if Ok
 */
int modifyName(sPassenger* list, char actualName[], int index);


/**
 * @fn int modifyLastName(sPassenger*, char[], int, char*)
 * @brief  modifies lastname if data is alpha only
 *
 * @param list  sPassenger*  Pointer to array of passenger.
 * @param actualName  pointer to actual lastname
 * @param index  index position in array
 * @return  Return (-1) if Error [Invalid length or NULL pointer or no more retries] - (0) if Ok
 */
int modifyLastName(sPassenger* list, char actualLastName[], int index);


/**
 * @fn int modifyPrice(float, int, sPassenger*)
 * @brief modifies price if data is  ok
 *
 * @param actualPrice  actual price
 * @param index  index position in array
 * @param list  sPassenger*  Pointer to array of passenger.
 * @return  Return (-1) if Error [Invalid length or NULL pointer or no more retries] - (0) if Ok
 */
int modifyPrice(float actualPrice, int index, sPassenger* list);


/**
 * @fn int modifyTipePassenger(sPassenger*, int, int, sTypePassenger*, int)
 * @brief  modifies type of passenger if data is ok
 *
 * @param list  sPassenger*  Pointer to array of passenger.
 * @param index  index position in array
 * @param actualTypePassId  actual type passenger ID.
 * @param typePassenger  Pointer to array of type of passenger.
 * @param typeLen int  Array lenght.
 * @return  Return (-1) if Error [Invalid length or NULL pointer or no more retries] - (0) if Ok
 */
int modifyTypePassenger(sPassenger* list, int index, int actualTypePassId, sTypePassenger* typePassenger, int typeLen);



/**
 * @fn int modifyFlycode(sPassenger*, char[], int, char*)
 * @brief  modifies flycode if data is alphanumeric only
 *
 * @param list  sPassenger*  Pointer to array of passenger.
 * @param actualName  pointer to actual flycode
 * @param index  index position in array
 * @return  Return (-1) if Error [Invalid length or NULL pointer or no more retries] - (0) if Ok
 */
int modifyFlycode(sPassenger* list, char actualCode[], int index);



/**
 * @fn int reportAverages(sPassenger*, int)
 * @brief  reports total and average of active passengers
 *
 * @param list   sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @return  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int reportAverages(sPassenger* list, int len);


/**
 * @fn int countOccupied(sPassenger*, int)
 * @brief  looks for all occupied places from a passenger's array.
 *
 * @param list sPassenger*  Pointer to array of passenger.
 * @param len int  Array lenght.
 * @return int  Return (-1) if Error [Invalid length or NULL pointer] - (qty of elements occupied) if Ok
 */
int countOccupied(sPassenger* list, int len);


/**
 * @fn int verifyOccupied(sPassenger*, int)
 * @brief  verifies if an element (received by an array and a position) is empty or occupied.
 *
 * @param list  sPassenger*  Pointer to array of passenger.
 * @param indexPosition  index position in array
 * @return  Return (-1) if Error [Invalid length or NULL pointer or not occupied] - (index psoition) if Ok
 */
int verifyOccupied(sPassenger* list, int indexPosition);






/**
 * @fn int calcularTotalImportes(sPassenger*, int, float*, float)
 * @brief  funcion para calcular el total de importes de pasajeros activos mayores a un monto especifico y devolverlos por referencia.
 *
 * @param list   sPassenger*  Pointer to array of passenger.
 * @param len  Array lenght.
 * @param pTotalImportes  pointer to input total number
 * @param importeMinimo  minimum number
 * @return  Return (-1) if Error [Invalid length or NULL pointer] - (qty of elements that surpass minimum value) if Ok
 */
int calcularTotalImportes(sPassenger* list, int len, float* pTotalImportes, float importeMinimo);



/**
 * @fn int calcularPromedio(float, int, float*)
 * @brief calcula el promedio de un numero recibido como parametro y la cantidad que lo divide y lo devuelve por referencia
 *
 * @param numTotal  num a dividir
 * @param cantidad  num por el cual dividir
 * @param promedio  promedio
 * @return  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int calcularPromedio(float numTotal, int cantidad, float* promedio);


#endif /* ARRAYPASSENGER_H_ */

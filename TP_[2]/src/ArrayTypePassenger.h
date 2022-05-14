/*
 * ArrayTypePassenger.h
 *
 *  Created on: May 14, 2022
 *      Author: Facundo
 */

#ifndef ARRAYTYPEPASSENGER_H_
#define ARRAYTYPEPASSENGER_H_


#define QTY_TYPE 21


typedef struct
{
	int id;
	char typeName[QTY_TYPE];
} sTypePassenger;




/**
 * @fn int printAllTypePassengers(sTypePassenger*, int, char[])
 * @brief  print the content of a type of passengers array
 *
 * @param typePassenger* Pointer to array of typePassenger.
 * @param len  Array lenght.
 * @param message  message to print.
 * @return int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printAllTypePassengers(sTypePassenger* typePassenger, int len, char message[]);


/**
 * @fn void printTypePassenger(sTypePassenger, int)
 * @brief  print a type of passengers
 *
 * @param typeOfPassenger  type to print.
 * @param position
 */
void printTypePassenger(sTypePassenger typeOfPassenger, int position);


/**
 * @fn int getTypePassengerByIndex(sTypePassenger*, int)
 * @brief  gets a type of passenger by index
 *
 * @param typePassenger
 * @param index  index of typePassenger
 * @return  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getTypePassengerByIndex(sTypePassenger* typePassenger, int index);


/**
 * @fn int getTypePassengerName(int, sTypePassenger*, int, char*)
 * @brief  return to a pointer name (char*) of id received
 *
 * @param idTypePassenger  id to find.
 * @param typePassenger* Pointer to array of typePassenger.
 * @param len  Array lenght.
 * @param typeDescription  pointer to char to copy original name.
 * @return  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getTypePassengerName(int idTypePassenger, sTypePassenger* typePassenger, int len, char* typeDescription);



#endif /* ARRAYTYPEPASSENGER_H_ */

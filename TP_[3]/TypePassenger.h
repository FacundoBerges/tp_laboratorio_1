/*
 * TypePassenger.h
 *
 *  Created on: Jun 6, 2022
 *      Author: Facundo
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_


/**
 * @fn int TypePassenger_getIdByName(char*, int*)
 * @brief 	gets a type passenger ID by his name
 *
 * @param TypePassengerName	Type passenger name to look for
 * @param id	int pointer where to put ID
 * @return	0 if ok, -1 if error
 */
int TypePassenger_getIdByName(char* TypePassengerName, int* id);

/**
 * @fn int TypePassenger_getNameById(int, char*)
 * @brief 	gets a type passenger name by his ID
 *
 * @param id	id to look for
 * @param TypePassengerName		char pointer where to put type name
 * @return	0 if ok, -1 if error
 */
int TypePassenger_getNameById(int id, char* TypePassengerName);

/**
 * @fn void showTypePassenger(void)
 * @brief 	shows type passenger list
 *
 */
void showTypePassenger(void);



#endif /* TYPEPASSENGER_H_ */

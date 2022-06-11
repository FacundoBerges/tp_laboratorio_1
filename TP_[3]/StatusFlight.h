/*
 * StatusFlight.h
 *
 *  Created on: Jun 6, 2022
 *      Author: Facundo
 */

#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_


/**
 * @fn int StatusFlight_getIdByName(char*, int*)
 * @brief	gets a flight status ID by his name
 *
 * @param StatusFlightName	Status name to look for
 * @param id	int pointer where to put ID
 * @return	0 if ok, -1 if error
 */
int StatusFlight_getIdByName(char* StatusFlightName, int* id);


/**
 * @fn int StatusFlight_getNameById(int, char*)
 * @brief	gets a flight status name by his ID
 *
 * @param id	ID to look for
 * @param StatusFlightName	char pointer where to put status name
 * @return	0 if ok, -1 if error
 */
int StatusFlight_getNameById(int id, char* StatusFlightName);


/**
 * @fn void showFlightStatus(void)
 * @brief 	shows flight status list
 *
 */
void showFlightStatus(void);



#endif /* STATUSFLIGHT_H_ */

/*
 * ArrayFlight.h
 *
 *  Created on: May 13, 2022
 *      Author: Facundo
 */

#ifndef ARRAYFLIGHT_H_
#define ARRAYFLIGHT_H_



#define QTY_TYPE 21


typedef struct
{
	int id;
	char statusName[QTY_TYPE];
}sFlightStatus;


/**
 * @fn int printAllStatusFlights(sFlightStatus*, int, char[])
 * @brief  print the content of a status flight's array
 *
 * @param statusFlights  Pointer to array of statusFlights.
 * @param len  Array lenght.
 * @param message message to print.
 * @return  int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printAllStatusFlights(sFlightStatus* statusFlights, int len, char message[]);


/**
 * @fn void printStatusFlight(sFlightStatus, int)
 * @brief print a flight status
 *
 * @param flightStatus  status to print.
 * @param position
 */
void printStatusFlight(sFlightStatus flightStatus, int position);


/**
 * @fn int getFlightStatusByIndex(sFlightStatus*, int)
 * @brief  gets a status flight by index
 *
 * @param statusFlights
 * @param index  index of flightstatus.
 * @return  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getFlightStatusByIndex(sFlightStatus* statusFlights, int index);




/**
 * @fn int getFlightStatusName(int, sFlightStatus*, int, char*)
 * @brief  return to a pointer name (char*) of id received
 *
 * @param idStatusFlight  id to find.
 * @param statusFlights* Pointer to array of flightStatus.
 * @param len  Array lenght. pointer to char to copy original name.
 * @param statusDescription
 * @return  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getFlightStatusName(int idStatusFlight, sFlightStatus* statusFlights, int len, char* statusDescription);



#endif /* ARRAYFLIGHT_H_ */

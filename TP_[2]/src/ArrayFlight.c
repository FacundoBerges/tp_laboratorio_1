/*
 * ArrayFlight.c
 *
 *  Created on: May 13, 2022
 *      Author: Facundo
 */

#include <stdio.h>
#include <string.h>
#include "ArrayFlight.h"


int printAllStatusFlights(sFlightStatus* statusFlights, int len, char message[])
{
	int ret = -1;
	int i;

	if(statusFlights != NULL && message != NULL && len > 0)
	{
		printf("%s\n", message);

		for(i = 0; i < len; i++)
		{
			printStatusFlight(statusFlights[i], i+1);
		}

		ret = 0;
	}

	return ret;
}


void printStatusFlight(sFlightStatus flightStatus, int position)
{
	printf("%d.\t%15s\n", position, flightStatus.statusName);
}


int getFlightStatusByIndex(sFlightStatus* statusFlights, int index)
{
	int ret = -1;

	if(statusFlights != NULL && index >= 0)
	{
		ret = statusFlights[index].id;
	}

	return ret;
}


int getFlightStatusName(int idStatusFlight, sFlightStatus* statusFlights, int len, char* statusDescription)
{
	int ret = -1;
	int i;

	if(statusFlights != NULL && statusDescription != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(statusFlights[i].id == idStatusFlight)
			{
				strcpy(statusDescription, "\0");
				strcpy(statusDescription, statusFlights[i].statusName);
				ret = 0;
				break;
			}
		}
	}

	return ret;
}

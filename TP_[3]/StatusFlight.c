/*
 * StatusFlight.c
 *
 *  Created on: Jun 6, 2022
 *      Author: Facundo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StatusFlight.h"



int StatusFlight_getIdByName(char* StatusFlightName, int* id)
{
	int rtn = -1;

	if(StatusFlightName != NULL && id != NULL)
	{
		if(stricmp(StatusFlightName, "Aterrizado") == 0)
		{
			*id = 1;
			rtn = 0;
		}
		else if(stricmp(StatusFlightName, "En Horario") == 0)
		{
			*id = 2;
			rtn = 0;
		}
		else if(stricmp(StatusFlightName, "En Vuelo") == 0)
		{
			*id = 3;
			rtn = 0;
		}
		else if(stricmp(StatusFlightName, "Demorado") == 0)
		{
			*id = 4;
			rtn = 0;
		}
		else
		{
			*id = 0; // Error
		}
	}

	return rtn;
}


int StatusFlight_getNameById(int id, char* StatusFlightName)
{
	int rtn = -1;

	if(StatusFlightName != NULL && id > 0)
	{
		if(id == 1)
		{
			strcpy(StatusFlightName, "");
			strcpy(StatusFlightName, "Aterrizado");
			rtn = 0;
		}
		else if(id == 2)
		{
			strcpy(StatusFlightName, "");
			strcpy(StatusFlightName, "En Horario");
			rtn = 0;
		}
		else if(id == 3)
		{
			strcpy(StatusFlightName, "");
			strcpy(StatusFlightName, "En Vuelo");
			rtn = 0;
		}
		else if(id == 4)
		{
			strcpy(StatusFlightName, "");
			strcpy(StatusFlightName, "Demorado");
			rtn = 0;
		}
	}

	return rtn;
}


void showFlightStatus(void)
{
	printf("\n\n-----Estado del vuelo-----\n\n\t1. Aterrizado.\n\t2. En Horario.\n\t3. En Vuelo.\n\t4. Demorado.\n\n");
}


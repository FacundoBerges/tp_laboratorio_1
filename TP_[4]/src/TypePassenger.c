/*
 * TypePassenger.c
 *
 *  Created on: Jun 6, 2022
 *      Author: Facundo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TypePassenger.h"


int TypePassenger_getIdByName(char* TypePassengerName, int* id)
{
	int rtn = -1;

	if(TypePassengerName != NULL && id != NULL)
	{

		if(stricmp(TypePassengerName, "EconomyClass") == 0)
		{
			*id = 1;
			rtn = 0;
		}
		else if(stricmp(TypePassengerName, "ExecutiveClass") == 0)
		{
			*id = 2;
			rtn = 0;
		}
		else if(stricmp(TypePassengerName, "FirstClass") == 0)
		{
			*id = 3;
			rtn = 0;
		}
		else
		{
			*id = 0; // Error
		}
	}

	return rtn;
}


int TypePassenger_getNameById(int id, char* TypePassengerName)
{
	int rtn = -1;

	if(TypePassengerName != NULL && id > 0)
	{
		if(id == 1)
		{
			strcpy(TypePassengerName, "");
			strcpy(TypePassengerName, "EconomyClass");
			rtn = 0;
		}
		else if(id == 2)
		{
			strcpy(TypePassengerName, "");
			strcpy(TypePassengerName, "ExecutiveClass");
			rtn = 0;
		}
		else if(id == 3)
		{
			strcpy(TypePassengerName, "");
			strcpy(TypePassengerName, "FirstClass");
			rtn = 0;
		}
	}

	return rtn;
}


void showTypePassenger(void)
{
	printf("\n\n-----Tipo de pasajero-----\n\n\t1. EconomyClass.\n\t2. ExecutiveClass.\n\t3. FirstClass.\n\n");
}



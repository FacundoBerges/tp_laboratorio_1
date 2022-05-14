/*
 * ArrayTypePassenger.c
 *
 *  Created on: May 14, 2022
 *      Author: Facundo
 */


#include <stdio.h>
#include <string.h>
#include "ArrayTypePassenger.h"


int printAllTypePassengers(sTypePassenger* typePassenger, int len, char message[])
{
	int ret = -1;
	int i;

	if(typePassenger != NULL && message != NULL && len > 0)
	{
		printf("%s\n", message);

		for(i = 0; i < len; i++)
		{
			printTypePassenger(typePassenger[i], i+1);
		}

		ret = 0;
	}

	return ret;
}


void printTypePassenger(sTypePassenger typeOfPassenger, int position)
{
	printf("%d.\t%15s\n", position, typeOfPassenger.typeName);
}


int getTypePassengerByIndex(sTypePassenger* typePassenger, int index)
{
	int retorno = -1;

	if(typePassenger != NULL && index >= 0)
	{
		retorno = typePassenger[index].id;
	}

	return retorno;
}


int getTypePassengerName(int idTypePassenger, sTypePassenger* typePassenger, int len, char* typeDescription)
{
	int ret = -1;
	int i;

	if(typePassenger != NULL && typeDescription != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(typePassenger[i].id == idTypePassenger)
			{
				strcpy(typeDescription, "\0");
				strcpy(typeDescription, typePassenger[i].typeName);
				ret = 0;
				break;
			}
		}
	}

	return ret;
}



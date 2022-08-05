/*
 * Computer.c
 *
 *  Created on: Aug 2, 2022
 *      Author: Facundo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Computer.h"

eComputer* Computer_new(void)
{
	eComputer* pComputer = (eComputer*) malloc(sizeof(eComputer));
	return pComputer;
}

eComputer* Computer_newParam(char* idStr, char* descripcion, char* precioStr, char* idTipoStr)
{
	int id;
	int idTipo;
	float precio;

	eComputer* pComputer = Computer_new();

	if(idStr != NULL && descripcion != NULL && precioStr != NULL && idTipoStr != NULL)
	{
		id = atoi(idStr);
		idTipo = atoi(idTipoStr);
		precio = atof(precioStr);

		if(	Computer_setId(pComputer, id) != 0 ||
			Computer_setDesc(pComputer, descripcion) != 0 ||
			Computer_setPrecio(pComputer, precio) != 0 ||
			Computer_setIdTipo(pComputer, idTipo) != 0)
		{
			Computer_delete(pComputer);
		}
	}

	return pComputer;
}


void Computer_delete(eComputer* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}


int Computer_setId(eComputer* this, int id)
{
	int rtn = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		rtn = 0;
	}

	return rtn;
}

int Computer_getId(eComputer* this, int* id)
{
	int rtn = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		rtn = 0;
	}

	return rtn;
}


int Computer_setDesc(eComputer* this, char* descr)
{
	int rtn = -1;

	if(this != NULL && descr != NULL && strlen(descr) > 0)
	{
		strcpy(this->descripcion, "");
		strcpy(this->descripcion, descr);
		rtn = 0;
	}

	return rtn;
}

int Computer_getDesc(eComputer* this, char* descr)
{
	int rtn = -1;

	if(this != NULL && descr != NULL)
	{
		strcpy(descr, "");
		strcpy(descr, this->descripcion);
		rtn = 0;
	}

	return rtn;
}


int Computer_setPrecio(eComputer* this, float precio)
{
	int rtn = -1;

	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		rtn = 0;
	}

	return rtn;
}

int Computer_getPrecio(eComputer* this, float* precio)
{
	int rtn = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		rtn = 0;
	}

	return rtn;
}



int Computer_setIdTipo(eComputer* this, int id)
{
	int rtn = -1;

	if(this != NULL && id > 0)
	{
		this->idTipo = id;
		rtn = 0;
	}

	return rtn;
}

int Computer_getIdTipo(eComputer* this, int* id)
{
	int rtn = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->idTipo;
		rtn = 0;
	}

	return rtn;
}


int Computer_compareByIdTipo(void* p1, void* p2)
{
	int rtn = 0;
	int auxId1;
	int auxId2;
	eComputer* pComputer = NULL;
	eComputer* anotherComputer = NULL;

	if(p1 != NULL && p2 != NULL)
	{
		pComputer = (eComputer*) p1;
		anotherComputer = (eComputer*) p2;

		if(	Computer_getIdTipo(pComputer, &auxId1) == 0 &&
			Computer_getIdTipo(anotherComputer, &auxId2) == 0)
		{
			if(auxId1 > auxId2)
			{
				rtn = 1;
			}
			else
			{
				if(auxId1 < auxId2)
				{
					rtn = -1;
				}
			}
		}
	}

	return rtn;
}



int Computer_getIdPorNombreTipo(char* nombreTipo, int* id)
{
	int rtn = -1;

	if(nombreTipo != NULL && id != NULL)
	{
		if(stricmp(nombreTipo, "Desktop") == 0)
		{
			*id = 1;
			rtn = 0;
		}
		else if(stricmp(nombreTipo, "Laptop") == 0)
		{
			*id = 2;
			rtn = 0;
		}
		else
		{
			*id = 0; // Error
		}
	}

	return rtn;
}


int Computer_getNombreTipoPorId(int id, char* nombreTipo)
{
	int rtn = -1;

	if(nombreTipo != NULL && id > 0)
	{
		if(id == 1)
		{
			strcpy(nombreTipo, "");
			strcpy(nombreTipo, "Desktop");
			rtn = 0;
		}
		else if(id == 2)
		{
			strcpy(nombreTipo, "");
			strcpy(nombreTipo, "Laptop");
			rtn = 0;
		}
	}

	return rtn;
}


int Computer_incrementarPrecioPorTipo(void* pElement)
{
	int rtn = -1;
	int auxIdTipo;
	float auxPrecio;
	float precioAumentado;
	float aumento;

	eComputer* pComputer = (eComputer*) pElement;

	if(pComputer != NULL)
	{
		if(	Computer_getIdTipo(pComputer, &auxIdTipo) == 0 &&
			Computer_getPrecio(pComputer, &auxPrecio) == 0)
		{
			if(auxIdTipo == 1)
			{
				aumento = 0.10;
			}
			else if(auxIdTipo == 2)
			{
				aumento = 0.20;
			}
			precioAumentado = auxPrecio + (auxPrecio * aumento);

			rtn = Computer_setPrecio(pComputer, precioAumentado);
		}
	}

	return rtn;
}


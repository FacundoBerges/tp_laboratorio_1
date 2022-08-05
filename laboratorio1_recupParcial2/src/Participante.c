/*
 * Participante.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Facundo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Participante.h"

eParticipante* eParticipante_new()
{
	eParticipante* pParticipante = (eParticipante*) malloc(sizeof(eParticipante));
	return pParticipante;
}

eParticipante* eParticipante_newParametros(char* strId, char* strNombre, char* strEdad, char* strCategId, char* strScore)
{
	int auxId;
	int auxEdad;
	int auxCatId;
	int auxScore;
	eParticipante* pParticipante = NULL;

	if(strId != NULL && strNombre != NULL && strEdad  != NULL && strCategId != NULL && strScore != NULL)
	{
		pParticipante = eParticipante_new();

		auxId = atoi(strId);
		auxEdad = atoi(strEdad);
		auxCatId = atoi(strCategId);
		auxScore = atoi(strScore);

		if(pParticipante != NULL)
		{
			if(	eParticipante_setId(pParticipante, auxId) == -1 ||
				eParticipante_setNombre(pParticipante, strNombre) == -1 ||
				eParticipante_setEdad(pParticipante, auxEdad) == -1 ||
				eParticipante_setCategId(pParticipante, auxCatId) == -1 ||
				eParticipante_setScore(pParticipante, auxScore) == -1)
			{
				eParticipante_delete(pParticipante);
			}
		}
	}

	return pParticipante;
}


void eParticipante_delete(eParticipante* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}


int eParticipante_setId(eParticipante* this, int id)
{
	int rtn = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		rtn = 0;
	}

	return rtn;
}

int eParticipante_getId(eParticipante* this, int* id)
{
	int rtn = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		rtn = 0;
	}

	return rtn;
}


int eParticipante_setNombre(eParticipante* this, char* nombre)
{
	int rtn = -1;

	if(this != NULL && nombre != NULL && strlen(nombre) > 0)
	{
		strcpy(this->nombre, "");
		strcpy(this->nombre, nombre);
		rtn = 0;
	}

	return rtn;
}

int eParticipante_getNombre(eParticipante* this, char* nombre)
{
	int rtn = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, "");
		strcpy(nombre, this->nombre);
		rtn = 0;
	}

	return rtn;
}


int eParticipante_setEdad(eParticipante* this, int edad)
{
	int rtn = -1;

	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		rtn = 0;
	}

	return rtn;
}

int eParticipante_getEdad(eParticipante* this, int* edad)
{
	int rtn = -1;

	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		rtn = 0;
	}

	return rtn;
}


int eParticipante_setCategId(eParticipante* this, int id)
{
	int rtn = -1;

	if(this != NULL && id > 0)
	{
		this->idCategoria = id;
		rtn = 0;
	}

	return rtn;
}

int eParticipante_getCategId(eParticipante* this, int* id)
{
	int rtn = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->idCategoria;
		rtn = 0;
	}

	return rtn;
}


int eParticipante_setScore(eParticipante* this, int score)
{
	int rtn = -1;

	if(this != NULL && score > 0)
	{
		this->score = score;
		rtn = 0;
	}

	return rtn;
}

int eParticipante_getScore(eParticipante* this, int* score)
{
	int rtn = -1;

	if(this != NULL && score != NULL)
	{
		*score = this->score;
		rtn = 0;
	}

	return rtn;
}


int eParticipante_getCategoriaPorId(int id, char* nombreTipo)
{
	int rtn = -1;


	if(nombreTipo != NULL && id > 0)
	{
		if(id == 1)
		{
			strcpy(nombreTipo, "");
			strcpy(nombreTipo, "MENOR");
			rtn = 0;
		}
		else if(id == 2)
		{
			strcpy(nombreTipo, "");
			strcpy(nombreTipo, "MAYOR");
			rtn = 0;
		}
	}

	return rtn;
}


int eParticipante_compararPorScore(void* p1, void* p2)
{
	int rtn = 0;
	int auxScore1;
	int auxScore2;
	eParticipante* pParticipante= NULL;
	eParticipante* otroParticipante = NULL;

	if(p1 != NULL && p2 != NULL)
	{
		pParticipante = (eParticipante*) p1;
		otroParticipante = (eParticipante*) p2;

		if(	eParticipante_getScore(pParticipante, &auxScore1) == 0 &&
				eParticipante_getScore(otroParticipante, &auxScore2) == 0)
		{
			if(auxScore1 > auxScore2)
			{
				rtn = 1;
			}
			else
			{
				if(auxScore1 < auxScore2)
				{
					rtn = -1;
				}
			}
		}
	}

	return rtn;
}


int eParticipante_esMenor(void* pParticipante)
{
	int rtn = 0;
	int auxCatId;
	pParticipante = (eParticipante*) pParticipante;

	if(pParticipante != NULL)
	{
		if(eParticipante_getCategId(pParticipante, &auxCatId) == 0)
		{
			if(auxCatId == 1)
			{
				rtn = 1;
			}
		}
	}

	return rtn;
}


int eParticipante_esMayor(void* pParticipante)
{
	int rtn = 0;
	int auxCatId;
	pParticipante = (eParticipante*) pParticipante;

	if(pParticipante != NULL)
	{
		if(eParticipante_getCategId(pParticipante, &auxCatId) == 0)
		{
			if(auxCatId == 2)
			{
				rtn = 1;
			}
		}
	}

	return rtn;
}

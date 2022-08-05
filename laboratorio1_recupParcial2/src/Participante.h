/*
 * Participante.h
 *
 *  Created on: Aug 4, 2022
 *      Author: Facundo
 */

#ifndef PARTICIPANTE_H_
#define PARTICIPANTE_H_


typedef struct
{
	int id;
	char nombre[128];
	int edad;
	int idCategoria;
	int score;
} eParticipante;


eParticipante* eParticipante_new();
eParticipante* eParticipante_newParametros(char* strId, char* strNombre, char* strEdad, char* strCategId, char* strScore);

void eParticipante_delete(eParticipante* this);

int eParticipante_setId(eParticipante* this, int id);
int eParticipante_getId(eParticipante* this, int* id);

int eParticipante_setNombre(eParticipante* this, char* nombre);
int eParticipante_getNombre(eParticipante* this, char* nombre);

int eParticipante_setEdad(eParticipante* this, int edad);
int eParticipante_getEdad(eParticipante* this, int* edad);

int eParticipante_setCategId(eParticipante* this, int id);
int eParticipante_getCategId(eParticipante* this, int* id);

int eParticipante_setScore(eParticipante* this, int score);
int eParticipante_getScore(eParticipante* this, int* score);

int eParticipante_getCategoriaPorId(int id, char* nombreTipo);

int eParticipante_compararPorScore(void* p1, void* p2);

int eParticipante_esMenor(void* pParticipante);
int eParticipante_esMayor(void* pParticipante);



#endif /* PARTICIPANTE_H_ */

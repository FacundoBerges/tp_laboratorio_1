/*
 * Computer.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Facundo
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_

typedef struct
{
	int id;
	char descripcion[512];
	float precio;
	int idTipo;
} eComputer;


eComputer* Computer_new(void);
eComputer* Computer_newParam(char* idStr, char* descripcion, char* precioStr, char* idTipoStr);
void Computer_delete(eComputer* this);

int Computer_setId(eComputer* this, int id);
int Computer_getId(eComputer* this, int* id);

int Computer_setDesc(eComputer* this, char* descr);
int Computer_getDesc(eComputer* this, char* descr);

int Computer_setPrecio(eComputer* this, float precio);
int Computer_getPrecio(eComputer* this, float* precio);

int Computer_setIdTipo(eComputer* this, int id);
int Computer_getIdTipo(eComputer* this, int* id);

int Computer_compareByIdTipo(void* p1, void* p2);

int Computer_getIdPorNombreTipo(char* nombreTipo, int* id);
int Computer_getNombreTipoPorId(int id, char* nombreTipo);

int Computer_incrementarPrecioPorTipo(void* pElement);

#endif /* COMPUTER_H_ */

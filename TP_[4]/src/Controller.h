
#ifndef CONTROLLER_H_
#define CONTROLLER_H_


/**
 * @fn int controller_loadFromText(char*, LinkedList*)
 * @brief 	Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * @param path char*	ruta del archivo a cargar.
 * @param pArrayListPassenger	 LinkedList*	puntero a array donde cargar los datos.
 * @return	int  cantidad de pasajeros (0 o mas) OK, -1 ERROR (path o pArrayListPassenger NULL)
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);


/**
 * @fn int controller_loadFromBinary(char*, LinkedList*)
 * @brief 	Carga los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * @param path	ruta del archivo a cargar.
 * @param pArrayListPassenger	puntero a array donde cargar los datos.
 * @return	cantidad de pasajeros (0 o mas) OK, -1 ERROR (path o pArrayListPassenger NULL)
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);


/**
 * @fn int controller_addPassenger(LinkedList*)
 * @brief 	Alta de pasajero
 *
 * @param pArrayListPassenger	puntero a la lista de pasajeros
 * @return	retorna 0 si se anadio pasajero correctamente, -1 si el puntero a lista es nulo, -2 si hubo error al setear datos y -3 si no se consiguio espacio para un nuevo pasajero en memoria dinamica.
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);


/**
 * @fn int controller_editPassenger(LinkedList*)
 * @brief 	Modificar datos de pasajero
 *
 * @param pArrayListPassenger	Lista donde buscar pasajeros a modificar
 * @return	0 si se pudo modificar dato correctamente, -1 puntero de lista nulo, -2 modificacion cancelada, -3 si se agotaron los intentos de ingreso del submenu, -4 puntero a pasajero apuntando a nulo, -5 ID ingresado no se encuentra dado de alta, -6 si se agotaron los reintentos de ingreso de ID o no se pudieron traer datos del ultimo pasajero de la lista
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);


/**
 * @fn int controller_removePassenger(LinkedList*)
 * @brief 	Baja de pasajero
 *
 * @param pArrayListPassenger	Lista donde buscar pasajeros a modificar
 * @return	retorna 0 si se dio de baja el pasajero correctamente, -1 puntero de lista nulo, -2 baja cancelada, -3 puntero a pasajero apuntando a nulo, -4 ID ingresado no se encuentra dado de alta, -5 si se agotaron los reintentos de ingreso de ID, -6 no se pudieron traer datos del ultimo pasajero de la lista
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);


/**
 * @fn int controller_ListPassenger(LinkedList*)
 * @brief 	Listar pasajeros
 *
 * @param pArrayListPassenger	Lista de pasajeros a listar
 * @return	Cantidad de pasajeros si se pudo listar, 0 si no hay paasajeros para listas, -1 Error (puntero a lista nulo)
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);


/**
 * @fn int controller_sortPassenger(LinkedList*)
 * @brief 	Ordenar pasajeros
 *
 * @param pArrayListPassenger	Lista de pasajeros a ordenar
 * @return	0 si se ordeno correctamente, -1 si el puntero a la lista de pasajeros es nulo, -2 si se cancelo ordenamiento, -3 si se agotaron los reintentos de ingreso de orden, -4 si se agotaron los reintentos de ingreso de opcion del submenu
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*	ruta del archivo a guardar.
 * \param pArrayListPassenger LinkedList*	puntero a array de datos a guardar.
 * \return int	0 OK, -1 ERROR al guardar
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 *
 * \param path char*	ruta del archivo a guardar.
 * \param pArrayListPassenger LinkedList*	puntero a array de datos a guardar.
 * \return int	0 OK, -1 ERROR al guardar
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


#endif /* CONTROLLER_H_ */

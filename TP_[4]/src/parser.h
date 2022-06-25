#ifndef PARSER_H_
#define PARSER_H_

/**
 * @fn int parser_PassengerFromText(FILE*, LinkedList*)
 * @brief 	Parses passengers data from data.csv file (text mode)
 *
 * @param pFile		pointer to file
 * @param pArrayListPassenger	pointer to passenger list
 * @return	returns 	quantity of passengers or -1 if error
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);


/**
 * @fn int parser_PassengerFromBinary(FILE*, LinkedList*)
 * @brief 	Parses passengers data from data.bin file (binary mode)
 *
 * @param pFile		pointer to file
 * @param pArrayListPassenger	pointer to passenger list
 * @return	 	quantity of passengers or -1 if error
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);


#endif /* PARSER_H_ */

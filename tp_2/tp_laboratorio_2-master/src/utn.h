/*
 * header.h
 *
 *  Created on: 16 sept. 2020
 *      Author: Fede
 */

#ifndef UTN_H_
#define UTN_H_



float utn_getFloat(char *mensaje, char *mensajeError, float *pResultado,int reintentos,float min, float max);
int utn_getNumero(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int minimo,int maximo);
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int utn_getString(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int ordenar(int array[], int len);



#endif /* UTN_H_ */

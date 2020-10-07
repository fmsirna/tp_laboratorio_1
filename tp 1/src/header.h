/*
 * header.h
 *
 *  Created on: 3 sept. 2020
 *      Author: Fede
 */

#ifndef HEADER_H_
#define HEADER_H_

float factorial(float numero, float *resultado);
float getFloat(char *mensaje, char *mensajeError, float *pResultado,int reintentos,float min, float max);
float Suma(float numeroA, float numeroB, float *resultado);
float Resta(float numeroA, float numeroB, float *resultado);
float Division(float numeroA, float numeroB, float *resultado);
float Multiplicacion(float numeroA, float numeroB, float *resultado);

#endif /* HEADER_H_ */

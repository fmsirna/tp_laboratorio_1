/*
 * informe.h
 *
 *  Created on: 3 oct. 2020
 *      Author: Fede
 */

#ifndef INFORME_H_
#define INFORME_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contratacion.h"
#include "pantalla.h"
#include "utn.h"

int info_imprimirPantallasPorCuit(Contratacion *arrayUno, int limiteUno,Pantalla *arrayDos,int limiteDos,char *auxCuit);
int info_imprimirFacturacion(Contratacion *arrayUno, int limiteUno,Pantalla *arrayDos,int limiteDos,char *auxCuit);
int info_imprimirDosArrays(Contratacion *arrayUno, int limiteUno,Pantalla *arrayDos,int limiteDos);

#endif /* INFORME_H_ */

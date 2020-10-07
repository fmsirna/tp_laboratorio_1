/*
 * logica.h
 *
 *  Created on: 17 sept. 2020
 *      Author: Fede
 */

#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#include "pantalla.h"
#include "utn.h"
#define NOMBRE_LEN 200
#define CUIT_LEN 200
#define CANT_CONTRATACION 1000


typedef struct
{
	char nombreArchivo [NOMBRE_LEN];
	int cantDias;
	int isEmpty;
	int idContratacion;
	char cuitCliente[CUIT_LEN];
	int idPantalla;
}Contratacion;

int cont_imprimir(Contratacion* pElemento);
int cont_imprimirArray(Contratacion *array, int limite);
int cont_inicializarArray(Contratacion *array, int limite);
int cont_altaArray(Contratacion *array,int limite,Pantalla *arrayRelacionado, int limiteRelacionado);
int cont_modificarArrayDias(Contratacion *array,int limite);
int cont_bajaArray(Contratacion *array,int limite);
int cont_buscarId(Contratacion *array, int limite,int valorBuscado);
int cont_getNextEmptyIndex(Contratacion *array, int limite);

int cont_altaForzada(Contratacion *array,int limite,int indice,int idContratacion,int idPantalla,char *nombreArchivo, int cantDias, char *cuitCliente);


#endif /* CONTRATACION_H_ */

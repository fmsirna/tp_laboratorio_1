/*
 * logica.h
 *
 *  Created on: 17 sept. 2020
 *      Author: Fede
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

#define NOMBRE_LEN 200
#define CANTIDAD_PANTALLAS 100


typedef struct
{
	char nombre [NOMBRE_LEN];
	char direccion [NOMBRE_LEN];
	int tipoPantalla;
	float precioDia;
	int isEmpty;
	int idPantalla;
}Pantalla;

int pant_imprimir(Pantalla* pElemento);
int pant_imprimirArray(Pantalla *array, int limite);
int pant_inicializarArray(Pantalla *array, int limite);
int pant_altaArray(Pantalla *array,int limite);
int pant_modificarArray(Pantalla *array,int limite);
int pant_bajaArray(Pantalla *array,int limite);
int pant_buscarId(Pantalla *array, int limite,int valorBuscado);
int pant_getNextEmptyIndex(Pantalla *array, int limite);

int pant_altaForzada(Pantalla *array,int limite,int indice,int id,char *nombre,char *direccion, float precio, int tipoPantalla);

#endif /* PANTALLA_H_ */

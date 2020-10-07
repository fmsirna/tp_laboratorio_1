/*
 * logica.c
 *
 *  Created on: 17 sept. 2020
 *      Author: Fede
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contratacion.h"
#include "pantalla.h"
#include "utn.h"

static int generarIdNuevo(void);

int cont_imprimir(Contratacion* pElemento)
{
	int retorno = -1;
	if(pElemento != NULL && pElemento->isEmpty ==0)
	{
		retorno=0;
		printf("\nidContratacion: %d - Archivo: %s -Dias: %d - idPantalla: %d - cuit: %s",pElemento->idContratacion,pElemento->nombreArchivo,pElemento->cantDias,pElemento->idPantalla,pElemento->cuitCliente);
	}
	return retorno;
}
int cont_imprimirArray(Contratacion *array, int limite)
{
	int retorno = -1;
	if(array !=NULL && limite>0)
	{
		retorno=0;
		for(int i=0;i<limite;i++)  //recordar que va con ;
		{
			cont_imprimir(&array[i]);
		}
	}
	return retorno;
}
int cont_altaForzada(Contratacion *array,int limite,int indice,int idContratacion,int idPantalla,char *nombreArchivo, int cantDias, char *cuitCliente) // NO anidar mas de 3 ifs, concatenar en todo caso
{
	int retorno = -1;
	Contratacion bufferContratacion;

	if(array !=NULL && limite>0 && indice >= 0)
	{

			strncpy(bufferContratacion.nombreArchivo,nombreArchivo,NOMBRE_LEN);
			strncpy(bufferContratacion.cuitCliente,cuitCliente,NOMBRE_LEN);
			bufferContratacion.cantDias =cantDias;
			bufferContratacion.idContratacion =idContratacion;
			bufferContratacion.idPantalla =idPantalla;
			bufferContratacion.isEmpty =0;
			array[indice]= bufferContratacion;
			retorno=0;
	}
	return retorno;
}
int cont_inicializarArray(Contratacion *array, int limite)
{
	int retorno=-1;

	if(array != NULL && limite >0)
	{
		retorno=0;
		for(int i=0;i<limite;i++)
		{
			array[i].isEmpty=1;  //si es verdadero, esta vacio
		}
	}
	return retorno;
}
static int generarIdNuevo(void)
{
	static int id=0; //es global pero solo la funcion puede usarla, es como si estuviese arriba. s einicializa en 0 solo una vez
	id= id+1;
	return id;
}
int cont_altaArray(Contratacion *array,int limite,Pantalla *arrayRelacionado, int limiteRelacionado)
{
	int retorno = -1;
	Contratacion bufferContratacion;
	int auxIdRelacionado;
	int indexContratacion;
	int indexRelacionado;
	indexContratacion= cont_getNextEmptyIndex(array, CANT_CONTRATACION);
	pant_imprimirArray(arrayRelacionado, CANTIDAD_PANTALLAS);
	if(utn_getNumero("\nelija id de pantalla", "\nError", &auxIdRelacionado, 2, 0,9999)==0)
	{
		indexRelacionado=pant_buscarId(arrayRelacionado, CANTIDAD_PANTALLAS, auxIdRelacionado);
		if(array !=NULL && limite>0 && indexContratacion >= 0 && indexRelacionado >=0)
		{
			if( utn_getNombre("nombre del archivo?", "\nError",bufferContratacion.nombreArchivo, 2,NOMBRE_LEN)==0 &&
				utn_getNumero("cantidad dias", "\nError", &bufferContratacion.cantDias, 2, 0, 9999)==0 &&
				utn_getString("cuit cliente?", "\nError", bufferContratacion.cuitCliente, 2,NOMBRE_LEN)==0)
			{

				bufferContratacion.idContratacion =generarIdNuevo();
				bufferContratacion.isEmpty =0;
				array[indexContratacion]= bufferContratacion;
				retorno=0;
			}
		}
	}
	return retorno;
}

int cont_bajaArray(Contratacion *array,int limite)
{
	int retorno = -1;
	int auxiliarId;
	int indice;

	if(utn_getNumero("indique id de contratacion a dar de baja", "id invalido", &auxiliarId, 2, 0, CANT_CONTRATACION)==0)
	{
		indice = cont_buscarId(array, CANT_CONTRATACION, auxiliarId);
		if(array !=NULL && limite>0 && indice >= 0 && array[indice].isEmpty==0)
		{
				array[indice].isEmpty= 1;
				retorno=0;
		}
	}
	return retorno;
}
int cont_buscarId(Contratacion *array, int limite,int valorBuscado)
{
	int retorno=-1;
	int i;

	if(array != NULL && limite >0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			if(array[i].idContratacion== valorBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int cont_getNextEmptyIndex(Contratacion *array, int limite)
{
	int retorno=-1;
	int i;

	if(array != NULL && limite >0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty==1)
			{
				retorno= i;
				break;
			}
		}
	}
	return retorno;
}
int cont_modificarArrayDias(Contratacion *array,int limite)
{
	int retorno = -1;
	int dias;
	int indice;
	int auxiliarId;

	if(utn_getNumero("\nindique id de contratacion a modificar", "id invalido", &auxiliarId, 2, 0, CANT_CONTRATACION)==0)
	{
		indice = cont_buscarId(array, CANT_CONTRATACION, auxiliarId);
		if(array !=NULL && limite>0 && indice >= 0 && array[indice].isEmpty==0)
		{
			if(utn_getNumero("cantidad dias", "\nError", &dias, 2, 0, 9999)==0)
			{
				array[indice].cantDias= dias;
				retorno=0;
			}
		}
	}
	return retorno;
}

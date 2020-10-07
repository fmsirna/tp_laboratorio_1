/*
 * informe.c
 *
 *  Created on: 3 oct. 2020
 *      Author: Fede
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contratacion.h"
#include "pantalla.h"
#include "informe.h"
#include "utn.h"

int info_imprimirPantallasPorCuit(Contratacion *arrayUno, int limiteUno,Pantalla *arrayDos,int limiteDos,char *auxCuit)
{
	int retorno = -1;
	int auxIndicePantalla;
	char strTipo[20];
	if(arrayUno !=NULL && limiteUno>0 && arrayDos !=NULL && limiteDos>0 && auxCuit !=NULL)
	{
		for(int i=0;i<limiteUno;i++)  //recordar que va con ;
		{
			if(strncmp(arrayUno[i].cuitCliente,auxCuit,limiteUno)==0)
			{
				retorno=0;
				auxIndicePantalla= pant_buscarId(arrayDos, CANTIDAD_PANTALLAS, arrayUno[i].idPantalla);
				if(arrayDos[auxIndicePantalla].tipoPantalla==1)
						{
							sprintf(strTipo,"led");
						}
						else
						{
							sprintf(strTipo,"lcd");
						}
				cont_imprimir(&arrayUno[i]);
				pant_imprimir(&arrayDos[auxIndicePantalla]);
			}
		}
	}
	return retorno;
}
int info_imprimirFacturacion(Contratacion *arrayUno, int limiteUno,Pantalla *arrayDos,int limiteDos,char *auxCuit)
{
	int retorno = -1;
	int auxIndicePantalla;
	float facturacion;
	if(arrayUno !=NULL && limiteUno>0 && arrayDos !=NULL && limiteDos>0 && auxCuit !=NULL)
	{
		for(int i=0;i<limiteUno;i++)  //recordar que va con ;
		{
			if(strncmp(arrayUno[i].cuitCliente,auxCuit,limiteUno)==0)
			{
				auxIndicePantalla= pant_buscarId(arrayDos, CANTIDAD_PANTALLAS, arrayUno[i].idPantalla);
				facturacion= (arrayDos[auxIndicePantalla].precioDia * arrayUno[i].cantDias);
				cont_imprimir(&arrayUno[i]);
				printf(" factura: %.2f",facturacion);
			}
		}
	}
	return retorno;
}

int info_imprimirDosArrays(Contratacion *arrayUno, int limiteUno,Pantalla *arrayDos,int limiteDos)
{
	int retorno = -1;
	int idUno;
	int auxIndiceDos;
	if(arrayUno !=NULL && limiteUno>0 && arrayDos !=NULL && limiteDos>0)
	{
		for(int i=0;i<limiteUno;i++)
		{
				retorno=0;
				idUno=arrayUno[i].idPantalla;
				auxIndiceDos= pant_buscarId(arrayDos, CANTIDAD_PANTALLAS,idUno); // pone el indiceArray2 de donde esta el id del primer array
				cont_imprimir(&arrayUno[i]);
				pant_imprimir(&arrayDos[auxIndiceDos]);
		}
	}
	return retorno;
}

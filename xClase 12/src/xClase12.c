/*
 ============================================================================
 Name        : clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "contratacion.h"
#include "pantalla.h"
#include "informe.h"
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);
	Pantalla arrayPantalla[CANTIDAD_PANTALLAS];
	Contratacion arrayContratacion[CANT_CONTRATACION];
	int opcion;
	int opcionDos;
	char auxCuit[CUIT_LEN];

	if(pant_inicializarArray(arrayPantalla, CANTIDAD_PANTALLAS)==0 && cont_inicializarArray(arrayContratacion, CANT_CONTRATACION)==0 )
	{
		printf("INIT OK\n");
		pant_altaForzada(arrayPantalla, CANTIDAD_PANTALLAS,0,0,"frav","chascomus", 32, 2);
		pant_altaForzada(arrayPantalla, CANTIDAD_PANTALLAS,1,1,"style","india", 32, 2);
		cont_altaForzada(arrayContratacion, CANT_CONTRATACION, 0, 0,1, "video23", 17, "5674");
		cont_altaForzada(arrayContratacion, CANT_CONTRATACION, 1, 1,1, "video456", 17, "6784");
		cont_altaForzada(arrayContratacion, CANT_CONTRATACION, 2, 2,1, "video456", 17, "6784");
		do
		{
			if(utn_getNumero("\nMenu de opciones"
							"\n1-dar de alta pantalla "
							"\n2-modificar pantalla "
							"\n3-eliminar pantalla "
							"\n4-agregar contratacion"
							"\n5-modificar contratacion"
							"\n6-cancelar contratacion"
							"\n7-consulta facturacion"
							"\n8-listar contrataciones"
							"\n9-listar pantallas"
							"\n10-informar "
							"\n11-salir\n","Error,opcion invalida\n",&opcion, 2, 1, 11)== 0)
			{
				switch(opcion)
				{
				case 1:
					if(pant_altaArray(arrayPantalla, CANTIDAD_PANTALLAS)==0)
						{
							printf("carga realizada con exito");
						}
					else
					{
						printf("no hay mas lugar");
					}
					break;
				case 2:
						if(	pant_modificarArray(arrayPantalla, CANTIDAD_PANTALLAS)==0)
						{
							printf("modificacion realizada con exito");
						}
					break;
				case 3:
						if(pant_bajaArray(arrayPantalla, CANTIDAD_PANTALLAS)==0)
						{
							printf("\nBaja realizada con exito");
						}
					break;
				case 4:

					if(cont_altaArray(arrayContratacion,CANT_CONTRATACION,arrayPantalla,CANTIDAD_PANTALLAS)==0)
					{
						printf("carga realizada con exito");
					}
					break;
				case 5:
					if(utn_getString("\ningrese cuit para modificar", "/nerror",auxCuit, 2,CUIT_LEN)==0 &&
					   info_imprimirPantallasPorCuit(arrayContratacion,CANT_CONTRATACION,arrayPantalla,CANTIDAD_PANTALLAS,auxCuit)==0)
					{
					cont_modificarArrayDias(arrayContratacion, CANT_CONTRATACION);
					}
					else
					{
						printf("cuit incorrecto");
					}
					break;
				case 6:
					if(utn_getString("\ningrese cuit para modificar", "/nerror",auxCuit, 2,CUIT_LEN)==0 &&
					   info_imprimirPantallasPorCuit(arrayContratacion,CANT_CONTRATACION,arrayPantalla,CANTIDAD_PANTALLAS,auxCuit)==0)
					{
					cont_bajaArray(arrayContratacion, CANT_CONTRATACION);
					}
					else
					{
						printf("cuit incorrecto");
					}
					break;
				case 7:
					if(utn_getString("\ningrese cuit para ver faturaciones", "/nerror",auxCuit, 2,CUIT_LEN)==0)
					{
						 info_imprimirFacturacion(arrayContratacion,CANT_CONTRATACION,arrayPantalla,CANTIDAD_PANTALLAS,auxCuit);
					}
					else
					{
						printf("cuit incorrecto");
					}
					break;
				case 8:
					cont_imprimirArray(arrayContratacion, CANT_CONTRATACION);
					break;
				case 9:
					pant_imprimirArray(arrayPantalla, CANTIDAD_PANTALLAS);
					break;
				case 10:
					do
					{
						if(utn_getNumero("\n1-lista de clientes con cant contratacion e importe a pagar\n2-cliente con importe mas alto a facturar\n3/salir",
											"\nError",&opcionDos, 2, 1, 3)==0)
						{
							switch(opcionDos)
							{
							case 1:

								break;
							case 2:

								break;
							}
						}

					}while(opcionDos !=3);

				 	break;
				}
			}

		 }while(opcion !=11);
	}



	return EXIT_SUCCESS;
}

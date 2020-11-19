/*
 * formulas.c
 *
 *  Created on: 8 sept. 2020
 *      Author: Fede
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int getInt(int *pResultado);
static int myGets(char *cadena, int longitud);
static int esNumerica(char* cadena, int limite);

float Suma(float numeroA, float numeroB, float *resultado)
{
	*resultado = numeroA + numeroB;
	return 0;
}

float Resta(float numeroA, float numeroB, float *resultado)
{
	*resultado = numeroA - numeroB;
	return 0;
}

float Division(float numeroA, float numeroB, float *resultado)
{
	int retorno;
		if(numeroB != 0.00)
		{
		   *resultado = (float) numeroA / numeroB;
		    retorno = 0;
		}
		else
		{
		    retorno = -1;
		}
		return retorno;
}

float Multiplicacion(float numeroA, float numeroB, float *resultado)
{
	*resultado = numeroA * numeroB;
	return 0;
}


float factorial(float numero, float *resultado)
{
	int fact;
	fact = 1;

	if(numero !=0)
	{
	  for (int i = 1; i <= numero; i++)
	  {
		  fact = fact*i;
	  }
	}

	*resultado = fact;
	return 0;
}


float getFloat(char *mensaje, char *mensajeError, float *pResultado,int reintentos,float min, float max)
{
	int retorno = -1;
	float numero;
	int resultadoScan;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			resultadoScan = scanf("%f", &numero);
			if(resultadoScan != 0 && numero >= min && numero <= max)
			{
				*pResultado = numero;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;

}
int getNumero(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int minimo,int maximo)
{
	int retorno = -1;
	int bufferInt;
	if(	mensaje != NULL && 	mensajeError != NULL &&	pResultado != NULL && reintentos >= 0 && maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			if(getInt(&bufferInt)==0 && bufferInt >=minimo && bufferInt <=maximo)
			{
				retorno =0;
				*pResultado = bufferInt;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >= 0);
	}
	return retorno;
}
static int getInt(int *pResultado)
{
	int retorno=-1;
	char bufferString[5000];
	if(pResultado !=NULL && myGets(bufferString,sizeof(bufferString))==0 && esNumerica(bufferString,5000))
	{
		retorno =0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}
static int myGets(char *cadena, int longitud)
{
	fflush(stdin);
	fgets (cadena, longitud, stdin);
	cadena[strlen (cadena) - 1] = '\0';
	return 0;
}



static int esNumerica(char* cadena, int limite)
{
	int retorno = 1; // VERDADERO
	int i;
	for(i=0;i<limite && cadena[i] != '\0';i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;		}
		//CONTINUE
	}
	//BREAK
	return retorno;
}

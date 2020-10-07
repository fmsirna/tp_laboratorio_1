/*
 * formulas.c
 *
 *  Created on: 8 sept. 2020
 *      Author: Fede
 */

#include <stdio.h>
#include <stdlib.h>

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
		if(numeroB != 0)
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

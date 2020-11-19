/*
 ============================================================================
 Name        : tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void) {

	setbuf(stdout,NULL);

	float numero1;
	float numero2;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	float resultadoFactorial;
	float resultadoFactorialDos;
	int opcion;
	do
	{
		if(getNumero("\nMenu de opciones"
					 "\n1-ingresar primer operando"
					 "\n2-ingresar segundo operando"
					 "\n3-calcular todos los resultados"
					 "\n4-informar resultados"
					  "\n5-salir","Error,opcion invalida\n",&opcion, 2, 1, 5)==0)
		{
			switch(opcion)
			{
			case 1:
				getFloat("\ningrese primer numero", "ingresaste mal", &numero1, 3, 0, 9999999);
				break;
			case 2:
				getFloat("\ningrese segundo numero", "ingresaste mal", &numero2, 3, 0, 9999999);
				break;
			case 3:
				 Suma(numero1, numero2,&resultadoSuma);
				 Resta(numero1, numero2,&resultadoResta);
				 Division(numero1, numero2,&resultadoDivision);
				 Multiplicacion(numero1, numero2,&resultadoMultiplicacion);
				 factorial(numero1,&resultadoFactorial);
				 factorial(numero2,&resultadoFactorialDos);

				break;
			case 4:
				printf("\na) El resultado de %.2f + %.2f es: %.2f",numero1,numero2,resultadoSuma);
				printf("\nb) El resultado de %.2f - %.2f es: %.2f",numero1,numero2,resultadoResta);
				printf("\nc) El resultado de %.2f * %.2f es: %.2f",numero1,numero2,resultadoMultiplicacion);
				if(numero2==0)
				{
				 printf("\nd)El resultado de %.2f / %.2f no es posible dado que no se puede dividir por 0",numero1,numero2);
				}
				else{
				printf("\nd) El resultado de %.2f / %.2f es: %.2f",numero1,numero2,resultadoDivision);
				}
				printf("\ne) El factorial de %.2f es: %.2f y El factorial de %.2f es: %.2f”",numero1,resultadoFactorial,numero2,resultadoFactorialDos);
			}
		}
	}while(opcion!=5);


	return EXIT_SUCCESS;
}



#include <stdio.h>
#include <stdlib.h>
#include "header.h"



int main(void){

	setbuf(stdout,NULL);

	float numero1;
	float numero2;
	char funcion;
	float resultado;
	float resultadoDos;
	int flag = 0;

	printf("ingrese la funcion + - * / !):");
	fflush(stdin);
	scanf("%c",&funcion);

	while(funcion != '+' && funcion != '-' && funcion != '/' && funcion != '*' && funcion != '!')
	{
		printf("ingrese una funcion valida + - * / !):");
		fflush(stdin);
		scanf("%c",&funcion);
	}


	getFloat("\ningrese primer numero", "ingresaste mal", &numero1, 3, 0, 9999999);
	getFloat("\ningrese segundo numero", "ingresaste mal", &numero2, 3, 0, 9999999);

	switch(funcion)
	{
	 case'+':

		 Suma(numero1, numero2,&resultado);
		 break;

	 case'-':

			 Resta(numero1, numero2,&resultado);
			 break;

	 case'/':

			 if(Division(numero1, numero2,&resultado) == -1)
			 {
				 printf("\n no se puede dividir por 0");
				flag = 1;
			 }
			 break;

	 case'*':

			 Multiplicacion(numero1, numero2,&resultado);
			 break;
	 default:
			 factorial(numero1,&resultado);
			 factorial(numero2,&resultadoDos);
			 printf("\n el factorial del primer numero es %.2f, y el segundo %.2f",resultado, resultadoDos);
			 flag = 1;
			 break;
	}



	if(flag == 0)
	{
	printf("El resultado es : %.2f",resultado);
	}
}



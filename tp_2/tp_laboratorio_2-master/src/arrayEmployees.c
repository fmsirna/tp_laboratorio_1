/*
 * logica.c
 *
 *  Created on: 17 sept. 2020
 *      Author: Fede
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayEmployees.h"
#include "utn.h"

static int getNewId(void);

/** \brief find next index with no employees on it.
*
* \param list Employee*
* \param len int
* \return Return  (-1) if [Invalid length or NULL
pointer received or employee not found] or 0 if its ok
*
*/
int getNextEmptyIndex(Employee *list, int len)
{
	int retorno=-1;
	int i;

	if(list != NULL && len >0)
	{
		retorno=0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==1)
			{
				retorno= i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
	int retorno=-1;

		if(list != NULL && len >0)
		{
			retorno=0;
			for(int i=0;i<len;i++)
			{
				list[i].isEmpty=1;
			}
		}
		return retorno;
}
/** \brief load variables of the employee
*
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int loadEmployee(char *name, char *lastName,float *salary,int *sector,int *id)
{
	int retorno= -1;
	char bufferName[NAME_LEN];
	char bufferLastName[NAME_LEN];
	float bufferSalary;
	int bufferSector;

	if(name != NULL && lastName != NULL && salary != NULL && sector !=NULL)
	{
		if(utn_getNombre("name?", "\nError",bufferName, 2,NAME_LEN)==0 &&
		   utn_getNombre("last name?", "\nError", bufferLastName, 2,NAME_LEN)==0 &&
		   utn_getFloat("salary?", "\nError", &bufferSalary, 2, 0, 999999)==0 &&
		   utn_getNumero("sector?", "\nError", &bufferSector, 2, 1, 5)==0)
		{
			strncpy(name,bufferName,NAME_LEN);
			strncpy(lastName,bufferLastName,NAME_LEN);
			*salary=bufferSalary;
			*sector=bufferSector;
			*id=getNewId();
			retorno=0;
		}
	}
	return retorno;
}
static int getNewId(void)
{
	static int id=0;
	id= id+1;
	return id;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
	int retorno = -1;

	int index;
	index= getNextEmptyIndex(list, QTY_EMPLOYEES);
	if(list !=NULL && len>0 && index >= 0) //otras validaciones realizadas en loadEmployee
	{

			list[index].isEmpty=0;
			list[index].id=id;
			strncpy(list[index].name,name,NAME_LEN);
			strncpy(list[index].lastName,lastName,NAME_LEN);
			list[index].salary=salary;
			list[index].sector=sector;
			retorno=0;
	}
	else
	{
		printf("no more space");
	}
	return retorno;
}
/** \brief print the content of one employee
 *
 * \param list Employee*
  * \return int
 *
 */
int printAnEmployee(Employee* list)
{
	int retorno = -1;
	if(list != NULL && list->isEmpty ==0)
	{
		retorno=0;
		printf("\n%5d %13s %15s %15.2f %15d",list->id,list->name,list->lastName,list->salary,list->sector);
	}
	return retorno;
}
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length)
{
	int retorno = -1;
		if(list !=NULL && length>0)
		{
			retorno=0;
			for(int i=0;i<length;i++)
			{
				if(i==0)
				{
					printf("\n%5s %13s %15s %15s %15s","id","name","last name","salary","sector");
				}
				printAnEmployee(&list[i]);
			}
		}
		return retorno;
}
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno=-1;
		int i;

		if(list != NULL && len >0)
		{
			retorno=0;
			for(i=0;i<len;i++)
			{
				if(list[i].id== id)
				{
					retorno = i;
					break;
				}
			}
		}
		return retorno;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int index;
	index=findEmployeeById(list, len, id);

		if(list !=NULL && len>0 && id >= 0 && list[index].isEmpty==0)
		{
			list[index].isEmpty= 1;
				retorno=0;
		}
		return retorno;
}
/** \brief edit a Employee by Id
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int editEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	Employee bufferEmployee;
	char bufferName[NAME_LEN];
	char bufferLastName[NAME_LEN];
	float bufferSalary;
	int bufferSector;
	int index;
	index=findEmployeeById(list, len, id);
	if(list !=NULL && len>0 && index >= 0 && list[index].isEmpty==0)
	{
		if( utn_getNombre("name?", "\nError",bufferName, 2,NAME_LEN)==0 &&
			utn_getNombre("last name?", "\nError", bufferLastName, 2,NAME_LEN)==0 &&
			utn_getFloat("salary?", "\nError", &bufferSalary, 2, 0, 999999)==0 &&
			utn_getNumero("sector?", "\nError", &bufferSector, 2, 1, 5)==0)
		{
			bufferEmployee.id=getNewId();
			bufferEmployee.isEmpty =0;
			list[index]= bufferEmployee;
			retorno=0;
		}
	}
	return retorno;
}
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
	int retorno=-1;
		int flagSwap;
		int i;
		int auxiliarCmp;
		Employee buffer;
		if(list != NULL && len >0)
		{
			do
			{
				flagSwap=0;
				for(i=0;i<len-1;i++) // -1 para que no haga swap cuando llegue al ultimo
				{
					if(list[i].isEmpty || list[i+1].isEmpty) // isEmpty dejarlo solo significa decirle = verdadero =1 fuerza otra iteracion
					{
						continue;
					}
					auxiliarCmp=strncmp(list[i].lastName,list[i+1].lastName,NAME_LEN);

					if( ((order == 1 && auxiliarCmp>0) || (order == 1 && auxiliarCmp==0 && list[i].sector > list[i+1].sector))
						||
						(order == 2 && auxiliarCmp <0)|| (order == 2 && auxiliarCmp==0 && list[i].sector < list[i+1].sector))

					{
						flagSwap =1;
						buffer=list[i];
						list[i] = list[i+1];
						list[i+1]=buffer;
					}
				}
				len--;

			}while(flagSwap); // corta cuando flagSwap sea falso, = 0.
		}

		return retorno;

}
/** \brief sum salary of employees
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error  - (0) if Ok
*
*/
float sumSalary(Employee* list, int len)
{
	float retorno = -1;

		if(list != NULL && len >0)
		{
			retorno=0;
			for(int i=0;i<len;i++)
			{
				if(list[i].isEmpty==0)
				{
					retorno= retorno + list[i].salary;
				}
			}
		}
		return retorno;
}
/** \brief sum employees
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error  - (0) if Ok
*
*/
float sumEmployees(Employee* list, int len)
{
	float retorno = -1;

		if(list != NULL && len >0)
		{
			retorno=0;
			for(int i=0;i<len;i++)
			{
				if(list[i].isEmpty==0)
				{
					retorno++;
				}
			}
		}
		return retorno;
}

/** \brief sum employees above average
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error  - (0) if Ok
*
*/
float exceedingEmployees(Employee* list, int len, float averageSalary)
{
	float retorno = -1;

		if(list != NULL && len >0)
		{
			retorno=0;
			for(int i=0;i<len;i++)
			{
				if(list[i].isEmpty==0 && list[i].salary > averageSalary)
				{
					retorno++;
				}
			}
		}
		return retorno;
}
/** \brief print the content of employees exceeding array
 *
 * \param list Employee*
 * \param length int
 * \param float average salary
 * \return int
 *
 */
int printEmployeesExceeding(Employee* list, int length, float averageSalary)
{
	int retorno = -1;
		if(list !=NULL && length>0)
		{
			retorno=0;
			for(int i=0;i<length;i++)
			{
				if(i==0)
				{
					printf("\n%5s %13s %15s %15s %15s","id","name","last name","salary","sector");
				}
				if(list[i].isEmpty==0 && list[i].salary >= averageSalary)
				{
					printAnEmployee(&list[i]);
				}
			}
		}
		return retorno;
}

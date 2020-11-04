#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* this = NULL;

    char idStr[20];
    char nombreStr[51];
    char horasTrabajadasStr[51];
    char sueldoStr[20];

    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            this = employee_newParametrosTxt(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            ll_add(pArrayListEmployee, this);
        }
        retorno = 0;

    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* this = NULL;
    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        while(!feof(pFile))
        {
            this = employee_new();
            if(this != NULL)
            {
                fread(this, sizeof(Employee), 1, pFile); // 1 de solamente va a leer una vez al empleado
                if(feof(pFile))
                {
                    retorno = -1;             // para que no agregue si ya termino
                    break;
                }
                ll_add(pArrayListEmployee, this);
            }
        }
        retorno = 0;
    }
    return retorno;
}

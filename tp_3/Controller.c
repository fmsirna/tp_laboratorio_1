#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE* pFile;

    pFile = fopen(path,"r");

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty == 1)
        {
            retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
            fclose(pFile);
        }
        else
        {
            retorno = 2;
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE* pFile = NULL;

    pFile = fopen(path,"rb");

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty == 1)
        {
            retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        }
        else
        {
            retorno = 2;
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int retorno = -1;
    int isEmpty = 0;
    char nombre[51];
    char salario[51];
    char horasTrabajadas[51];
    char idStr[51];
    Employee* nuevo_Empleado;

    if(pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty != 1)
        {
                printf("CARGA DE EMPLEADOS:\n");

                utn_getNombre("Ingrese el nombre del empleado: ", "\nError", nombre, 2, 51);
                utn_getString("Ingrese las horas trabajadas del empleado: ", "\nError", horasTrabajadas, 2, 51);
                utn_getString("Ingrese salario del empleado: ", "\nError", salario, 2, 51);

                sprintf(idStr, "%d", *id);
                nuevo_Empleado = employee_newParametrosTxt(idStr, nombre, horasTrabajadas, salario);
                printf("Estos son los datos ingresados:\n");
				printf("%4s %18s %20s %20s\n", "ID:", "Nombre:", "Horas trabajadas:", "Salario:");
				printOneEmployee(nuevo_Empleado);
                if(nuevo_Empleado != NULL)
                {
                	retorno=0;
					ll_add(pArrayListEmployee, nuevo_Empleado);
					*id = *id+1;
                }
        }
        else{
        	printf("cargue la planilla primero");
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int isEmpty = 0;
    int id;
    int opcion;
    char auxNombre [51];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* empleadoAModificar;

    if(pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty!= 1)
        {
            printf("Estos son los empleados: \n");
            controller_ListEmployee(pArrayListEmployee);
            utn_getNumero("Ingrese el id del empleado a modificar: \n", "\nError", &id, 2, 0, 99999);

            empleadoAModificar = getEmployeeById(pArrayListEmployee, id);  // te trae el empleado del linkedlist con ese id. con el ll get

            if(empleadoAModificar != NULL)
            {
                printf("\n");
                printf("Este es el empleado a modificar: \n");
                printf("%4s %18s %20s %20s\n", "ID:", "Nombre:", "Horas trabajadas:", "Salario:");
                printOneEmployee(empleadoAModificar);
                do
                {
                	if(utn_getNumero("Ingrese una opcion:\n1. Cambiar nombre.\n2. Cambiar cantidad de horas trabajadas.\n3. Cambiar salario.\n4. Salir al menu principal.\n",
                					"\nError", &opcion, 2, 1, 4)==0)
                	{
						switch(opcion)
						{
						case 1:
							utn_getString("Ingrese un nuevo nombre: ", "\nError", auxNombre, 0, 51);
							employee_setNombre(empleadoAModificar, auxNombre);
							break;
						case 2:
							utn_getNumero("Ingrese una nueva cantidad de horas trabajadas: ", "\nError", &auxHorasTrabajadas, 2, 0, 99999);
							employee_setHorasTrabajadas(empleadoAModificar, auxHorasTrabajadas);

							break;
						case 3:
							utn_getNumero("Ingrese sueldo: ", "\nError", &auxSueldo, 2, 0, 99999);
							employee_setSueldo(empleadoAModificar, auxSueldo);
							break;
						}
                	}
                }
                while(opcion != 4);
            }

            printf("\n");
            printf(" cambios realizados:\n");
            printf("%4s %18s %20s %20s\n", "ID:", "Nombre:", "Horas trabajadas:", "Salario:");
            printOneEmployee(empleadoAModificar);
            retorno=0;
        }
        else
        {
        	printf("cargue la planilla primero");
        }
    }
    return retorno;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int id;
    int isEmpty = 0;
    int confirmacion;
    Employee* auxEmpleado;
    int indiceEmpleado;

    if(pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty != 1)
        {
        	retorno=0;
            printf("Estos son los empleados:\n");
            controller_ListEmployee(pArrayListEmployee);
            utn_getNumero("Ingrese el id del empleado a dar de baja: \n", "\nError", &id, 2, 0, 99999);

            auxEmpleado = getEmployeeById(pArrayListEmployee, id);

            if(auxEmpleado != NULL)
            {
                printf("%4s %18s %20s %20s\n", "ID:", "Nombre:", "Horas trabajadas:", "Salario:");
                printOneEmployee(auxEmpleado);
                utn_getNumero("\nEsta seguro que quiere eliminar al empleado? Ingrese 1 para SI o 2 para NO:", "\nError", &confirmacion, 2, 1, 2);
                if(confirmacion == 1)
                {
                    indiceEmpleado = ll_indexOf(pArrayListEmployee, auxEmpleado);
                    ll_remove(pArrayListEmployee, indiceEmpleado);
                }
                else if(confirmacion == 2)
                {
                    retorno = 1;
                }
            }
        }
        else
        {
            printf("debe cargar empelados antes");
        }
    }
    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int len;
    int isEmpty = 0;

    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty != 1)
        {
            len = ll_len(pArrayListEmployee);
            Employee* auxEmpleado;
            printf("%4s%20s%20s%22s\n","Id:","Nombre:","Horas Trabajadas:","Sueldo:");
            for(i=0; i<len; i++)
            {
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
                printOneEmployee(auxEmpleado);
            }
        }
        else
        {
            printf("\ntodavia no se han cargado empleados\n");
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int opcion;
    int orden;
    int isEmpty = 0;

    if(pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        retorno = 2;
        if(isEmpty != 1)
        {
            do
            {
            	utn_getNumero("\nordenar a los empleados:\n1.Por ID.\n2.Por nombre.\n3.Por horas trabajadas.\n4.Por salario.\n5-salir", "\nError", &opcion, 2, 1, 5);
                switch(opcion)
                {
                case 1:
                	utn_getNumero("\nIngrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente:", "\nError", &orden, 2, 0, 1);
                    printf("ordenando, puedo tomar unos segundos...");
                	ll_sort(pArrayListEmployee, compareById, orden);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
                case 2:
                    utn_getNumero("\nIngrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente:", "\nError", &orden, 2, 0, 1);
                    printf("ordenando, puedo tomar unos segundos...");
                    ll_sort(pArrayListEmployee, compareByName, orden);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
                case 3:
                	utn_getNumero("\nIngrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente:", "\nError", &orden, 2, 0, 1);
                	printf("ordenando, puedo tomar unos segundos...");
                	 ll_sort(pArrayListEmployee, compareByHoursWorked, orden);
                	controller_ListEmployee(pArrayListEmployee);
                    break;
                case 4:
                	utn_getNumero("\nIngrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente:", "\nError", &orden, 2, 0, 1);
                	printf("ordenando, puedo tomar unos segundos...");
                	ll_sort(pArrayListEmployee, compareBySalary, orden);
                	controller_ListEmployee(pArrayListEmployee);
                    break;
                }
            }
            while(opcion != 5);
        }
        else{
        	printf("cargue empleados");
        }
    }
    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    Employee* auxEmployee = NULL;

    int idStr;
    char nombreStr[51];
    int horasTrabajadasStr;
    int sueldoStr;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pFile = fopen(path, "w");//abro el archivo en modo escritura
        len = ll_len(pArrayListEmployee);

        if(pFile != NULL)
        {
            fprintf(pFile, "Id,Nombre,Horas trabajadas,Salario\n");
            for(i=0; i<len; i++)
            {
                auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
                employee_getId(auxEmployee, &idStr);
                employee_getNombre(auxEmployee, nombreStr);
                employee_getHorasTrabajadas(auxEmployee, &horasTrabajadasStr);
                employee_getSueldo(auxEmployee, &sueldoStr);

                fprintf(pFile, "%d,%s,%d,%d\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            }
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    Employee* auxEmployee = NULL;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pFile = fopen(path, "wb");//abro el archivo en modo escritura
        len = ll_len(pArrayListEmployee);

        if(pFile != NULL)
        {
            for(i=0; i<len; i++)
            {
                auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
                fwrite(auxEmployee, sizeof(Employee), 1, pFile);
            }
        }
        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}

int getBiggerId(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        int len;
        int flag = 0;
        int i;
        Employee* auxEmployee;

        len = ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if(flag == 0 || retorno < auxEmployee->id)
            {
                retorno = auxEmployee->id;
                flag = -1;
            }
        }
    }
    return retorno;
}

int getNextId(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        retorno = getBiggerId(pArrayListEmployee);
        retorno++;
    }
    return retorno;
}

void* getEmployeeById(LinkedList* pArrayListEmployee, int id)
{
    int len;
    int i;
    Employee* auxEmployee = NULL;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {

            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);


            if(id == auxEmployee->id)
            {
                break;
            }
        }
    }
    return auxEmployee;
}


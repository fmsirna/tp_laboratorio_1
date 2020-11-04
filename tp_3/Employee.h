#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utn.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;


Employee* employee_new();
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
int printOneEmployee(Employee* employee);
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
void employee_delete(Employee* employee);

int compareById(void* pElementOne, void* pElementTwo);
int compareBySalary(void* pElementOne, void* pElementTwo);
int compareByHoursWorked(void* pElementOne, void* pElementTwo);
int compareByName(void* pElementOne, void* pElementTwo);


#endif // employee_H_INCLUDED

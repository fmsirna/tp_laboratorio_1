/*
 * logica.h
 *
 *  Created on: 17 sept. 2020
 *      Author: Fede
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define NAME_LEN 50
#define QTY_EMPLOYEES 1000


struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int getNextEmptyIndex(Employee *list, int len);
int initEmployees(Employee* list, int len);
int loadEmployee(char *name, char *lastName,float *salary,int *sector,int *id);
int printAnEmployee(Employee* list);
int printEmployees(Employee* list, int length);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int editEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
float sumSalary(Employee* list, int len);
float sumEmployees(Employee* list, int len);
float exceedingEmployees(Employee* list, int len, float averageSalary);
int printEmployeesExceeding(Employee* list, int length, float averageSalary);


#endif /* ARRAYEMPLOYEES_H_ */

/*
 ============================================================================
 Name        : tp.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayEmployees.h"
#include "utn.h"
int main(void) {
	setbuf(stdout,NULL);
	int option;
	int secondOption;
	Employee arrayEmployees[QTY_EMPLOYEES];
	char name[NAME_LEN];
	char lastName[NAME_LEN];
	float salary;
	int sector;
	int id;
	int order;
	float totalSalary;
	int totalEmployees;
	float averageSalary;
	int ExceedEmployees;


	if(initEmployees(arrayEmployees, QTY_EMPLOYEES)==0)
	{
		printf("INIT OK\n");
		do
		{
			totalEmployees = sumEmployees(arrayEmployees, QTY_EMPLOYEES);
			if(utn_getNumero("\noption menu"
							"\n1-add employee"
							"\n2-edit employee "
							"\n3-remove employee "
							"\n4-inform"
							"\n5-Exit\n","Error, invalid option\n",&option, 2, 1, 5)== 0)
			{
				switch(option)
				{
				case 1:
					if(loadEmployee(name,lastName,&salary,&sector,&id)==0)
					{
						if(addEmployee(arrayEmployees,QTY_EMPLOYEES, id, name, lastName, salary, sector)==0)
						{
							printf("employee added successfully");
						}
					}
					break;
				case 2:
					if(totalEmployees>0)
					{
						printEmployees(arrayEmployees, QTY_EMPLOYEES);
						if(utn_getNumero("\nselect id of employee to edit", "id invalid", &id, 2, 0,QTY_EMPLOYEES )==0)
						{
							if(editEmployee(arrayEmployees, QTY_EMPLOYEES,id)==0)
							{
								printf("\nemployee edited successfully");
							}
						}
					}
					else
					{
						printf("you must load an employee");
					}
					break;
				case 3:
					if(totalEmployees>0)
					{
					printEmployees(arrayEmployees, QTY_EMPLOYEES);
					if(utn_getNumero("\nselect id of employee to remove", "id invalid", &id, 2, 0,QTY_EMPLOYEES )==0)
					{
						if(removeEmployee(arrayEmployees, QTY_EMPLOYEES, id)==0)
						{
							printf("\nemployee removed successfully");
						}
					}
					}
					else
					{
						printf("you must load an employee");
					}
					break;
				case 4:
					if(totalEmployees>0)
					{
						if(utn_getNumero("\noselect:\n 1: print employees arranged by last name and sector "
								"\n 2: inform total and average salary, and employees exceding average salary","Error, invalid option\n",&secondOption, 2, 1, 2)== 0)
						{
							switch(secondOption)
							{
							case 1:
								if(utn_getNumero("\nselect 1 to arange upwards or 2 downwards","Error, invalid option\n",&order, 2, 1, 2)== 0)
								{
									switch(order)
									{
									case 1:
										sortEmployees(arrayEmployees, QTY_EMPLOYEES, order);
										break;
									case 2:
										sortEmployees(arrayEmployees, QTY_EMPLOYEES, order);
										break;
									}
								}
							printEmployees(arrayEmployees, QTY_EMPLOYEES);
							break;
							case 2:
								totalSalary= sumSalary(arrayEmployees,QTY_EMPLOYEES);
								totalEmployees = sumEmployees(arrayEmployees, QTY_EMPLOYEES);
								averageSalary= totalSalary/totalEmployees;
								ExceedEmployees= exceedingEmployees(arrayEmployees, QTY_EMPLOYEES, averageSalary);
								if(totalSalary >=0 && totalEmployees > 0 && averageSalary > 0)
								{
									printf("total salary is %.2f"
											"\naverage salary is %.2f"
											"\nemployees exceeding average salary: %d:",totalSalary,averageSalary,ExceedEmployees);
									printEmployeesExceeding(arrayEmployees, QTY_EMPLOYEES, averageSalary);
								}
								break;
						    }
						}
					}
					else
					{
						printf("you must load an employee");
					}
					break;
				case 5:
					printf("you have quit the program");
					break;
				}
			}

		}while(option !=5);
	}


	return EXIT_SUCCESS;
}

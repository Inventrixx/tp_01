#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#include "math.h"

#define QTY_EMPLOYEES 1000

int main() {

  int option;
  int countID = 0;
  //int flag = 0;
	Employee arrayEmployee[QTY_EMPLOYEES];
	initEmployees(arrayEmployee,QTY_EMPLOYEES);
  do {

		 utn_getUnsignedInt("\n\n1) Alta del Empleado \n2) Modificar Empleado \n3) Baja del Empleado \n4) Mostrar Empleados \n5) Salir \n",
                 "\nError",1,sizeof(int),1,11,1,&option);
	        switch(option) {
	            case 1: //Alta
                printf("Alta de empleado\n");
                addEmployee(arrayEmployee,QTY_EMPLOYEES,&countID);
                //flag = 1;
	              break;
	            case 2: //Modificar
                //if(flag == 1) {
	              if(validateData(arrayEmployee,QTY_EMPLOYEES) == 0) {
                  printf("Modificar el registro de un empleado\n");
                  modifyEmployee(arrayEmployee,QTY_EMPLOYEES);
                } else {
                  printf("Debe cargar una persona empleada antes");
                }
                break;
	            case 3: //Baja
                //if(flag == 1) {
	              if(validateData(arrayEmployee,QTY_EMPLOYEES) == 0) {
                  printf ("Dar de baja un empleado.\n");
                  removeEmployee(arrayEmployee,QTY_EMPLOYEES);
                } else {
                  printf("Debe cargar una persona empleada antes");
                }
                break;
	            case 4:
                //if(flag == 1) {
	              if(validateData(arrayEmployee,QTY_EMPLOYEES) == 0) {
                  printf ("Lista de Empleados.\n");
                  sortEmployees(arrayEmployee,QTY_EMPLOYEES);
                  printEmployees(arrayEmployee,QTY_EMPLOYEES);
                  printSalaryInformation(arrayEmployee,QTY_EMPLOYEES);
                } else {
                  printf("Debe cargar una persona empleada antes");
                }
                break;
	            case 5:
	              printf("\nSaliendo...");
	              break;
	            default:
	                 printf("\nOpcion no valida");
	        }
	    }
	    while(option != 5);
	    return 0;
}

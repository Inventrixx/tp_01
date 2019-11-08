#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee) {
	int ret = 0;
	FILE* pFile;
	pFile = fopen(path, "r");
	ret = parser_EmployeeFromText(pFile, pArrayListEmployee);
	fclose(pFile);
	return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee) {
	int ret = 0;
	FILE* pFile;
	pFile = fopen(path, "rb");
	ret = parser_EmployeeFromText(pFile, pArrayListEmployee);
	fclose(pFile);
	return ret;
}

/** \brief Obtiene el mayor id del LinkedList y lo carga en la estructura empleado.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_lastIdEmployee(LinkedList* pArrayListEmployee) {
	int ret = -1;
	Employee* auxEmployee;
	int  bufferId;
	int auxId = -1;
	int i, len;

	if(pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		for(i = 0; i < len; i++) {
			auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee,&bufferId);
			if(bufferId > auxId) {
				auxId = bufferId;
			}
		}
		employe_idInit(auxId);
		ret = 0;
	}
	return ret;
}

/** \brief Obtiene la posicione del id a buscar
 *
 * \param pArrayListEmployee LinkedList*
 * \param int id
 * \param int* index
 * \return int
 *
 */


int controller_searchEmployeeById(LinkedList* pArrayListEmployee, int id, int* index) {
	int ret = -1;
	Employee* auxEmployee;
	int auxId;
	int i, len;

	if(pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
			for(i = 0; i < len; i++) {
				auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(auxEmployee,&auxId);
				if(auxId == id) {
					*index = i;
					ret = 0;
				}
			}
		}
	return ret;
	}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee) {
  int ret = -1;
  char auxNombre[128];
  int auxHorasTrabajadas;
  int auxSueldo;
  Employee* auxEmployee;
  auxEmployee = employee_new();
  if(pArrayListEmployee != NULL && auxEmployee != NULL) {

    if(utn_getName("Ingrese el nombre: ", "Error. Ingrese un nombre valido: ", 1, 127, 2, auxNombre) == 0 && utn_getUnsignedInt("Ingrese la cantidad de horas trabajadas: ", "Error. Ingrese un valor valido: ", 1, 10, 0, 200, 2, &auxHorasTrabajadas) == 0 && utn_getUnsignedInt("Ingrese el sueldo: ", "Error. Ingrese un valor valido: ", 1, 10, 1, 50000, 2, &auxSueldo) == 0) {
      employee_setId(auxEmployee, employee_idGenerator());
      employee_setNombre(auxEmployee, auxNombre);
      employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
      employee_setSueldo(auxEmployee, auxSueldo);

      ll_add(pArrayListEmployee, auxEmployee);
    }
  }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee) {
	int ret = -1;

	if(pArrayListEmployee != NULL) {
		if(ll_len(pArrayListEmployee)) {
			char auxNombre[128];
			int auxHorasTrabajadas;
			int auxSueldo;
			Employee* auxEmployee;
			int option;
			int auxIndex;
			int auxId;

			utn_getUnsignedInt("Ingrese el Id del empleado a modificar: ", "Error. Ingrese un Id valido: ", 1, 5, 1, 10000, 2, &auxId);
			if(controller_searchEmployeeById(pArrayListEmployee, auxId, &auxIndex) == 0) {
				do {
					controller_PrintEmployee(pArrayListEmployee, auxIndex);
					auxEmployee = (Employee*)ll_get(pArrayListEmployee, auxIndex);

					utn_getUnsignedInt("\nModificar: 1(Nombre) 2(Horas Trabajadas) 3(Sueldo) 4(salir)", "Error. Ingrese una opción valida: ", 1, sizeof(int), 1, 4, 2, &option);

					switch(option) {
						case 1:
							if(utn_getName("Ingrese el nombre: ", "Error. Ingrese un nombre valido: ", 1, 127, 2, auxNombre) == 0) {
								employee_setNombre(auxEmployee, auxNombre);
							}
							break;
						case 2:
							if(utn_getUnsignedInt("Ingrese la cantidad de horas trabajadas: ", "Error. Ingrese un valor valido: ", 1, 10, 0, 200, 2, &auxHorasTrabajadas) == 0) {
								employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
							}
							break;
						case 3:
							if(utn_getUnsignedInt("Ingrese el sueldo: ", "Error. Ingrese un valor valido: ", 1, 10, 1, 50000, 2, &auxSueldo) == 0) {
								employee_setSueldo(auxEmployee, auxSueldo);
							}
							break;
						case 4:
							break;
						}
				} while(option != 4);
				ret = 0;
			} else {
				printf("Id invalido");
				}
		} else {
			printf("No existen registros cargados");
			}
	}
	return ret;
}

/** \brief Baja de empleado
*
* \param path char*
* \param pArrayListEmployee LinkedList*
* \return int
*
*/

int controller_removeEmployee(LinkedList* pArrayListEmployee) {
	int ret = -1;
	if(pArrayListEmployee != NULL) {
			if(ll_len(pArrayListEmployee) > 0) {
				Employee* auxEmployee;
				int auxIndex;
				int auxId;

				utn_getUnsignedInt("\nId a cancelar: ","\nError, ingrese un Id valido",1,5,1,10000,1,&auxId);

				if(controller_searchEmployeeById(pArrayListEmployee, auxId, &auxIndex) == 0) {
					auxEmployee = (Employee*)ll_get(pArrayListEmployee, auxIndex);
					employee_delete(auxEmployee);
					ll_remove(pArrayListEmployee, auxIndex);
					ret = 0;
				} else {
					printf("Id invalido");
				}
			} else {
				printf("No existen registros cargados");
			}
	}
	return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee) {
	int ret = -1;
	int i, len;
	if(pArrayListEmployee != NULL) {
		if(ll_len(pArrayListEmployee) > 0) {
			len = ll_len(pArrayListEmployee);
			for(i = 0; i < len; i++) {
				controller_PrintEmployee(pArrayListEmployee, i);
			}
			ret = 0;
		} else {
			printf("No existen registros cargados");
		}
		return ret;
	}
	return ret;
}

int controller_PrintEmployee(LinkedList* pArrayListEmployee, int index) {
	int ret = -1;
	Employee* auxEmployee;
	int auxId;
	char auxNombre[4096];
	int auxHorasTrabajadas;
	int auxSueldo;

	if(pArrayListEmployee != NULL) {
		auxEmployee = ll_get(pArrayListEmployee, index);
		employee_getId(auxEmployee, &auxId);
		employee_getNombre(auxEmployee, auxNombre);
		employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas);
		employee_getSueldo(auxEmployee, &auxSueldo);
		printf("ID: %d\n1.Nombre: %s\n2.Horas trabajadas: %d\n3.Sueldo: %d\n", auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
		ret = 0;
	}
	return ret;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee) {
    int ret = -1;
    if(pArrayListEmployee != NULL) {
    	if(ll_len(pArrayListEmployee) > 0) {
    		ll_sort(pArrayListEmployee,employee_compareNombre,-1);
    	}
    		ret = 0;
    		printf("Operacion completada");
    	} else {
    		printf("No hay registros cargados");
    	}
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee) {
    int ret = 0;
	Employee* auxEmployee;
    FILE* pf;
    int auxId;
    char auxNombre[4096];
    int auxHorasTrabajadas;
    int auxSueldo;
    int i, len;
    pf = fopen(path, "w");
    if(pArrayListEmployee != NULL && pf != NULL) {
    	fprintf(pf,"id,nombre,horasTrabajadas,sueldo\n");
    	len = ll_len(pArrayListEmployee);
    	for(i = 0; i < len; i++) {
    		auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
    		employee_getId(auxEmployee, &auxId);
    		employee_getNombre(auxEmployee, auxNombre);
    		employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas);
    		employee_getSueldo(auxEmployee, &auxSueldo);
    		fprintf(pf,"%d,%s,%d,%d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
    		ret++;
    	}
    	fclose(pf);
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee) {
	int ret = 0;
	Employee* auxEmployee;
	FILE* pf;
	int i, len;
	pf = fopen(path, "wb");

	if(pArrayListEmployee != NULL && pf != NULL) {
		len = ll_len(pArrayListEmployee);
		for(i = 0; i < len; i++) {
			auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			fwrite(auxEmployee, sizeof(Employee), 1, pf);
			ret++;
		}
		fclose(pf);
	}
	return ret;
}

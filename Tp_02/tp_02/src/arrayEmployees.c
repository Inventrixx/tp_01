#include "ArrayEmployees.h"
#include "utn.h"
#include "math.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/** \brief Indica que todas las posiciones en el array estan vacias, para eso se pone un FLAG (isEmpty) en TRUE en todas las posiciones del array
* \param Employee* list es el array de la estructura Employee
* \param int len es la longitud del array
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int initEmployees(Employee* list, int len)
{
  int retorno = -1;
  int i;
  if(list != NULL && len > 0) {
    for(i = 0; i < len; i++) {
      list[i].isEmpty = 0;
    }
    retorno = 0;
  }
 return retorno;
}

/** \brief Busca la primer posici�n vacia que encuentra y la devuelve
* \param Employee* list es el array de la estructura Employee
* \param int len es la longitud del array
* \param *index acceso al lugar de memoria en el que se encuentra index
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int searchEmpty(Employee* list, int len, int* index) {
    int retorno = -1;
    int i;
    if(list != NULL && len >= 0 && index != NULL) {
        for(i = 0; i < len; i++) {
            if(list[i].isEmpty == 0) {
                retorno = 0;
                *index = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Agrega en una lista existente de empleados los valores recibidos como parametros en la primera posicion vacia
* \param Employee* list es el array de la estructura Employee
* \param int len es la longitud del array
* \param int *countID accede a la posici�n de memoria de countID que esta en 0
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
 */
 int addEmployee(Employee* list, int len, int *countID)
{
  int retorno = -1;
  int index;
  if(list != NULL && len > 0 && countID != NULL) {
    if(searchEmpty(list, len, &index) == - 1) {
      printf("\nNo hay lugares vacios");
    } else {
            (*countID)++;
            list[index].id = *countID;
            list[index].isEmpty = 1;
            utn_getName("Ingrese el nombre de la persona empleada: ","\nError",1,TEXT_SIZE,2,list[index].name);
            utn_getTexto("Ingrese el apellido de la persona empleada: ","\nError",1,TEXT_SIZE,2,list[index].lastName);
            utn_getFloat("Ingrese el salario de la persona empleada: ","\nError",1,10,1,58000,2,&list[index].salary);
            utn_getUnsignedInt("Ingrese el sector de la persona empleada: ","\nError",1,sizeof(int),1,10,2,&list[index].sector);
            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Sector: %d\n Salario: %f\n ",
                    index, list[index].id,list[index].name,list[index].lastName,list[index].sector,list[index].salary);
            retorno=0;
        }
  }
 return retorno;
}

/** \brief Busca un empleado por id y devuelve la posicion del array en el que se encuentra find an Employee by Id en returns the index index in array.
* \param Employee* list es el array de la estructura Employee
* \param int len es la longitud del array
* \param int searchValue es el valor que el usuario ingresa para buscar
* \param int *index acceso al lugar de memoria en el que se encuentra index
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int findEmployeeById(Employee* list, int len,int searchValue, int* index)
{
  int retorno = - 1;
  int i;
  if(list != NULL && len > 0) {
    for(i = 0; i < len; i++) {
      if(list[i].isEmpty == 0) {
        continue;
      } else if(list[i].id == searchValue) {
          retorno = 0;
          *index = i;
          break;
        }
    }
  }
 return retorno;
}

/** \brief Busca que exista un empleado, pregunta para modificar alguno de sus campos y lo devuelve modificado
* \param int len es la longitud del array
* \param Employee* list es el array de la estructura Employee
* \param int len es la longitud del array
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int modifyEmployee(Employee* list, int len) {
  int retorno = -1;
  int index;
  int id;
  char option;
  if(list != NULL && len > 0) {
    utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,len,2,&id);
        if(findEmployeeById(list,len,id,&index) == - 1) {
      printf("\nNo existe el ID, por favor escriba un ID valido");
    } else {
          do {
            printf("\n Nombre: %s\n Apellido: %s \n ID: %d\n Sector: %d\n Salario: %f",
                       list[index].name,list[index].lastName,list[index].id,list[index].sector,list[index].salary);
            utn_getChar("\nModificar: A(nombre) B(apellido) C(sector) D(salario) S(salir)","\nError",'A','Z',1,&option);
            switch(option) {
              case 'A':
                utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,list[index].name);
                break;
              case 'B':
                utn_getTexto("Apellido: \n","\nError",1,TEXT_SIZE,1,list[index].lastName);
                break;
              case 'C':
                utn_getUnsignedInt("\nSector: ","\nError",1,sizeof(int),1,10,2,&list[index].sector);
                break;
              case 'D':
                utn_getFloat("\nSalario: ","\nError",1,10,1,58000,1,&list[index].salary);
                break;
              default:
                printf("\nOpcion no valida");
            }
          } while(option != 'S');
          retorno = 0;
    }
  }
  return retorno;
}

/** \brief Busca un empleado por ID y lo da de baja del array de empleados
* \param Employee* list es el array de la estructura Employee
* \param int len es la longitud del array
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int removeEmployee(Employee* list, int len)
{
  int retorno = -1;
  int index;
  int id;
  if(list != NULL && len > 0 ) {
    utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,len,2,&id);
    if(findEmployeeById(list,len,id,&index) == - 1) {
      printf("\nNo existe el ID, por favor escriba un ID valido");
    } else {
            list[index].isEmpty = 0;
            list[index].id = 0;
            strcpy(list[index].name,"");
            strcpy(list[index].lastName,"");
            list[index].sector = 0;
            list[index].salary = 0;
            retorno = 0;
        }
  }
 return retorno;
}

/** \brief Ordena los elementos del array primeramente por apellido, como segundo criterio por sector
* \param Employee* list es el array de la estructura Employee
* \param int len es la longitud del array
* \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
*/
int sortEmployees(Employee* list, int len) {
  int retorno = -1;
  int i, j;
  Employee bufferList;

  if(list != NULL && len >= 0) {
    for(i = 0; i < len; i++) {
      for(j = i+1; j < len; j++) {
        if(strcmp(list[i].lastName, list[j].lastName) > 0) {
          bufferList = list[i];
          list[i] = list[j];
          list[j] = bufferList;
          } else if(strcmp(list[i].lastName, list[j].lastName) == 0) {
            if(list[i].sector > list[j].sector) {
              bufferList = list[i];
              list[i] = list[j];
              list[j] = bufferList;
              }
            }
          }
        }
        retorno = 0;
    }
  return retorno;
}

/** \brief Imprime el contenido que se encuentra en el array de empleados
 * \param list Employee*
 * \param length int
 * \return Esta funci�n devuelve -1 si hay alg�n error [Invalid length or NULL pointer], 0 si est� OK.
 */
int printEmployees(Employee* list, int len)
{
  int retorno = -1;
  int i;
  if(list!= NULL && len > 0) {
    for(i = 0; i < len; i++) {
      if(list[i].isEmpty == 0) {
        continue;
      } else {

        printf("\n Nombre: %s\n Apellido: %s \n ID: %d\n Sector: %d\n Salario: %f.\n",
                       list[i].name,list[i].lastName,list[i].id,list[i].sector,list[i].salary);
      }
    }
    retorno = 0;
  }
 return retorno;
}

/** \brief Valida que el array este vacio o con datos ya cargados
 * \param list Employee*
 * \param length int
 * \return Esta funci�n devuelve -1 si el array ya contiene data, 0 si est� vacio.
 */
int validateData(Employee* list, int len) {
    int retorno;
    int i;
    if(list != NULL && len >= 0) {
        for(i = 0; i < len; i++) {
            if(list[i].isEmpty == 1) {
                retorno = 0;
                break;
            } else {
            	retorno = -1;

            }
        }
    }
    return retorno;
}




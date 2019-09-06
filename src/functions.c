#include <stdio.h>
#include "functions.h"

/**
 *\brief Recibe dos numeros flotantes y devuelve la suma de estos
 *\param Numeros flotantes que se sumaran
 *\return Suma de dos n�meros
*/
float sum(float a, float b) {
	float total;
	total = a + b;
	return total;
}

/**
 *\brief Recibe dos numeros flotantes y devuelve la resta de estos
 *\param Numeros flotantes que se restaran
 *\return Resta de dos n�meros
*/
float subtraction(float a, float b) {
	float total;
	total = a - b;
	return total;
}

/**
 *\brief Recibe dos numeros flotantes y devuelve la multiplicaci�n de estos
 *\param Numeros flotantes que se multiplicaran
 *\return Multiplicaci�n de dos n�meros
*/
float multiplication(float a, float b) {
	float total;
	total = a * b;
	return total;
}

/**
 *\brief Recibe dos numeros flotantes y devuelve la divisi�n de estos
 *\param Numeros flotantes para proceder a realizar una divisi�n de los mismos
 *\return Divisi�n del 1er n�mero por el segundo
*/
float division(float a, float b) {
	float total;
	if(b <= 0) {
		printf("No es posible dividir por cero");
	}
	total = a / b;
	return total;
}

/**
 *\brief Recibe un entero y devuelve el factorial de este
 *\param N�mero entero para calcular su factorial
 *\return factorial del n�mero recibido por parametro
*/
int factorialA(int a) {
	int i, factorial = 1;
	    for (i = 1; i <= a; i++){
	        factorial = factorial * i;
	    }
	    return factorial;
}

/**
 *\brief Recibe un entero y devuelve el factorial de este
 *\param N�mero entero para calcular su factorial
 *\return factorial del n�mero recibido por parametro
*/
int factorialB(int b) {
	int i, factorial = 1;
	    for (i = 1; i <= b; i++){
	        factorial = factorial * i;
	    }
	    return factorial;
}

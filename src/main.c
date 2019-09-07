#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
	setbuf(stdout, NULL);
    int options;
    float A = 0.00;
    float B = 0.00;
    float resultSum;
    float resultSubtraction;
    float resultMultiplication;
    float resultDivision;
    int resultFactorialA;
    int resultFactorialB;
    float num1,num2;

    printf("Bienvenide a la calculadora, se le solicitar� dos n�meros:\n");
    printf("\n1- Ingresar primer operando:\n");
    scanf("%f", &A);
    printf("\n2- Ingresar segundo operando:\n");

    scanf("%f", &B);

while(1) {
        printf("1- 1er operando (%f)\n", A);
        printf("2- 2do operando (%f)\n", B);
        printf("3- Calcular los resultados\n");
        printf("4- Imprimir los resultados\n");
        printf("5- Salir\n");
        scanf("%d", &options);

  switch(options) {
	  case 1:
	   printf("1er Numero: ");
	   scanf("%f", &num1);
	   A = num1;
	   break;
	  case 2:
	   printf("2do N�mero: ");
	   scanf("%f", &num2);
	   B = num2;
	   break;
	  case 3:
	   resultSum = sum(A, B);
	   resultSubtraction = subtraction(A, B);
	   resultMultiplication = multiplication(A, B);
	   resultDivision = division(A, B);
	   resultFactorialA = factorialA(A);
	   resultFactorialB = factorialB(B);
	   printf("Operaciones realizadas con exito.\n");
	   break;
	  case 4:
	   printf("El resultado de la suma es: %.2f\n", resultSum);
	   printf("El resultado de la resta es: %.2f\n", resultSubtraction);
	   printf("El resultado de la multiplicaci�n es: %.2f\n", resultMultiplication);
	   printf("El resultado de la division es: %.2f\n", resultDivision);
	   printf("El factorial del primer n�mero es: %d y el factorial del segundo es: %d\n\n\n",
		 resultFactorialA, resultFactorialB);
	   break;
	  case 5:
	   printf("\nSaliendo del programa...\n");
	   return 0;
	  default:
	   printf("Ingrese una opci�n valida\n");
	   break;
         }
  printf("\e[1;1H\e[2J");
  }

}

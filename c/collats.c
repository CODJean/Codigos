#include <stdio.h>
#include <math.h>

void main() {
    int A;
    printf("Ingrese un numero para realizar la conjetura de collats: ");
    scanf("%d",&A);
    while (A != 1){
        if (A % 2 == 0)
        {
            A = A/2;

        }else{
            A = (3*A)+1;
        }
        printf("%d,", A);     
    }
    if (A = 1){
printf("El numero ingresado es 1 por lo cual la conjetura de collats es 1.");
    }
}
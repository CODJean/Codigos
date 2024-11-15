#include <stdio.h>
float notas1 (int A, int B, int C){
    return (((A+B+C)/3)*0.55);
}
float notas2 (int D){
    return (D * 0.3);
}
float notas3 (int E){
    return (E * 0.15);
}

void main(){
    float A, B, C, D, E, Result;
    printf("Ingrese la primera nota: ");
    scanf("%f",&A);
    printf("Ingrese la segunda nota: ");
    scanf("%f",&B);
    printf("Ingrese la tercera  nota: ");
    scanf("%f",&C);
    printf("Ingrese la nota del examen final: ");
    scanf("%f",&D);
    printf("Ingrese la nota del trabja final: ");
    scanf("%f",&E);
    Result = (notas1(A,B,C)+notas2(D)+notas3(E))/3;
    printf("El promedio total es de: %f",Result);
}

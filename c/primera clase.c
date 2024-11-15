#include <stdio.h>
void main(){
    int A, B, Result;
    Result = suma(A,B);
    imprimir(Result);
}
int suma (int A, int B){
    return A+B;
}
void imprimir(int r){
    printf("La suma es\n\"%i\"", r);
}
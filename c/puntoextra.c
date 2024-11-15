#include <stdio.h>

void main(){
    int filas; 
    scanf("%d", &filas);
    printf(imprimir);

}
int imprimir(){
      int l,m,n;
      for(i = 1 ; i <= filas; i++){
        for(j = 1; j <= i; j++){
            pintf("*");
        }
      }  
      for(k = 1; k <= filas-i; k++){
        printf(" ");
      }
      printf(" ");
      for(k = 1; k <= filas-i; k++){
        printf(" ");
      }
      for(j = 1; j <= i; j++){
        printf("*");
      }
      printf("\n");
      return(0);
}

#include <stdio.h>

  void main(){
    int f; 
    scanf("%d", &f);
     int i,j,k;
      for(i = 1 ; i <=f; i++){
        for(j = 1; j <= i; j++){
            pintf("*");
        }
      }  
      for(k = 1; k <= f-i; k++){
        printf(" ");
      }
      printf(" ");
      for(k = 1; k <= f-i; k++){
        printf(" ");
      }
      for(j = 1; j <= i; j++){
        printf("*");
      }
      printf("\n");

}
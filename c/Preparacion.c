#include <stdio.h>
//funciones que no retornan valores
void letra(){    
    //sirve para ver la una letra en un determinado lugar es una lista un string es una lista de caracteres
    char perro[] = "perro";
    puts("Ingrese un nombre: \t");//puts es solo para imprimir textos
    gets(perro);//sirve para obtener datos la diferencia es que no termina cuando hay espacios
    printf("%c\n",perro[1]);
    }
void numeros(){
    //Listas de numeros
    int numeros[] = {1, 2, 3, 4 ,5 ,6 ,7 };// para imprimir el numero deseado o el caracter deseado se empieza de 0 al maximo numero de la lista
    printf("%d\n", numeros[3]);
}
void listasdestrings(){
    //Listas de strings
    char *gato[/*aqui se puede determinar la catidad que va a tener la lista*/2]={"hola", "perro"};
    printf("%s\n",gato[1]);
}
void constantes(){
    //para determminar constantes
    const float pi = 3.141516;
    printf("%f", pi);
}
void operadorescomparativos(){
    //operadores comparativos
    printf("\n%d\n",  4 == 4 ); //compara si 4 es igual al numero 4 
    printf("%d\n",  4 == '4' ); //compara si 4 es igual al texto 4 
    printf("%d\n",  4 !=5 ); //compara si 4 es diferente al numero 5
    printf("%d\n",  4 < 5 ); //compara si 4 es menor al numero 5 
    printf("%d\n",  4 > 5 ); //compara si 4 es mayor al numero 5
    printf("%d\n",  4 <= 5 ); //compara si 4 es menor igual al numero 5
    printf("%d\n",  4 >= 5 ); //compara si 4 es mayor igual al numero 5 
}
void operadoreslogicos(){
    //operadores logicos
    // operador y
    printf("\n%d\n",  1 && 1 ); //1
    printf("%d\n",  1 && 0 ); //0 
    printf("%d\n",  0 && 1 ); //0
    printf("%d\n",  0 && 0 ); //0
    //operador O
    printf("%d\n",  1 || 1 ); //1
    printf("%d\n",  1 || 0 ); //1
    printf("%d\n",  0 || 1 ); //1 
    printf("%d\n",  0 || 0 ); //0
}
void condicionesles() {
    //condiciones boleanos
    int autorizado = 1;
    if(autorizado){
        puts("autorizado");
    }else{
        puts("no autorizado");
    }
    //switch solo acepta int y char
}
void suma(int A, int B /*Argumentos*/){
    printf("%d\n",A+B);
}
//funcion que retorna valores
int multiplicar(int A, int B){
    return A * B;
}
//estructuras
typedef struct hola
{
    char* nombre;
    int año;
}/*Aqui va el nombre para llamar a la estructura en el codigo*/ HOLA;
void descripcion(HOLA penta){
    printf("%s fue creado en %d\n",penta.nombre, penta.año);
}
//main
int main(){
    //letra(); a si se llaman funciones al programa que no retornan valores
    suma(2 , 5);
    //llamar funcion que retorna valores
    int result = multiplicar(2 , 5);
    printf("%i\n", result);
    //usar las estructuras
    HOLA html;
    html.nombre = "HTML";
    html.año = 1993;

    HOLA css;
    css.nombre = "CSS";
    css.año = 1996;

    descripcion(html); //imprime la estructura con el combre html
    descripcion(css); //imprime la estructura con el combre css
    // la Funcion sizeof permite determinar el tamaño de los tipos de datos o listas listas es arreglo
    // y para saber el tamaño de un arreglo de puede hacer de la siguiente manera 
    /*intA[]{1,2,3,4,5,}  
    int p = sizeof(A)/sizeof(A[0])
    */
   // funcion goto sirve para salter una parte del codigo como se muestra
   /*
   printf("1"); se muestra
   goto jump;
   printf("2"); no se muestra
   jump:
   printf("3"); se muestra
   printf("4"); se muestra
   printf("5"); se muestra
   */




    return (0);
}
    #include <stdio.h>
    //getchar(); o system.clear; limpiar buffer
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
      /*        OPERADORES ARITMETICOS
        SUMA                    +
        RESTA                   -
        MULTIPLICACION          *
        DIVISION                /
        RESIDULO(MODULO)        %
                PRECEDENCIA DE OPERADORES
        ()                      IZQUIERDA A DERECHA
        * / %                   IZQUIERDA A DERECHA
        + -                     IZQUIERDA A DERECHA
        =                       DERECHA A IZQUIERDA
    
        */
   
   
   
        return (0);
    }
    /*                                                                                TUTORIA
    EJEMPLO 1 AORCADO CON FOR
    #include <stdio.h>

    int main() {
    char letra1 = 'P', letra2 = 'R', letra3 = 'O', letra4 = 'G', letra5 = 'R';
    char letra6 = 'A', letra7 = 'M', letra8 = 'A', letra9 = 'C', letra10 = 'I';
    char letra11 = 'O', letra12 = 'N';

    char estado1 = '', estado2 = '', estado3 = '', estado4 = '', estado5 = '_';
    char estado6 = '', estado7 = '', estado8 = '', estado9 = '', estado10 = '_';
    char estado11 = '', estado12 = '';

    int aciertos = 0; 
    char intento;    
    int encontrada;    

    printf("Bienvenido al juego del ahorcado!\n");
    printf("La palabra tiene 12 letras. Tienes un máximo de 5 fallos.\n");

   
    for (int fallos = 0; fallos < 5 && aciertos < 12; fallos++) {

        printf("\nPalabra: %c %c %c %c %c %c %c %c %c %c %c %c\n",
               estado1, estado2, estado3, estado4, estado5,
               estado6, estado7, estado8, estado9, estado10,
               estado11, estado12);

    
        printf("Introduce una letra: ");
        scanf(" %c", &intento);

  
        if (intento >= 'a' && intento <= 'z') {
            intento -= 32;
        }


        encontrada = 0;
        if (intento == letra1 && estado1 == '_') { estado1 = letra1; aciertos++; encontrada = 1; }
        if (intento == letra2 && estado2 == '_') { estado2 = letra2; aciertos++; encontrada = 1; }
        if (intento == letra3 && estado3 == '_') { estado3 = letra3; aciertos++; encontrada = 1; }
        if (intento == letra4 && estado4 == '_') { estado4 = letra4; aciertos++; encontrada = 1; }
        if (intento == letra5 && estado5 == '_') { estado5 = letra5; aciertos++; encontrada = 1; }
        if (intento == letra6 && estado6 == '_') { estado6 = letra6; aciertos++; encontrada = 1; }
        if (intento == letra7 && estado7 == '_') { estado7 = letra7; aciertos++; encontrada = 1; }
        if (intento == letra8 && estado8 == '_') { estado8 = letra8; aciertos++; encontrada = 1; }
        if (intento == letra9 && estado9 == '_') { estado9 = letra9; aciertos++; encontrada = 1; }
        if (intento == letra10 && estado10 == '_') { estado10 = letra10; aciertos++; encontrada = 1; }
        if (intento == letra11 && estado11 == '_') { estado11 = letra11; aciertos++; encontrada = 1; }
        if (intento == letra12 && estado12 == '_') { estado12 = letra12; aciertos++; encontrada = 1; }

    
        if (!encontrada) {
            printf("\nLetra incorrecta. Te quedan %d intentos.\n", 4 - fallos);
        } else {
            printf("\n¡Letra correcta!");
            fallos--;
        }
    }

    if (aciertos == 12) {
        printf("\n\n¡Felicidades! Has adivinado la palabra: PROGRAMACION\n");
    } else {
        printf("\n\nHas perdido... La palabra era: PROGRAMACION\n");
    }

    return 0;
    
    
    }
    /*EJEMPLO 2 AORCADO CON WHILE
    #include <stdio.h>
    #include <stdbool.h>
    
    //juego del ahorcado usando while loop
    
    
    int main() {
        // PROGRAMACION
        char letra1 = 'P', letra2 = 'R', letra3 = 'O', letra4 = 'G', letra5 = 'R';
        char letra6 = 'A', letra7 = 'M', letra8 = 'A', letra9 = 'C', letra10 = 'I';
        char letra11 = 'O', letra12 = 'N';
    
        char estado1 = '', estado2 = '', estado3 = '', estado4 = '', estado5 = '_';
        char estado6 = '', estado7 = '', estado8 = '', estado9 = '', estado10 = '_';
        char estado11 = '', estado12 = '';
    
        int fallos = 0;    
        int aciertos = 0; 
        char intento;
    
        printf("Bienvenido al juego del ahorcado!\n");
        printf("La palabra tiene 12 letras. Tienes un máximo de 5 fallos.\n");
    
        while (fallos < 5 && aciertos < 12) {
            // mostrar
            printf("\nPalabra: %c %c %c %c %c %c %c %c %c %c %c %c\n",
                   estado1, estado2, estado3, estado4, estado5,
                   estado6, estado7, estado8, estado9, estado10,
                   estado11, estado12);
    
            printf("Introduce una letra: ");
            scanf(" %c", &intento);
    
    
            if (intento >= 'a' && intento <= 'z') {
                intento -= 32;
            }
    
            bool encontrada = 0;
    
    
    
            if (intento == letra1 && estado1 == '_') { estado1 = letra1; aciertos++; encontrada = 1; }
            if (intento == letra2 && estado2 == '_') { estado2 = letra2; aciertos++; encontrada = 1; }
            if (intento == letra3 && estado3 == '_') { estado3 = letra3; aciertos++; encontrada = 1; }
            if (intento == letra4 && estado4 == '_') { estado4 = letra4; aciertos++; encontrada = 1; }
            if (intento == letra5 && estado5 == '_') { estado5 = letra5; aciertos++; encontrada = 1; }
            if (intento == letra6 && estado6 == '_') { estado6 = letra6; aciertos++; encontrada = 1; }
            if (intento == letra7 && estado7 == '_') { estado7 = letra7; aciertos++; encontrada = 1; }
            if (intento == letra8 && estado8 == '_') { estado8 = letra8; aciertos++; encontrada = 1; }
            if (intento == letra9 && estado9 == '_') { estado9 = letra9; aciertos++; encontrada = 1; }
            if (intento == letra10 && estado10 == '_') { estado10 = letra10; aciertos++; encontrada = 1; }
            if (intento == letra11 && estado11 == '_') { estado11 = letra11; aciertos++; encontrada = 1; }
            if (intento == letra12 && estado12 == '_') { estado12 = letra12; aciertos++; encontrada = 1; }
    
    
            if (!encontrada) {
                fallos++;
                printf("\nLetra incorrecta. Te quedan %d intentos.\n", 5 - fallos);
            } else {
                printf("\n¡Letra correcta!");
            }
        }
    
        if (aciertos == 12) {
            printf("\n\n¡Felicidades! Has adivinado la palabra: PROGRAMACION\n");
        } else {
            printf("\n\nHas perdido... La palabra era: PROGRAMACION\n");
        }
    
        return 0;
    }
    EJERCICIO 3
    #include<stdio.h>
    
    int main() {
    	int d;
    	int r;
    	int x1;
    	int x2;
    	int y1;
    	int y2;
    	printf("ingresar primera coordenada en x\n");
    	scanf("%i",&x1);
    	printf("ingresar primera coordenada en y\n");
    	scanf("%i",&y1);
    	printf("ingresar segunda coordenada en x\n");
    	scanf("%i",&x2);
    	printf("ingresar segunda coordenada en y\n");
    	scanf("%i",&y2);
    	r = ((x2-x1)^2+(y2-y1)^2);
    	d = (r)^1/2;
    	printf("la distancia entre los dos puntos es %i\n",d);
    	return 0;
    }
    
    ALEATORIEDAD
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    
    int main() {
        // Inicializar la semilla usando el tiempo actual
        srand(time(NULL));
    
        printf("Números aleatorios:\n");
        for (int i = 0; i < 5; i++) {
            // Generar un número aleatorio entre 1 y 100
            int numero = rand() % 10 + 1 ;
            printf("%d ", numero);
        }
    
        printf("\n");
        return 0;
    }
    Has sido contratado en la famosa empresa de desarrollo Enchufesoft, para realizar un 
    minijuego de la famosa franquicia “Monstruos de Bolsillo”. El objetivo es implementar 
    un juego interactivo en C donde puedas enfrentarte a la computadora en un 
    emocionante duelo “Monstruos de Bolsillo”. Pero esta vez, los combates no serán con 
    “Monstruos de Bolsillo” reales, sino con su tipo elemental.
    1. Crea un algoritmo donde el jugador y la computadora seleccionen un tipo 
    “Monstruos de Bolsillo” para combatir.
    2. El jugador elegirá entre 5 tipos elementales de “Monstruos de Bolsillo” (Fuego, 
    Agua, Planta, Eléctrico, Roca). El usuario ingresa un NUMERO de 1 al 5 para 
    elegir el tipo de “Monstruos de Bolsillo”. Cada tipo tendrá interacciones 
    específicas que determinen quién gana, que son las siguientes.
    Fuego (1):
    • Vence a: Planta, Roca
    • Pierde contra: Agua, Eléctrico
    Agua (2):
    • Vence a: Fuego, Roca
    • Pierde contra: Planta, Eléctrico
    Planta (3):
    • Vence a: Agua, Roca
    • Pierde contra: Fuego, Eléctrico
    Eléctrico (4):
    • Vence a: Agua, Planta
    • Pierde contra: Fuego, Roca
    Roca (5):
    • Vence a: Fuego, Eléctrico
    • Pierde contra: Agua, Planta
    3. La computadora elegirá un tipo al azar en cada ronda.
    4. Se jugarán 3 rondas y el ganador será quien gane al menos 2 de ellas (mejor de 
    tres). En caso de empate en una ronda, esta no contará para el marcador final.
    5. Al final del juego, muestra quién es el campeón: el jugador o la computadora.
    
    CODIGO
    #include <stdio.h>
    
    #include <stdlib.h>
    
    #include <time.h>
    
    // Función para determinar el resultado de una ronda
    
    int determinarGanador(int jugador, int computadora) {
    
        // Reglas del juego
    
        if (jugador == computadora) {
    
            return 0; // Empate
    
        } else if (
    
            (jugador == 1 && (computadora == 3 || computadora == 4)) || // Fuego vence a Planta, Eléctrico
    
            (jugador == 2 && (computadora == 1 || computadora == 5)) || // Agua vence a Fuego, Roca
    
            (jugador == 3 && (computadora == 2 || computadora == 5)) || // Planta vence a Agua, Roca
    
            (jugador == 4 && (computadora == 2 || computadora == 3)) || // Eléctrico vence a Agua, Planta
    
            (jugador == 5 && (computadora == 1 || computadora == 4))    // Roca vence a Fuego, Eléctrico
    
        ) {
    
            return 1; // Gana el jugador
    
        } else {
    
            return -1; // Gana la computadora
    
        }
    
    }
    
    int main() {
    
        int jugador, computadora;
    
        int puntajeJugador = 0, puntajeComputadora = 0;
    
        int rondasJugadas = 0;
    
        // Semilla para generación de números aleatorios
    
        srand(time(NULL));
    
        printf("¡Bienvenido al duelo de Monstruos de Bolsillo!\n");
    
        printf("Selecciona tu tipo elemental:\n");
    
        printf("1. Fuego\n2. Agua\n3. Planta\n4. Eléctrico\n5. Roca\n");
    
        // Jugar 3 rondas
    
        while (rondasJugadas < 3) {
    
            printf("\nElige un número del 1 al 5 para tu monstruo: ");
    
            scanf("%d", &jugador);
    
            if (jugador < 1 || jugador > 5) {
    
                printf("Opción inválida. Inténtalo de nuevo.\n");
    
                continue;
    
            }
    
            // Selección aleatoria de la computadora
    
            computadora = rand() % 5 + 1;
    
            printf("La computadora eligió: %d\n", computadora);
    
            // Determinar ganador de la ronda
    
            int resultado = determinarGanador(jugador, computadora);
    
            if (resultado == 0) {
    
                printf("Empate en esta ronda.\n");
    
            } else if (resultado == 1) {
    
                printf("¡Ganaste esta ronda!\n");
    
                puntajeJugador++;
    
            } else {
    
                printf("La computadora ganó esta ronda.\n");
    
                puntajeComputadora++;
    
            }
    
            rondasJugadas++;
    
        }
    
        // Determinar el ganador del juego
    
        printf("\nResultado final:\n");
    
        printf("Jugador: %d puntos\n", puntajeJugador);
    
        printf("Computadora: %d puntos\n", puntajeComputadora);
    
        if (puntajeJugador > puntajeComputadora) {
    
            printf("¡Felicidades! ¡Eres el campeón!\n");
    
        } else if (puntajeComputadora > puntajeJugador) {
    
            printf("La computadora es el campeón. ¡Mejor suerte la próxima vez!\n");
    
        } else {
    
            printf("¡El juego terminó en empate!\n");
    
        }
    
        return 0;
    
    }
    
    OTRO MANERA Mismo EJERCICIO
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    
    // Función para determinar el resultado de una ronda
    int determinarGanador(int jugador, int computadora) {
      // Reglas del juego
      if (jugador == computadora) {
        return 0; // Empate
      } else if ((jugador == 1 &&
                  (computadora == 3 ||
                   computadora == 4)) || // Fuego vence a Planta, Eléctrico
                 (jugador == 2 && (computadora == 1 ||
                                   computadora == 5)) || // Agua vence a Fuego, Roca
                 (jugador == 3 &&
                  (computadora == 2 ||
                   computadora == 5)) || // Planta vence a Agua, Roca
                 (jugador == 4 &&
                  (computadora == 2 ||
                   computadora == 3)) || // Eléctrico vence a Agua, Planta
                 (jugador == 5 &&
                  (computadora == 1 ||
                   computadora == 4)) // Roca vence a Fuego, Eléctrico
      ) {
        return 1; // Gana el jugador
      } else {
        return -1; // Gana la computadora
      }
    }
    
    int main() {
      int jugador, computadora;
      int puntajeJugador = 0, puntajeComputadora = 0;
      int rondasJugadas = 0;
    
      // Semilla para generación de números aleatorios
      srand(time(NULL));
    
      printf("¡Bienvenido al duelo de Monstruos de Bolsillo!\n");
      printf("Selecciona tu tipo elemental:\n");
      printf("1. Fuego\n2. Agua\n3. Planta\n4. Eléctrico\n5. Roca\n");
    
      // Jugar 3 rondas
      while (rondasJugadas < 3) {
    
        do {
          printf("\nElige un número del 1 al 5 para tu monstruo: ");
          scanf("%d", &jugador);
    
        } while (jugador < 1 || jugador > 5);
    
        // Selección aleatoria de la computadora
        computadora = rand() % 5 + 1;
        printf("La computadora eligió: %d\n", computadora);
    
        // Determinar ganador de la ronda
        int resultado = determinarGanador(jugador, computadora);
        if (resultado == 0) {
          printf("Empate en esta ronda.\n");
        } else if (resultado == 1) {
          printf("¡Ganaste esta ronda!\n");
          puntajeJugador++;
        } else {
          printf("La computadora ganó esta ronda.\n");
          puntajeComputadora++;
        }
    
        rondasJugadas++;
      }
    
      // Determinar el ganador del juego
      printf("\nResultado final:\n");
      printf("Jugador: %d puntos\n", puntajeJugador);
      printf("Computadora: %d puntos\n", puntajeComputadora);
    
      if (puntajeJugador > puntajeComputadora) {
        printf("¡Felicidades! ¡Eres el campeón!\n");
      } else if (puntajeComputadora > puntajeJugador) {
        printf("La computadora es el campeón. ¡Mejor suerte la próxima vez!\n");
      } else {
        printf("¡El juego terminó en empate!\n");
      }
    
      return 0;
    }
    
    ARREGLOS
    
        #include <stdio.h>
    int main() {
    
    float nums[6] = {0, 0, 0, 0, 0, 0};
    float min=10, max=0, avg =0;
    
    for (int i = 0; i < 6; i++)
    {
        printf("calificacion %d = ", i + 1);
    
        scanf("%f", &nums[i]);
    
        if (nums[i]>10 || nums[i]<0)
        {
            printf("El valor ingresado no es correcto, se debe volver a ingresar\n");
            i--;
        }
    }
    //algoritmo max y min
    for (int i = 0; i < 6; i++)
    {
        if(nums[i]>max)
        {
            max=nums[i];
        }
         if(nums[i]<min)
        {
            min=nums[i];
        }
    //promedio
            avg=avg+nums[i];
    }
            avg=avg/6;
    
        printf("La calificacion mas alta es: %.2f\n", max);
        printf("La calificacion mas baja es: %.2f\n", min);
        printf("EL promedio es: %.2f\n", avg);
    
    return 0;
    }
    
    */

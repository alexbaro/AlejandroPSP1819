#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <signal.h>

#define RUTA_PIPE "/tmp/tuberia.pipe"
#define TAM_MAX 100

int main(int argc, char const *argv[]){
    
    double atof (const char *cadena);

    char numero[50];
    char operacion[1];
    double num;

    printf("Escribe el primer número que quieres operar: ");
    //scanf("%c", &numero);
    fgets(numero, TAM_MAX, stdin);
    
    num = atof(numero);

    char caracter[1] = ',';

    for (int i=0;i<strlen(num);i++)
    { 
        while (num[i] != '\0') 
        { 
             if (num[i] == caracter) 
             { 
                 printf("hola");  // Solo subes quando encuentra el primer caracter, y por eso
                                    // no encuentra los otros caracteres, a mi me funciono
             } 
             
        }
    }
    /*
    if(){//controlar la ,(si pones , no hace la operacion)
        //cambiar la , por un .

        double total = 3.2 + num;
        printf("%lf %lf\n", num, total);

    }else{

        double total = 3.2 + num;
        printf("%lf %lf\n", num, total);

    }*/

    printf("Escribe la operación ( +, -, *, /): ");
    //scanf("%c", &operacion);
    fgets(operacion, TAM_MAX, stdin);

    while(operacion != '+'){
        printf("Operador incorrecto escribe uno de estos ( +, -, *, /): ");
        //scanf("%c\n", &operacion);
        fgets(operacion, TAM_MAX, stdin);
    }
    printf("hola");
    return 0;
}

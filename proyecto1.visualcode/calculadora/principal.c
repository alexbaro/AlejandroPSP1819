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
    while(numero){


        
    }
    num = atof(numero);

    printf("%lf\n", num);

    

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

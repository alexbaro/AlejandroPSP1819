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
int prepararPipe(const char*);

int main(int argc, char const *argv[]){
    //system("rm "RUTA_PIPE);
    double atof (const char *cadena);

    int pipe = prepararPipe(RUTA_PIPE);
    char buffer[TAM_MAX];

    char numero[50];
    char operacion[1];
    double num;
   
    printf("Escribe el primer número que quieres operar: ");
    //scanf("%c\n", &numero);
    fgets(numero, TAM_MAX, stdin);
    
    num = atof(numero);

    printf("Escribe la operación ( +, -, *, /): ");
    //scanf("%c", operacion);
    fgets(operacion, TAM_MAX, stdin);
    //printf("%c\n", &operacion);
    /*
    while(operacion != '+'){

        printf("Escribe la operación ( +, -, *, /): ");
        //scanf("%c\n", &operacion);
        fgets(operacion, TAM_MAX, stdin);
        printf("%c\n", operacion);
        if(operacion == '+'{
            break;
        }
    }*/
    
    //write(RUTA_PIPE, TAM_MAX, num);
 
    system("rm "RUTA_PIPE);

    return 0;
}

int prepararPipe(const char* rutaPipe){
  fprintf(stdout,"Creando el pipe...");
 
  if ( mkfifo(rutaPipe,0666) == -1){
    perror("Error creando el fichero de PIPE");
    exit(-1);
  }
  printf("Hecho!\n");
  printf("Abriendo el pipe. Esperando a que el receptor lo abra en modo lectura...");
  fflush(stdout); 
  int descriptor = open(rutaPipe,O_WRONLY);
  if ( descriptor == -1 ){
    perror("Error abriendo el PIPE");
    exit(-2);
  }
  printf("Hecho!\n");
  return descriptor;
}
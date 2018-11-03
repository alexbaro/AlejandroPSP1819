#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[]){
    //creo los procesos
    pid_t pid;
    pid = fork();

    if(pid == -1){//error de procesos

        fprintf(stderr, "Error");
        exit(-1);

    }else if(pid == 0){//proceso hijo
        
        int caracter;

        printf("Soy el hijo, voy a enviar el fichero al padre.\n"); 

        FILE * ficherolectura = fopen("./texto.txt", "r");//fichero original


    }else {

        FILE * ficherow;
        ficherow = fopen("./copiatexto.txt", "w");//fichero nuevo
        FILE * ficherolectura = fopen("./texto.txt", "r");//fichero original
        printf("Soy el padre, voy a enviar el texto para copiar.");

        char caracter;
        while((caracter = getc(ficherolectura)) != -1){//leo el fichero original y lo copio al nuevo fichero

            putc(caracter,ficherow);

        }
       
    }

    return 0;
}

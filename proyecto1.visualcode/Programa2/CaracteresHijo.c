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
    //Hijo: envia el fichero nuevo, que se va a copiar.
    //Padre: envia el fichero principal con el texto.
    pid_t pid;
    pid = fork();

    if(pid == -1){

        fprintf(stderr, "Error");
        exit(-1);

    }else if(pid == 0){
        
        printf("Soy el hijo, voy a crear el fichero."); 
        int ficherolectura;
        ficherolectura = fopen("./texto.txt", O_RDONLY);

    }else if(pid == 1){

        FILE * ficherow;
        ficherow = fopen("./copiatexto.txt", "w");
        printf("Soy el padre, voy a enviar el texto para copiar.");

        char caracter;
        while((caracter = getc(ficherolectura)) != -1){

            putc(caracter,ficherow);

        }
        
    }

    return 0;
}

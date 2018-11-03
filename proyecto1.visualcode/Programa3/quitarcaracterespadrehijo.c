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
    //Copiar fichero y eliminar una letra
    //Hijo: escribe la copia
    //Padre: lee el fichero
    
    FILE * ficherolectura = argv[0];
    char caracterbuscar = argv[1];
    
    caracterbuscar = 'o';

    char cambio = '#';

    pid_t pid;
    pid = fork();

    if(pid == -1){

        fprintf(stderr, "Error");
        exit(-1);

    }else if(pid == 0){//Hijo
        
        int ficherolectura = fopen("./texto3.txt", O_RDONLY);
        FILE * ficherow = fopen("./copiatexto.txt", "w");

        printf("Soy el hijo, voy a escribir la copia."); 

        if(ficherolectura == -1){
        
        perror("Error abierto el fichero");

        }else{
            
            char caracter;

            while((caracter = getc(ficherolectura)) != -1){
                
                printf("%c", caracter);

                if(caracter == caracterbuscar){

                    putc(cambio, ficherow);

                }else{

                    putc(caracter, ficherow);

                }
            }
            
            printf("\n");
        }
        

    }else if(pid == 1){//Padre

        printf("Soy el padre, voy a leer la copia del texto.");

        FILE * ficherow;
        ficherow = fopen("./copiatexto.txt", O_RDONLY);

        char caracter;

        while((caracter = getc(ficherow)) != -1){
            
            printf("%c", caracter);

        }
        
        
    }

    return 0;
}

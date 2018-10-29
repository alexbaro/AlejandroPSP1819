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
    
    FILE * ficherolectura = argv[0];
    char caracterbuscar = argv[1];

    //FILE * fichero;
    ficherolectura = fopen("./texto.txt", "r");

    FILE * ficherow;
    ficherow = fopen("./copiatexto.txt", "w");

    if(fichero == NULL){
        
        perror("Error abierto el fichero");

    }else{
        
        char caracter;

        while((caracter = fgetc(ficherolectura)) != -1){
            
            printf("%c", caracter);

            if(caracter = caracterbuscar){

                putc("_", ficherow);

            }else{

                putc(caracter, ficherow);

            }

            

        }
        printf("\n");
             
        printf("\n");
    }


    return 0;
}

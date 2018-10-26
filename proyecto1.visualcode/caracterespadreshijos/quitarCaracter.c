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
    
    FILE * fichero;
    fichero = fopen("./texto.txt", "r");

    FILE * ficherow;
    ficherow = fopen("./copiatexto.txt", "w");

    if(fichero == NULL){
        
        perror("Error abierto el fichero");

    }else{
        
        char caracter;

        while((caracter = fgetc(fichero)) != -1){
            
            printf("%c", caracter);

            if(caracter == 'a'){

                putc("_", ficherow);

            }else{

                putc(caracter, ficherow);

            }

            

        }
        printf("\n");
        char caracter2;
        while((caracter2 = fgetc(ficherow)) != -1){
            printf("%c", caracter2);
        }      
        printf("\n");
    }


    return 0;
}

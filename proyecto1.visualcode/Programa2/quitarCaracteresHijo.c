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
    
    char caracterbuscar = argv[1];
    caracterbuscar = 'a';

    char cambio = '_';

    int ficherolectura;
    ficherolectura = fopen("./texto.txt", O_RDONLY);
    

    FILE * ficherow;
    ficherow = fopen("./copiatexto.txt", "w");

    if(ficherolectura == NULL){
        
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

    return 0;
}

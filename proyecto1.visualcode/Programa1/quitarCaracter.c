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
    
    FILE * ficherolectura = argv[0];//creo el fichero que voy a leer
    char caracterbuscar = argv[1];//envio el caracter que voy a buscar el el fichero
    
    caracterbuscar = 'a';

    char cambio = '_';

    ficherolectura = fopen("./texto.txt", "r");//abro el fichero de lectura
    //creo y abro el fichero que voy a cambiar un caracter.
    FILE * ficherow;
    ficherow = fopen("./copiatexto.txt", "w");

    if(ficherolectura == NULL){//error de fichero original
        
        perror("Error abierto el fichero");

    }else{
        
        char caracter;
        //leo el fichero original y lo saco por consola
        while((caracter = getc(ficherolectura)) != -1){
            
            printf("%c", caracter);
            //busco el caracter que quiro intercambiar y lo intercambio
            if(caracter == caracterbuscar){

                putc(cambio, ficherow);
            //introduzco los caracteres del fichero original en la copia 
            }else{

                putc(caracter, ficherow);

            }
        }
        
        printf("\n");

    }

    return 0;
}

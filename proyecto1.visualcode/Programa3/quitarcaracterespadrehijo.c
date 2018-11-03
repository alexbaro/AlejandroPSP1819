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
    
    FILE * ficherolectura = argv[0];//creo el fichero original
    char caracterbuscar = argv[1];//el caracter que sera cambiado
    
    caracterbuscar = 'o';

    char cambio = '#';

    int p[2];//creo la tuberia
    if (pipe(p) == -1){//error de la tuberia
        exit(-1);
    }
    pipe(p);
    int entrada = p[1];//la entrada de la tuberia
    int salida = p[0];//la salida de la tuberia

    pid_t pid;
    pid = fork();
    
    if(pid == -1){//error de proceso

        fprintf(stderr, "Error");
        exit(-1);

    }else if(pid == 0){//proceso hijo
        
        char caracterRecibido;
        FILE * ficherow = fopen("./copiatexto.txt", "w");//fichero nuevo con caracter cambiado
        ficherolectura = fopen("./texto3.txt", "r");//fichero de lectura original
        printf("Soy el hijo, voy a cambiar el caracter\n");

        read(salida, &caracterRecibido, sizeof(char));//lectura de caracteres que le pasa el padre

        if(ficherow == -1){//error de fichero nuevo
        
            perror("Error abierto el fichero");

        }else{
            //leo los caracteres que le envia el padre
            while((caracterRecibido = getc(ficherolectura)) != -1){
                //cambio el caracter que busco por el nuevo caracter y grabo los caracteres en el fichero
                if(caracterRecibido == caracterbuscar){

                    putc(cambio, ficherow);

                }else{//grabo los caracteres en el fichero

                    putc(caracterRecibido, ficherow);

                }
            }
        }
        printf("Texto cambiado.\n");

    }else{//Padre
        
        printf("Soy el padre, voy a leer el texto.\n");
        
        ficherolectura = fopen("./texto3.txt", "r");//abro el fichero original que voy a leer
        char caracter;
        //leo los caracteres del fichero
        while((caracter = getc(ficherolectura)) != -1){
            //escribo los caracteres en la entrada de la tuberia
            write(entrada, &caracter, sizeof(char));
            
        }
        printf("Texto leido\n");
        wait(NULL);//espero al hijo
        close(entrada);
        close(salida);
    }

    return 0;
}

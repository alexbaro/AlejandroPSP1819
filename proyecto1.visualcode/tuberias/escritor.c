#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]){
    
    char*  frase = "Hola soy el escritor";
    
    int descriptorEscritura;
    descriptorEscritura = open("./tuberias", O_WRONLY);

    write(descriptorEscritura, frase, strlen(frase) * sizeof(char));
    close(descriptorEscritura);
    return 0;
}

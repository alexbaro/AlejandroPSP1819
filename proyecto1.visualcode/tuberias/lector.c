#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]){
    
    char leido[100];
    
    int descriptorLectura;
    descriptorLectura = open("./tuberias", O_RDONLY);

    read(descriptorLectura, leido, 100 * sizeof(char));
    fprintf(stdout, "%s\n", leido);
    close(descriptorLectura);

    return 0;
}
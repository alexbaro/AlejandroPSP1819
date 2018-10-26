#include <stdio.h>
#include <string.h>
#include <errno.h>


int main(int argc, char const *argv[])
{
    FILE * fichero;

    fichero = fopen("./hola.txt", "r");
    if(fichero == NULL){
        perror("Error abierto el fichero");
        fprintf(stderr, "Error ""%s: Linea %d: Codigo de error %d. Texto %s\n", __FILE__, __LINE__, errno, strerror(errno));
    }

    return 0;
}

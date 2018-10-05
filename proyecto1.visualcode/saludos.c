#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    
    char cadenaSalida[] = "salir";



    fprintf(stdout, "Escribe un un nombre y te saludaré: ");

    char nombre[15];

    fscanf(stdin, "%s", nombre);

    while(strcmp(cadenaSalida,nombre) != 0){

        fprintf(stdout, "Escribe un un nombre y te saludaré: ");
        fprintf(stdout, "Hola %s\nTu inicial es %c\n", nombre, nombre[0]);
        fscanf(stdin, "%s", nombre);

    }

    fprintf(stdout, "Se escribió la palabra clave %s\n", nombre);
    return 0;
}

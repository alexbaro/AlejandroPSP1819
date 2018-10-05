#include <stdio.h>

/*1.- Pedir un string por consola y escribir los 4 primeros caracteres de ese 
        string en un fichero ejer1.txt*/

int main(int argc, char const *argv[])
{
    FILE* fichero = fopen("./ejercicio1.txt", "w");
    char texto[100];
    fprintf(stdout, "Escribe un mensaje:");
    scanf("%s", texto);
    fwrite(texto, 4, sizeof(char), fichero);
    putc('\n', fichero);
    fclose(fichero);
    return 0;
}
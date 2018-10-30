#include <stdio.h>
#include <string.h>

/*3.- Pedir 2 strings por consola y escribirlos enteros (strlen) 
        en un fichero ejer3.txt, separándolos con 2 saltos de línea.*/

int main(int argc, char const *argv[])
{
    FILE* fichero = fopen("./ejercicio3.txt", "w");

    char texto[30];

    for(int i = 1; i <= 2; i++){

        fprintf(stdout, "Escribe una cadena de dos palabras: ");
        scanf("%s", texto);
        fwrite(texto, sizeof(char), strlen(texto), fichero);

        for(int j = 0; j < 2; j++){

            putc('\n', fichero);
        
        }
    }

    return 0;
}
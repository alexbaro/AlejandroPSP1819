#include <stdio.h>

/*2.- Pedir 3 string por consola y escribir los 5 primeros caracteres de esos strings 
        en un fichero ejer2.txt, separándolos con saltos de línea.*/
        
int main(int argc, char const *argv[])
{
    int entero = 135694;
    FILE* fichero = fopen("./ejercicio2.txt", "wb");
    fwrite(&entero, sizeof(int), 1, fichero);
    return 0;
}
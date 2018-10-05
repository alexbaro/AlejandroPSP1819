#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE* fichero = fopen("./hola.txt", "w");
    char texto[] = "Hola mundo";
    fwrite(texto, 5, sizeof(char), fichero);
    putc('\n', fichero);
    fseek(fichero, 0, SEEK_SET);
    putc('J', fichero);
    fclose(fichero);
    return 0;
}

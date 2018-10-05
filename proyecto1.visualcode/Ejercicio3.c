#include <stdio.h>
#include <string.h>

/*3.- Pedir 2 strings por consola y escribirlos enteros (strlen) 
        en un fichero ejer3.txt, separándolos con 2 saltos de línea.*/

int main(int argc, char const *argv[])
{
    FILE* fichero = fopen("./ejercicio3.txt", "w");

    char texto[30];

    for(int i = 1; i <= 2; i++){

        fprintf(stdout, "Escribe una cadena: ");
        scanf("%s", texto);
        fwrite(texto, sizeof(char), strlen(texto), fichero);

        for(int j = 0; j < 2; j++){

            putc('\n', fichero);
        
        }
    }

    return 0;
}


/*
4.- Escribir 2 enteros cualesquiera en un fichero ejer4.dat
5.- Leer 2 enteros del fichero ejer4.dat sumarlos y guardar el resultado en texto plano en ejer5.txt
6.- Transformar el texto ejer5.txt a entero y escribirlo en un fichero binario ejer6.dat
7.- Diccionario: Pedir de la entrada estandar una palabra en inglés, y después su traducción en español. Añadir al fichero ejer7.txt con el formato "word = palabra" seguido de un salto de línea. El fichero ejer7.txt deberá crecer en palabras en cada ejecución.
8.- Diccionariov2: Realizar el ejercicio7 en un bucle que no saldrá hasta que escribamos la cadena ".-" como palabra.
9.- Crea el programa indexarDiccionario que cree un fichero diccionario.txt que será igual al fichero ejer7.txt pero añadiendo números correlativos empezando por 0001-, 0002-, 0003-,... al inicio de cada línea del fichero.*/
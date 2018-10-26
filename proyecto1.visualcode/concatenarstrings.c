#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprimirAsciihasta(char);

int main(int argc, char const *argv[]){
    char cad1[] = "Hola";
    char cad2[] = " ";
    char cad3[] = "mundo.";
    //tamTotal es el total de todas las cadenas más el \0 del final.
    int tamTotal = strlen(cad1) + strlen(cad2) + strlen(cad3) + 1; 
    char* cadRes = (char*) malloc(tamTotal * sizeof(char));

    imprimirAsciihasta('H');

    cadRes = strcat(cadRes, cad1);
    cadRes = strcat(cadRes, cad2);
    cadRes = strcat(cadRes, cad3);

    fprintf(stdout, "%s\n", cadRes);

    
    return 0;
}

void imprimirAsciihasta(char a){

    fprintf(stdout, "Los caracteres desde 0 hasta %d son: \n", a);

    for(int i = 0; i <= a; i++){
        
        fprintf(stdout, "El número %d pertenece al caracter ASCII: %c\n", i, i);

    }

}
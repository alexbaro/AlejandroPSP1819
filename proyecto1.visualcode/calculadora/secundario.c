#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <signal.h>

#define RUTA_PIPE "/tmp/tuberia.pipe"
#define TAM_MAX 100

int abrirPipe(const char*);

int main(int argc, char const *argv[]){
    
    int pipe = abrirPipe(RUTA_PIPE);

    char buffer[TAM_MAX];
    int leido;

    leido = read(pipe, buffer, TAM_MAX);
    fprintf("%s\n", buffer);
    return 0;
}

int abrirPipe(const char* rutaPipe){
  printf("Abriendo el pipe...");
  int descriptor = open(RUTA_PIPE,O_RDONLY);
  if ( descriptor == -1 ){
    perror("Error abriendo el PIPE. ¿Ha lanzado el emisor? Él es el encargado de crear el PIPE.");
    exit(-1);
  }
  printf("Hecho!\n");
  return descriptor;
}
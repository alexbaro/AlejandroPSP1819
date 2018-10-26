#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int pPadreHijo[2];
    int pHijoPadre[2];

    pipe(pPadreHijo);
    pipe(pHijoPadre);

    pid_t pid;
    pid = fork();

    if(pid == 0){//Código hijo. Espera a que el padre le envie 

        close(pPadreHijo[1]); //cierro la scritura del pipe por el que recibo
        close(pHijoPadre[0]); //cierro la lectura del pipe por el que envio

        int recibido;
        read(pPadreHijo[0], &recibido, sizeof(int));
        printf("Hijo: leido %d del pipe\n", recibido);
        int mensaje = 98765;
        write(pHijoPadre[1], &mensaje, sizeof(int));
        

    }else{//Código padre. Inicia la comunicación

        close(pPadreHijo[0]); //cierro la scritura del pipe por el que recibo
        close(pHijoPadre[1]); //cierro la lectura del pipe por el que envio
        int mensaje = 12345;
        write(pPadreHijo[1], &mensaje, sizeof(int));
        
        int recibido;

        read(pHijoPadre[0], &recibido, sizeof(int));
        printf("Padre: leido %d del pipe\n", recibido);
        wait(NULL);
    }
    //Esto lo ejecutan los dos
    return 0;
}


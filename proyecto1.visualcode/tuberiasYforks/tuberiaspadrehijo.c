#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int tub[2];

    if(pipe(tub) == -1){

        exit(-1);

    }

    int entrada = tub[1];
    int salida = tub[0];

    pid_t pidH1, pidH2;

    pidH1 = fork();

    if(pidH1 == -1){

        exit(-2);

    }
    if(pidH1 == 0){
        
        int msj = 123;
        printf("H1: Enviando entero %d por el pipe", msj);
        fflush(stdout);
        write(entrada, &msj, sizeof(int));
        fprintf(stdout, "H1: Hecho!\n");

    }else{//codigo del padre

        pidH2 = fork();

        if(pidH2 == -1){

            exit(-3);

        }
        if(pidH2 == 0){//codigo del hijo 2
            int msj_recibido = 0;
            fprintf(stdout, "H2: Recibendo entero por el pipe...");
            read(salida, &msj_recibido, sizeof(int));
            fprintf(stdout, "H2: Hecho!\n");
        }else{//codigo del padre
            fprintf(stdout, "Padre: Esperando a un hijo...");
            wait(NULL);
            fprintf(stdout, "Hecho!\n");
            fprintf(stdout, "Padre: Hecho!\n");
            fprintf(stdout, "Padre: Esperando a otro hijo...");
            wait(NULL);
            fprintf(stdout, "Hecho!\n");
            close(entrada);
            close(salida);
        }
    }

    return 0;
}

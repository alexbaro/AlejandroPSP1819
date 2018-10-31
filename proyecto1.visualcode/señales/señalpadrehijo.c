#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void tratarSIGINT(int);

int main(int argc, char const *argv[])
{
    printf("PADRE: pid: %d\n", getpid());
    pid_t pid;
    signal(SIGINT, tratarSIGINT);
    pid = fork();
    if(pid == -1){

        perror("Error en el fork");
        exit(-1);

    }
    if(pid == 0){//Soy el hijo

        printf("HIJO: pid: %d\n", getpid());
        if(kill(getpid(), SIGINT) == -1){
            perror("HIJO: Error en el kill");
        }

    }else{//Soy el padre
        sleep(1);
        if(kill(pid, SIGINT) == -1){
            perror("HIJO: Error en el kill");
        }
        wait(NULL);

    }

    return 0;
}

void tratarSIGINT(int codSenyal){

    printf("Soy el proceso %d me han enviado una señal", getpid());

}

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    fprintf(stdout, "Soy el proceso principal mi pid es: %d\n\n", getpid());
    pid = fork();
    
    if(pid == -1){

        fprintf(stderr, "Error");
        exit(-1);

    }else if(pid == 0){ //Codigo hijo
        
        fprintf(stdout, "Soy el hijo y mi pid es: %d\n", getpid());
        sleep(1);

        pid_t pidNieto;
        if(pidNieto = fork() == -1){
            exit(-1);
        }
        if(pidNieto == 0){ //Soy el nieto
            fprintf(stdout, "Soy un proceso nieto\n\t mi pid es: %d\n\t mi padre es: %d\n", getpid(), getpid());
        }else{//Vuelvo a ser el hijo
            wait(NULL); //Espero a mi hijo, que es el nieto de mi padre
            fprintf(stdout, "El nieto ha acabado.\n");
        }
    }else{//Codigo padre
        
        fprintf(stdout, "Soy el padre y mi pid es: %d. El hijo que e creado es: %d\n", getpid(), pid);
        wait(NULL);
        fprintf(stdout, "El hijo ha acabado.\n");
    }
    
    return 0;
}
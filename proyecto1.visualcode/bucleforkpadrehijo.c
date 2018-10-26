#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    
    if(argc != 2){
        fprintf(stdout, "Uso del programa: \n\t %s num_hijos", argv[0]);
        exit(-1);
    }

    int num_hijos = atoi(argv[1]);
    int pid_hijo;

    for(int i = 0; i <= num_hijos; i++){
        
        pid_hijo = fork();

        if(pid_hijo == 0){

            fprintf(stdout, "HIJO %3d: mi pid es:%d\n", i, getpid());
            return 0;

        }

    }    

    for(int i = 0; i <= num_hijos; i++){
        fprintf(stdout, "PADRE: un hijo ha acabado.\n");
        wait(NULL);
    }

    return 0;
}

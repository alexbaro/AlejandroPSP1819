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

    }else if(pid == 0){
        
        fprintf(stdout, "Soy el hijo y mi pid es: %d\n", getpid());
        sleep(1);

    }else{
        
        fprintf(stdout, "Soy el padre y mi pid es: %d. El hijo que e creado es: %d\n", getpid(), pid);
        wait(NULL);
        fprintf(stdout, "El hijo ha acabado.\n");
    }
    
    return 0;
}

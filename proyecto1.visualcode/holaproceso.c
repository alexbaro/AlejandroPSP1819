#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int error;
    
    if(error = system("ls") == -1){

        fprintf(stderr, "Ha ocurrido un error. \n");

    }

    fprintf(stdout, "Ahora con execl: \n\n");
    execl("/bin/ls", "ls", "-l", NULL);

     return 0;
}

#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("hola");
    fork();
    printf("Hola2");
    fflush(stdout);
    sleep(1);
    return 0;
}



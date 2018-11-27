#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void controlZ(int);
void controlC(int);

int main(int argc, char const *argv[])
{
    
    signal(SIGTSTP, controlZ);
    signal(SIGINT, controlC);

    int i = 0;

    while(i < 100){

        printf("%d\n",++i);
        sleep(1);

    }

    return 0;
}

void controlC(int num){

    printf("Has tocado control C");
    fflush(stdout);
    sleep(1);
}

void controlZ(int num){

    printf("Has tocado control Z");
    fflush(stdout);
    sleep(1);
}

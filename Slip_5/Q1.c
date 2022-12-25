#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int pid;
    int retnice;
    pid = fork();

    if(pid==0)
    {
        retnice = nice(-20);
        printf("Yhis is Child process");
        printf("Child pid: %d",getpid());
        exit(0);
    }
    else
    {
        retnice = nice(19);
        printf("This is Parent process");
        printf("Parent pid: ",getpid());
        exit(1);
    }
    return 0;
}
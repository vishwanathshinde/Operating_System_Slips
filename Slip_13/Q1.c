#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int pid;
    int retnice;
    pid = fork();

    if(pid == 0)
    {
        retnice = nice(-20);
        printf("This is child process");
    }
    else
    {
        retnice = nice(19);
        printf("This is parent process");
    }
}
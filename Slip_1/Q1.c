#include<stdio.h>
#include<unistd.h>

int main()
{
    int pid;
    int retnice;
    pid=fork();

    if(pid==0)
    {
        retnice = (-20);
        printf("I am child process and my pid is: %d",getpid());
    }
    
    else
    {
        retnice = nice(19);
        printf("This is Parent process and my process id is: %d",getpid());
    }
    return 0;
}
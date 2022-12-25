#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int pid = fork();

    if(pid==0)
    {
        printf("Child process pid %d: "+getpid());
        printf("Hello World");
    }
    else
    {
        printf("Parent process id %d: ",getpid());
        printf("Hii");
    }
    return 0;
}
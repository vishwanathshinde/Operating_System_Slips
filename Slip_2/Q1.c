#include<stdlib.h>
#include<unistd.h>

int main()
{
    int pid;
    pid = fork();

    if(pid<0)
    {
        printf("Error");
        exit(1);
    }
    if(pid==0)
    {
        printf("I am Child Process");
        printf("Child pid: %d",getpid());
        printf("Hello World");
        printf("-----------------------");
        exit(0);
    }
    else
    {
        printf("This is parent process");
        printf("Parent pid: %d",getpid());
        printf("Hi");
        printf("-----------------------");
        exit(1);
    }
    return 0;
}
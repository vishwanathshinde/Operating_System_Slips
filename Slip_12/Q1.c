#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int pid = fork();

    if(pid > 0)
    {
        printf("This is Parent process.");
        printf("Parent pid %d: ",getpid());
    }
    else if(pid == 0)
    {
        printf("Child process id %d: ",getpid());
        printf("PArent pid - %d",getppid());

        sleep(10);

        printf("Child pid %d: ",getpid());
        printf("Parent pid - %d", getpid());
    }
    else
    {
        printf("Fork failed to create a child process");
    }
    return 0;
}
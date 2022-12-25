#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int pid = fork();

    if(pid > 0)
    {
        printf("This is Parent process.");
        printf("Parent pid: %d",getpid());
        printf("-----------------------");
    }
    else if(pid == 0)
    {
        printf("This is child process.");
        printf("Child pid: %d",getpid());
        printf("Parent - %d",getppid());
        printf("-------------------------");

        sleep(10);

        printf("This is child process.");
        printf("Child pid: %d",getpid());
        printf("Parent - %d",getppid());
        printf("-------------------------");
    }
    else
    {
        printf("Fork failed to create a child.");
    }
}
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int pid;
    pid = fork();

    if(pid<0)
    {
        printf("Error");
        exit(0);
    }

    else if(pid==0)
    {
        printf("Child process running");
        execl("/bin/ls","ls",NULL);
    }
    else
    {
        printf("Child process terminated");
        sleep(5);
    }
    return 0;
}
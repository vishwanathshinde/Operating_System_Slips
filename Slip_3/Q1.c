#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
    int pid;
    char *args[] = {"Hello","World",NULL};
    pid = fork();
    {
        if(pid==0)
        {
            printf("\nChild completed.\n");
            printf("Child pid: %d",getpid());
            execv(".A22.exe",args);
            exit(0);
        }
        else
        {
            printf("This is parent process");
            printf("Parent pid %d: ",getpid());
            exit(1);
        }
    }
}
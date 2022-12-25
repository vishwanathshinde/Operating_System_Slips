#include<stdio.h>
#include<unistd.h>

int main()
{
    int pid = fork();

    if(pid == 0)
    {
        printf("This is child process");
        execl("/bin/ls","ls",NULL);
    }
    else
    {
        sleep(5);
        printf("This is parent process");
    }
}
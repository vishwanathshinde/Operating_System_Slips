#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int pid = fork();

    if(pid==0)
    {
        printf("This is Child process");
        execl("/bin/ls","ls",NULL);
    }
    else
    {
        sleep(5);
        printf("This is Parent process");
    }
}
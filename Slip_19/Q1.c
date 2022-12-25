#include<stdio.h>

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
        printf("this is parent process");
    }
    return 0;
}
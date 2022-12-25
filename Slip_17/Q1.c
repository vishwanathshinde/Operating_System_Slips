#include<stdio.h>
#include<unistd.h>

int main()
{
    int process, need;

    printf("Enter no of process: ");
    scanf("%d",&process);

    printf("Enter need: ");
    scanf("%d",&need);

    int minResources = process * (need-1) + 1;

    printf("Minimum no of resources needed: %d",minResources);
}
#include<stdio.h>

int main()
{
    int i, j, np, nr, max[20][20], allocation[20][20], need[20][20];

    printf("Enter the number of processes: ");
    scanf("%d",&np);

    printf("Enter the number of resources: ");
    scanf("%d",&nr);

    printf("Enter the elements for max matrix: ");
    for(i=0; i<np; i++)
    {
        printf("\nFor %d: ",i+1);
        for(j=0; j<nr; j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("Enter the elements for Allocation matrix: ");
    for(i=0; i<np; i++)
    {
        printf("\nFor %d: ",i+1);
        for(j=0; j<nr; j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("Need matrix: \n");
    for(i=0; i<np; i++)
    {
        for(j=0; j<nr; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
}
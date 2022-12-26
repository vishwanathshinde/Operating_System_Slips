#include <stdio.h>
#include <string.h>

int i, j, k = 1, np, min, at[20], bt[20], wt[20], tat[20], temp[20], priority[20];
float Awt, Atat;
char pname[20][20], cname[20][20];

void getdata();
void np_priority();
void calculate();
void gantt_chart();
void chart();

void getdata()
{
    printf("Enter the number of process: ");
    scanf("%d", &np);

    for (i = 0; i < np; i++)
    {
        printf("Enter the name of process: ");
        scanf("%s", &pname[i]);
        printf("Enter the arrival time for %s : ", pname[i]);
        scanf("%d", &at[i]);
        printf("Enter the Burst time for %s : ", pname[i]);
        scanf("%d", &bt[i]);
        printf("Enter the priority of the process %s: ", pname[i]);
        scanf("%d", &priority[i]);
    }
}

void np_priority()
{
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < np; j++)
        {
            if (at[i] < at[j])
            {
                int temp = bt[i];
                int temp1 = at[i];

                bt[i] = bt[j];
                at[i] = at[j];

                at[j] = temp1;
                bt[j] = temp;

                strcpy(cname[i], pname[i]);
                strcpy(pname[i], pname[j]);
                strcpy(pname[j], cname[i]);
            }
        }
    }
}

void calculate()
{
    wt[1] = 0;
    for (int i = 1; i <= np; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    for (int j = 0; j < np; j++)
    {
        int b = b + bt[j];
        min = bt[k];

        for (int i = k; i < np; i++)
        {
            min = priority[k];
            if (b >= at[i])
            {
                if (priority[i] < min)
                {
                    int temp = at[k];
                    at[k] = at[i];
                    at[i] = temp;

                    temp = bt[k];
                    bt[k] = bt[i];
                    bt[i] = temp;

                    temp = priority[i];
                    priority[k] = priority[i];
                    priority[i] = temp;
                }
            }
            k++;
        }
    }
    
}

void chart()
{
    printf("\nProcess\tArrival_Time\tBurst_Time\tPriority\tT_A_T\tWaiting_Time\n");

    for (i = 0; i < np; i++)
    {
        tat[i] = 0;
        wt[i] = 0;
        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        Awt = Awt + wt[i];
        Atat = Atat + tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, at[i], bt[i], priority[i], tat[i], wt[i]);
    }
    Awt = Awt / np;
    Atat = Atat / np;
    printf("\nAverage waiting time: %3.2fms\n", Awt);
    printf("\nAverage turn around time: %3.2fms\n", Atat);
}

void main()
{
    getdata();
    np_priority();
    calculate();
    chart();
}
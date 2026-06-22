#include<stdio.h>

struct process
{
    int bt, pr, wt, tat, pid;
};

int main()
{
    struct process p[10], temp;
    int n, i, j;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &p[i].bt);

        printf("Enter Priority for P%d: ", i + 1);
        scanf("%d", &p[i].pr);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(p[i].pr < p[j].pr)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].wt = 0;

    for(i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        p[i].tat = p[i].wt + p[i].bt;

        avg_wt += p[i].wt;
        avg_tat += p[i].tat;

        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid,
               p[i].bt,
               p[i].pr,
               p[i].wt,
               p[i].tat);
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

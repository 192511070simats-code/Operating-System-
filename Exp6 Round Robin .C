#include<stdio.h>

int main()
{
    int bt[10], rem[10], wt[10], tat[10];
    int n, tq, i, time = 0, remain;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    remain = n;

    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d",&bt[i]);

        rem[i] = bt[i];
        wt[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    i = 0;

    while(remain != 0)
    {
        if(rem[i] > 0 && rem[i] <= tq)
        {
            time += rem[i];
            wt[i] = time - bt[i];
            rem[i] = 0;
            remain--;
        }
        else if(rem[i] > tq)
        {
            rem[i] -= tq;
            time += tq;
        }

        i++;

        if(i == n)
            i = 0;
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];

        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d\t%d\t%d\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

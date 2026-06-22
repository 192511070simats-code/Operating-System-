#include<stdio.h>
#include<stdlib.h>

int main()
{
    int req[20], n, head, i, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++)
    {
        total += abs(head - req[i]);
        head = req[i];
    }

    printf("Total Head Movement = %d\n", total);

    return 0;
}

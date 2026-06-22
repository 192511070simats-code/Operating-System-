#include<stdio.h>
#include<stdlib.h>

int main()
{
    int req[20], visited[20]={0};
    int n, head, total=0, i, j;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter request sequence: ");
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);

    printf("Enter head position: ");
    scanf("%d",&head);

    for(i=0;i<n;i++)
    {
        int min=9999,pos=-1;

        for(j=0;j<n;j++)
        {
            if(!visited[j] && abs(head-req[j])<min)
            {
                min=abs(head-req[j]);
                pos=j;
            }
        }

        visited[pos]=1;
        total+=abs(head-req[pos]);
        head=req[pos];
    }

    printf("Total Head Movement = %d\n",total);

    return 0;
}

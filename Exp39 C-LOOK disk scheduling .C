#include<stdio.h>

int main()
{
    int low, high, head;

    printf("Enter lowest request: ");
    scanf("%d",&low);

    printf("Enter highest request: ");
    scanf("%d",&high);

    printf("Enter head position: ");
    scanf("%d",&head);

    printf("Total Head Movement = %d\n",(high-head)+(high-low));

    return 0;
}

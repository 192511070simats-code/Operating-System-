#include<stdio.h>

int main()
{
    int highest, head;

    printf("Enter highest request: ");
    scanf("%d",&highest);

    printf("Enter head position: ");
    scanf("%d",&head);

    printf("Total Head Movement = %d\n", highest-head);

    return 0;
}

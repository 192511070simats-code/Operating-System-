#include<stdio.h>

int main()
{
    int size,head;

    printf("Enter disk size: ");
    scanf("%d",&size);

    printf("Enter head position: ");
    scanf("%d",&head);

    printf("Total Head Movement = %d\n",(size-1-head)+(size-1));

    return 0;
}

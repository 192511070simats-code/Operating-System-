#include<stdio.h>
#include<stdlib.h>

int main()
{
    int head,size;

    printf("Enter disk size: ");
    scanf("%d",&size);

    printf("Enter head position: ");
    scanf("%d",&head);

    printf("Total Head Movement = %d\n",(size-1-head));

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct file
{
    char fname[20];
};

int main()
{
    int n, i, choice;
    struct file dir[20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter file %d name: ", i + 1);
        scanf("%s", dir[i].fname);
    }

    printf("\nFiles in Single Level Directory:\n");

    for(i = 0; i < n; i++)
    {
        printf("%s\n", dir[i].fname);
    }

    return 0;
}

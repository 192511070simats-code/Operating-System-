#include<stdio.h>

struct directory
{
    char dirname[20];
    char filename[20][20];
    int filecount;
};

int main()
{
    struct directory dir[10];
    int ndir, i, j;

    printf("Enter number of directories: ");
    scanf("%d", &ndir);

    for(i = 0; i < ndir; i++)
    {
        printf("Enter directory name: ");
        scanf("%s", dir[i].dirname);

        printf("Enter number of files: ");
        scanf("%d", &dir[i].filecount);

        for(j = 0; j < dir[i].filecount; j++)
        {
            printf("Enter file name %d: ", j + 1);
            scanf("%s", dir[i].filename[j]);
        }
    }

    printf("\nDirectory Structure\n");

    for(i = 0; i < ndir; i++)
    {
        printf("\n%s\n", dir[i].dirname);

        for(j = 0; j < dir[i].filecount; j++)
        {
            printf("  %s\n", dir[i].filename[j]);
        }
    }

    return 0;
}

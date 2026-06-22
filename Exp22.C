#include<stdio.h>

int main()
{
    int f[50], i, j, n, start, len, k, ch;

    for(i = 0; i < 50; i++)
        f[i] = 0;

    printf("File Allocation Strategies\n");
    printf("1. Sequential Allocation\n");
    printf("2. Indexed Allocation\n");
    printf("3. Linked Allocation\n");

    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            printf("Enter starting block and length of file: ");
            scanf("%d%d", &start, &len);

            k = start;

            for(i = 0; i < len; i++)
            {
                if(f[k] == 0)
                {
                    f[k] = 1;
                    k++;
                }
                else
                {
                    printf("Block already allocated\n");
                    break;
                }
            }

            if(i == len)
            {
                printf("File allocated successfully\n");
                for(j = start; j < start + len; j++)
                    printf("%d -> %d\n", j, f[j]);
            }
            break;

        case 2:
            printf("Enter index block: ");
            scanf("%d", &start);

            if(f[start] == 0)
            {
                f[start] = 1;

                printf("Enter number of blocks needed: ");
                scanf("%d", &n);

                printf("Enter blocks:\n");

                for(i = 0; i < n; i++)
                {
                    scanf("%d", &k);

                    if(f[k] == 0)
                    {
                        f[k] = 1;
                        printf("%d allocated\n", k);
                    }
                    else
                    {
                        printf("%d already allocated\n", k);
                    }
                }
            }
            else
            {
                printf("Index block already allocated\n");
            }
            break;

        case 3:
            printf("Enter starting block and length: ");
            scanf("%d%d", &start, &len);

            k = start;

            for(i = 0; i < len; i++)
            {
                if(f[k] == 0)
                {
                    f[k] = 1;
                    printf("%d -> ", k);
                    k++;
                }
                else
                {
                    printf("Block already allocated\n");
                    break;
                }
            }

            printf("NULL\n");
            break;

        default:
            printf("Invalid Choice\n");
    }

    return 0;
}

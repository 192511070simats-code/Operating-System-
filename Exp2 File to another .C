#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    char filename[100], c;

    printf("Enter source file name: ");
    scanf("%s", filename);

    fptr1 = fopen(filename, "r");

    if(fptr1 == NULL)
    {
        printf("Cannot open source file");
        exit(0);
    }

    printf("Enter destination file name: ");
    scanf("%s", filename);

    fptr2 = fopen(filename, "w");

    c = fgetc(fptr1);

    while(c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    printf("Contents copied successfully");

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}

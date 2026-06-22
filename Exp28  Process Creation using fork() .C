#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();

    printf("Process Running\n");

    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if(pid > 0)
    {
        printf("Parent sleeping...\n");
        sleep(10);
    }
    else
    {
        printf("Child exiting\n");
    }

    return 0;
}

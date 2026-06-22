#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if(pid > 0)
    {
        printf("Parent Process exiting\n");
    }
    else
    {
        sleep(5);
        printf("Child (Orphan) Process\n");
    }

    return 0;
}

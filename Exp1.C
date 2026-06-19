#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid, ppid;

    // Display IDs before forking
    printf("Before fork:\n");
    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n\n", getppid());

    // Create a new process
    pid = fork();

    if (pid < 0)
    {
        // fork failed
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child Process:\n");
        printf("Process ID (Child): %d\n", getpid());
        printf("Parent Process ID (of Child): %d\n", getppid());
    }
    else
    {
        // Parent process
        sleep(1); // ensures child prints first (optional)
        printf("Parent Process:\n");
        printf("Process ID (Parent): %d\n", getpid());
        printf("Parent Process ID (of Parent): %d\n", getppid());
        printf("Child Process ID (created): %d\n", pid);
    }

    return 0;
}
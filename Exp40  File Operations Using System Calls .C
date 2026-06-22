#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd;
    char buffer[50];

    fd = open("oslab.txt", O_CREAT | O_RDWR, 0777);

    write(fd, "Operating System Lab", 20);

    lseek(fd, 0, SEEK_SET);

    read(fd, buffer, 20);

    buffer[20] = '\0';

    printf("File Content: %s\n", buffer);

    close(fd);

    return 0;
}

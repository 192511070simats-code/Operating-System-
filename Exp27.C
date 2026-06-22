#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[100];

    printf("Enter directory path: ");
    scanf("%s", path);

    dir = opendir(path);

    if (dir == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    printf("\nFiles and directories in '%s':\n", path);

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}

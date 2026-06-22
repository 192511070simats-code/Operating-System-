#include <stdio.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_NAME_LENGTH 50

struct File {
    char name[MAX_NAME_LENGTH];
};

struct Directory {
    struct File files[MAX_FILES];
    int fileCount;
};

void initializeDirectory(struct Directory *dir) {
    dir->fileCount = 0;
}

void addFile(struct Directory *dir) {
    if (dir->fileCount >= MAX_FILES) {
        printf("Directory is full. Cannot add more files.\n");
        return;
    }

    char fileName[MAX_NAME_LENGTH];
    printf("Enter file name to add: ");
    scanf("%s", fileName);

    for (int i = 0; i < dir->fileCount; i++) {
        if (strcmp(dir->files[i].name, fileName) == 0) {
            printf("File already exists.\n");
            return;
        }
    }

    strcpy(dir->files[dir->fileCount].name, fileName);
    dir->fileCount++;

    printf("File added successfully.\n");
}

void listFiles(struct Directory *dir) {
    if (dir->fileCount == 0) {
        printf("Directory is empty.\n");
        return;
    }

    printf("\nFiles in the directory:\n");
    for (int i = 0; i < dir->fileCount; i++) {
        printf("%d. %s\n", i + 1, dir->files[i].name);
    }
}

void deleteFile(struct Directory *dir) {
    char fileName[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter file name to delete: ");
    scanf("%s", fileName);

    for (int i = 0; i < dir->fileCount; i++) {
        if (strcmp(dir->files[i].name, fileName) == 0) {
            found = 1;

            for (int j = i; j < dir->fileCount - 1; j++) {
                dir->files[j] = dir->files[j + 1];
            }

            dir->fileCount--;
            printf("File deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("File not found.\n");
    }
}

void searchFile(struct Directory *dir) {
    char fileName[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter file name to search: ");
    scanf("%s", fileName);

    for (int i = 0; i < dir->fileCount; i++) {
        if (strcmp(dir->files[i].name, fileName) == 0) {
            found = 1;
            printf("File found in the directory.\n");
            break;
        }
    }

    if (!found) {
        printf("File not found.\n");
    }
}

int main() {
    struct Directory dir;
    int choice;

    initializeDirectory(&dir);

    while (1) {
        printf("\n--- Single Level Directory Organization ---\n");
        printf("1. Add File\n");
        printf("2. List Files\n");
        printf("3. Delete File\n");
        printf("4. Search File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFile(&dir);
                break;

            case 2:
                listFiles(&dir);
                break;

            case 3:
                deleteFile(&dir);
                break;

            case 4:
                searchFile(&dir);
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char buffer[100];

    // Open file for writing
    file = fopen("example.txt", "w");

    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return 1;
    }

    // Write data into the file
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a C file management example.\n");

    // Close the file after writing
    fclose(file);

    printf("Data written to file successfully.\n");

    // Open file for reading
    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return 1;
    }

    printf("\nData read from the file:\n");

    // Read and display file content
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file after reading
    fclose(file);

    return 0;
}

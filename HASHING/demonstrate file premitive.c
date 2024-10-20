#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    // Default code
    printf("Practial-10\n");
    printf("Enrollment NO. :-230130107052 \n");
    printf("Krina jain\n");  
    printf("10.2 Write a program to demonstrate the file primitives such as fopen, fclose,fprintf.\n");
    FILE *file;
    const char *filename = "example.txt";
    // Open the file for writing ("w" mode)
    file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    // Write to the file using fprintf
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a demonstration of file primitives in C.\n");
    fprintf(file, "File handling is important for persistent data storage.\n");
    // Close the file
    fclose(file);
    printf("Data written to %s successfully.\n", filename);
    return EXIT_SUCCESS;
}
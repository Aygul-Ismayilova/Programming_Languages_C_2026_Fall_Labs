// week5_task1_file_io.c
// Name: Aygul  Surname: Ismayilova  Student ID: 251ADB153
//
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.
//
// Build: make lab5   Run: ./bin/week5_task1_file_io

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    const char *filename = DEFAULT_FILENAME;
    char line[LINE_LEN];
    int line_count = 0;

    if (argc > 1) {
        filename = argv[1];
    }

    // 1. Open the file for writing
    printf("Writing lines to %s...\n", filename);
    fp = fopen(filename, "w");

    // 2. Stop if the file could not be opened
    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 3. Write a few lines of text
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");

    // 4. Close the file (this also flushes the data to disk)
    if (fclose(fp) != 0) {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 5. Open the same file again, this time for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 6. Read and print the file line by line
    printf("Reading contents:\n");
    while (fgets(line, sizeof line, fp) != NULL) {
        printf("%s", line);   // fgets keeps the '\n', so no extra newline here
        line_count++;
    }

    // 7. Close the file
    fclose(fp);

    // BONUS: report how many lines were read
    printf("Lines read: %d\n", line_count);

    return EXIT_SUCCESS;
}

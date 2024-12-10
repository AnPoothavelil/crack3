#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// Load the text file into a 2D array
char (*loadFile2D(char *filename, int *size))[COLS]
{
    int CAPACITY = 10;
    FILE *in = fopen(filename, "r");
    if (!in)
    {
        perror("Can't open file");
        exit(1);
    }

    char (*arr)[COLS] = malloc(CAPACITY * sizeof(char[COLS]));
    if (!arr)
    {
        perror("Memory allocation failed");
        exit(1);
    }

    *size = 0;
    char buffer[1000];

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), in))
    {
        // Trim newline
        buffer[strcspn(buffer, "\n")] = '\0';

        // Expand the array if needed
        if (*size >= CAPACITY)
        {
            CAPACITY *= 2;
            arr = realloc(arr, CAPACITY * sizeof(char[COLS]));
            if (!arr)
            {
                perror("Memory reallocation failed");
                exit(1);
            }
        }

        // Copy the line into the array
        strcpy(arr[*size], buffer);
        (*size)++;
    }

    fclose(in);
    return arr;
}

// Search the 2D array for a substring
char *substringSearch2D(char *target, char (*lines)[COLS], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (strstr(lines[i], target))
        {
            return lines[i];
        }
    }
    return NULL;
}

// Free memory used by the 2D array
void free2D(char (*arr)[COLS])
{
    free(arr);
}

// Load text file into an array of arrays
char **loadFileAA(char *filename, int *size)
{
    int CAPACITY = 10;
    FILE *in = fopen(filename, "r");
    if (!in)
    {
        perror("Can't open file");
        exit(1);
    }

    char **arr = malloc(CAPACITY * sizeof(char *));
    if (!arr)
    {
        perror("Memory allocation failed");
        exit(1);
    }

    *size = 0;
    char buffer[1000];

    // Read file line by line
    while (fgets(buffer, sizeof(buffer), in))
    {
        buffer[strcspn(buffer, "\n")] = '\0';  // Trim newline

        if (*size >= CAPACITY)
        {
            CAPACITY *= 2;
            arr = realloc(arr, CAPACITY * sizeof(char *));
            if (!arr)
            {
                perror("Memory reallocation failed");
                exit(1);
            }
        }

        arr[*size] = malloc(strlen(buffer) + 1);
        if (!arr[*size])
        {
            perror("Memory allocation failed");
            exit(1);
        }
        strcpy(arr[*size], buffer);
        (*size)++;
    }

    fclose(in);
    return arr;
}

// Search the array-of-arrays for a substring
char *substringSearchAA(char *target, char **lines, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (strstr(lines[i], target))
        {
            return lines[i];
        }
    }
    return NULL;
}

// Free memory used by the array of arrays
void freeAA(char **arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        free(arr[i]);
    }
    free(arr);
}

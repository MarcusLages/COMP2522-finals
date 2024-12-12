#include "array_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Marcus: I changed the signature to char *** instead of char *[]
// for the string array to handle it better when writing.

// Function to reverse an array of integers
void reverseArray(int *arr, int start, int end) {
    if(arr == NULL) return;

    while(start < end) {
        swap_int(arr + start, arr + end);

        start++;
        end--;
    }
}

// Function to reverse an array of strings
void reverseStringArray(char ***arr, int start, int end) {
    if(arr == NULL || *arr == NULL || **arr == NULL) return;

    while(start < end) {
        swap_str(*arr + start, *arr + end);

        start++;
        end--;
    }
}

// Function to read an array of integers from a file
void readIntArrayFromFile(const char *filename, int *arr, int *size) {
    if(filename == NULL) return;

    FILE *file = open_input_file(filename);
    char curr_line[MAX_LINE_SIZE];
    *size = EMPTY_ARRAY;

    while(fgets(curr_line, MAX_LINE_SIZE, file)) {
        int error;
        int num = get_int_from_line(curr_line, &error);

        if(error == true) break;

        arr[*size] = num;
        (*size)++;
    }

    fclose(file);
    file = NULL;
}

// Function to write an array of integers to a file
void writeIntArrayToFile(const char *filename, int *arr, int size) {
    if(filename == NULL) return;

    FILE *file = open_output_file(filename);

    for(int i = 0; i < size; i++)
        fprintf(file, "%d\n", arr[i]);

    fclose(file);
    file = NULL;
}

// Function to read an array of strings from a file
void readStringArrayFromFile(const char *filename, char ***arr, int *size) {
    if(filename == NULL || arr == NULL) return;

    FILE *file = open_input_file(filename);
    char curr_line[MAX_LINE_SIZE];

    *size = EMPTY_ARRAY;
    *arr = (char **) malloc((*size + 1) * sizeof(char *));

    while(fgets(curr_line, MAX_LINE_SIZE, file)) {
        *arr = (char **) realloc(*arr, (*size + 1) * sizeof(char *));
        (*arr)[*size] = (char *) malloc(MAX_LINE_SIZE * sizeof(char));

        if(*arr == NULL) {
            perror("Error allocating memory for array of strings.");
            exit(EXIT_FAILURE);
        }

        strcpy((*arr)[*size], curr_line);
        (*size)++;
    }

    fclose(file);
    file = NULL;
}

// Function to write an array of strings to a file
void writeStringArrayToFile(const char *filename, char *arr[], int size) {
    if(filename == NULL || arr == NULL) return;

    FILE *file = open_output_file(filename);

    for(int i = 0; i < size; i++)
        fprintf(file, "%s", arr[i]);

    fclose(file);
    file = NULL;
}

int get_int_from_line(char *line, int *error) {
    if(line == NULL || error == NULL) return ERROR_CODE;

    char *error_msg;
    *error = false;
    int i = strtod(line, &error_msg);

    if((*error_msg != '\n') && (*error_msg != '\0' || error_msg == line)) {
        i = ERROR_CODE;
        *error = true;
        errno = 0;  // Resetting errno code.
    }

    return i;
}

void swap_int(int *a, int *b) {
    if(a == NULL || b == NULL) return;

    if(*a == *b) return;

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void swap_str(char **a, char **b) {
    if(a == NULL || b == NULL) return;

    char *temp = *a;
    *a = *b;
    *b = temp;
}

FILE * open_input_file(char *filename) {
    if(filename == NULL) return NULL;

    FILE *file = fopen(filename, "r");
    if(!file) {
        perror("Error: Could not find given input file.\n");
        exit(EXIT_FAILURE);
    }

    return file;
}

FILE * open_output_file(char *filename) {
    if(filename == NULL) return NULL;

    FILE *file = fopen(filename, "w");
    if(!file) {
        perror("Error: Could not open output file.\n");
        exit(EXIT_FAILURE);
    }

    return file;
}

#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H
#include <stdio.h>

#define true    1
#define false   0

#define EMPTY_ARRAY     0
#define ERROR_CODE      -1
#define MAX_LINE_SIZE   99

// Marcus: I changed the signature to char *** instead of char *[]
// for the string array to handle it better when writing.

void reverseArray(int *arr, int start, int end);
void reverseStringArray(char ***arr, int start, int end);
void readIntArrayFromFile(const char *filename, int *arr, int *size);
void writeIntArrayToFile(const char *filename, int *arr, int size);
void readStringArrayFromFile(const char *filename, char ***arr, int *size);
void writeStringArrayToFile(const char *filename, char *arr[], int size);

void swap_str(char **a, char **b);
int get_int_from_line(char *line, int *error);
void swap_int(int *a, int *b);
FILE * open_input_file(char *filename);
FILE * open_output_file(char *filename);

#endif //ARRAY_UTILS_H

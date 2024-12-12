#include <stdio.h>
#include <stdlib.h>

#include "array_utils.h"

int main() {
    int intArray[100];
    char **stringArray;
    int size;

    // Example usage of integer array functions
    readIntArrayFromFile("input_int.txt", intArray, &size);
    reverseArray(intArray, 0, size - 1);
    writeIntArrayToFile("output_int.txt", intArray, size);

    // Example usage of string array functions
    readStringArrayFromFile("input_str.txt", &stringArray, &size);
    reverseStringArray(&stringArray, 0, size - 1);
    writeStringArrayToFile("output_str.txt", stringArray, size);

    // Deallocating stringArray
    for(int i = 0; i < size; i++) {
        free(stringArray[i]);
    }
    free(stringArray);
    stringArray = NULL;

    return 0;
}
 #include <stdio.h>
 #include "sorting.h"

 int main() {
     int array[] = {234, 2, 4, 6, 23, 5, 7, 34, 3};
     insertionSort(array, 9);
     displayArray(array, 9);
 }

 void insertionSort(int *array, size_t size) {
     if(size <= 1) return;

     int key, y;
     for (int x = 1; x < size; x++) {

         key = array[x];
         y = x - 1;
         while (y >= 0 && array[y] > key) {

             array[y + 1] = array[y];
             y = y - 1;
         }
         array[y + 1] = key;
     }
 }

 void displayArray(int *array, size_t size) {
     for(int i = 0; i < size; i++) {
         printf("%d ", array[i]);
     }
 }
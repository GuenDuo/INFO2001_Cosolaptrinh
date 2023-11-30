#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000 

//Sort the array using bubble sort
void bubbleSort(int arr[], int n) {
    int temp, i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Sort the array using selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr_bubble[SIZE], arr_selection[SIZE];
    int i;

    // Initialize the array with random values
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr_bubble[i] = rand() % 1000;
        arr_selection[i] = arr_bubble[i];
    }

    clock_t start, end;
    double cpu_time_used;

    // Measure time for Bubble Sort
    start = clock();
    bubbleSort(arr_bubble, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Thoi gian thuc thi cua Bubble Sort: %f\n", cpu_time_used);

    //Measure time for Selection Sort
    start = clock();
    selectionSort(arr_selection, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Thoi gian thuc thi cua Selection Sort: %f\n", cpu_time_used);

    return 0;
}


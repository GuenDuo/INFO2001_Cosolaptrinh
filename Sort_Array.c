#include <stdio.h>
#include <time.h>

// Bubble Sort
void bubbleSort(int arr[], int n) {
}

// Selection Sort
void selectionSort(int arr[], int n) {
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    clock_t start, end;

    //Measure the time for Bubble Sort
    start = clock();
    bubbleSort(arr1, n);
    end = clock();
    printf("Thoi gian thuc thi cua Bubble Sort: %f giay\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    //Measure the time forSelection Sort
    start = clock();
    selectionSort(arr2, n);
    end = clock();
    printf("Thoi gian thuc thi cua Selection Sort: %f giay\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}

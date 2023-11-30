#include <stdio.h>

//Linear search
int linearSearch(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}

//Binary search
int binarySearch(int arr[], int size, int x) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid; 
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int arr[] = {2, 3, 5, 7, 9, 12, 15, 19, 21};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 7;

    int linearResult = linearSearch(arr, size, x);
    if (linearResult != -1) {
        printf("Tim thay %d tai vi tri %d (Tim kiem tuyen tinh).\n", x, linearResult);
    } else {
        printf("Khong tim thay %d (Tim kiem tuyen tinh).\n", x);
    }

    int binaryResult = binarySearch(arr, size, x);
    if (binaryResult != -1) {
        printf("Tim thay %d tai vi tri %d (Tim kiem nhi phan).\n", x, binaryResult);
    } else {
        printf("Khong tim thay %d (Tim kiem nhi phan).\n", x);
    }

    return 0;
}


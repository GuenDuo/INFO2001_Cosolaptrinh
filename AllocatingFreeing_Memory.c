#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Nhap kich thuoc cua mang: ");
    scanf("%d", &size);

    // Memory Allocation
    int *dynamicArray = (int *)malloc(size * sizeof(int));

    if (dynamicArray == NULL) {
        printf("Khong du bo nho!");
        return 1;
    }

    // Array Elements
    printf("Vui long nhap cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("dynamicArray[%d] = ", i);
        scanf("%d", &dynamicArray[i]);
    }

    // Print Array Elements
    printf("Cac phan tu cua mang la:\n");
    for (int i = 0; i < size; i++) {
        printf("dynamicArray[%d] = %d\n", i, dynamicArray[i]);
    }

    // Freeing Memory
    free(dynamicArray);

    return 0;
}


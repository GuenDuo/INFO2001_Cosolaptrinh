#include <stdio.h>

#define SIZE 5

// Import Array
void nhapMang(int arr[], int size) {
	printf("CHUONG TRINH TRUY CAP VA THAO TAC VOI MANG\n------------------------------------------\n");
    printf("[Vui long nhap cac phan tu cua mang]\n");
    for (int i = 0; i < size; i++) {
        printf("|arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

// Print Array
void inMang(int arr[], int size) {
    printf("\n[Cac phan tu cua mang la]\n");
    for (int i = 0; i < size; i++) {
        printf("|arr[%d] = %d\n", i, arr[i]);
    }
}

// Search Array
int timKiem(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int myArray[SIZE];
    int key, index;
    char tiepTuc = 'y'; // Kh?i t?o bi?n c?

    nhapMang(myArray, SIZE); // Nh?p m?ng
    inMang(myArray, SIZE);   // In m?ng

    while (tiepTuc == 'y' || tiepTuc == 'Y') {
        printf("\n------------------------------------------\nVui long nhap phan tu can tim kiem: ");
        scanf("%d", &key);

        index = timKiem(myArray, SIZE, key); // Tìm ki?m ph?n t?

        if (index != -1) {
            printf("\nPhan tu %d duoc tim thay tai vi tri arr[%d]\n", key, index);
        } else {
            printf("Khong tim thay phan tu %d trong mang!\n", key);
        }

        printf("\n------------------------------------------\nBan co muon tiep tuc tim kiem? (y/n): ");
        scanf(" %c", &tiepTuc); // S? d?ng d?u cách tru?c %c d? lo?i b? ký t? Enter trong b? nh? d?m
    }

    return 0;
}

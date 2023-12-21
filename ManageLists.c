#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[50];
    char author[50];
    float price;
};

int main() {
    int size;
    printf("CHUONG TRINH QUAN LY DANH SACH\n----------------------------------\n");
    printf("Vui long nhap so luong sach: ");
    scanf("%d", &size);

    // Allocate Memory for Book
    struct Book *library = (struct Book *)malloc(size * sizeof(struct Book));

    if (library == NULL) {
        printf("Khong du bo nho!");
        return 1;
    }

    // Book Information
    struct Book *temp = library; // Con tr? t?m d? duy?t m?ng
    for (int i = 0; i < size; i++) {
        printf("\nNhap thong tin cho cuon sach thu %d:\n", i + 1);
        printf("|Ten sach: ");
        scanf("%s", temp->title);
        printf("|Tac gia: ");
        scanf("%s", temp->author);
        printf("|Gia sach[$]:");
        scanf("%f$", &temp->price);
        temp++; // Di chuy?n con tr? d?n ph?n t? ti?p theo
    }

    // Display Book Information
    printf("\nThang tin cac sach:\n----------------------------------\n");
    temp = library; // Ð?t l?i con tr? d? duy?t t? d?u
    for (int i = 0; i < size; i++) {
        printf("\nCuon sach %d:\n", i + 1);
        printf("|Ten sach: %s\n", temp->title);
        printf("|Tac gia: %s\n", temp->author);
        printf("|Gia sach:$%.2f\n", temp->price);
        temp++;
    }

    // Freeing Memory
    free(library);

    return 0;
}


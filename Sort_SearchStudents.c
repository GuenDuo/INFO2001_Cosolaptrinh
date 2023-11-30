// 2.SAP XEP VA TIM KIEM SINH VIEN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student structure
struct Student {
    char ID[20];
    char FullName[100];
    int Age;
    float Grade;
};

// Display student information
void displayStudent(struct Student student) {
    printf("Ma so sinh vien: %s\n", student.ID);
    printf("Ten sinh vien: %s\n", student.FullName);
    printf("Tuoi: %d\n", student.Age);
    printf("Diem so: %.2f\n", student.Grade);
    printf("\n");
}

// Compare names between students
int compareByName(const void *a, const void *b) {
    return strcmp(((struct Student *)a)->FullName, ((struct Student *)b)->FullName);
}

// Compare scores between students
int compareByGrade(const void *a, const void *b) {
    return (((struct Student *)a)->Grade > ((struct Student *)b)->Grade) ? 1 : -1;
}

// Search for students by name
void searchByName(struct Student students[], int numStudents, char searchName[]) {
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].FullName, searchName) == 0) {
            printf("\nSinh vien duoc tim thay:\n------------------------------\n");
            displayStudent(students[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("\nKhong tim thay du lieu sinh vien!\n");
    }
}

// Search students by ID
void searchByID(struct Student students[], int numStudents, char searchID[]) {
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].ID, searchID) == 0) {
            printf("\nSinh vien duoc tim thay:\n------------------------------\n");
            displayStudent(students[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("\nKhong tim thay du lieu sinh vien!\n");
    }
}

int main() {
    int numStudents;
    int option;
    printf("CHUONG TRINH SAP XEP & TIM KIEM SINH VIEN\n-----------------------------------------\n");
    printf("Nhap vao so luong sinh vien trong danh sach: ");
    scanf("%d", &numStudents);
    struct Student students[numStudents];

    // Enter student information
    for (int i = 0; i < numStudents; i++) {
        printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
        printf("Ma sinh vien: ");
        scanf("%s", students[i].ID);
        printf("Ten sinh vien: ");
        scanf(" %[^\n]s", students[i].FullName);
        printf("Tuoi: ");
        scanf("%d", &students[i].Age);
        printf("Diem so: ");
        scanf("%f", &students[i].Grade);
    }

    // Display student information
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        displayStudent(students[i]);
    }

    // Options
    while (1) {
    	printf("----------------------------------------\nSAP XEP HOAC TIM KIEM SINH VIEN\n");
        printf("\nVui long lua chon:\n1. Sap xep theo ten\n2. Sap xep theo diem\n3. Tim kiem sinh vien theo ten\n4. Tim kiem sinh vien theo ID\n5. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                qsort(students, numStudents, sizeof(struct Student), compareByName);
                printf("\nDanh sach sau khi duoc sap xep theo ten:\n--------------------------------\n");
                for (int i = 0; i < numStudents; i++) {
                    printf("\nSinh vien thu %d:\n", i + 1);
                    displayStudent(students[i]);
                }
                break;
            case 2:
                qsort(students, numStudents, sizeof(struct Student), compareByGrade);
                printf("\nDanh sach sau khi duoc sap xep theo diem so:\n------------------------------\n");
                for (int i = 0; i < numStudents; i++) {
                    printf("\nSinh vien thu %d:\n", i + 1);
                    displayStudent(students[i]);
                }
                break;
            case 3:
                printf("Nhap ten sinh vien de tim kiem: ");
                char searchName[100];
                scanf(" %[^\n]s", searchName);
                searchByName(students, numStudents, searchName);
                break;
            case 4:
                printf("Nhap ma so sinh vien de tim kiem: ");
                char searchID[20];
                scanf("%s", searchID);
                searchByID(students, numStudents, searchID);
                break;
            case 5:
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    }

    return 0;
}


//1. QUAN LY DANH SACH SINH VIEN
#include <stdio.h>

//Structure Student
struct Student {
	char Id[6];
    char FirstName[30];
    char LastName[30];
    int Age;
    float Grade;
};

// Displays information of a student
void displayStudent(struct Student student) {
	printf("Ma sinh vien: %s\n", student.Id);
    printf("Ho va ten: %s %s\n", student.FirstName, student.LastName);
    printf("Tuoi: %d\n", student.Age);
    printf("Diem so: %.2f diem\n", student.Grade);
    printf("\n");
}

int main() {
    int numStudents;
    printf("CHUONG TRINH QUAN LY DANH SACH SINH VIEN\n----------------------------------------\n");
    printf("Nhap so luong sinh vien trong danh sach: ");
    scanf("%d", &numStudents);

    // Declare the students0
    struct Student students[numStudents];

    // Enter information for each student
    for (int i = 0; i < numStudents; i++) {
        printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
        printf("Ma sinh vien ");
        scanf("%s", students[i].Id);
        printf("Ho: ");
        scanf("%s", students[i].FirstName);
        printf("Ten: ");
        scanf("%s", students[i].LastName);
        printf("Tuoi: ");
        scanf("%d", &students[i].Age);
        printf("Diem so: ");
        scanf("%f", &students[i].Grade);
    }

    // Display information for each student before updating
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        displayStudent(students[i]);
    }

    // Update student information
    printf("\nCap nhat thong tin sinh vien trong danh sach:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nCap nhat thong tin cho sinh vien thu %d:\n", i + 1);\
        printf("Ma sinh vien moi: ");
        scanf("%s", students[i].Id);
        printf("Ho moi: ");
        scanf("%s", students[i].FirstName);
        printf("Ten moi: ");
        scanf("%s", students[i].LastName);
        printf("Tuoi moi: ");
        scanf("%d", &students[i].Age);
        printf("Diem so moi: ");
        scanf("%f", &students[i].Grade);
    }

    //Display updated student information
    printf("\nDanh sach sinh vien sau khi cap nhat:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        displayStudent(students[i]);
    }

    return 0;
}


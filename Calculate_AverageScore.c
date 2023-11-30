#include <stdio.h>
#define MAX_STUDENTS 50

int main() {
    int numStudents;
    float grades[MAX_STUDENTS];
    float total = 0.0, average;
    
    printf("CHUONG TRINHG TINH DIEM TRUNG BINH CUA LOP\n____________________________________\n");
    printf("Vui long nhap so luong hoc sinh: ");
    scanf("%d", &numStudents);

    //Enter scores for students and calculate scores
    for (int i = 0; i < numStudents; i++) {
        printf("\nNhap diem cho hoc sinh thu %d: ", i + 1);
        scanf("%f", &grades[i]);

        //Calculate total score
        total += grades[i];
    }

    //Calculate average score
    average = total / numStudents;

    printf("\nDiem trung binh cua ca lop: %.2f\n", average);

    return 0;
}


//3. QUAN LY NHAN SU
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

//Employee structure
struct Employee {
    int ID;
    char Name[50];
    char Position[50];
    float Salary;
};

// Declare Employee
struct Employee employees[MAX_EMPLOYEES];

int numEmployees = 0; //Number of employees displayed

//Add an employee
void addEmployee() {
    if (numEmployees >= MAX_EMPLOYEES) {
        printf("KHONG THE THEM NHAN VIEN MOI. DA VUOT QUA SO LUONG TOI DA!\n");
        return;
    }

    struct Employee newEmployee;

    printf("------------------------------\nNhap ma nhan vien: ");
    scanf("%d", &newEmployee.ID);
    printf("Nhap ten nhan vien: ");
    scanf(" %[^\n]s", newEmployee.Name);
    printf("Nhap chuc vu: ");
    scanf(" %[^\n]s", newEmployee.Position);
    printf("Nhap luong: ");
    scanf("%f", &newEmployee.Salary);

    employees[numEmployees] = newEmployee;
    numEmployees++;
    printf("DA THEM NHAN VIEN MOI!\n");
}

//Display employee information
void displayEmployees() {
    if (numEmployees == 0) {
        printf("\nKHONG CO NHAN VIEN NAO DE HIEN THI!\n");
        return;
    }

    printf("Danh sach nhan vien:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("\nMa nhan vien: %d\n |Ten: %s\n |Chuc vu: %s\n |Luong: %.2f\n",
               employees[i].ID, employees[i].Name, employees[i].Position, employees[i].Salary);
    }
}

//Sort employees by name
void sortEmployeesByName() {
    if (numEmployees == 0) {
        printf("\nKHONG CO NHAN VIEN NAO DE SAP XEP!\n");
        return;
    }

    struct Employee temp;
    for (int i = 0; i < numEmployees - 1; i++) {
        for (int j = i + 1; j < numEmployees; j++) {
            if (strcmp(employees[i].Name, employees[j].Name) > 0) {
                temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }

    printf("DA SAP XEP NHAN VIEN THEO TEN!\n");
}

//Delete employee
void deleteEmployee(int employeeID) {
    int found = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].ID == employeeID) {
            found = 1;
            for (int j = i; j < numEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            numEmployees--;
            printf("DA XOA NHAN VIEN CO MA NHAN VIEN %d\n", employeeID);
            break;
        }
    }
    if (!found) {
        printf("KHONG TIM THAY NHAN VIEN CO MA NHAN VIEN %d\n. VUI LONG THU LAI!", employeeID);
    }
}

int main() {
    int choice, idToDelete;

    while (1) {
    	printf("\nCHUONG TRINH QUAN LY NHAN SU\n------------------------------");
        printf("\nVui long chon mot chuc nang:\n");
        printf("1. Them nhan vien\n");
        printf("2. Hien thi danh sach nhan vien\n");
        printf("3. Sap xep nhan vien theo ten\n");
        printf("4. Xoa nhan vien\n");
        printf("5. Thoat\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                sortEmployeesByName();
                break;
            case 4:
                printf("Nhap ma nhan vien can xoa: ");
                scanf("%d", &idToDelete);
                deleteEmployee(idToDelete);
                break;
            case 5:
                exit(0);
            default:
                printf("CHUC NANG KHONG HOP LE. VUI LONG THU LAI!\n");
        }
    }

    return 0;
}


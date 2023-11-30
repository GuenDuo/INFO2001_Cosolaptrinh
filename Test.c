#include <stdio.h>
struct Student {
char name[50];
int id;
int age;
float grade;
};
int main() {
struct Student s;
printf("Nhap thong tin sinh vien:\n");
printf("Nhap ten: ");
fgets(s.name, sizeof(s.name), stdin);
printf("Nhap ma so: ");
scanf("%d", &s.id);
printf("Nhap tuoi: ");
scanf("%d", &s.age);
printf("Nhap diem: ");
scanf("%f", &s.grade);
printf("\nThong tin sinh vien:\n");
printf("Ten: %s", s.name);
printf("Ma so: %d\n", s.id);
printf("Tuoi: %d\n", s.age);
printf("Diem: %.2f\n", s.grade);
return 0;
}

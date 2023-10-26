#include <stdio.h>

struct student {
    char name [200];
    char student_id [11]; // Assuming 10 digits.
    int mark;
};

int main () {
    struct student new_student = {"Name Surname", "28932123", 35};
    struct student student2 = {"Mila Ford", "201660773", 50};
    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %d\n", new_student.mark);
    printf("Student name: %s\n", student2.name);
    printf("Student ID:   %s\n", student2.student_id);
    printf("Final mark:   %d\n", student2.mark);

    struct student student3;

    printf("\nPlease enter the student's full name:   ");
    scanf("%s", student3.name);
    printf("Please enter the student's ID:    ");
    scanf("%s", student3.student_id);
    printf("Please enter the student's mark:   ");
    scanf("%d", &student3.mark);
    printf("\nStudent name: %s\n", student3.name);
    printf("Student ID:   %s\n", student3.student_id);
    printf("Final mark:   %d\n", student3.mark);
    return 0;
}
//Grade Checker with Distinction: Write a program to check if a student has passed, failed, or achieved a distinction based on an input mark (pass mark is 50, distinction is 70).

# include <stdio.h>

int main() {
    int inputMark;
    printf("please enter the students mark: \n");
    scanf("%d", &inputMark);

    if (inputMark >= 0 && inputMark <= 100)
    {
        if (inputMark >= 70)
        {
            printf("At %d, this student achieved a distinction!\n", inputMark);
        }
        else if (inputMark >= 50)
        {
            printf("At %d, this student has passed\n", inputMark);
        }
        else
        {
            printf("At %d, this student has failed\n", inputMark);
        }
    }
    else
    {
        printf("sorry, %d is outside the mark range\n", inputMark);
    }
    return 0;
}
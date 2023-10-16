//Positive, Negative, or Zero: Write a program to check if a number is positive, negative, or zero.

#include <stdio.h>

int main() {
    // assigns the number a value
    int num = -97;

    // checks if number is zero
    if (num == 0)

    {
        printf("The number %d is zero\n", num);
    }

    else if (num > 0)

    {
        printf("The number %d is positive\n", num);
    }

    else if (num < 0)

    {
        printf("The number %d is negative\n", num);
    }
    else

    {
        printf("aaa??");
    }
    return 0;
}
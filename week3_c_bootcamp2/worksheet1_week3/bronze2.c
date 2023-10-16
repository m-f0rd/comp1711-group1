// Divisible by 4 and 5: Write a program to check if a number is divisible by both 4 and 5.


#include <stdio.h>

int main() {
    int num = 40;

    int res4 = num % 4;
    int res5 = num % 5;
    if (res5 == 0 && res4 == 0)
    {
        printf("The number %d is divisible by both 4 and 5!\n", num);
    }
    else
    {
        printf("The number %d is not divisible by both 4 and 5\n", num);

    }
    return 0;
}
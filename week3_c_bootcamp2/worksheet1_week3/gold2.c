//Input Validation Loop with Termination Value: Write a program that continuously asks the user for a number until they enter a termination value of -1. 
//The program should validate if the number is within the range of 0 to 100 or if it’s the termination value, and print a message accordingly

#include <stdio.h>

int main() {
    int userNum;
    int cond = 1;
    while (cond == 1)
    {
        printf("Can you input a number: \n");
        scanf("%d",userNum);

        if (userNum == -1)
        {
            printf("program terminated\n");
            cond = 0;
        }
        else if (userNum >= 0 && userNum <= 100)
        {
            printf("The number %d is within range!\n", userNum);
        }
        else
        {
            printf("sorry, %d is out of range\n", userNum);
        }
    }
    return 0;
}
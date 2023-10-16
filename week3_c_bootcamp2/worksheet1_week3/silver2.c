//Temperature Range Validator: Write a program to validate if a temperature is within the range of -10 to 40 degrees Celsius.

#include <stdio.h>

int main () {
    float temp = 30;
    if (temp >= -10 && temp <= 40)
    {
        printf("the temperature %.3f is between the range -10 and 40 degrees Celsius\n", temp);
    }
    else
    {
        printf("the temperature %.3f is not between the range -10 and 4 degrees celsius\n", temp);
    }
    return 0;
}
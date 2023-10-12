#include <stdio.h>

int main() {
    int a;
// while a is less than five, starting at 0, going up by 1 each loop
    for (a = 0; a < 5; a++) //a++ is the same as a=a+1, you could write a+=2 to go up in twos
    {// print that a is equal to the number of loop 
        printf ("a is equal to %d\n", a);
    }
    printf ("I've finished the loop and a is equal to %d\n", a);

    return (0);
}
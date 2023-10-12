#include <stdio.h>

int main() {
    int a = 0;

    while (a > 2 && a < 50 || a!= 5 )
    {
        printf ("a is equal to %d\n", a);
        a+=2; // assigned after it was printed
    }
    printf ("I've finished the loop and a is equal to %d\n", a);

    return (0);
}
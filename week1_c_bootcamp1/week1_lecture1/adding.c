#include <stdio.h>
int main() {
    float a;
    float b = 3.641;
    float c; // changed this from int to float

    a = 2.897;
    c = a + b;

    printf("The sum of adding %f and %f is %f\n", a, b, c); //changed the final format specifier to %f from %d

    return 0;
}
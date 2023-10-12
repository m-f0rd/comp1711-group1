#include <stdio.h>

int main() {
  //  int a, b, c;
    int a = 1;
    int b = 1;
    int c;
    for (a = 1; a < 13; a++)
    {
        for (b = 1; b < 13; b++)
        {
            c = a*b;
            printf("%d x %d = %d\n", a,b,c);
        }
    }
    

    return (0);
}
#include <stdio.h>

int main() {

    int array[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int counter;
    for (counter = 0; counter < 12; counter++) {
        printf("%d\n", array[counter]);
    }
    
    return (0);
}
#include <stdio.h>
int main() {

// define all varable on the same line since they are the same type
    float width, height, area;

    printf("Hello, please enter the width of the rectangle: ");
    scanf("%f", &width);
    printf("Now please enter the height of the rectangle: ");
    scanf("%f", &height);

    area = width * height;

    printf("The area of your rectangle is %.2f units squared\n", area); // %.2f is to 2.d.p
    
}
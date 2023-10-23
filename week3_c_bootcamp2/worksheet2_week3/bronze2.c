// Question 2: Calculate Volume of a Sphere Write a function that takes a float radius and returns the volumeof a sphere with that radius
#include <stdio.h>
 
float volume_of_circle (float rad)
{
    float volume;
    volume = ((4*rad*rad*rad*3.14159265359)/3);
    return volume;
}


int main() 
{
    // Write C code here
    float radius;
    printf("Please enter the radius of the circle");
    scanf("%f", &radius);
    printf("The volume of the circle is %.3f to 3.d.p\n", volume_of_circle(radius));

    return 0;
}
// Question1:CalculateAreaofaCircleWriteaCprogramthatdefinesafunctioncircleAreawhichtakesa floatradiusasaparameterandreturnstheareaofthecircle.Testthisfunctioninyourmainfunction. 
#include <stdio.h>
 
float area_of_circle (float rad)
{
    float area;
    area = (rad*rad*3.14159265359);
    return area;
}


int main() 
{
    // Write C code here
    float radius;
    printf("Please enter the radius of the circle");
    scanf("%f", &radius);
    printf("The area of the circle is %.3f to 3.d.p\n", area_of_circle(radius));

    return 0;
}
#include <stdlib.h>
#include <stdio.h>

void func(int *input)
{
    *input = 102;
}

int main()
{
    printf("An int is size: %ld\n", sizeof(int));
    printf("A double is size: %ld\n", sizeof(double));
    printf("A character is size: %ld\n", sizeof(char));
    char* name = "Johnathan";
    printf("The word %s is size: %ld\n", name, sizeof(name));

    char* address = malloc(200*sizeof(char));
    int* data = malloc(70*sizeof(int)); // can access them like 
    data[0] = 2;

    int count;
    printf("Enter the number of values: \n");
    scanf("%d", &count);
    double* samples = malloc(count*sizeof(double));

    int x = 3;

    func(&x);
    printf("%d\n", x);
    // int x[5];
    // void *y = malloc( 5 * sizeof(int));
    free(address);
    free(data);
    free(samples);
}
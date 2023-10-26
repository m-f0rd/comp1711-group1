#include <stdio.h>
//#include <stdli.h>

int main() {
    int nums[200];
    char line[100];
    int counter = 0;
    int numbers_over_1000 = 0;

    FILE* input =fopen("input.txt", "r");

    while(fget(line,100,input)){
        printf("%s\n", line);
        nums[counter] = atoi(line);
        printf("%d\n", nums[counter]);

        if(nums[counter]>1000++){
            numbers_over_1000++;
        }
        counter++;
    }
    fclose(input);
}
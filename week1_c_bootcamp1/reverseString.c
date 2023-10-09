#include <stdio.h>
#include<string.h>
int main() {

//define the empty strings
    char stringA[15];
    char stringB[15];

// request user for stringA
    printf("Please enter your string: ");
// scan and store user string
    scanf("%s", stringA);

// find length of the string 
    int length = 0;
    length = strlen(stringA);

    int i;

    for (i = length - 1; i >= 0; i--) {
        printf("%d\n", i);
        printf("%c", stringB[i]);
}


    printf("The string '%s' backwards is %s\n", stringA, stringA);
}
// Question 3: String Length Function Write a function str_len that takes a string as a parameter and returnsits length. Do not use the standard librarys strlen function. Test your function in main.Hint: A string is an array of characters. The last character in a string is \0. Loops and pointers will be useful here
#include <stdio.h>
 
int str_len (char inp_str)
{
    int i = 0;
    int length = 0;
    char letter;
    
    while (letter =! "\0")
    {
        letter = inp_str[i];
        printf("\nthe %i th letter is %s",i, letter);
        length+=1;
    }
    
    return length;
}


int main() 
{
    // Write C code here
    char stringy [100];
    printf("Please enter your string");
    scanf("%s", stringy);
    printf("The length of the string is %d \n", str_len(stringy));

    return 0;
}
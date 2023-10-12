#include <stdio.h>

int main() {
    int a = 0;

    int hiddenNumber = 69;
    int guess;
    while (guess != hiddenNumber)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        if (guess < hiddenNumber) {
            printf("Hint, the hidden number is greater than %d\n ", guess);
        } else if (guess > hiddenNumber) {
            printf("Hint, the hidden number is less than %d\n ", guess);
      }
            
    }
    printf ("Correct, the hidden number was %d\n", guess);

    return (0);
}
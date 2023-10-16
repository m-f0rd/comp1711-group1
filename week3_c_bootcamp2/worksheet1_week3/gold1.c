// 5. Advanced Menu System: Create a menu system using a SWITCH statement that allows the user to select between 5 options. Include an error message for invalid choices.

#include <stdio.h>

int main () {
    int menuOpt;
    printf("please enter your menu option, from 1-5\n");
    scanf("%d",&menuOpt);

    switch (menuOpt)
    {
        case 1: printf("You have selected option 1!\n");
        break;
        
        case 2: printf("You have selected option 2!\n");
        break;

        case 3: printf("You have selected option 3!\n");
        break;

        case 4: printf("You have selected option 4!\n");
        break;

        case 53: printf("You have selected option 5!\n");
        break;

        default: printf("You haven't selected one of the valid options :(( \n");
    }
}

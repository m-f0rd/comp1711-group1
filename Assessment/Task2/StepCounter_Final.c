#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
int main() {
   /**
    * my plan:
    * have a switch for the menu options
    * 
    * A: Specify the filename to be imported (we will give you some additional files to test with). This should have some error checking so that the program can cope with an incorrect filename and a file that is of an unexpected format.
    *       input the code from today about if filename not found return error message
    * B: Display the total number of records in the file
    * C: Find the date and time of the timeslot with the fewest steps
    * D: Find the data and time of the timeslot with the largest number of steps    
    * E: Find the mean step count of all the records in the file
    * F: Find the longest continuous period where the step count is above 500 steps
   */

  char menuOpt[3];
    printf("please enter your menu option, from A-F\n");
    scanf("%s",&menuOpt);

    switch (menuOpt) ///NOT WORKING, USE CODE.C FROM WEEK 7
    {
"""
        printf("\nPlease enter one of the following menu options\n\n");

        printf("A: View all your blood iron levels\n");                       // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your highest blood iron level\n");                     // SILVER
        printf("D: View your lowest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

        
// get the next character typed in and store in the 'choice'
    choice = getchar();

    // this gets rid of the newline character which the user will enter
    // as otherwise this will stay in the stdin and be read next time
    while (getchar() != '\n');


    // switch statement to control the menu.
    switch (choice)
    {
    // this allows for either capital or lower case
    case 'A':
    case 'a':

  """  
        case 'A': printf("Specify the filename to be imported\n");
        break;
        
        case 'B': printf("Display the total number of records in the file\n");
        break;

        case 'C': printf("Find the date and time of the timeslot with the fewest steps\n");
        break;

        case 'D': printf("Find the date and time of the timeslot with the largest number of steps\n");
        break;

        case 'E': printf("Find the mean step count of all the records in the file\n");
        break;
        
        case 'F': printf("Find the longest continuous period where the step count is above 500 steps\n");
        break;

        case 'Q': printf("Quit\n");
        break;

        default: printf("Invalid choice. Try again.\n");
    }
}
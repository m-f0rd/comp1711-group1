#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
FITNESS_DATA file_record[300];

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
    float lowest = 9999999999;
    int low;
    float highest = -9999999999;
    int high;
    float mean = 0;
    int total = 0;
    FITNESS_DATA file_record[300];
    char line_buffer[buffer_size];
    int record_counter = 0;
    char filename[buffer_size];
    char menuOpt;
    while (1)
    {

        
        printf("\n\nMenu Options: --------------------------------------\n\n");

        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n"); 
        printf("Q: Exit the program\n\n");
        printf("Enter choice: ");

            
    // get the next character typed in and store in the 'menuOpt'
        menuOpt = getchar();
        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');


        // switch statement to control the menu.
        switch (menuOpt)
        {
        // this allows for either capital or lower case

        case 'A': // DONE -------------------------
        case 'a': // Specify the filename to be imported
            printf("Input filename: ");
            fgets(line_buffer, buffer_size, stdin);
            sscanf(line_buffer, " %s ", filename);


            // if (!(open_file(filename))){ //calls on function that i have given up on
            //     printf("nononon");
            //     return 0;
            // }
            FILE *file = fopen(filename, "r");
                if (file == NULL) {
                    perror("");
                    printf("Error: Could not find or open the file.\n");

                    return 1;
                }
            char date_temp[11];
            char time_temp[6];
            char steps_temp[10];

                    
            while (fgets(line_buffer, buffer_size, file) != NULL) {

                tokeniseRecord(line_buffer,",", date_temp, time_temp, steps_temp);

                strcpy(file_record[record_counter].date, date_temp);
                strcpy(file_record[record_counter].time, time_temp);
                strcpy(file_record[record_counter].steps, steps_temp);
                //file_record[record_counter].steps= atoi(steps_temp);

                record_counter+=1;
            }
            fclose(file);
            printf("File successfully loaded.");

            break;
        
        case 'B': // DONE -------------------------
        case 'b': // Display the total number of records in the file DONE
            printf("Total records %d\n", record_counter);
            break;

        case 'C': // DONE -------------------------
        case 'c':// Find the date and time of the timeslot with the fewest steps
            
            for (int i = 0; i < record_counter; i++)
            {
                if (lowest > atoi(file_record[i].steps))
                {
                    lowest = atoi(file_record[i].steps);
                    low = i;
                }
            }

            printf("Fewest steps: %s %s", file_record[low].date, file_record[low].time );
            break;

        case 'D': // DONE -------------------------
        case 'd': // Find the date and time of the timeslot with the largest number of steps
            for (int i = 0; i < record_counter; i++)
            {
                if (highest < atoi(file_record[i].steps))
                {
                    highest = atoi(file_record[i].steps);
                    high = i;
                }
            }
            printf("Largest steps: %s %s", file_record[high].date, file_record[high].time );
            break;

        case 'E': // DONE ------------------------------------------
        case 'e': // Find the mean step count of all the records in the file
            for (int i = 0; i < record_counter; i++)
            {
                total += atoi(file_record[i].steps);
            }
            mean = total/record_counter;
            printf("Mean step count: %.0f", mean);
            break;
        
        case 'F': // Find the longest continuous period where the step count is above 500 steps
        case 'f':
            for (int i = 0; i < record_counter; i++)
            {
                if (500 < atoi(file_record[i].steps))
                {
                    highest = atoi(file_record[i].steps);
                    high = i;
                }
            }

            printf("Longest period start: ");
            printf("Longest period end: ");
            break;

        case 'Q': // Quit
        case 'q':
            printf("Choise q was chosen\n");
            return 0;
            break;

        default: // Invalid choice. Try again.
            printf("Invalid choice. Try again.\n");

        }
    }
}
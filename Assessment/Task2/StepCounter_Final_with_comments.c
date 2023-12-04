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
    float mean_f = 0;
    int mean = 0;
    int total = 0;
    // F 
    int tally = 0; // temporary chain of over 500
    int longest_chain; // permanent (current highest) longest chain
    int start_date_pos_check; // temporary location for the start date position
    int start_date_pos_store; // permanent location for the (current highest) start date position
    


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
            // delete
            printf("\nRecord counter = %d", record_counter);
            printf("\nFinal record %s %s\n\n", file_record[record_counter].date, file_record[record_counter].time);
            for (int i = 0; i < record_counter; i++)
            {
                printf("\nRecord number %d - date: %s",i,  file_record[i].date);
            }
            // delete
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
            mean_f = total/record_counter;
            mean = mean_f + 0.5; // adds 0.5 then converts to int so it is rounded
            printf("Mean step count: %d", mean);
            break;
        
        case 'F': // Find the longest continuous period where the step count is above 500 steps
        case 'f':
            for (int i = 0; i <= record_counter; i++) // <= otherwise it wont register the last chain if it ends at n
            {
                if (500 < atoi(file_record[i].steps)) // if record is above 500
                {

                    if (tally == 0) // if this is the start of a new chain
                    {
                        start_date_pos_check = i; // start date location is i
                        tally += 1;
                        printf("\n\nThis is the start location and step value: %d with steps %d \n", i, atoi(file_record[i].steps) );
                    }
                    else // if this isnt the start of a new chain aka 2nd/3rd etc item in chain
                    {
                        tally += 1;
                        printf("location and step value: %d with steps %d \n", i, atoi(file_record[i].steps) );

                    }
                    
                }
                else
                {
                    if (tally > longest_chain) // if the chain just checked is longer than the longest chain
                    {
                        longest_chain = tally;
                        start_date_pos_store = start_date_pos_check;
                        tally = 0;

                    } //else keep as is
                    else
                    {
                        tally = 0;
                    }
                }
                //delete
                if (i == record_counter)
                {
                    printf("\nhehehehehehe\n");
                }
                if (i == 59)
                {
                    printf("\nhohohohohho\n");
                }
                if (i == 58)
                {
                    printf("\nhahahahahah\n");
                }
                // delete
            }
            //delete
            printf("This is the longest chain: %d and this is the start date location %d", longest_chain, start_date_pos_store);
            // delete
            printf("\nLongest period start: %s %s", file_record[start_date_pos_store].date, file_record[start_date_pos_store].time);
            printf("\nLongest period end: %s %s", file_record[start_date_pos_store + longest_chain - 1].date, file_record[start_date_pos_store + longest_chain - 1].time);
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
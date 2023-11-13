#include "utilities.h"

int main()
{
    // array of daily readings
    reading daily_readings[100];

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice;
    int counter = 0;
    float mean = 0;
    float total = 0;

    //new
    float highest = -100;
    float lowest = 1000;
    // new end
    while (1)
    {
        FILE *input = fopen(filename, "r");
        if (!input)
        {
            printf("Error: File could not be opened\n");
            return 1;
        }
        printf("\nPlease enter one of the following menu options\n\n");

        printf("A: View all your blood iron levels\n");                       // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your highest blood iron level\n");                     // SILVER
        printf("D: View your lowest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

// new ----------------
        counter = 0;
        while (fgets(line, buffer_size, input))
        {
            // split up the line and store it in the right place
            // using the & operator to pass in a pointer to the bloodIron so it stores it
            tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
            counter++;
            printf("E");
        }
        int num_records=counter;
        fclose(input);
//new end ----------------

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
            // counter = 0;
            // while (fgets(line, buffer_size, input))
            // {
            //     // split up the line and store it in the right place
            //     // using the & operator to pass in a pointer to the bloodIron so it stores it
            //     tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
            //     counter++;
            // }
        
            for (int i = 0; i < num_records; i++)
            {
                printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
            }
            //fclose(input); PROBLEM CHILD
            break;

        case 'B':
        case 'b':
            // counter = 0;
            // while (fgets(line, buffer_size, input))
            // {
            //     // split up the line and store it in the right place
            //     // using the & operator to pass in a pointer to the bloodIron so it stores it
            //     tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
            //     total += daily_readings[counter].bloodIron;
            //     printf("total is: %.2f\n", total);
            //     printf("\n AAAAAAAAAAAAAAAAAAAAAAAAAA \n");
            //     counter++;
            // }
            for (int i = 0; i < num_records; i++)
            {
                total += daily_readings[i].bloodIron;
                //printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
            }
            mean = total/counter;
        //    printf("total is %.2f and counter is %d", total, counter);
            printf("Your average blood iron was %.2f\n", mean);
         //   fclose(input);
            break;

        case 'C':
        case 'c':
        //DONE - Find the reading with the highest blood iron level, and print it out for the user. Hint: a loop will be required.
            for (int i = 0; i < counter; i++)
            {
                // printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
                // printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
                if (highest < daily_readings[i].bloodIron)
                {
                    highest = daily_readings[i].bloodIron;
                }
            }
            printf("Your highest blood iron was %.2f\n", highest);
            return 0;
            break;

        case 'D':
        case 'd':
        //Find the reading with the lowest blood iron level, and print it out for the user.
            for (int i = 0; i < counter; i++)
            {
                // printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
                // printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
                if (lowest > daily_readings[i].bloodIron)
                {
                    lowest = daily_readings[i].bloodIron;
                }
            }
            printf("Your lowest blood iron was %.2f\n", lowest);        
           // return 0;
            break;

        case 'E':
        case 'e':

//         You may want to use the `<string.h>` function `strstr()` for this. You can use the `man` command in the terminal to see more for this.

// You should:
// - ask the user for the month (in the same format as in the data file)
// - check each date string to see if there is a match
// - print out the record if there is.

            return 0;
            break;

        case 'F':
        case 'f':
            return 0;
            break;

        case 'G':
        case 'g':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
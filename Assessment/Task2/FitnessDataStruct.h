#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// declaring this value so I can use it in different places
#define buffer_size 40

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[10];
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);



/**
 * @brief Opens the file in the correct mode
 *
 * @param filename the name of the file to open
 * @param mode the mode (r/w/a/r+/w+/a+)
 * @return FILE* The file object to store the opened file in.
 */
int open_file(char *filename)
{
	// FILE *file = fopen(filename, "r");
    //     if (file == NULL)
    //     {
	// 		perror("");
    //         printf("Error: Could not find or open the file.\n");
	// 		return 0;
    //     }
    // // to do
	// //read_file(file, )
	// fclose(file);
}




/**
 * @brief Reads the data from the input file into an array of structs
 *
 * @param inputFile the open file object
 * @param dataArray the array of readings
 * @return int Returns the number of readings from the file
 */
int read_file(FILE *inputFile, FITNESS_DATA *dataArray)
{
	// char date_temp[11];
    // char time_temp[6];
    // char steps_temp[10];
    // while (fgets(line_buffer, buffer_size, file) != NULL) {

    //     tokeniseRecord(line_buffer,",", date_temp, time_temp, steps_temp);

    //     strcpy(file_record[record_counter].date, date_temp);
    //     strcpy(file_record[record_counter].time, time_temp);
    //     strcpy(file_record[record_counter].steps, steps_temp);
    //     //file_record[record_counter].steps= atoi(steps_temp);

    //     record_counter+=1;
    // }
}


#endif // FITNESS_DATA_STRUCT_H
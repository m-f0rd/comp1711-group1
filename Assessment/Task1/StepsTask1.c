#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[10];
} FITNESS_DATA;

// Define any additional variables here



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
    
    FITNESS_DATA file_record[300];
    int buffer_size = 40;
    char line_buffer[buffer_size];
    int record_counter = 0;

    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
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

    printf("Number of records in file: %d\n", record_counter);


    for (int i = 0; i<3;i++){
        printf("%s/%s/%d\n", file_record[i].date, file_record[i].time, atoi(file_record[i].steps) );
    }
    return 0;



}
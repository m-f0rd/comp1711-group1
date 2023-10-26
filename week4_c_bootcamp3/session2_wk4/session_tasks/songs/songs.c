#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Holds the data for a song such as artist, title and year.
 *
 */
typedef struct
{
    int position;
    char artist[100];
    char title[100];
    char year[4];
} SONG_DATA;

/** tokenised record
 * @brief Splits a line from song_data.txt into the separate data. This is adapted from the coursework code.
 *
 * @param input the line which will be split /the line from the file
 * @param delimiter the character which deliminates (splits up) the data (in this case, a comma)
 * @param pos a pointer to where it should store the position
 * @param artist a pointer to where it should store the artist
 * @param title a pointer to where it should store the title
 * @param years a pointer to where it should store the years
 */

// this is basically line.split() in python. but 
void tokeniseRecord(const char *input, const char *delimiter,
                    char *pos, char *artist, char *title, char *years)
{
    // Create a copy of the input string as strtok modifies the string / DW ABOUT THIS
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(pos, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(artist, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(title, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(years, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

int main()
{
    SONG_DATA songs[100]; //DEFINES AN ARRAY CALLED SONGS (100 of them)// an array of 100 SONG_DATA structs
    int buffer_size = 250; //length of each song ame
    char line[buffer_size]; // strin for each line
    int counter=0;

    FILE *input = fopen("song_data.txt", "r");

    // creating some temporary storage:
    // pos will be converted to an int, but we'll be getting it as a string
    char pos[4];
    char artist[100];
    char title[100];
    char year[4];

    while (fgets(line, buffer_size, input)) //starts from first line auto
    {   
        // first we will get the info from the line
        tokeniseRecord(line,",",pos,artist,title,year);
        // but then what??

        // songs[0].artist=artist; //this will not work c strings are weird in c. the line below works instead
        strcpy(songs[counter].artist,artist);
// now for the others
        strcpy(songs[counter].title, title);
        strcpy(songs[counter].year,year);
// convert to 
        songs[counter].position = atoi(pos);
        counter++;

    }

    for (int i = 0; i<100;i++){
        printf("\nThis is the artist:  %s ", songs[i].artist);
        printf("\nThis is the title: %s ", songs[i].title);
        printf("\nThis is the year: %s ", songs[i].year);
    }
    // CHALLENGE: Count how many total songs you read in
}
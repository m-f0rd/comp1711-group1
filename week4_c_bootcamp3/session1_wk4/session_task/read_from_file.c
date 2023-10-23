#include <stdio.h>

int main() {
    char filename [] = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    int buffer_size = 2;
    char line_buffer[buffer_size]; //creates a character array of line buffer size
    while (fgets(line_buffer, buffer_size, file) != NULL) { //fgets = getting from a file. reads into a character array. (where we put the date, how much data we take, from which file) until we get to the end of the file.
        printf("%s\n", (line_buffer));
    }

    fclose(file);
    return 0;
}

//changed the lines from what it is on minerva to match the slides
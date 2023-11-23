Part 2: Submission deadline Wednesday December 13th 2023, 14:00.
Total marks available: 85
You have unlimited submissions attempts.
Task 2: Analysing our data
Difficulty level: SILVER
Task 2 marks: 30
Following on from your initial program, you now need to expand your initial program to add some features
to analyse the data and help us understand what the data means.
Following good programming practice, you should split your program functionality into two files:
FitnessDataStruct.h – a header file containing the struct typedef and any helper functions you want
StepCounter.c – a program that contains the code and functions to solve the requested tasks
The program should provide a simple menu system and ask the user to select from the following options and
an option to quit.
A: Specify the filename to be imported (we will give you some additional files to test with). This should have
some error checking so that the program can cope with an incorrect filename and a file that is of an
unexpected format.
B: Display the total number of records in the file
C: Find the date and time of the timeslot with the fewest steps
D: Find the data and time of the timeslot with the largest number of steps
E: Find the mean step count of all the records in the file
F: Find the longest continuous period where the step count is above 500 steps
These should be printed out exactly as below:
Option Example output
A Input filename:
B Total records: 229
C Fewest steps: 2023-09-01 14:20
D Largest steps: 2023-09-01 18:00
E Mean step count: 427
F Longest period start: 2023-09-01 14:20
Longest period end: 2023-09-01 18:00
How it will be marked:
1. Providing a menu system providing options A-F and Quit: 5 marks
2. Successfully coping with an incorrect filename: 4 marks
3. Displaying the total number of records: 4 marks
4. Date and time of fewest steps: 4 marks
5. Date and time of largest steps: 4 marks
6. Mean step count: 4 marks
7. Longest continuous period: 5 marksx<
# lab11

gcc -o lab_11 lab_11.c
./lab_11

Header includes:

#include <stdio.h>: Standard input/output functions.
#include <stdlib.h>: Standard library functions.
#include <string.h>: String manipulation functions.
Macro Definition:

MAX_COMMAND_LENGTH 256: Defines the maximum length of the user-input command.
Function: execute_command:

Takes a string command as input.
Uses popen to open a pipe to the command for reading.
Reads the output of the command using fgets and prints it to the console.
Closes the pipe using pclose.
Function: main:

Initializes a character array user_input to store the user's command.
Displays a welcome message.
Enters a loop where the user is prompted to enter a UNIX command.
Uses fgets to read the command and removes the trailing newline character.
Checks if the user wants to quit (by entering "quit").
Calls execute_command to execute the entered command and display the output.
The loop continues until the user enters "quit".
The program exits with a message if there's an error reading input.
Execution:

When you run this program, it will prompt you to enter UNIX commands.
It will execute the entered command using popen and display the output.
This process will continue until the user enters "quit," at which point the program will exit.

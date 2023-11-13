#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 256

void execute_command(const char *command) {
    FILE *fp;
    char buffer[256];

    // Open a pipe to the command
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Error opening pipe");
        exit(EXIT_FAILURE);
    }

    // Read and print the output
    printf("\n[Output]\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // Close the pipe
    if (pclose(fp) == -1) {
        perror("Error closing pipe");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char user_input[MAX_COMMAND_LENGTH];

    printf("Enter UNIX commands with wildcards and special characters.\n");
    printf("Type 'quit' to exit.\n");

    while (1) {
        // Prompt user for a command
        printf("\nEnter a UNIX command: ");
        fgets(user_input, sizeof(user_input), stdin);

        // Remove the newline character
        user_input[strcspn(user_input, "\n")] = '\0';

        // Check if the user wants to quit
        if (strcmp(user_input, "quit") == 0) {
            printf("Exiting program.\n");
            break;
        }

        // Execute the command using popen and display the output
        execute_command(user_input);
    }

    return 0;
}

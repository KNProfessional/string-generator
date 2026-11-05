#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define CONTAINER_SIZE 10

typedef struct stringObject {
    int pid;
    char* customString;
    struct stringObject* next;
} stringObject;

char** createContainer() {
    char
}

char* randomStringGenerator(int string_length) {
    int first_symbol = 32;
    int last_symbol = 126;
    //char c;

    char* newString = (char*) malloc(string_length + 1 * sizeof(char));
    
    srand(time(0));
    for (int i = 0; i < string_length; i++) {
        newString[i] =  rand() % (last_symbol - first_symbol + 1) + first_symbol;
        //printf("%c", c);
    }
    newString[string_length + 1] = '\0';
    return newString;
}

// char* createString(char* input, int size) {
//     char* newString = (char*) malloc(size + 1 * sizeof(char));
//     //newString = input;
//     newString[size + 1] = '\0';
//     return newString;
// }

void printString(char* input) {
    int i = 0;
    while (input[i] != '\0') {
        printf("%c", &input[i]);
        i++;
    }
    printf("\n");
}

void freeString(char* input) {
    free(input);
}

void printContainer(char* container[]) {
    printf("[");
    for (int i = 0; i < CONTAINER_SIZE; i++) {
        if (container[i] == NULL) {
            printf("NULL, ");
        }
        else {
            printf("%d, ", i);
        }
    }
    printf("]");
    printf("\n");
}

int main (int argc, char* argv[]) {
    bool quit = 0;
    int options = 0;
    int string_type = 0;
    int string_length;
    //char temp_char = ' ';
    char custom_string[100];
    //char* custom_string_ptr = &custom_string;
    //int CONTAINER_SIZE = 10;
    char* container[CONTAINER_SIZE];
    int container_index;


    // if (argc != 2) {
    //     printf("ERROR: You must enter the length of the string as an integer argument.\n");
    //     exit(1);
    // }
    for (int i = 0; i < CONTAINER_SIZE; i++) {
        container[i] = NULL;
    }
    

    do {
        printContainer(container);
        printf("Select an option:\n\n");
        printf("1: Create String.\n");
        printf("2: Print String.\n");
        printf("3: Free from memory.\n");
        printf("4: Save to disk.\n");
        printf("5: Print to paper.\n\n");
        printf("0: Quit\n");
        printf("\n");

        scanf("%d", &options);
        //options = atoi(&temp_char);

        switch (options) {
            case 1:
                //create string
                printf("Enter the array index 0-9 you would like to store your string in.\n");
                scanf("%d", &container_index);

                printf("Would you like to create a custom string, or generate a random string?\n\n");
                printf("1: Custom String.\n");
                printf("2: Random String.\n");

                scanf("%d", &string_type);

                if (string_type == 1) {
                    printf("Enter a custom string.\n");
                    int c; while ((c = getchar()) != '\n' && c != EOF); //clears the previous new line before the fgets.
                    fgets(custom_string, 100, stdin);
                    printf("User input: %s\n", custom_string);
                    container[container_index] = custom_string;
                    printString(container[container_index]);
                }
                else if (string_type == 2) {
                    printf("Enter the desired length of the string.\n");
                    scanf("%d", &string_length);
                    //randomStringGenerator(string_length);
                    container[container_index] = randomStringGenerator(string_length);
                    printString(container[container_index]);
                    printf("\n");
                }
                else {
                    printf("Not a valid option.\n");
                }
                break;
            case 2:
                //print string
                printf("Enter the array index 0-9 you would like to store your string in.\n");
                scanf("%d", &container_index);

                if (container[container_index] == NULL) {
                    printf("This index cannot be selected because its value is NULL.\n");
                }
                else {
                    printString(container[container_index]);
                }
                break;
            case 3:
                //free string
                break;
            case 4:
                //save to disk
                break;
            case 5:
                //print to paper
                break;
            case 0:
                printf("Exiting... \n");
                quit = 1;
                break;
            default:
                printf("ERROR: Not a valid selection.\n");
                break;
        }
    } while (quit != 1);


    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct stringObject {
    int pid;
    char* customString;
    struct stringObject* next;
} stringObject;


void randomStringGenerator(int string_length) {
    int first_symbol = 32;
    int last_symbol = 126;
    char c;
    
    srand(time(0));
    for (int i = 0; i < string_length; i++) {
        c =  rand() % (last_symbol - first_symbol + 1) + first_symbol;
        printf("%c", c);
    }
}

char* createString(int size) {
    char* newString = (char*) malloc(size + 1 * sizeof(char));
    newString[size + 1] = '\0';
    return newString;
}

void printString(char* input) {
    int i = 0;
    while (input[i] != '\0') {
        printf("%c", &input[i]);
        i++;
    }
}

void freeString(char* input) {
    free(input);
}

int main (int argc, char* argv[]) {
    bool quit = 0;
    int options = 0;
    int string_type = 0;
    char temp_char = ' ';
    char custom_string[100];


    // if (argc != 2) {
    //     printf("ERROR: You must enter the length of the string as an integer argument.\n");
    //     exit(1);
    // }
    int string_length;

    do {
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
                printf("Would you like to create a custom string, or generate a random string?\n\n");
                printf("1: Custom String.\n");
                printf("2: Random String.\n");

                scanf("%d", &string_type);

                if (string_type == 1) {
                    printf("Enter a custom string.\n");
                    int c; while ((c = getchar()) != '\n' && c != EOF);
                    fgets(custom_string, 100, stdin);
                    printf("User input: %s\n", custom_string);
                }
                else if (string_type == 2) {
                    printf("Enter the desired length of the string.\n");
                    scanf("%d", &string_length);
                    randomStringGenerator(string_length);
                    printf("\n");
                }
                else {
                    printf("Not a valid option.\n");
                }
                break;
            case 2:
                //print string
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
                quit = 1;
                break;
            default:
                printf("ERROR: Not a valid selection.\n");
                break;
        }
    } while (quit != 1);


    return 0;
}
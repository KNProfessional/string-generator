#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char* argv[]) {
    int first_symbol = 32;
    int last_symbol = 126;
    char c;

    if (argc != 2) {
        printf("ERROR: You must enter the length of the string as an integer argument.\n");
        exit(1);
    }
    int string_length = atoi(argv[1]);

    srand(time(0));
    for (int i = 0; i < string_length; i++) {
        c = first_symbol + (rand() % last_symbol - first_symbol + 1);
        printf("%c", c);
    }


    return 0;
}
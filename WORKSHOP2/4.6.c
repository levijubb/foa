/*
INSERT TITLE
*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    int characters = 0, lines = 0, spaces = 0, words = 0;
    char n;
    
    printf("Enter text:\n");
    while ((n = getchar()) != EOF) {
        characters++;

        if (n == ' ') {
            spaces++;
        }

        if (n == '\n') {
            lines++;
        }
    }
    words = spaces + lines;
    printf("Lines:  %d\nChars:  %d\nWords:  %d\n", lines, characters, words);

    return 0;
}
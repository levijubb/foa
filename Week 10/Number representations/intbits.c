// Show the encodings of different numbers

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    int i;
    unsigned val;
    if (argc<2) {   // Expecting only one argument from command line.
        exit(EXIT_FAILURE);
    }
    val = atoi(argv[1]);  // atio stores a string number as an int number
    printf("\t");
    for (i=8*sizeof(unsigned)-1; i>=0; i--) {
        if (val & (1<<i)) {
            printf("1");
        } else {
            printf("0");
        }
        if (i%8==0) {
            printf(" ");
        }
    }
    printf("\n");
    return EXIT_SUCCESS;
}
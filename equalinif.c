/*
INSERT TITLE
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_CLASS_SIZE 50

int
main(int argc, char *argv[]) {
    int classSize;
    printf("Enter class size:\t");
    if (scanf("%d", &classSize) != 1) {
        printf("ERROR. Please eneter valid input");
        exit(EXIT_FAILURE);
    }
    if (classSize <= MAX_CLASS_SIZE) {
        printf("More students can be accepted!\n");
    } else {
        printf("The class is full, fuck off.\n");
        exit(EXIT_SUCCESS);
    }
    return 0;
}
/*
INSERT TITLE
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXVALS 10

int
main(int argc, char *argv[]) {
    
    int A[MAXVALS];
    
    printf("Enter as many as %d values, (CTRL + D to end)\n", MAXVALS);
    int n = 0, excess = 0, next;
    while (scanf("%d", &next) == 1) {
        if (n == MAXVALS) {
            excess++;
        } else {
            A[n] = next;
            n++;
        }
    }
    printf("%d values read into array", n);
    if (excess) {
        printf(", %d excess values disregarded", excess);
    }
    printf("\n");




    return 0;
}
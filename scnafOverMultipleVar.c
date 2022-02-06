/*
INSERT TITLE
*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    int next, max, n;
    
    printf("Enter values, ctrl+D to end: ");
    if (scanf("%d", &next) != 1) {
        printf("\nNo data entered!\n");
        exit(EXIT_FAILURE);
    }

    n = 1;
    max = next;

    while (scanf("%d", &next) == 1) {
        if (next > max) {
            max = next;
        }
        n += 1;
    }
    printf("%d values read, maximum is %d\n", n, max);
    return 0;
}
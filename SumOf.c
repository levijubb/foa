/*
INSERT TITLE
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int
main(int argc, char *argv[]) {
    double cons, final;
    int n;

    printf("Calc sum of (CTRL+D to stop): ");
    if (scanf("%lf", &cons) != 1) {
        printf("\nInvalid input, need to enter numbers!\n");
        exit(EXIT_FAILURE);
    }

    final = cons;
    n = 1;

    while (scanf("%lf", &cons) == 1) {
        final += cons;
        n++;
    }
    printf("%d values were successfully read with a sum of:\n%.2lf\n", n, final);

    return 0;
}
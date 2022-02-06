/*
Hanoi solver for 3 pillars. NOT WRITTEN BY ME
*/
#include <stdio.h>
#include <stdlib.h>

void
hanoi(char from, char via, char to, int n) {
    int i;
    if (n <= 0) {
        return;
    }

    hanoi(from, to, via, n - 1);
    for (i = 1; i < n; i++) {
        printf("    ");
    }

printf("Move a disk from %c to %c\n", from, to);
hanoi(via, from, to, n - 1);
}

int
main(int argc, char *argv[]) {
    hanoi('A', 'B', 'C', 3);
    return 0;
}
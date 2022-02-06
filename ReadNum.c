/*
ReadNum example. NOT WRITTEN BY ME
*/
#include <stdio.h>
#include <stdlib.h>

#define READ_OK 0
#define READ_ERROR 1

//int readNum(int lo, int hi, int *num);

int
readNum(int lo, int hi, int *num) {
    int next;
    printf("Enter a number between %d and %d inclusive: ", lo, hi);
    while (scanf("%d", &next) == 1) {
        if (lo <= next && next <= hi) {
            *num = next;
            return READ_OK;
        }
        printf("%d is not between %d and %d\ntry again: ", next, lo, hi);
    }
    return READ_ERROR;
}

int
main(int argc, char *argv[]) {
    int value;
    if (readNum(-100, 100, &value) != READ_OK) {
        printf("Read error, program abort\n");
        exit(EXIT_FAILURE);
    }

    printf("value = %d\n", value);
    return 0;
}
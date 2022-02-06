/*
INSERT TITLE
*/
#include <stdio.h>
#include <stdlib.h>

#define N 5

int
main(int argc, char *argv[]) {
    int A[N], *p, i; //Defining Pointer and array

    //Generating numbers to fill array
    for (i=0; i<N; i++) {
        A[i] = i*(i+1)/2;
    }

    //Printing out the first element in A
    printf("A = %10p\n", A);
    printf("A = %10d\n", *A);


    for (p=A; p<A+N; p++) {
        printf("p = %10p, *p = %2d\n", p, *p);
    }

    return 0;
}
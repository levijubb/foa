/*
Excercise 1 from ch7 lecture recordings. Levi Jubb, 2 Sep 2020
*/
#include <stdio.h>
#include <stdlib.h>

#define IS_SORTED 1
#define NOT_SORTED 0

int
is_sorted(int A[], int n) {
    for (int i=1; i<n; i++) {
       if (A[i-1] > A[i]) {
           return NOT_SORTED;
       }
    }
    return IS_SORTED;
}



int
main(int argc, char *argv[]) {
    int arrau[5] = {1, 2, 3, 4, 5};
    printf("IS IT SORTED? |%d|\n", is_sorted(arrau, 5));

    return 0;
}
/*
This is my atempt at basic Binary Search. Uses reapated range
halving to find desired item. ONLY USEFUL ON SORTED ARRAYS.
*/
#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND 8008135

int
binarySearch(int A[], int size, int num) {
    int lo = 0, hi = size;
    while (lo < hi) {
        int m = (lo + hi)/2; //Strictly integer division
        if (num < A[m]) { // Item within lower bound
            hi = m;
        } else if (num > A[m]) { //Item within upper bound
            lo = m + 1;
        } else { // Must have found value
            while (A[m] == num) {
                m--;
            }
            return m;
        }
    }
    return NOT_FOUND;
}

    



int
main(int argc, char *argv[]) {
    int arry[31] = {1, 2, 3, 4, 5, 6, 7, 9, 9, 9, 9, 11, 12, 13, 14,
     15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
     printf("9 is int the array at position %d.\n", binarySearch(arry, 31, 9));
    return 0;
}
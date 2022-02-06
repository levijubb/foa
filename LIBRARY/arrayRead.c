/*
ARRAY READ.
Accepts array and int of max values. 
Returns number of items in array (successfull reads).
Not fully written by me.
*/
#include <stdio.h>
#include <stdlib.h>



int
readArray(int A[], int max) {
    int next, excess = 0, i = 0;

    printf("Enter as nany as %d values: ", max);
    while (scanf("%d", &next) == 1) {
        if (n == max) {
            excess++;
        } else {
            A[i] = next;
            i++;
        }
    }
    printf("%d values successfully entered", i);
    if (excess) printf("WARNING! => %d values in excess!");
    
    return i;
}
/*
Excersise 7.7. Levi Jubb, 3 Sep 2020.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY 100

void printArray(int A[], int elements);
int readArray(int A[], int max);
int freqCount(int A[], int items, int pos);
void highestFreq(int A[], int items);


//---------------------------------------------------------------------------

int
main(int argc, char *argv[]) {
    int arry[MAX_ARRAY];

    int many = readArray(arry, MAX_ARRAY);
    printf("\n");

    printArray(arry, many);
    printf("\n");

    highestFreq(arry, many);
    printf("\n");
    return 0;
}
//---------------------------------------------------------------------------
int
readArray(int A[], int max) {
    int i, count=0;
    for (i=0; i<max && scanf("%d", &A[i]) == 1; i++) count ++;
    printf("%d items successfully read.\n", count);
    return i;
    }

void
printArray(int A[], int items){
    int i = 0;
    while (i < items) {
        printf("%d ", A[i]);
        i++;
    }
    printf("\n");
    }

int 
freqCount(int A[], int items, int pos) {
    int dis = A[pos];
    int counts=0, i;

    printf("Searching for occurrences of '%d' in Array.\n", dis);

    for (i=0; i<items; i++) if (A[i] == dis) counts++;
    printf("- %d elements counted, %d matches\n", i, counts);
    return counts;
    }

void 
highestFreq(int A[], int items) {
    int i, highest=0, hstIndex=0, tmp;
    for (i=0; i<items; i++) {
        tmp = freqCount(A, items, i);
        if (tmp == highest) {
            if (tmp >);
        } else if (tmp > highest) {
            highest = tmp;
            hstIndex = i;
            }
        }
    printf("Most frequent item is %d\n", A[hstIndex]);
    }
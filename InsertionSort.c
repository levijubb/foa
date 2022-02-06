/*
Reads array, sorts it, and writes it out again. STUDY THIS. NOT WRITTEN BY ME
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 1000

int read_int_array(int A[], int n);
void sort_int_array(int A[], int n);
void print_int_array(int A[], int n);
void int_swap(int *p1, int *p2);

int
main(int argc, char *argv[]) {

    int numbers[MAXVAL], nnumbs;

    printf("\n-----------------------------------------------\n");

    nnumbs = read_int_array(numbers, MAXVAL);

    printf("\n*  Before: ");
    print_int_array(numbers, nnumbs);

    sort_int_array(numbers, nnumbs);

    printf("*  After:  ");
    print_int_array(numbers, nnumbs);

    printf("-----------------------------------------------\n");

    return 0;
}

int
read_int_array(int A[], int maxvals) {
    int n, excess, next;
    printf("Enter as many as %d values, type n to end\n", maxvals);

    n = 0; excess = 0;
    while (scanf("%d", &next) == 1) {
        if (n == maxvals) {
            excess++;
        } else {
            A[n] = next;
            n++;
        }
    }
    printf("%d values read into array\n", n);
    if (excess) {
        printf(", %d excess values disregarded", excess);
    }
    return n;
}


void
sort_int_array(int A[], int n) {
    int i, j;
    // Assume that A[0]  to A[n-1] have valid values
    for (i = 1; i < n; i++) {
        // Swap A[i] left into correct position
        for (j = i-1 ; j>=0 && A[j+1]<A[j] ; j--) {
            int_swap(&A[j], &A[j+1]);
        }
    }
}

void
print_int_array(int A[], int n) {
    int i;
    for (i = 0; i < n;  i++) {
        printf("%4d", A[i]);
    }
    printf("\n");
}

void
int_swap(int *p1, int *p2) {
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
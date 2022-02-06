/*
First example of Quicksort sorting algorithm. NOT WRITTEN BY ME.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 100000

typedef int data_t;

void
quick_sort(data_t A[], int n) {
	data_t pivot;
	int first_eq, first_gt; //First equals and first greater than
	if (n<=1) {
		return;
	}

	pivot = choose_pivot(A, n);
	partition(A, n, &pivot, &first_eq, &first_gt);
	quick_sort(A, first_eq);
	quick_sort(A + first_gt, n - first_gt);
}

void
partition(data_t A[], int n, data_t *pivot, int *first_eq, int *first_gt){
	int next = 0, fe = 0, fg = n, outcome;

	while (next < fg){
		if ((outcome = cmp(A + next, pivot)) < 0) {
			swap_data(A + fe, A + next);
			fe += 1;
			next += 1;
		} else if (outcome > 0) {
			fg -=1;
			swap_data(A + next, A + fg);
		} else {
			next += 1;
		}
	}

	assert(0 <= fe && fe < fg && fg <= n);
	*first_eq = fe;
	*first_gt = fg;


}

void
print_int_array(int A[], int n) {
    int i;
    for (i = 0; i < n;  i++) {
        printf("%4d", A[i]);
    }
    printf("\n");
}

int
main(int argc, char *argv[]) {
    int arry[30] = {1, 2, 3, 9, 5, 6, 7, 8, 9, 9, 11, 12, 13, 14,
     15, 16, 17, 18, 19, 20, 21, 9, 23, 24, 25, 26, 27, 28, 29, 30};
     
	printf("Unsorted:\n");
	print_int_array(arry, 30);
	quick_sort(arry, 30);
	printf("Sorted:\n");
	print_int_array(arry, 30);


    return 0;
}
/* Heapsort on an integer array.
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define SIZE 100000

typedef int data_t;

/* This needs to be included rather than compiled, because the use
   of data_t as the array that is being sorted. */
#include "sortscaffold.c"

/* Amongst other things, sortscaffold.c defines these two :
	int cmp(data_t *p1, data_t *p2);
	void swap_data(data_t *p1, data_t *p2);
*/

/* These functions are part of heap sort */
void build_heap(data_t A[], int n);
void sift_down(data_t A[], int parent, int n);
void heap_sort(data_t A[], int n);

void
sift_down(data_t A[], int parent, int n) {
	int child;
	if ((child = 2*parent+1) < n) {
		/* there is at least one child to be checked */
		if (child+1<n && cmp(A+child, A+child+1)<0) {
			/* the right child exists, and is larger */
			child += 1;
		}
		if (cmp(A+parent, A+child)<0) {
			/* parent is smaller than larger child */
			swap_data(A+parent, A+child);
			sift_down(A, child, n);
		}
	}
}

void
build_heap(data_t A[], int n) {
	int i;
	for (i=n/2-1; i>=0; i--) {
		sift_down(A, i, n);
	}
}

void
heap_sort(data_t A[], int n) {
	int active;
	build_heap(A, n);
	for (active=n-1; active>0; active--) {
		swap_data(A+0, A+active);
		sift_down(A, 0, active);
	}
}


int
main(int argc, char *argv[]) {
	int n=SIZE;
	if (argc>1) {
		n = atoi(argv[1]);
	}
	printf("Testing heap sort\n");
	do_sort_tests(heap_sort, n);
	return 0;
}

/* =====================================================================
   Program written by Alistair Moffat, as an example for the book
   "Programming, Problem Solving, and Abstraction with C", Pearson
   Custom Books, Sydney, Australia, 2002; revised edition 2012,
   ISBN 9781486010974.

   See http://people.eng.unimelb.edu.au/ammoffat/ppsaa/ for further
   information.

   Prepared December 2012 for the Revised Edition.
   ================================================================== */
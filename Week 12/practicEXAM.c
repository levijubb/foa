///////////////////////////////////////////////////////////////////

// comp20005 Practice Exam, 2020
// Sample Solution
// Prepared by Alistair Moffat, ammoffat@unimelb.edu.au
// (c) The University of Melbourne, 2020


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

///////////////////////////////////////////////////////////////////
// Section 2 -- Programming
///////////////////////////////////////////////////////////////////

// Background declarations so that this will all compile,
//     you don't need to provide these in your answers

typedef double data_t;

int
cmp_data(data_t *t1, data_t *t2) {
	if (*t1 < *t2) return -1;
	if (*t1 > *t2) return +1;
	return 0;
}

int
sum_data(data_t *d) {
	return 1;
}

// The provided declarations

typedef struct tree tree_t;

struct tree {
	data_t  data;            // the data stored at this node
	tree_t *left;            // left subtree of node
	tree_t *rght;            // right subtree of node
};

///////////////////////////////////////////////////////////////////

// Prototypes for the required functions

int sum_tree(tree_t *t);
tree_t *bst_insert(tree_t *t, data_t *d);
tree_t *bst_merge(tree_t *t1, tree_t *t2);

///////////////////////////////////////////////////////////////////

// Apply a "summing" function to every data item,
//     this should be easy marks

int
sum_tree(tree_t *t) {
	int sum;
	if (!t) return 0;
	sum = sum_data(&(t->data));
	sum += sum_tree(t->left);
	sum += sum_tree(t->rght);
	return sum;
}

///////////////////////////////////////////////////////////////////

// Insert an existing node into a bst, a useful helper function

tree_t
*bst_insert_node(tree_t *t, tree_t *node) {
	if (t==NULL) {
		return node;
	}
	if (cmp_data(&(node->data), &(t->data)) < 0) {
		// recurse left if new data < subtree root
		t->left = bst_insert_node(t->left, node);
	} else {
		// recurse rght if new data >= subtree root
		t->rght = bst_insert_node(t->rght, node);
	}
	return t;
}


// Insert a data item to a BST, this is what the question asked for

tree_t
*bst_insert(tree_t *t, data_t *d) {
	tree_t *node;
	node = (tree_t *)malloc(sizeof(tree_t));
	assert(node);
	node->data = *d;
	node->left = node->rght = NULL;
	return bst_insert_node(t, node);
}

///////////////////////////////////////////////////////////////////

// Merge two BSTs, and return a pointer to the merged tree

tree_t
*bst_merge(tree_t *t1, tree_t *t2) {
	tree_t *left, *rght;
	if (t2==NULL) {
		// easy base case
		return t1;
	}
	// cut t2 into three parts: root, left, right
	left = t2->left;
	rght = t2->rght;
	t2->left = t2->rght = NULL;
	// and insert each of the three parts into t1
	t1 = bst_insert_node(t1, t2);
	t1 = bst_merge(t1, left);
	t1 = bst_merge(t1, rght);
	return t1;
}

///////////////////////////////////////////////////////////////////

int
main(int argc, char *argv[]) {

	return 0;
}

#if 0

///////////////////////////////////////////////////////////////////
// Section 3 -- Programming
///////////////////////////////////////////////////////////////////

Student A is planning to: (a) completely sort the whole array using
mergesort; and then (b) to extract the k'th smallest from A[k].
And mergesort takes O(nlogn) time in worst case, and O(n) additional
space, matching the clues provided in the question.

///////////////////////////////////////////////////////////////////

Student B is planning to: (a) find the smallest element, in O(n)
time; then (b) find the second smallest, in O(n) time; and then, and
then, ...; and then (c) find the k'th smallest in O(n) time.

In total, (k+1) next-smallest elements are identified during this
process, each taking O(n) time, and hence the total is O(n + nk)
time, matching the clues provided in the question.

///////////////////////////////////////////////////////////////////

Student C knows about heaps, and is planning to: (a) build a min-heap
in the array (that is, with the smallest element at the root and no
child allowed to be less than its parent) in O(n) time; then (b)
remove the smallest element from the root of the heap and rebuild the
heap, in O(logn) time; then (c) remove the second smallest element
from the root of the heap and rebuild the heap, in O(logn) time; and
then, and then, ...; and then (d) remove the k'th smallest from the
root of the heap in O(logn) time.

In total, O(n) time is required to build the array into a heap, and
then there are k rebuilding steps required, each taking O(logn) time,
for a total of O(n + klogn) time, matching the clues provided in the
question.

///////////////////////////////////////////////////////////////////

Student D remembers the way that quicksort works, and (in a flash of
inspiration) realizes that a cunning recursive approach can be used,
sketched by this pseudocode: 

	int find_kth(A, n, k) {
	    if (n==1) {
	    	// base case, and k must be zero
		return A[0];
	    }
	    // recursive case, partition the array
	    pivot = A[rand()%n]
	    (fe, fg) = partition(A, n, pivot)
	    // and now look at fe and fg relative to k and do
	    //    at most *one* recursive call
	    if (k<fe) {
		// k'th smallest is somewhere in the < zone
	    	return find_kth(A, fe, k)
	    } else if (fe<=k && k<fg) {
		// k'th smallest is in the == zone
	    	return pivot
	    } else {
		// k'th smallest is somewhere in the > zone
	    	return find_kth(A+fg, n-fg, k-fg)
	    }
	    // Tadaa!
	}

In that second possible recursive call, the first two parts of the
partition (< pivot and = pivot) are bypassed, and so the index of
the element being looked for is similarly adjusted by the same amount.

Analysis: if we get lucky and the pivot is always exactly the
midpoint at ecery recursion, then each recursive call would be on
exactly half of the previous array, giving 

	T(1) = 1
	T(n) = n + T(n/2).

(because partition takes O(n) time) which has the solution T(n) =
2n-1 = O(n).

In the worst case, if we are unlucky, it becomes a bit like the
method of Student B of course, and the cost might be as large as
O(n(n-k)) which is O(n^2) when k<n/2.

On *average*, if the pivot is at a random location in the sorted
array, then the running time is O(n), just as the average running
time of quicksort is O(nlogn).

All of which matches the clues about execution time.

But what about space, you say?  In the question it says O(1) extra
space, whereas a recursive function takes O(logn)!  There is only
a single recursive call made in anhy execution of that function,
and it comes at the end, so it can be flattened into a simple loop
and handled without needing a stack:

	int find_kth(A, n, k) {
	    while (n>1) {
	        pivot = A[rand()%n]
	        (fe, fg) = partition(A, n, pivot)
	        if (k<fe) {
		    // k'th smallest is somewhere in the < zone
	    	    n = fe;
	        } else if (fe<=k && k<fg) {
		    // k'th smallest is in the == zone
	    	    return pivot
	        } else {
		    // k'th smallest is somewhere in the > zone
		    A += fg;
		    n -= fg;
		    k -= fg;
	        }
	    }
	    return A[0];
	    // Tadaa!
	}

Yes, that's a lot of knowledge and a lot of work required here for
just three points.  But if you want 90+ as a final mark, you have
to have a lot of knowledge, and you have to be willing to do a lot
of rapid work.

#endif
/*
The following declarations describe a struct to represent books in a library. 
Each book has a unique book number assigned to it, an author, a title, 
a publisher, a count of the total number of times it has been borrowed, and an 
array storing the library card numbers of the (up to) ten people who borrowed 
it most recently:

    #define MAXSTRLEN 40
    #define MAXBORROWS 10

    typedef char string_t[MAXSTRLEN+1];

    typedef struct {
        int booknum;
        string_t author, title, publisher;
        int tot_borrows;
        int num_borrowers;
        int borrowers[MAXBORROWS];
    } book_t;
In this structure num_borrowers is a buddy variable for the array borrowers in 
the struct for each book. The library as a whole is represented by an array B[] 
of type book_t and a buddy variable nbooks.

Write a function:

    void new_borrow(book_t B[], int nbooks, int this_booknum, int this_borrower)
that locates the book that matches this_booknum in the library 
(checking the booknum component in each entry)  and updates its record to show 
that it has now been borrowed by this_borrower.

Updating a record required the following steps:

if there is space to add this_borrower to the borrowers[] array, then it is 
added in the next vacant position; or if the borrowers[] array is already full, 
then the first entry in it is discarded, the other elements are all shifted one 
position down, and this_borrower is added in the now-vacant last position.
Marks will be allocated for style and simplicity as well as for correctness. 
This function is permitted and required to alter one of the elements in 
array B[].
*/

#include <stdio.h>
#include <stdlib.h>

    #define MAXSTRLEN 40
    #define MAXBORROWS 10
    #define MAXBOOKS 2

    typedef char string_t[MAXSTRLEN+1];

    typedef struct {
        int booknum;
        string_t author, title, publisher;
        int tot_borrows;
        int num_borrowers;
        int borrowers[MAXBORROWS];
    } book_t;

void new_borrow(book_t B[], int nbooks, int this_booknum, int this_borrower);

int
main(int argc, char *argv[]) {
    book_t B[MAXBOOKS];
    B[0] = {8000123, {5, 0}, {5, 0}, {5, 0}, 10, 10 , {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    new_borrow(&B, 1, 8000123, 11);
    
    printf("%d\n", &B[0].borrowers[9]);
    return 0;
}

void
new_borrow(book_t B[], int nbooks, int this_booknum, int this_borrower) {
    int i, j;
    for (i=0; i<nbooks; i++) {
        if (B[i].booknum == this_booknum) {
            if (B[i].num_borrowers == MAXBORROWS) {
                for (j=0; j<MAXBORROWS-1; j++) {
                    B[j] = B[j+1];
                    B[i].num_borrowers--;
                }
            }
            B[i].borrowers[B[i].num_borrowers++] = this_borrower;
        }
    }
}


f
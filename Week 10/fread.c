/*
Show the use of the functions fopen, fwrite and fread.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 70000
#define FILENAME "temp.dat"

void print_doubles(double *A, int n);

int
main(int argc, char *argv[]) {
    double A[SIZE];
    FILE *fp;
    int i;

    // Initialize array with some variables
    for (i=0; i<SIZE; i++) {
        A[i] = 1.2345*i + 0.8008;
    }

    printf("---- INTIAL ARRAY ----\n");
    print_doubles(A, SIZE);

    // Open file for writing.
    fp = fopen(FILENAME, "w");
    assert(fp != NULL);

    // Write array to the file.
    i = fwrite(A, sizeof(*A), SIZE, fp);
    assert(i == SIZE); // i will be how many elements are written.

    // Clear the array.
    for (i=0; i<SIZE; i++) {
        A[i] = 0.0;
    }

    printf("---- CLEARED ----\n");
    print_doubles(A, SIZE);

    // Open file for reading.
    fp = freopen(FILENAME, "r", fp);
    assert(fp != NULL);

    // Read array back.
    i = fread(A, sizeof(*A), SIZE, fp);
    assert(i == SIZE);

    printf("---- READ ARRAY ----\n");
    print_doubles(A, SIZE);

    fclose(fp);
    return 0;
}

void
print_doubles(double *A, int n) {
    int i;
    for (i=0; i<n; i++) {
        printf("%7.3f", A[i]);
    }
    printf("\n");
}
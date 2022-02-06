/*
Show the declaration and use of function pointers
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(int argc, char *argv[]) {
    
    // Defining a pointer to an item that returns a double and takes a double respectively.
    double (*F)(int), x=2.0;

    F = sqrt;  
    printf("x=%.4f, F(x)=%.4f\n", x, F(x));

    F = sin;
    printf("x=%.4f, F(x)=%.4f\n", x, F(x));

    F = log;
    printf("x=%.4f, (*F)(x)=%.4f\n", x, (*F)(x));  //<- this is the long form which matches the declaration.

    return 0;
}
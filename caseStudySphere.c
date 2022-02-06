/*
CALCULATES VOLUME OF SPHERE IN m3
*/
#include <stdio.h>
#include <stdlib.h>

#define PIE 3.1415926 // This can be used to deifne stuff. Its cool
int
main(int argc, char *argv[]) {

    double radius, volume;

    // Scanning variable
    printf("Enter a radius: ");
    scanf("%lf", &radius);
    
    // Ensuring radius correct
    if (radius < 0) {
        printf("Radius must be positive. Please try again\n");
        exit(EXIT_FAILURE);
    }


    // Calculating volume
    volume = 4.0 / 3.0 * PIE * radius * radius * radius;

    // Printing output
    printf("A sphere of radius %.2f has a volume of %.2f m3", radius, volume);
    return 0;
}
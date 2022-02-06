/*
Simple program for converting temperature from F to C. Aug 2020, Levi Jubb
*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {

    #define FRAC (5.0 / 9);
    double tempf, tempc;
    printf("Enter degrees F: ");
    scanf("%lf", &tempf);

    tempc = (tempf - 32) * FRAC;

    printf("In degrees C is %.1f\n", tempc);
    return 0;
}
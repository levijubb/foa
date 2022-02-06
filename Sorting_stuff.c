/*
Type sotrageeeee
*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    char character;
    int integer;
    double doubles;
    float floats;
    
    printf("This is how you sotre a character:\t");
    scanf("%c", &character);

    printf("This is how you sotre a integer:\t");
    scanf("%d", &integer);

    printf("This is how you sotre a double:\t");
    scanf("%lf", &doubles);

    printf("This is how you sotre a float:\t");
    scanf("%f", &floats);

    printf("This is what it is: %c %d %lf %f\n", character, integer, doubles, floats);




    return 0;
}
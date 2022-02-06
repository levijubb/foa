/*
INSERT TITLE
*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    int num=0;

    printf("Enter numbers:  ");
    while ((scanf("%d", &num)) == 1) {
        printf("\n%4d |", num);
        while (num > 0) {
            printf("*");
            num--;
        }
    }
    printf("\n");

    return 0;
}



/* THIS IS MY FIRST ATTEMPT
int
starPrint(int num) {
    printf("\n%d |", num);
    int i = 0;
    while (i < num) {
        printf("*");
        i++;
    }
    return 0;
}

int
main(int argc, char *argv[]) {
    int NumberOfStar;
    
    printf("Enter numbers: ");
    (scanf("%d", &NumberOfStar) != 1) ? exit(EXIT_FAILURE) : (0);
    starPrint(NumberOfStar);

    while (scanf("%d", &NumberOfStar) == 1) {
        starPrint(NumberOfStar);
    }
    printf("\n");
    return 0;
}
*/
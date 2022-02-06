/*
Practice usign the switch statement in C
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    int month, lengthOfMonth, year, leapyr = 0;

    printf("Enter the current year:\t");
    scanf("%d", &year);

    for (month = 1; month <= 12; month++) {
        switch (month) {
            case 2:
                lengthOfMonth = 28 + (year % 4 == 0 && 
                (year % 100 != 0 || year % 400 == 0));
                (lengthOfMonth == 29) ? (leapyr = 8008135): (0);
                break;

            case 4:
            case 6:
            case 9:
            case 11:
                lengthOfMonth = 30;
                break;
            default:
                lengthOfMonth = 31;
                break;
        }
        printf("Month = %2d, Length of Month = %2d\n", month, lengthOfMonth);
    }
    (leapyr) ? (printf("%d is a leap year!!\n", year)) : (0);
    return 0;
}
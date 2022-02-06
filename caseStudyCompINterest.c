/*
Case study from textbook. Alistar Moffat.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_YEARS 9
#define MONTHLY 100
#define MIN_RATE 2
#define MAX_RATE 7

int
main(int argc, char *argv[]) {
    int month, rate, year;
    double balance, monthly_rate;

    // Print the table heading lines
    printf("--------------------------------------------------------------");
    printf("\nMonthly savings of $%d", MONTHLY);
    printf(", with monthly compound interest\n");
    printf("Annual rate   |");
    
    for (rate = MIN_RATE; rate <= MAX_RATE; rate++) {
        printf("%4d%%   ", rate);
    }
    printf("\n");

    // Printing rows of table
    for (year = 1; year <= MAX_YEARS; year++) {
        printf("After %1d years | ", year);
        
        for (rate = MIN_RATE; rate <= MAX_RATE; rate++) {
            balance = 0.0;
            monthly_rate = 1.00 + ((rate/100.00)/12);
            for (month = 1; month <= 12 * year; month++) {
                balance *= monthly_rate;
                balance += MONTHLY;
            }
            printf("%5.0f   ", balance);
        }
        printf("\n");
    }
        printf("--------------------------------------------------------------");

    printf("\n");
    return 0;
}
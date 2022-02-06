/*
Written by Levi Jubb. Appends today's date and other relevent info onto
C program. Yes, this could be written much easier but I wanted to get my head
arround working with files in C so piss off.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#define DEBUG 1

#define MAXFILE 10
#define MAXCHARS 100000

void print_div();
void time_now(char cur_time[]);

int
main(int argc, char *argv[]) {
    char A[MAXCHARS], cur_time[128];
    FILE *fp;
    int charsRead, numFile, i;
    time_now(cur_time);

    char MESSAGE[] = "This program was written by Levi Jubb on ";
    strcat(MESSAGE, cur_time);

    printf("%s\n", MESSAGE);

    for (numFile=1; numFile<argc; numFile++) {
        print_div();
        fprintf(stderr, "Opening... %s\n", argv[numFile]);
        if ((fp = fopen(argv[numFile], "r")) == NULL) {
            fprintf(stderr, "!!! FAILED !!!\n");
            exit(EXIT_FAILURE);
        } else {
            if ((charsRead = fread(A, sizeof(A), MAXCHARS, fp)) != MAXCHARS) {
                fprintf(stderr, "Error Occured: Incorrect characters read\n");
                exit(EXIT_FAILURE);
            }
        strcat(A, MESSAGE);
        
        }
    }
    return 0;
}

void
print_div() {
    printf("\n--------------------\n");
}

void
time_now(char cur_time[]) {
    time_t t;
    struct tm* ptm;
    t = time(NULL);
    ptm = localtime(&t);
    strftime(cur_time, 128, "%d-%b-%Y %H:%M:%S", ptm);
}
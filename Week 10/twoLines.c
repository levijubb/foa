/*
Print the first few lines and number of lines of a set of files.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LINE_LIMIT 3
#define DIVIDER "=============================="

void first_lines(FILE *fp, int n);

int
main(int argc, char *argv[]) {
    int fnum;
    FILE *fp;

    // Process list of command line arguments
    for (fnum=1; fnum<argc; fnum++) { // Start at 1 as argv[0] is name of twolines function
        fprintf(stderr, "Opening %s: ", argv[fnum]);
        if ((fp = fopen(argv[fnum], "r")) == NULL) {
            fprintf(stderr, "...... Failed\n");
        } else {
            fprintf(stderr, "\n");
            printf("%s %s \n", DIVIDER, argv[fnum]);
            first_lines(fp, LINE_LIMIT);
            printf("%s\n", DIVIDER);
            fclose(fp);
        }
    }
    return 0;
}

void
first_lines(FILE *fp, int n) {
    int c;
    int lines=0;
    while ((c=getc(fp)) != EOF) {
        if (lines < n) {
            putchar(c);  // This putchar is putting each character to stdout.
        }
        lines += (c=='\n'); // This really eligantly counts the number of lines.
    }
    printf("-- %d lines in total --\n", lines);
}


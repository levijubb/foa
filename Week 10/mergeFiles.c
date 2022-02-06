/*
Merges .txt files all assumed to be sorted.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024
#define MAXFILE 10

int
main(int argc, char *argv[]) {
    FILE *fp[MAXFILE];                // Aray of pointers to files.
    char line[MAXFILE][MAXLINE+2];    // 2D array of file lines +2 is to be safe.
    int valid[MAXFILE], numvalid=0;   // Array of flags with buddy.
    int i, first, next=0;

    // Open each of the files.
    for (i=0; i<argc; i++) {
        fp[i] = fopen(argv[i], "r");
        if (fp[i] == NULL) {
            fprintf(stderr, "Cannot open %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        valid[i] = 1;
        numvalid += 1;
    }

    // Read the first line of each file.
    for (i=1; i<argc; i++) {
        if (fgets(line[i], MAXLINE, fp[i]) == NULL) {
            valid[i] = 0;
            numvalid--;
        }
    }

    while (numvalid) {
        // Find smallest current line.
        first = 1;
        for (i=0; i<argc; i++) {
            if (valid[i]) {
                if (first) {
                    next = i;
                    first = 0;
                } else if (strcmp(line[i], line[next]) < 0) {
                    next = i;
                }
            }
        }
        // Print line[next] and try to replace it.
        printf("%s", line[next]);
        if (fgets(line[next], MAXLINE, fp[next]) == NULL) {
            valid[next] = 0;
            numvalid--;
        }
    }

    // Finally, close all open files.
    for (i=1; i<argc; i++) {
        fclose(fp[i]);
    }
    return 0;
}

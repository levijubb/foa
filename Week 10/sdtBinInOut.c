/*
STANDARD RECEPIE FOR WORKING WITH FILES. BINARY INPUT/OUTPUT
*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    
    type_t *tptr;
    FILE *datafyle;
    n = ;
    tptr = (type_t*)malloc(n*sizeof(*tptr));
    assert(tptr);
    if ((datafyle = fopen(FYLENAME, "r")) == NULL) {
        fprintf(stderr, "cannot read from  %s\n", FYLENAME);
        exit(EXIT_FAILURE);
    }
    if (fread(tptr, sizeof(*tptr), n, datafyle) != n) {
        fprintf(stderr, "read error on %s\n", FYLENAME);
        exit(EXIT_FAILURE);
    }
    fclose(datafyle);
    
    /* do stuff with array at *tptr, including realloc()
    if required, and adjust n if so */

    if ((datafyle = fopen(FYLENAME, "w")) == NULL) {
        fprintf(stderr, "cannot write to %s\n", FYLENAME);
        exit(EXIT_FAILURE);
    }
    if (fwrite(tptr, sizeof(*tptr), n, datafyle) != n) {
        fprintf(stderr, "write error on %s\n", FYLENAME);
        exit(EXIT_FAILURE);
    }
    fclose(datafyle);

    return 0;

}
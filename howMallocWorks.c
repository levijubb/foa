/*
Show the use of nalloc and free
*/
#include <stdio.h>
#include <stdlib.h>

#define PTRS 5

int
main(int argc, char *argv[]) {
    
    char *p[PTRS];
    size_t nbytes=10;
    int i;    
    
    // Allocating the array of pointers.
    for (i=0; i<PTRS; i++) {
        printf("malloc of %10lu bytes ", nbytes);
    
        if ((p[i] = (char *)malloc(nbytes)) == NULL) {
            printf("failed\n");
        } else {
            printf("succeeded, at %10u", (unsigned)p[i]);
            printf(" to %10lu\n", nbytes-1+(unsigned)p[i]);
        }
        nbytes *= 100;
    }

    // Now free the memory.
    for (i=0; i<PTRS; i++) {
        if (p[i]) {
            free(p[i]);
            p[i] = NULL;
        }
    }

    return 0;
}
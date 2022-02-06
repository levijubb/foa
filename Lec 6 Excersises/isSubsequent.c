/*
DOES NOT WORK.
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int isSubsequence(char *s1, char *s2);

int
main(int argc, char *argv[]) {
    int num1 = isSubsequence("bee", "abbreviate");
    int num2 = isSubsequence("bee", "acerbate");
    printf("%d\n%d\n", num1, num2);
    return 0;
}


int
isSubsequence(char *s1, char *s2) {
    while (*s2) {
        if (*s1 == *s2) {
            s1++;
            s2++;
        
        } else {
            s1
            s2++;
        }
    }
    if (*s1) {
        return FALSE;
    }
    return TRUE;
}
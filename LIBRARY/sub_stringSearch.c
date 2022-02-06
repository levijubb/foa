/*
To test myself. Written by Levi Jubb.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
subStrSearch(char str[], char sub[]) {
    int i;
    char *p1 = str, *p2 = sub;
    while (*p1) {
        if (!p2) return p2;
        if (*p1==*p2) {
            p1++;
            p2++;
        } else {
            p2 = sub;
        }
        p1++;
    }
    return NULL;
}



int
main(int argc, char *argv[]) {
    return 0;
}
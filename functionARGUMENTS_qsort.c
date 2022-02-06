/*
Show the use of the library qsort function
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int
string_ascending(const void *v1, const void *v2) {
    return strcmp(*(char**)v1, *(char**)v2);
}

int
string_length(const void *v1, const void *v2) {
    return strlen(*(char**)v1) - strlen(*(char**)v2);
}

int main(int argc, char *argv[]) {
    int i;
    char *S[] = {"wombat", "wallaby", "quoll", "quokka", "koala", "kangaroo", "goanna", "bilby"};

    //  Array,  How many elemnts,how big each element is, what order you want them in
    qsort(S, sizeof(S)/sizeof(*S), sizeof(*S), string_length);
    for (i=0; i<sizeof(S)/sizeof(*S); i++) {
        printf("%s\n", S[i]);
    }
    return 0;
}
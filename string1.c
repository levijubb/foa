/*
First example from Wk6 lectures
*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    char *p = "Hello World!";
    
    while (*p)
    {
        printf("p = %12p, string at p = %s\n", p, p);
        p++;
    }

    return 0;
}
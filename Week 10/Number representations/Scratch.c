
#include <stdio.h>
#include <stdlib.h>

#define SOMTHIN 500
int hello = 5;

void printer(int x);

int 
main(int argc, char *argv[])
{
    printer(SOMTHIN);
    printer(hello);
    return 0;
}

void
printer(int x) {
    printf("%s = %d\n", #x, x);
}
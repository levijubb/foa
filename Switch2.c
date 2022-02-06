/*
Another switch statement example
*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    int i, x;
    for (i = 1; i <=10; i++) {
        x = i;
        switch (x) {
            case 1:
                x += 4;
            case 4:
            case 7:
                x += 2;
                break;
            case 3:
            case 9:
                x += 3;
            default:
                x += 8;
                
        }
    printf("i = %2d, x = %2d\n", i, x);
    }
    return 0;
}
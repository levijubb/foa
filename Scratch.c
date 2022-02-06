/*
INSERT TITLE
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>

// C program to set the value 
// of unsigned char array during runtime 
  
#include <stdio.h> 
#include <string.h> 

int 
main(int argc, char *argv[]) {
        int n=10;
        int i, j, k;
        int sum1=0, sum2=0, sum3=0;
        for (i=1; i<=n; i*=2) {
            sum1++;
            printf("1=%d\n", sum1);                          // location 1
            for (j=0; j<i; j++) {
                sum2++;
                printf("2=%d\n", sum2);                          // location 1
                    // location 2
                for (k=0; k*k<n; k++) {
                    printf("3=%d\n", sum3);                          // location 1
                    sum3++;                     // location 3
                }
            }
        }
        printf("1max=%d\n", sum1);                          // location 1
        printf("2max=%d\n", sum2);                          // location 1
        printf("3max=%d\n", sum3);                          // location 1
    
    


    return 0;
}
/*
FINDING AMICABLE PAIRS. LEVI JUBB, 24/AUG/2020
*/
#include <stdio.h>
#include <stdlib.h>

int
amic_pair(int fst, int snd) {
    int fst_sum = 0, snd_sum = 0;
    //Counting from 1 to largest of two imputs
    int lrgst_multiple = ((fst > snd) ? (fst) : (snd)) / 2;
    for (int n = 1; n <= lrgst_multiple; n++) {
        if (fst % n == 0) {
            fst_sum += n;
        }
        if (snd % n == 0) {
            snd_sum += n;
        }
    }
   return (fst_sum == snd) && (snd_sum == fst);
}


int
main(int argc, char *argv[]) {
    int inone, intwo;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &inone, &intwo);

    printf("**************\nAMICABLE?: %d\n**************\n", amic_pair(inone, intwo));
    return 0;
}
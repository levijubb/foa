/* Simulate a game of chance using random numbers.
*/
#include <stdio.h>
#include <stdlib.h>

#define START_AT 5
#define STOP_AT 20
#define SEED 1234567
/* use SEED 12345678 gives 133 games and EUREKA */

int
main(int argc, char *argv[]) {
	int cash=START_AT, games=0, dice1, dice2, i;
	printf("seed for this run = %d\n", SEED);
	srand(SEED);
	while (0<cash && cash<STOP_AT) {
		printf("%3d games |", games);
		for (i=0; i<cash-1; i++) {
			printf(" ");
		}
		printf("*\n");
		games += 1;
		cash -= 1;
		dice1 = 1 + rand()%6;
		dice2 = 1 + rand()%6;
		if (dice1+dice2 == 12) {
			cash += 6;
		} else if (dice1+dice2 >= 8) {
			cash += 2;
		}
	}
	printf("%3d games |", games);
	if (cash==0) {
		printf("BUST :-(\n");
	} else {
		printf("EUREKA!\n");
	}
	return 0;
}

/* =====================================================================
   Program written by Alistair Moffat, as an example for the book
   "Programming, Problem Solving, and Abstraction with C", Pearson
   Custom Books, Sydney, Australia, 2002; revised edition 2012,
   ISBN 9781486010974.

   See http://people.eng.unimelb.edu.au/ammoffat/ppsaa/ for further
   information.

   Prepared December 2012 for the Revised Edition.
   ================================================================== */
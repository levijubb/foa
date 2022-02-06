/* Simulate a game of chance using random numbers.
*/
#include <stdio.h>
#include <stdlib.h>

#define START_AT 5
#define STOP_AT 20
#define SEED 1234567

#define NRUNS 100000

int
main(int argc, char *argv[]) {
	int cash, games, dice1, dice2, i;
	int wgames=0, lgames=0, winners=0, losers=0;
	printf("seed for this run = %d\n", SEED);
	srand(SEED);
	for (i=0; i<NRUNS; i++) {
		cash = START_AT;
		games = 0;
		while (cash>0 && cash<STOP_AT) {
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
		/* printf("cash=%d, games=%d\n", cash, games); */
		if (cash==0) {
			lgames += games;
			losers += 1;
		} else {
			wgames += games;
			winners += 1;
		}
	}
	printf("winning players: %6d, average length %.1f games\n",
			winners, (double)wgames/winners);
	printf("losing players : %6d, average length %.1f games\n",
			losers, (double)lgames/losers);
	printf("overall        : %6d, average length %.1f games\n",
			winners+losers, 
			(double)(wgames+lgames)/(winners+losers));
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
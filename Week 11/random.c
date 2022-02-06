/* Show the use of srand and rand.
*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	int seed=83449168, i;
	char toss[] = "HT";
	if (argc==2) {
		seed = atoi(argv[1]);
	}
	srand(seed);
	for (i=0; i<5; i++) {
		printf("coin = %c, dice = %d, float = %.6f\n",
			toss[rand()%2], 1+rand()%6,
			rand()/(1.0+RAND_MAX));
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
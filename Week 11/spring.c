/* Program to show numeric solution to ordinary differential equation
 * involving a spring
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define K      10.0  /* spring constant, N/m */
#define C      2.0   /* damping force, Ns/m */
#define EPS    1e-6  /* stopping condition */
#define INTERV 0.5   /* interval on output snapshots, in seconds */

#define MIN_X  -1.1  /* presumed min x on spring */
#define MAX_X  +1.1  /* presumed min x on spring */
#define SCALE  55.0  /* multiplier for output graph */

void
graph(double t, double x) {
	int draw_x, i;
	int draw_axis;
	if (x<MIN_X || x>MAX_X) {
		printf("Mechanical failure!\n");
		exit(EXIT_FAILURE);
	}
	draw_x    = (int)(SCALE*(x-MIN_X)/(MAX_X-MIN_X));
	draw_axis = (int)(SCALE*(0-MIN_X)/(MAX_X-MIN_X));
	printf("%5.2f:", t);
	for (i=0; i<draw_x; i++) {
		if (i==draw_axis) {
			printf("|");
		} else {
			printf(" ");
		}
	}
	printf("x");
	if (draw_axis>draw_x) {
		for (i=draw_x+1; i<draw_axis; i++) {
			printf(" ");
		}
		printf("|");
	}
	printf("\n");
}

int
main(int argc, char *argv[]) {
	double a, v, x, t, m, deltat, next_output_time=-EPS;
	if (argc!=4) {
		printf("Usage: %s x_0 m deltat\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	x = atof(argv[1]);
	m = atof(argv[2]);
	deltat = atof(argv[3]);
	v = 0.0;
	t = 0.0;
	while (fabs(x)>EPS || fabs(v)>EPS) {
		if (t > next_output_time) {
			graph(t, x);
			next_output_time += INTERV;
		}
		a = (1/m)*(-K*x - C*v);
		x += deltat * v;
		v += deltat * a;
		t += deltat;
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
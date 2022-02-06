/*
Quick code for calculating the first 11 elements of an infinite series
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double
factorial(int n) {
	int i, tot =1;
	for (i=1; i <= n; i++) {
		tot *= i;
	}
	return tot;
}

double
power(int p) {
	int i;
	double tot=1;
	for (i=0; i < p; i++) {
		tot *= -1;
	}
	return tot;
}


int
main(int argc, char *argv[]) {
	double ojsado = power(6);
	printf("%lf", ojsado);
	
	int i;
	double sum;
	for (i=0; i < 11; i++) {
		printf("%d is ", i);
		double po = power(i);
		int fac = factorial(i);
		sum += po/fac;
		printf("%1.0f/%d\n", po, fac);
	}
	printf("The series converges to: %lf", sum);
    return 0;
}
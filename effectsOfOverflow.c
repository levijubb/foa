// Program that will show the effects of integer overflow

#include <stdio.h>

int main(int argc, char *argv[]) {
    int big, bp1, bt2, bp1t2; //Allocating memory for variables
	big   = 2147483647;//
	bp1   = big+1;//
	bt2   = big*2;// Assigning variables
	bp1t2 = bp1*2;//
	printf("big=%d, bp1=%d, bt2=%d, bp1t2=%d\n",
		big, bp1, bt2, bp1t2);// %d is fstring for consecutive variables
	return 0;
}
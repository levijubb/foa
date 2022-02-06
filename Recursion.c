/*
Example 5.8 from the textbook. An example of recursion
*/
#include <stdio.h>
#include <stdlib.h>

// Calculate the sum of consecutive numbers

// For loop:
int
t_for(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

//Recursion:
int
t_rec (int n) {
    if (n == 0) {
        return n;
    } else {
        return n + t_rec(n - 1);
    }
}

int
main(int argc, char *argv[]) {
    int number;
    printf("Enter a number: ");
    
    if (scanf("%d", &number) != 1) {
        printf("Please enter an integer");
        exit(EXIT_FAILURE);
    }
    printf("The for example returned: %d\nThe recursion example returned %d\n", t_for(number), t_rec(number));

    return 0;
}
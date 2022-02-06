/*
This is my attemp at writing the BMH substring search algorithm from scratch.
*/

#include <stdio.h>
#include <stdlib.h>

#define ALPHABET 26

typedef int BMT_t[ALPHABET];

typedef struct {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    int w;
    int x;
    int y;
    int z;
} alphabet_t;

alphabet_t alphabet_s = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20, 21, 22, 23, 24, 25};






int
main(int argc, char *argv[]) {
    printf("%d\n", alphabet_s.e);
    return 0;
}

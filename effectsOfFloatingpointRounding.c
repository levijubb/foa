// Program to show effects of floating point rounding

#include <stdio.h>

int
main(int argc, char *argv[]) {
    double x, y, z;
    x = 0.1;
    y = x + x + x + x + x + x + x + x + x + x;
    z = y - 1.0;

  printf("x=%23.20f\ny=%23.20f\nz=%23.20f\n", x, y, z);
  return 0;
}
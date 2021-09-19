/* succ-double.c */
/*
  MARC BALLESTERO RIBO (M1b)

  Calcula els 40 primers termes de la recurrència proposada a l'enunciat usant
  variables double.
*/

#include <stdio.h>
#include <math.h>


int main(void) {
  double a = 6.2, b = .5;
  double xn, xn1 = .01;
  int n;

  for(n = 0; n <= 40; ++n) {
    printf("x_%d = %+.20e\n", n, xn1);
    xn = exp(-a*pow(xn1, 2)) + b;
    xn1 = xn;
  }

  return 0;
}

/* succ-float.c */
/*
  MARC BALLESTERO RIBO (M1b)

  Calcula els 40 primers termes de la recurrència proposada a l'enunciat usant
  variables float.
*/

#include <stdio.h>
#include <math.h>

#define FLOAT_ERR 1.19e-7

int main(void) {
  float a = 6.2, b = .5;
  float xn, xn1 = .01, dxn, dxn1 = .01*FLOAT_ERR;
  int n;

  for (n = 0; n <= 40; ++n) {
    printf("x_%d = %+.20e\t+-\t%+.20e\n", n, xn1, dxn1);
    xn = exp(-a*pow(xn1, 2)) + b;
    dxn = 2*a*xn*exp(-a*pow(xn, 2)) * dxn1;
    xn1 = xn, dxn1 = dxn;
  }

  return 0;
}

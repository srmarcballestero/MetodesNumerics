/* interpolacio.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double avalua(double *, double *, int, double);

int main(void) {



  return 0;
}


double avalua(double *x, double *c, int n, double z) {
  int j;
  double p = c[n-1];

  for (j = n-2; j > -1; --j)
    p = (z - x[j])*p + c[j];

  return p;
}

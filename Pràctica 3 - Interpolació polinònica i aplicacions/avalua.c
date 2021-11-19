/* avalua.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "interpolacio.h"


double avalua(double *x, double *c, int n, double z) {
  int j;
  double p = c[n];

  for (j = n-1; j > -1; --j)
    p = (z - x[j])*p + c[j];

  return p;
}

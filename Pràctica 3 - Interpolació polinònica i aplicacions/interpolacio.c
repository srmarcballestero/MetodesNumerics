/* interpolacio.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "interpolacio.h"


void interpolacio(double *x, double *f, int n, double *c) {
  int i, j;

  for (i = 0; i < n+1; ++i)
    c[i] = f[i];

  for (j = 0; j < n; ++j) {
    for (i = n; i > j; --i)
      c[i] = (c[i]-c[i-1]) / (x[i]-x[i-j-1]);
  }

  return;
}

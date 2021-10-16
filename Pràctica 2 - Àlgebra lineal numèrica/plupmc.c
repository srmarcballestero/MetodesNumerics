/* plupmc.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "lineal.h"

double plupmc(int n, double **c, int *p, double tol) {
  int i, j, k, pivot_ind = 0, temp_ind;
  double pivot, *temp_row, det = 1.;

  for (j = 0; j < n-1; ++j) {
    pivot = 0.;
    for (i = j; i < n; ++i)
      if (fabs(c[i][j]) > fabs(pivot)) {
        pivot = c[i][j];
        pivot_ind = i;
      }

    temp_row = c[j];
    c[j] = c[pivot_ind];
    c[pivot_ind] = temp_row;

    temp_ind  = p[j];
    p[j] = p[pivot_ind];
    p[pivot_ind] = temp_ind;

    for (i= j+1; i < n; ++i) {
      if (c[j][j] < tol)
        return 0.;
      c[i][j] /= c[j][j];
      for (k = j+1; k < n; ++k)
        c[i][k] -= c[i][j]*c[j][k];
    }
  }

  for (i = 0; i < n; ++i)
    det *= c[i][i];

  return det;
}

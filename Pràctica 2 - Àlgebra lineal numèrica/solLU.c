#include "lineal.h"

void solLu(int n, double **c, double *b, double *x) {
  int i, j;
  double *y, sum;

  y = (double *) calloc(n, sizeof(double));
  if (y == NULL) {
    perror("Error de memoria!\n");
    exit(1);
  }

  /* Sistema Ly = b */
  y[0] = b[0] / 1.;
  for (i = 1; i < n; ++i) {
    sum = 0.;
    for (j = 0; j < i; ++j) {
      sum += c[i][j] * y[j];
    }
    sum += 1. * y[i];
    if (i == j)
      y[i] = (b[i] - sum) / 1.;
    else
      y[i] = (b[i] - sum) / c[i][i];
  }

  /* Sistema Ux = y */
  x[n-1] = y[n-1] / c[n-1][n-1];
  for (i = n-2; i > -1; --i) {
    sum = 0.;
    for (j = i; j < n; ++j) {
      sum += c[i][j] * x[j];
    }
    x[i] = (y[i] - sum) / c[i][i];
  }

  free(y);

  return;
}

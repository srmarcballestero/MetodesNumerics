/* lineal1.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


void solLu(int, double **, double *, double *);


int main(void) {
  int n, na, nb;
  int i, j, k;
  double **A, *b, *x;
  double rtemp, normS, normMax = INT_MIN;
  FILE *fin;

  fin = fopen("matriu.in", "r");

  fscanf(fin, "%d", &n);
  fscanf(fin, "%d %d", &na, &nb);

  A = (double **) calloc(n, sizeof(double*));
  for (k = 0; k < n; ++k)
    A[k] = (double *) calloc(n, sizeof(double));

  b = (double *) calloc(n, sizeof(double));

  x = (double *) calloc(n, sizeof(double));

  if (A == NULL || b == NULL || x == NULL) {
    printf("Error de memoria!\n");
    return -1;
  }


  for (k = 0; k < na; ++k) {
    fscanf(fin, "%d %d %lf", &i, &j, &rtemp);
    A[i][j] = rtemp;
  }

  for (k = 0; k < nb; ++k) {
    fscanf(fin, "%d %lf", &j, &rtemp);
    b[j] = rtemp;
  }

  fclose(fin);

  /*
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j)
      printf("%f ", A[i][j]);
    printf("\n");
  }

  for (j = 0; j < n; ++j)
    printf("%f ", b[j]);
  */

  /* Normes sub-infinit de A i b */
  printf("Normes sub-infinit de la matriu i el vector\n");

  for (i = 0; i < n; ++i) {
    normS = 0.;
    for (j = 0; j < n; ++j)
      normS += A[i][j];
    if (normS > normMax)
      normMax = normS;
  }
  printf("||A|| = %.6e\n", normMax);

  normMax = INT_MIN;
  for (j = 0; j < n; ++j) {
    normS = b[j];
    if (normS > normMax)
      normMax = normS;
  }
  printf("||b|| = %.6e\n", normMax);

  solLu(n, A, b, x);


  for (k = 0; k < n; ++k)
    free(A[k]);
  free(A);

  free(b);
  free(x);

  return 0;
}


void solLu(int n, double **c, double *b, double *x) {
  int i, j;
  double y[n], sum;

  /* Sistema Ly = b */
  y[0] = b[0] / 1.;
  for (i = 1; i < n; ++i) {
    sum = 0.;
    for (j = 0; j < i; ++j) {
      if (i == j)
        sum += 1. * y[j];
      else
        sum += c[i][j] * y[j];
    }
    if (i == j)
      y[j] = (b[i] - sum) / 1.;
    else
      y[j] = (b[i] - sum) / c[i][j];
  }

  for (i = 0; i < n; ++i)
    printf("%.3f ", y[i]);
  printf("\n");

  /* Sistema Ux = y */
  x[n-1] = y[n-1] / c[n-1][n-1];
  for (i = n-2; i >= 0; --i) {
    x[i] = y[i];
    for (j = i+1; j < n; ++j) {
      x[i] -= c[i][j] * x[j];
    }
    x[i] /= c[i][i];
  }

  for (i = 0; i < n; ++i)
    printf("%.3f ", x[i]);
  printf("\n");

  return;
}

/* lineal1.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


void solLu(int, double **, double *, double *);
double plupmc(int, double **, int * , double);


int main(void) {
  int n, na, nb;
  int i, j, k;
  int *p;
  double **A, *b, *x;
  double rtemp, normS, normMax = INT_MIN;
  FILE *fin;

  fin = fopen("matriu.in", "r");
  if (fin == NULL) {
    perror("Error obrint el fitxer d'entrada!\n");
    exit(1);
  }

  fscanf(fin, "%d", &n);
  fscanf(fin, "%d %d", &na, &nb);

  A = (double **) calloc(n, sizeof(double*));
  for (k = 0; k < n; ++k)
    A[k] = (double *) calloc(n, sizeof(double));

  b = (double *) calloc(n, sizeof(double));

  x = (double *) calloc(n, sizeof(double));

  p = (int *) malloc(n * sizeof(int));

  if (A == NULL || b == NULL || x == NULL || p == NULL) {
    perror("Error de memoria!\n");
    exit(1);
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

  for (k = 0; k < n; ++k)
    p[k] = k;

  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j)
      printf("%f ", A[i][j]);
    printf("\n");
  }

  for (j = 0; j < n; ++j)
    printf("%f ", b[j]);
  printf("\n");

  /* Normes sub-infinit de A i b */
  printf("Normes sub-infinit de la matriu i el vector\n");

  for (j = 0; j < n; ++j) {
    normS = 0.;
    for (i = 0; i < n; ++i)
      normS += A[i][j];
    if (normS > normMax)
      normMax = normS;
  }
  printf("||A|| = %.0e\n", normMax);

  normMax = INT_MIN;
  for (j = 0; j < n; ++j) {
    normS = b[j];
    if (normS > normMax)
      normMax = normS;
  }
  printf("||b|| = %.0e\n", normMax);

  solLu(n, A, b, x);
  for (k = 0; k < n; ++k)
    printf("%+.3e ", x[k]);
  printf("\n");

  plupmc(n, A, p, 0.);

  for (k = 0; k < n; ++k)
    free(A[k]);
  free(A);

  free(b);
  free(x);
  free(p);

  return 0;
}


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


double plupmc(int n, double **c, int *p, double tol) {
  int i, j, k, pivot_ind = 0, temp_ind;
  int ii, jj;
  double pivot = (double) INT_MIN, *temp_row;

  for (j = 0; j < n; ++j) {

    pivot = (double) INT_MIN;
    for (i = j; i < n; ++i)
      if (fabs(c[i][j]) > fabs(pivot)) {
        pivot = c[i][j];
        pivot_ind = i;
      }

    temp_row = c[0];
    c[0] = c[pivot_ind];
    c[pivot_ind] = temp_row;

    temp_ind  = p[0];
    p[0] = p[pivot_ind];
    p[pivot_ind] = temp_ind;

    printf("Pas %d\n", j);
    for (ii = 0; ii < n; ++ii) {
      for (jj = 0; jj < n; ++jj)
        printf("%f ", c[ii][jj]);
      printf("\n");
    }
    printf("\n");

    for (k = j+1; k < n; ++k) {
      c[k][j] /= c[j][j];
      c[k][k] -= c[k][j]*c[j][k];
    }

  }

  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if (i>j)
        printf("%f ", c[i][j]);
      else if (i==j)
        printf("%f ", 1.);
      else
        printf("%f ", 0.);
    }
    printf("\n");
  }

  printf("\n");

  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if (i>j)
        printf("%f ", 0.);
      else
        printf("%f ", c[i][j]);

    }
    printf("\n");
  }

  for (i = 0; i < n; ++i)
    printf("%d ", p[i]);
  printf("\n");

  return 0.;
}

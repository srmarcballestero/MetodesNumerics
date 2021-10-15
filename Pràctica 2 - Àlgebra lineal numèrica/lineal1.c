/* lineal1.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "lineal.h"


int main(void) {
  int n, na, nb;
  int i, j, k;
  int *p;
  double **A, *b, *x;
  double rtemp, normS, normMax = 0.;
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
      printf("%+2.0f ", A[i][j]);
    printf("\n");
  }

  for (j = 0; j < n; ++j)
    printf("%f ", b[j]);
  printf("\n");

  /* Normes sub-infinit de A i b */
  printf("Normes sub-infinit de la matriu i el vector\n");

  for (i = 0; i < n; ++i) {
    normS = 0.;
    for (j = 0; j < n; ++j)
      normS += fabs(A[i][j]);
    if (normS > normMax)
      normMax = normS;
  }
  printf("||A|| = %.0e\n", normMax);

  normMax = 0.;
  for (j = 0; j < n; ++j) {
    normS = fabs(b[j]);
    if (normS > normMax)
      normMax = normS;
  }
  printf("||b|| = %.0e\n", normMax);

  printf("%f\n", plupmc(n, A, p, 1e-16));

  j = 0;
  for (i = 0; i < n; ++i) {
    j = p[i];
    while (j < i)
      j = p[j];
    rtemp = b[i];
    b[i] = b[j];
    b[j] = rtemp;
  }

  solLu(n, A, b, x);
  for (k = 0; k < n; ++k)
    printf("%+.3e ", x[k]);
  printf("\n");

  for (k = 0; k < n; ++k)
    free(A[k]);
  free(A);

  free(b);
  free(x);
  free(p);

  return 0;
}

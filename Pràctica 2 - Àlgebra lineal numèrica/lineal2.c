/* lineal2.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "lineal.h"


int main(void) {
  int n, na, nb;
  int i, j, k;
  int *p;
  double **A, *b, *x, *d;
  double rtemp, normS, normMax = 0.;
  double det, tol;
  FILE *fin, *fout;

  fin = fopen("sis1.data", "r");
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

  d = (double *) calloc(n, sizeof(double));

  p = (int *) malloc(n * sizeof(int));

  if (A == NULL || b == NULL || x == NULL || p == NULL || d == NULL) {
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


  /* Vector de permutacio de files */
  for (k = 0; k < n; ++k)
    p[k] = k;


  /* Resolucio del sistema Ax = b */
  fout = fopen("sis1.res", "w");
  if (fout == NULL) {
    perror("Error obrint el fitxer de sortida!\n");
    exit(1);
  }

  /* Calcul de la descomposcio PA = LU i det(A) */
  printf("Tolerancia per a la descomposicio LU = ");
  scanf("%lf", &tol);
  det = plupmc(n, A, p, tol);
  fprintf(fout, "det(A) = %+.6e\n", det);

  /* Apliquem la permutacio P al vector de termes independents */
  j = 0;
  for (i = 0; i < n; ++i) {
    j = p[i];
    while (j < i)
      j = p[j];
    rtemp = b[i];
    b[i] = b[j];
    b[j] = rtemp;
  }

  /* Resolem el sistema LU = Pb */
  fprintf(fout, "Solucio del sistema Ax = b:\n");
  solLU(n, A, b, x);
  for (k = 0; k < n; ++k)
    fprintf(fout, "%+.6e ", x[k]);
  fprintf(fout, "\n");

  /* Calculem ||Ax-b||_inf */
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j)
      A[i][j] = 0.;
    b[i] = 0.;
  }

  rewind(fin);
  fscanf(fin, "%*[^\n]\n");
  fscanf(fin, "%*[^\n]\n");

  for (k = 0; k < na; ++k) {
    fscanf(fin, "%d %d %lf", &i, &j, &rtemp);
    A[i][j] = rtemp;
  }

  for (k = 0; k < nb; ++k) {
    fscanf(fin, "%d %lf", &j, &rtemp);
    b[j] = rtemp;
  }

  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j)
      d[i] += A[i][j]*x[j];
    d[i] -= b[i];
  }

  for (j = 0; j < n; ++j) {
    normS = fabs(d[j]);
    if (normS > normMax)
      normMax = normS;
  }

  fprintf(fout, "||Ax-b|| = %.6e\n", normMax);

  fclose(fin);
  fclose(fout);

  for (k = 0; k < n; ++k)
    free(A[k]);
  free(A);

  free(b);
  free(x);
  free(d);
  free(p);

  return 0;
}

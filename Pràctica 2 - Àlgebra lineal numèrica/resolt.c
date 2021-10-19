/* resolt.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "lineal.h"


int main(void) {
  int n, na, nb;
  int i, j, k;
  double **A, *b, *x;
  double rtemp;
  FILE *fin;

  /* Obertura del fitxer d'entrada */
  fin = fopen("matriuC.data", "r");
  if (fin == NULL) {
    perror("Error obrint el fitxer d'entrada!\n");
    exit(1);
  }

  /* Lectura de les dimensions */
  fscanf(fin, "%d", &n);
  fscanf(fin, "%d %d", &na, &nb);

  /* Reserva de memoria dinamica */
  A = (double **) calloc(n, sizeof(double*));
  for (k = 0; k < n; ++k)
    A[k] = (double *) calloc(n, sizeof(double));

  b = (double *) calloc(n, sizeof(double));

  x = (double *) calloc(n, sizeof(double));

  if (A == NULL || b == NULL || x == NULL) {
    perror("Error de memoria!\n");
    exit(1);
  }


  /* Lectura de la matriu i el vector */
  for (k = 0; k < na; ++k) {
    fscanf(fin, "%d %d %lf", &i, &j, &rtemp);
    A[i][j] = rtemp;
  }

  for (k = 0; k < nb; ++k) {
    fscanf(fin, "%d %lf", &j, &rtemp);
    b[j] = rtemp;
  }

  fclose(fin);

  /* Resolucio del sistema d'equacions */
  solLU(n, A, b, x);

  printf("Solucio del sistema\n");
  for (i = 0; i < n; ++i)
    printf("%+.6e ", x[i]);
  printf("\n");


  /* Alliberament de la memoria dinamica */
  for (k = 0; k < n; ++k)
    free(A[k]);
  free(A);

  free(b);
  free(x);

  return 0;
}

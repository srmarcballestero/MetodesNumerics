/* lineal1.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
  int n, na, nb;
  int i, j, k;
  double **A, *b;
  double rtemp, normS, normMax = 0.;
  FILE *fin;

  /* Obertura del fitxer d'entrada */
  fin = fopen("sis1.data", "r");
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

  if (A == NULL || b == NULL) {
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

  /* Imprimim per pantalla A i b */
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
  printf("||A|| = %+.6e\n", normMax);

  normMax = 0.;
  for (j = 0; j < n; ++j) {
    normS = fabs(b[j]);
    if (normS > normMax)
      normMax = normS;
  }
  printf("||b|| = %+-6e\n", normMax);


  /* Alliberament de la memoria dinamica */
  for (k = 0; k < n; ++k)
    free(A[k]);
  free(A);

  free(b);

  return 0;
}

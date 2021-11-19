/* interpolacio.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535897932


double avalua(double *, double *, int, double);
void interpolacio(double *, double *, int, double *);


int main(void) {
  int n = 10, nf = 199, i;
  double *x, *f, *c, z, p;
  FILE *fout;

  x = (double *) calloc(n+1, sizeof(double));
  f = (double *) calloc(n+1, sizeof(double));
  c = (double *) calloc(n+1, sizeof(double));


  /* Ex. 3: Fenomen de Runge */

  for (i = 0; i < n+1; ++i) {
    x[i] = -1. + 2./n * i;
    f[i] = 1. / (1.+25.*x[i]*x[i]);
  }

  interpolacio(x, f, n, c);


  fout = fopen("runge.res", "w");
  if (fout == NULL) {
    printf("Error obrint el fitxer de sortida!\n");
    exit(-1);
  }

  for (i = 0; i < nf+1; ++i) {
    z = -1. + 2./nf * i;
    p = avalua(x, c, n, z);
    fprintf(fout, "%+.6e %+.6e\n", z, p);
  }
  fclose(fout);


  /* Ex. 4: Abscisses de Txevixev */

  for (i = 0; i < n+1; ++i) {
    x[i] = cos(((2*i+1)*PI) / (2*n + 2));
    f[i] = 1. / (1.+25.*x[i]*x[i]);
  }

  interpolacio(x, f, n, c);


  fout = fopen("txevixev.res", "w");
  if (fout == NULL) {
    printf("Error obrint el fitxer de sortida!\n");
    exit(-1);
  }

  for (i = 0; i < nf+1; ++i) {
    z = -1. + 2./nf * i;
    p = avalua(x, c, n, z);
    fprintf(fout, "%+.6e %+.6e\n", z, p);
  }
  fclose(fout);


  free(x);
  free(f);
  free(c);

  return 0;
}


double avalua(double *x, double *c, int n, double z) {
  int j;
  double p = c[n];

  for (j = n-1; j > -1; --j)
    p = (z - x[j])*p + c[j];

  return p;
}

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


/*
  RESPOSTES A LES PREGUNTES
    (3) Veure fitxers "runge.res" i "runge.png".
    (4) Veure fitxers "txevixev.res" i "txevixev.res". En tots dos casos, els
        polinomis calculats interpolen la funcio proposada en els punts
        corresponents. Si mes no, observem que en el cas de l'interpolacio
        en les abscisses de Txevixev, el polinomi s'aproxima millor a la corba
        de la funcio proposada, ja que, en els punts allunyats del maxim local
        de la funcio, el polinomi d'interpolacio no presenta tantes oscilacions
        com el que s'obte interpolant abscisses lineals.
*/

/* runge-txebi.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "interpolacio.h"


int main(void) {
  int n = 10, nf = 199, i;
  double *x, *f, *c, z, p;
  FILE *fout;

  x = (double *) calloc(n+1, sizeof(double));
  f = (double *) calloc(n+1, sizeof(double));
  c = (double *) calloc(n+1, sizeof(double));


  /* Ex. 4: Abscisses de Txevixev */

  for (i = 0; i < n+1; ++i) {
    x[i] = cos(((2*i+1)*PI) / (2*n + 2));
    f[i] = 1. / (1.+25.*x[i]*x[i]);
  }

  interpolacio(x, f, n, c);


  fout = fopen("runge-txebi.res", "w");
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


/*
  RESPOSTES A LES PREGUNTES
    (3) Veure fitxers "runge-equi.res" i "runge-equi.png".
    (4) Veure fitxers "runge-txebi.res" i "runge-txebi.png". En tots dos casos,
        els polinomis calculats interpolen la funcio proposada en els punts
        corresponents. Si mes no, observem que en el cas de l'interpolacio
        en les abscisses de Txevixev, el polinomi s'aproxima millor a la corba
        de la funcio proposada, ja que, en els punts allunyats del maxim local
        de la funcio, el polinomi d'interpolacio no presenta tantes oscilacions
        com el que s'obte interpolant abscisses lineals.
*/

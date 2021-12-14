/* primitiva.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "integracio.h"


int main(void) {
  int i, imax = 30, m = 10;
  double h, x, sf = 0., a = 0., b = 1., tol = 1.e-12;
  FILE *fout;

  fout = fopen("primitiva.res", "w");

  h = (b-a) / m;

  for (i = 0; i < m+1; ++i) {
    x = a + i*h;
    imax = 30;
    printf("%d\n", duptrap(a, x, tol, &imax, &sf));
    fprintf(fout, "%+.6e %+.6e\n", x, sf);
  }

  fclose(fout);

  return 0;
}

double f(double x) {
  return 1.;
}

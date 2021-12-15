/* duptrap.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "integracio.h"


int duptrap(double a, double b, double tol, int *imax, double *integ) {
  int i, j, n = 1;
  double h, integAnt, err = 1.+tol;

  for (i = 0; err >= tol ; ++i) {
    integAnt = *integ;
    if (i == *imax)
      return 1;

    h = fabs(b-a) / n;
    *integ = h * .5 * (f(a)+f(b));

    for (j = 1; j < n; ++j) {
      *integ += h * f(a+j*h);
    }

    err = fabs(*integ - integAnt);

    n *= 2;
  }

  *imax = i;

  return 0;
}

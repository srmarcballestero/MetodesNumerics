/* intnewt.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "integracio.h"


int main(void) {
  int imax = 30;
  double a, z, z1 = 0., fz = 0., tol = 1.e-12;

  printf("Aproximacio inicial del zero:");
  scanf("%lf", &z);

  do {
    if (!duptrap(0., z, tol, &imax, &fz))
      z -= fz / f(z);
    else {
      printf("Error en la integracio!\n");
      return 1;
    }
  } while (fabs(z-z1) >= tol || fabs(fz) >= tol);

  return 0;
}

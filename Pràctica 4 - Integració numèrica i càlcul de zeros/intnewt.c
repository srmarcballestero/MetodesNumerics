/* intnewt.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "integracio.h"


int main(void) {
  int imax = 30;
  double a, z = 0., z1 = 0., fz = 0., tol = 1.e-12;

  printf("Aproximacio inicial del zero:");
  scanf("%lf", &z);

  do {
    z1 = z;
    if (!duptrap(0., z, tol, &imax, &fz)) {
      z -= fz / f(z);
      imax = 30;
    }
    else {
      printf("Error en la integracio!\n");
      return 1;
    }
  } while (fabs(z-z1) >= tol || fabs(fz) >= tol);

  printf("Zero trobat: %.6e\n", z);

  return 0;
}

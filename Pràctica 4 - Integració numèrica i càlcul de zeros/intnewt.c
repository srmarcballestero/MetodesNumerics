/* intnewt.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "integracio.h"


int main(void) {
  int j = 1, jmax, imax = 30;
  double a, z, z1, fz = 0., tol;

  printf("a = ");
  scanf("%lf", &a);

  printf("tol = ");
  scanf("%lf", &tol);

  printf("Maxim d'iterats:");
  scanf("%d", &jmax);

  printf("Aproximacio inicial del zero:");
  scanf("%lf", &z);

  do {
    if (j >= jmax) {
      printf("No s'ha pogut trobar un zero amb la precisio demanada!\n");
      return 1;
    }

    z1 = z;
    if (!duptrap(0., z, tol, &imax, &fz)) {
      z -= fz / f(z);
      imax = 30;
    }
    else {
      printf("Error en la integracio!\n");
      return 1;
    }
    ++j;
  } while (fabs(z-z1) >= tol || fabs(fz) >= tol);

  printf("Zero trobat: %.12e\n", z);
  printf("Iteracions del metode: %d\n", j);

  return 0;
}

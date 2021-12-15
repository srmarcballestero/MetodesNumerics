/* primitiva.c */
/*
  MARC BALLESTERO RIBO (M1b)
*/


#include "integracio.h"


int main(void) {
  int i, dup, imax = 30, m = 100;
  double h, x, sf = 0., a = 0., b = 4., tol = 1.e-12;
  FILE *fout;

  fout = fopen("primitiva2.res", "w");

  if (fout == NULL) {
    printf("Error obrint el fitxer de sortida!\n");
    return 1;
  }

  h = fabs(b-a) / m;

  for (i = 0; i < m+1; ++i) {
    x = a + i*h;
    imax = 30;
    dup = duptrap(a, x, tol, &imax, &sf);

    if (!dup) {
      printf("S'ha pogut integrar. Nombre d'operacions: %d\n", imax);
      fprintf(fout, "%+.12e %+.12e\n", x, sf);
    }

    else
      printf("No s'ha pogut integrar\n");
  }

  fclose(fout);

  return 0;
}

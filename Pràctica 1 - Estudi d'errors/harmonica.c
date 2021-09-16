/* harmonica.c */
/*
  MARC BALLESTERO RIBO (M1b) - NIUB20151261

  Calcula terme a terme el valor de les sumes parcials de la sèrie harmonica
  i s'atura quan s_n-1 = s_n
  Posteriorment, calcula l'ultima suma parcial sumant els termes en ordre invers
  i compara els resultats.
*/

#include <stdio.h>
#include <math.h>


int main(void) {
  float sn = 0., sn1 = 1.;
  int n, j;

  /* Suma en ordre CREIXENT */
  for (n = 1; sn != sn1; ++n) {
    sn1 = sn;
    sn += 1. / (float) n;
  }

  printf("--- Suma en ordre CREIXENT ---\n");
  printf("\tPrograma aturat després de %d iteracions.\n", n);
  printf("\ts_%d = %.20f\n\ts_%d = %.20f\n\n", n-1, sn1, n, sn);

  /* Suma en ordre DECREIXENT */
  sn = 0.;
  for (j = n; j > 0; --j) {
    sn += 1. / (float) j;
  }

  printf("--- Suma en ordre DECREIXENT ---\n");
  printf("\ts_%d = %.20f\n\n", n, sn);

  printf("Diferència absoluta entre les sumes: %.20f\n", fabs(sn-sn1));


  return 0;
}

/* harmonica.c */
/*
  Calcula terme a terme el valor de les sumes parcials de la sèrie harmonica
  i s'atura quan s_n-1 = s_n
*/

#include <stdio.h>


int main(void) {
  float sn = 0., sn1 = 1.;
  int i;

  for (i = 1; sn != sn1; ++i) {
    sn1 = sn;
    sn += 1./(float) i;

    printf("sn = %.20f, i = %d\n", sn, i);
  }

  printf("Programa aturat després de %d iteracions.\n", i);

  return 0;
}

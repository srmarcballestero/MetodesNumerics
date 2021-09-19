/* harmonica.c */
/*
  MARC BALLESTERO RIBO (M1b)

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
  printf("\ts_%d = %+.20e\n\ts_%d = %+.20e\n\n", n-1, sn1, n, sn);

  /* Suma en ordre DECREIXENT */
  sn = 0.;
  for (j = n; j > 0; --j) {
    sn += 1. / (float) j;
  }

  printf("--- Suma en ordre DECREIXENT ---\n");
  printf("\ts_%d = %+.20e\n\n", n, sn);

  printf("Diferència absoluta entre les sumes: %+.20e\n", fabs(sn-sn1));


  return 0;
}


/*
  RESPOSTES A LES PREGUNTES
    (a) Si, el programa s'aturara, i en concret ho fa per n = 209153. Aixo es
        deu al fet que les variables float tenen precisio limitada, i vist que
        en cada iteracio se sumen valors mes propers a 0 (1/n per n cada cop
        mes gran), arriba un punt en que una variable float no pot representar
        el nombre 1/n, i per tant el valor que se suma es 0.
    (b) No, el resultat difereix en 2.707...e-01 de la suma en ordre directe
        calculada en l'apartat anterior. Aixo s'explica tenint en compte que,
        com a norma general, quan un programa calcula la suma de variables float
        (i en general tipus de dades de punt flotant), aquesta operacio no es
        commutativa.
*/

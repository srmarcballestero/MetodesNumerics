/* func.c */
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
  float inici = -1.e-3, final = 1.e-3, pas = 1.e-6;
  float x, f;
  FILE *fout;

  fout = fopen("func.csv", "w");
  for (x = inici; x < final; x += pas) {
    f = pow(x, 2);
    fprintf(fout, "%+.20e,%+.20e\n", x, f);
  }

  fclose(fout);

  return 0;
}

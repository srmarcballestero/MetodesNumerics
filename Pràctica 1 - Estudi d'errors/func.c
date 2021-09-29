/* func.c */
/*
  MARC BALLESTERO RIBO (M1b)

  Calcula una taula de valors per la funcio proposada i la desa en un fitxer
  .csv
*/

#include <stdio.h>
#include <math.h>


int main(void) {
  double inici = -1.e-3, final = 1.e-3, pas = 1.e-4;
  double x, f;
  FILE *fout;

  fout = fopen("func.csv", "w");
  for (x = inici; x < final; x += pas) {
    f = -.5 + pow(x, 2)/24.;
    fprintf(fout, "%+.12f,%+.12f\n", x, f);
  }

  fclose(fout);

  return 0;
}


/*
  RESPOSTES A LES PREGUNTES
    (a) No, la grafica (grafica1.png) presenta irregularitats i punts angulosos
        que no es corresponen amb la monotonia, continuitat i diferenciabilitat
        de la funcio que es demana representar. Aixo es deu al fet que, d'una
        banda, en la resta del numerador el nombre resultant es molt proper
        a 0 i per tant hi ha un augment notable de l'error relatiu, i de
        l'altra, que al dividir en el denominador per un nombre tambe molt
        proper a 0, es dispara l'error absolut, conduint a una grafica que
        presenta un error molt significatiu.
    (b) Primer de tot, desenvolupem en serie de Taylor cosx al voltant de
        x=0 i en ordre 4, amb la qual cosa, tenim que
          f(x) = (cosx - 1)/x^2 ~ -1/2 + x^2/24 + o(x^6)/x^2 =>
          f(x) ~ -1/2 + x^2/24, per x a prop de 0.
        Amb aixo, l'error de f(x) calculada per aquest metode es la resta de
        Lagrange
          df(x) = cos(s)/6!*x^4
        on s esta entre x i 0.
        Tenim que com mes ens allunyem del 0 mes gran sera l'error en el calcul
        de la funcio, i sera maxim en els extrems de l'interval [-1.e-3, 1.e-3].
        Amb aixo, trobem que la cota de l'error en f(x) es de l'ordre
          df(x) ~ (1.e-3)^4 ~ 1.e-12
        que ja es l'error desitjat.
    (c) Si representem ambdues funcions (grafica2.png), notem que la calcualda
        per l'algorisme presentat es correspon amb el comportament esperat.
        Observant la grafica, estimem l'error del calcul de l'apartat (a) de
        l'ordre de 5e-6.
  */

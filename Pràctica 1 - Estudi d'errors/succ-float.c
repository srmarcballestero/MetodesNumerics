/* succ-float.c */
/*
  MARC BALLESTERO RIBO (M1b)

  Calcula els 40 primers termes de la recurrència proposada a l'enunciat usant
  variables float.
*/

#include <stdio.h>
#include <math.h>

#define FLOAT_ERR 1.19e-7


float expf(float);


int main(void) {
  float a = 6.2, b = -.5;
  float xn, xn1 = .01, dxn, dxn1 = xn1*FLOAT_ERR;
  int n;

  for (n = 0; n <= 40; ++n) {
    printf("x_%d = %+.8e\t+-\t%+.8e\n", n, xn1, dxn1);
    xn = expf(-a*pow(xn1, 2)) + b;
    dxn = 2.*a*fabs(xn1)*expf(-a*pow(xn1, 2)) * dxn1;
    xn1 = xn, dxn1 = dxn;
  }

  return 0;
}


/*
  RESPOSTES A LES PREGUNTES
    (a) Obtenim els valors
          float:  x_40 = +5.5(1.0)e-2
          double: x_40 = -1.899063797247(18)e-1
        que no son compatibles, i difereixen absolutament en aproximadament
        0.022.
    (b) Incloem en els programes la propagacio de l'error en x_{n+1}, partint
        dels errors inicials que es diuen en l'enunciat.
        Observem que, d'una banda, el valor obtingut amb el tipus double es
        mes proper a zero, i de l'altra, l'error absolut que te es molt inferior
        al que s'obte amb el tipus float. De fet, els errors relatius en les
        dades son
          float:  dx_40/x_40 = 18%
          double: dx_40/x_40 = 0.000000001%
        amb la qual cosa, concloem que la precisio dels calculs amb el tipus
        double es molt superior a la del tipus float.
*/

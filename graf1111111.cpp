#include "TXLib.h"

void DrawGraphic (double (*func) (double x), COLORREF color);
double Sqr (double x);

int main ()
    {

     txCreateWindow (800, 600);
     DrawGraphic(&Sqr, TX_LIGHTRED);
     DrawGraphic(&sin, TX_LIGHTGREEN);
    }


void DrawGraphic (double (*func) (double x), COLORREF color)
    {
    txSetColor (color);
    txSetFillColor (color);

    double x = - 10;
    while (x <= +10)
        {
        double y = (*func) (x);

        txCircle (400 + 50 * x, 300 - 50 * y, 3);

        x += 0.01;
        }
      }


double Sqr (double x) {return x*x;}


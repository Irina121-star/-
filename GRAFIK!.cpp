#include "TXLib.h"

void DrawGraphic (double (*func) (double x, double k),  COLORREF color);
double Sinkx (double x, double k);

int main ()
    {

     txCreateWindow (800, 600);
     DrawGraphic(&Sinkx, TX_LIGHTGREEN);
     DrawGraphic(&Sinkx, TX_LIGHTRED);
     DrawGraphic(&Sinkx, TX_CYAN);
     DrawGraphic(&Sinkx, TX_MAGENTA);
     DrawGraphic(&Sinkx, TX_ORANGE);
    }

void DrawGraphic (double (*func) (double x, double k),  COLORREF color)
    {
    txSetColor (color);
    txSetFillColor (color);

    double x = - 10;

    double k = 1;

    while (k < 5)
        {
        while (x <= +10)
            {

            double y = (*func) (x, k);

            txCircle (400 + 50 * x, 300 - 50 * y, 3);

            x += 0.01;
            }

        k = k + 1;
        txSleep(50);

        }
      }


double Sinkx (double x, double k) {return k*sin (x);}

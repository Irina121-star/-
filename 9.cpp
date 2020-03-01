#include "TXLib.h"

void DrawGraphic (double (*func) (double x, double k), double k, COLORREF color);
double Sinkx (double x, double k);

int main ()
    {

     txCreateWindow (800, 600);
     DrawGraphic(&Sinkx, 1, TX_LIGHTGREEN);
     DrawGraphic(&Sinkx, 2, TX_LIGHTRED);
     DrawGraphic(&Sinkx, 3, TX_CYAN);
     DrawGraphic(&Sinkx, 4, TX_MAGENTA);
     DrawGraphic(&Sinkx, 5, TX_ORANGE);
    }


void DrawGraphic (double (*func) (double x, double k), double k, COLORREF color)
    {
    txSetColor (color);
    txSetFillColor (color);

    double x = - 10;
    while (x <= +10)
        {
        double y = (*func) (x , k);

        txCircle (400 + 50 * x, 300 - 50 * y, 3);

        x += 0.01;
        }
      }


double Sinkx (double x, double k) {return k * sin(x);}

#include "TXLib.h"

void DrawGraphic (double (*func) (double x, double k), double k, COLORREF color);
double Sqrkx (double x, double k);

int main ()
    {

     txCreateWindow (800, 600);
     DrawGraphic(&Sqrkx, 1, TX_LIGHTGREEN);
     DrawGraphic(&Sqrkx, 2, TX_LIGHTRED);
     DrawGraphic(&Sqrkx, 3, TX_CYAN);
     DrawGraphic(&Sqrkx, 4, TX_MAGENTA);
     DrawGraphic(&Sqrkx, 5, TX_ORANGE);
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


double Sqrkx (double x, double k) {return k * x * x;}

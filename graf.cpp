#include "TXLib.h"
void DrawGraphic ();


int main ()
    {

     txCreateWindow (800,600);

     DrawGraphic();
    }

void DrawGraphic()
    {
    double x = - 10;
    while (x<= +10)
        {
        double y = x * x;
        txCircle (400 + 10 * x, 300 - 10 * y, 3);
        x = x + 0.1 ;
        }
      }

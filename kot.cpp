#include "TXLib.h"
void DrawCircle(int xx, int yy );

int main ()
    {

    txCreateWindow (800,600);
    txSetFillColor (TX_WHITE);
    txClear ();
    DrawCircle(0, 0);
    DrawCircle(1, 0);
    DrawCircle(0, 1);
    DrawCircle(1, 1);
     return 0;
    }



void DrawCircle(int xx, int yy )
    {
    txSetColor  (TX_LIGHTRED);

    for  (double y= -5; y<= +5; y+= 0.04)
        for  (double x= -10; x<= +10; x+= 0.04)
            {
             if (y * y  + x * x <=  16)
                txSetPixel (400 + xx + 50 * x, 300 + yy - 50 * y, TX_LIGHTGRAY);

             if ((y - 2) * (y - 2)  + (x - 2) * (x - 2) <=  0.4)
                txSetPixel (400 + xx + 50 * x, 300 + yy - 50 * y, TX_LIGHTGREEN);

            if ((y - 2) * (y - 2)  + (x + 2) * (x + 2) <=  0.4)
                txSetPixel (400 + xx + 50 * x, 300 + yy - 50 * y, TX_LIGHTGREEN);

            if ((y <=  0.3) && (y -x >= -0.3) && (y + x >= -0.3))
                txSetPixel (400 + 3 + 50 * x, 300 + 3 - 50 * y, TX_RED);

            if ((y <=  0.1) && (y - 3 * x <= -0.1) && (y + 3 * x <= 0.1))
                txSetPixel (500 + xx + 50 * x, 10 + yy - 50 * y, TX_LIGHTGRAY);

            if ((y <=  0.1) && (y - 3 * x <= -0.1) && (y + 3 * x <= 0.1))
                txSetPixel (300 + xx + 50 * x, 10 + yy - 50 * y, TX_LIGHTGRAY);

            if (y <=  - x * x)
                txSetPixel (400 + xx + 50 * x, 450 + yy - 50 * y, TX_LIGHTGRAY);
            if (y <=  fabs (sin (x)))
                txSetPixel (400 + xx + 50 * x, 580 + yy - 50 * y, TX_ORANGE);
            }
            txSetColor (TX_BLACK);
            txLine (100, 250, 380, 320);
            txLine (420, 320, 700, 250);
    }

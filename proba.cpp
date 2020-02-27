
//! @code
            sneg_draw (400, 500, 20, t);
//! @endcode

#include <stdio.h>
#include <stdlib.h>
#include "TXLib.h"
void sneg_draw (double x, double y, double r, int t);
void dom_draw (double x0, double y0, double x1, double y1);
void DrawHello();
void  Titr ();

int main()
    {
    txCreateWindow (800, 600);
    txSetColor (RGB (0, 128, 0), 5);

    DrawHello();

    int t = 0;
    while(t <= 100)
    {
    txSetFillColor (TX_BLUE);
    txClear ();

    sneg_draw (400 + t * 2, 450, 20, t);
    sneg_draw (400, 500, 20, t);
    dom_draw (50, 400, 300, 550);

    t++;
    txSleep(100);
    }

    Titr ();

    return 0;

}

void sneg_draw (double x, double y, double r, int t)
    {
    txSetFillColor (TX_WHITE);
    txCircle (x, y + 30, r * 2);
    txCircle (x + abs((t % 7) - 3), y, r);
    txLine(x + 35 ,y + 25,x + 75, y + abs((t % 7) + 25));
    txLine(x -35 ,y + 25,x - 75, y + abs((t % 7) + 25));
    txSetFillColor (TX_WHITE);
    }

void dom_draw (double x0, double y0, double x1, double y1)
    {
    txSetColor (RGB (255, 255, 0), 5);
    txLine(x0, y0, x0, y1);
    txLine(x0, y1, x1, y1);
    txLine(x1, y1, x1, y0);
    txLine(x1, y0, x0, y0);
    txLine(x0, y0, x1/2, y0-20);
    txLine(x1, y0, x1/2, y0-20);
    txLine(x0+30, y0+30, x0+30, y1-30);
    txLine(x0+30, y1-30, x1-30, y1-30);
    txLine(x1-30, y1-30, x1-30, y0+30);
    txLine(x1-30, y0+30, x0+30, y0+30);

    }

void DrawHello()
    {
    txSetColor (TX_GREEN);
    txSelectFont ("Times New Roman", 70);
    txSetTextAlign (TA_CENTER);

    int dy=800;
    while (dy>=0){
    txClear ();
    txTextOut (400, dy, "Hello, world!");
    dy=dy-10;
    txSleep(100);
    }
}
void  Titr ()
    {
    txSetColor (TX_BLACK);
    int y3=500;
    while (y3>10)
        {
        txClear ();
        txDrawText  (10, y3, 790, y3+100, "Автор ###########################################################################################################################.\n");
        y3=y3-10;
        txSleep(100);
        }



    }


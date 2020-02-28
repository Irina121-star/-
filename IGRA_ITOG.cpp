#include <stdio.h>
#include <stdlib.h>
#include "TXLib.h"
void DrawBall (int x, int y, int r);
void MoveBall ();
void Physics (int* x, int* y, int* vx, int* vy, int dt, int a, int b, int c);
void Ball_upr (int* vx, int* vy);

int main()

    {
    txCreateWindow (800, 600);

    MoveBall ();
    }


void DrawBall (int x, int y, int r, int a, int b, int c)
    {
    txSetColor (TX_YELLOW);
    txSetFillColor (RGB ( a, b, c));
    txCircle (x, y, r);
    }

void MoveBall ()
    {
    int x1 = 100, y1 = 100, vx1 = 5, vy1 = 5, dt = 1, a1 = 255, b1 = 255, c1 = 0;
    int x2 = 100, y2 = 200, vx2 = 3, vy2 = 3, a2 = 255, b2 = 0, c2 = 0;
    int x3 = 400, y3 = 200, vx3 = 3, vy3 = 3, a3 = 0, b3 = 255, c3 = 0;
    int x4 = 200, y4 = 300, vx4 = 1, vy4 = 7, a4 = 0, b4 = 0, c4 = 255;


    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_WHITE);
        txClear ();

        Ball_upr (&vx1,&vy1);
        Ball_upr (&vx2,&vy2);

        Physics (&x1, &y1, &vx1, &vy1, dt, a1, b1, c1);
        Physics (&x2, &y2, &vx2, &vy2, dt, a2, b2, c2);
        Physics (&x3, &y3, &vx3, &vy3, dt, a3, b3, c3);
        Physics (&x4, &y4, &vx4, &vy4, dt, a4, b4, c4);


        txSleep (10);
        }


    }

void Physics (int* x, int* y, int* vx, int* vy, int dt, int a, int b, int c)
    {
        DrawBall (*x, *y, 21, a, b, c);

        (*x) = (*x) + (*vx) * dt;
        (*y) = (*y) + (*vy) * dt;

        if (*x > 800)
            {
            *vx = - *vx;
            *x = 800;
            }

        if (*y > 600)
            {
            *vy = - *vy;
            *y = 600;
            }

        if (*x < 0)
            {
            *vx = - *vx;
            *x = 0;
            }

        if (*y < 0)
            {
            *vy = - *vy;
            *y = 0;
            }

        }


void Ball_upr (int* vx, int* vy)
    {
    if (GetAsyncKeyState (VK_RIGHT))
        {
        (*vx) = *vx + 10;
        }


    if (GetAsyncKeyState (VK_LEFT))
        {
        (*vx)--;
        }

    if (GetAsyncKeyState (VK_UP))
        {
        (*vy)++;
        }

    if (GetAsyncKeyState (VK_DOWN))
        {
        (*vy)--;
        }

    }

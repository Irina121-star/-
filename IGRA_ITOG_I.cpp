#include <stdio.h>
#include <stdlib.h>
#include "TXLib.h"
void DrawBall (int x, int y, int r);
void MoveBall ();
void Physics (int* x, int* y, int* vx, int* vy, int dt, int a, int b, int c);
void Ball_upr1 (int* vx1, int* vy1);
void Ball_upr2 (int* vx2, int* vy2);
double Distance (int* x1, int* y1, int* x2, int* y2);

int main()

    {
    printf("Управление клавишими. Красный: RIGHT, DOWN, UP, LEFT. Желтый: D, S, W, A.");
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
    int x1 = 100, y1 = 100, vx1 = 15, vy1 = 15, dt = 1, a1 = 255, b1 = 255, c1 = 0;
    int x2 = 100, y2 = 200, vx2 = 3, vy2 = 3, a2 = 255, b2 = 0, c2 = 0;

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_WHITE);
        txClear ();

        Ball_upr1 (&vx1,&vy1);
        Ball_upr2 (&vx2,&vy2);

        Physics (&x1, &y1, &vx1, &vy1, dt, a1, b1, c1);
        Physics (&x2, &y2, &vx2, &vy2, dt, a2, b2, c2);

        int temp = 0;
        double dist12 = Distance (&x1, &y1, &x2, &y2);
        if (dist12 <= 35 * 2)
            {
            txSetColor (TX_RED);
            txSelectFont ("Comic Sans MS", 100);
            txSetTextAlign (TA_CENTER);
            txTextOut (300, 300, "БУМ!");

            break;
            }

        txSleep (10);
        }


    }

void Physics (int* x, int* y, int* vx, int* vy, int dt, int a, int b, int c)
    {
        DrawBall (*x, *y, 35, a, b, c);

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


void Ball_upr1 (int* vx1, int* vy1)
    {
    if (GetAsyncKeyState ('D'))
        {
        *vx1 = *vx1 + 10;
        }


    if (GetAsyncKeyState ('A'))
        {
        *vx1 = *vx1 - 10;
        }

    if (GetAsyncKeyState ('W'))
        {
        *vy1 = *vy1 + 10;
        }

    if (GetAsyncKeyState ('S'))
        {
        *vy1 = *vy1 - 10;
        }

    }

void Ball_upr2 (int* vx2, int* vy2)
    {
    if (GetAsyncKeyState (VK_RIGHT))
        {
        *vx2 = *vx2 + 10;
        }


    if (GetAsyncKeyState (VK_LEFT))
        {
        *vx2 = *vx2 - 10;
        }

    if (GetAsyncKeyState (VK_UP))
        {
        *vy2 = *vy2 - 10;
        }

    if (GetAsyncKeyState (VK_DOWN))
        {
        *vy2 = *vy2 + 10;
        }

    }
double Distance (int* x1, int* y1, int* x2, int* y2)
    {
    double dist = sqrt((*x1 - *x2) * (*x1 - *x2) + (*y1 - *y2) * (*y1 - *y2));
    return dist;
    }

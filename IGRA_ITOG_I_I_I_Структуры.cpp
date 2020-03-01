#include <stdio.h>
#include <stdlib.h>
#include "TXLib.h"
struct Sczc
    {
      int x, y;
      int vx, vy;
      int r;
      int dt;
      int a, b, c;
    };
void DrawBall (Sczc s);
void MoveBall ();
void Physics (Sczc* s);
void Ball_upr1 (Sczc* s);
void Ball_upr2 (Sczc* s);
double Distance ( Sczc* s1, Sczc* s2);


int main()

    {
    printf("Управление клавишими. Красный: RIGHT, DOWN, UP, LEFT. Желтый: D, S, W, A.");
    txCreateWindow (800, 600);

    MoveBall ();
    }


void DrawBall (Sczc s)
    {
    txSetColor (TX_YELLOW);
    txSetFillColor (RGB ( s.a, s.b, s.c));
    txCircle (s.x, s.y, s.r);
    }

void MoveBall ()
    {
    Sczc s1 = {100, 20, 5, 7, 21, 1, 255, 255, 0};
    Sczc s2 = {300, 200, 5, 7, 21, 1, 0, 255, 255};

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_WHITE);
        txClear ();

        Ball_upr1 (&s1);
        Ball_upr2 (&s2);

        Physics (&s1);
        Physics (&s2);

        double dist12 = Distance (&s1, &s2);
        if (dist12 <= 21 * 2)
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

void Physics (Sczc* s)
    {
        DrawBall (*s);

        (s->x) = (s->x) + (s->vx) * s->dt;
        (s->y) = (s->y) + (s->vy) * s->dt;

        if (s->x > 800)
            {
            s->vx = - s->vx;
            s->x = 800;
            }

        if (s->y > 600)
            {
            s->vy = - s->vy;
            s->y = 600;
            }

        if (s->x < 0)
            {
            s->vx = - s->vx;
            s->x = 0;
            }

        if (s->y < 0)
            {
            s->vy = - s->vy;
            s->y = 0;
            }

        }


void Ball_upr1 (Sczc* s)
    {
    if (GetAsyncKeyState ('D'))
        {
        s->vx = s->vx + 10;
        }


    if (GetAsyncKeyState ('A'))
        {
        s->vx = s->vx - 10;
        }

    if (GetAsyncKeyState ('W'))
        {
        s->vy = s->vy + 10;
        }

    if (GetAsyncKeyState ('S'))
        {
        s->vy = s->vy - 10;
        }

    }

void Ball_upr2 (Sczc* s)
    {
    if (GetAsyncKeyState (VK_RIGHT))
        {
        s->vx = s->vx + 10;
        }


    if (GetAsyncKeyState (VK_LEFT))
        {
        s->vx = s->vx - 10;
        }

    if (GetAsyncKeyState (VK_UP))
        {
        s->vy = s->vy - 10;
        }

    if (GetAsyncKeyState (VK_DOWN))
        {
        s->vy = s->vy + 10;
        }

    }
double Distance ( Sczc* s1, Sczc* s2)
    {
    double dist = sqrt((s1->x - s2->x) * (s1->x - s2->x) + (s1->y - s2->y) * (s1->y - s2->y));
    return dist;
    }

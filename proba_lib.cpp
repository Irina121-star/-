
//! @file proba_lib.cpp
//! @brief Это функция рисует снеговика
//! @mainpage Проба. Библиотека.
//! @warning <b>Это пробная версия. Для использования библиотеки не требуется согласование с ее автором.</b>


#include <stdio.h>
#include <stdlib.h>
#include "TXLib.h"

//! @brief Это функция рисует снеговика
//! @param x - абсцисса центра круга - основания
//! @param y - ордината центра круга - основания
//! @param r - радиус центра круга - основания
//! @param t - параметр смещения
void sneg_draw (double x, double y, double r, int t);


//! @brief Это функция рисует дом
//! @param x0 - абсцисса левой верхней вершины прямоугольника
//! @param y0 - ордината левой верхней вершины прямоугольника
//! @param x1 - абсцисса правой нижней вершины прямоугольника
//! @param y1 - абсцисса правой нижней вершины прямоугольника
void dom_draw (double x0, double y0, double x1, double y1);

//! @brief Это функция приветствия
void DrawHello();


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



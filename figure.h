#ifndef FIGURE_H
#define FIGURE_H
#include "QColor"
#include "QPainter"


class Figure
{

int lineCellSize; //размер клетки
int rowCoord;  //Индексы верхней клетки фигуры (текущее положение фигурки в стакане)
int colCoord; //Индексы верхней клетки фигуры (текущее положение фигурки в стакане)

QColor arrColorList[6] = {
    QColor(204, 0, 0),
    QColor(204, 255, 0),
    QColor(0, 125, 255),
    QColor(50, 205, 50),
    QColor(127,255,212),
    QColor(128,0,128)
};

QColor arrColorLine[3]; //фигурка


public:
    Figure(int lineCellSize);

    void rotateColors(int direction); //циклический сдвиг цветов
    void MakeRandomColors();//рандомный выбор цвета клеток
    void paintFigure(QPainter&painter); //отрисовка фигуры
    void fallDown(); //фигурка роняется вниз

    void setRowCoord(int ri){
        rowCoord = ri;
    }
    void setColCoord(int ci){
        colCoord = ci;
    }

    int getRowCoord(){
        return rowCoord;
    }

    int getColCoord(){
        return colCoord;
    }

    int getLineCellSize(){
        return lineCellSize;
    }

     QColor getColor(int i) {
         return arrColorLine[i];
     }
};

#endif // FIGURE_H

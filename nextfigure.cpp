#include "nextfigure.h"
#include "QDebug"


nextFigure::nextFigure(QWidget *parent) : QWidget(parent)
{
    next = nullptr;
}


void nextFigure::paintEvent (QPaintEvent * event){
    QPainter painter(this);

    painter.QPainter::translate(-35, height() / 2-15); //Переводит начало системы координат в offset

    if(next!=nullptr)
        next->paintFigure(painter);
}


void nextFigure::slotShowNewFigure(Figure* next) {
    this->next = next;
    repaint();
}

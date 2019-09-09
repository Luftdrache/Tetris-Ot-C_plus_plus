#include "figure.h"
#include "QtDebug"

Figure::Figure(int lineCellSize)
{
this->lineCellSize = lineCellSize;
rowCoord = 5*lineCellSize;
colCoord = 0;
MakeRandomColors();
}


void Figure::rotateColors(int direction){
    switch (direction) {
    case 1: {//up
        QColor tmpUp = arrColorLine[0];
        for(int i = 0; i<2; i++) {
            arrColorLine[i] = arrColorLine[i+1];
        }
        arrColorLine[2] = tmpUp;
    }
        break;
    case 2: {//down
        QColor tmpDown = arrColorLine[2];
        for(int i = 2; i>0; i--) {
            arrColorLine[i] = arrColorLine[i-1];
        }
        arrColorLine[0] = tmpDown;
    }
        break;
    }
}


void Figure::MakeRandomColors() {

 for (int i = 0; i<sizeof(arrColorLine)/sizeof(QColor); i++) {
     arrColorLine[i] = arrColorList[rand() % 5];
 }
}

void Figure::paintFigure(QPainter&painter) {
    for(int i = 0; i < sizeof(arrColorLine)/sizeof(QColor); i++) {
        painter.fillRect(rowCoord,colCoord+i*lineCellSize, lineCellSize-1,lineCellSize-1, arrColorLine[i]);
        }
    }


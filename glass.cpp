#pragma once
#include "glass.h"
#include "QDebug"
#include "QPainter"
#include "QBrush"
#include "figure.h"
#include <QKeyEvent>
#include "QMessageBox"

Glass::Glass(QWidget *parent) : QWidget(parent)
{
    cur = new Figure(30); //текущая (падающая) фигурка
    next = new Figure(30); //образец следующей фигурки

    QObject::connect(this, SIGNAL(signalGlassInit ()), this, SLOT(slotGlassInit()), Qt::QueuedConnection); //ассинхронно
    emit signalGlassInit();
}



void Glass::checkGlass() {
 this->killTimer(idTimer);
  QVector<QPoint> cellsForDelete; //клетки, которые потом удаляются

//сравнение по вертикали
    for(int i = 0; i < rows(); i++ ) {
        for (int j = 0; j < cols() - 2; j++) {
            if(glassArray[i][j] != *emptyCellColor && glassArray[i][j] ==glassArray[i][j+1] && glassArray[i][j] == glassArray[i][j+2]){
                if(!cellsForDelete.contains(QPoint(i, j)))
                    cellsForDelete.append(QPoint(i, j));
                if(!cellsForDelete.contains(QPoint(i, j+1)))
                    cellsForDelete.append(QPoint(i, j+1));
                if(!cellsForDelete.contains(QPoint(i, j+2)))
                    cellsForDelete.append(QPoint(i, j+2));
            }
        }
    }
    //по горизонтали
    for(int j = 0; j < cols(); j++ ) {
        for (int i = 0; i < rows() - 2; i++) {

            if(glassArray[i][j] != *emptyCellColor &&  glassArray[i][j] ==glassArray[i+1][j] && glassArray[i][j] == glassArray[i+2][j]){
                if(!cellsForDelete.contains(QPoint(i, j)))
                    cellsForDelete.append(QPoint(i, j));
                if(!cellsForDelete.contains(QPoint(i+1, j)))
                    cellsForDelete.append(QPoint(i+1, j));
                if(!cellsForDelete.contains(QPoint(i+2, j)))
                    cellsForDelete.append(QPoint(i+2, j));
            }
        }
    }
    //Закраска в песочный

    for(int i = 0; i < rows(); i++) {
        for(int j = 0; j < cols(); j++) {
            if(cellsForDelete.contains(QPoint(i, j)))
                glassArray[i][j] = *emptyCellColor;
        }
    }

    for(int k = 0; k < 5; k++) {
    for(int i = 0; i < rows(); i++) {
        for(int j = 0; j < cols()-1; j++) {
            if(glassArray[i][j] != *emptyCellColor && glassArray[i][j+1] == *emptyCellColor) {
                glassArray[i][j+1] = glassArray[i][j];
                glassArray[i][j] = *emptyCellColor;
            }
        }
    }
}

    score +=cellsForDelete.count();
    emit(signalSetScore(score));
    //qDebug()<<score;
    idTimer = startTimer(timerInterval);
}





void Glass::checkEndGame() {
    for(int i = 0; i < rows(); i++) {
        if(glassArray[i][0]!= *emptyCellColor)
        {
            this->killTimer(idTimer);
            QMessageBox::information(this, "Game over", "Game over!");
            isGameOn=false;
            //cur = next = nullptr;
        }
    }
}

void Glass::timerEvent(QTimerEvent* event) {
    repaint();
    //если уперлись
    if(cur->getColCoord()/cur->getLineCellSize() + 3 == cols()
            ||glassArray[cur->getRowCoord()/cur->getLineCellSize()][cur->getColCoord()/cur->getLineCellSize() +3]
            != *emptyCellColor) {
        for(int i = 0; i < 3; i++){
            glassArray[cur->getRowCoord()/30][cur->getColCoord()/30+i] = cur->getColor(i);
        }

        //checkGlass();
        //checkEndGame(); //потом - не заполнен ли доверху стакан
        std::swap(cur, next);
        next->setColCoord(0);
        next->setRowCoord(5*cur->getLineCellSize());
        next->MakeRandomColors();
        if(!isGameOn) { //убираем следующую фигурку с экрана, если игра проиграна
             cur = next = nullptr;
             emit(signalDrawNextFigure(next));
        }
    }
    else if (glassArray[cur->getRowCoord()/cur->getLineCellSize()][cur->getColCoord()/cur->getLineCellSize() + 3]
             == *emptyCellColor && cur->getColCoord()/cur->getLineCellSize() +3  < cols()){
        cur->setColCoord(cur->getColCoord()+cur->getLineCellSize());   //иначе перемещаемся вниз
    }
    checkGlass();
    checkEndGame();
    emit(signalDrawNextFigure(next));
}


void Glass::keyPressEvent(QKeyEvent * event){

    if(isGameOn) //Если«идет игра»
    {

        switch(event->key()){//код нажатой клавиши
        case Qt::Key_Left:
            if(cur->getRowCoord()>=cur->getLineCellSize()) {
            cur->setRowCoord(cur->getRowCoord()-cur->getLineCellSize());
            //qDebug()<<cur->getRowCoord();
            repaint();
            }
            break;
        case Qt::Key_Right:
            if(cur->getRowCoord()/cur->getLineCellSize()<rows()-1) {
            cur->setRowCoord(cur->getRowCoord()+cur->getLineCellSize());
           // qDebug()<<cur->getRowCoord();
            repaint();
            }
            break;
        case Qt::Key_Down:
            //циклически ”переливаем” цвета в фигурке сверху вниз
            cur->rotateColors(2);
            break;
        case Qt::Key_Up:
            //циклически ”переливаем” цвета в фигурке снизу вверх
            cur->rotateColors(1);
            break;
        case Qt::Key_Space:  //«роняем» фигурку
           AcceptColors(cur->getRowCoord()/cur->getLineCellSize(),   cur->getColCoord()/cur->getLineCellSize() + 3); //на три штуки вниз
           std::swap(cur, next);
           next->setColCoord(0);
           next->setRowCoord(5*cur->getLineCellSize());
           next->MakeRandomColors();
           repaint();
           emit(signalDrawNextFigure(next));
           break;
        default:
            QWidget::keyPressEvent(event); //при нажатии любых других клавиш вызываем базовую обработку события
        }
    }
    else{
        QWidget::keyPressEvent(event);//предоставляем возможность базовому
        //классу обработать событие
    }
}

void Glass::AcceptColors(int i, int j){

        while(glassArray[i][j] == *emptyCellColor && j<cols()){ //если цвет фона и фигурка в пределах стакана
            cur->setColCoord(cur->getColCoord()+cur->getLineCellSize());   //перемещаемся вниз на клетку
            j = cur->getColCoord()/cur->getLineCellSize() + 3; //новое значение
            if(j == cols()) break;
        }
    //записываем цвет в вектор, когда достигли дна или уперлись в цвет!
   for(int i = 0; i < 3; i++){
       glassArray[cur->getRowCoord()/30][cur->getColCoord()/30+i] = cur->getColor(i);
    }
       checkGlass();
       checkEndGame();
}


void Glass::paintEvent (QPaintEvent * event){
    QPainter painter(this);


    if(!isGameOn)
        clearGlass();

    for(int i = 0; i < rows(); i++) {
        for(int j = 0; j<glassArray[i].length(); j++) {
            painter.fillRect(i*cellSize, j*cellSize, cellSize-1, cellSize-1, glassArray[i][j]);
        }
    }
    if(isGameOn) //а фигурку будем рисовать только, если «идет игра»
    {
        //здесь будем рисовать падающую фигурку

        cur->paintFigure(painter);

       // emit(signalDrawNextFigure(next)); //???????

    }
}


void Glass::slotNewGame() {
    isGameOn = true;
    clearGlass(); //клетки красим в песочный
    cur = new Figure(30);
    next = new Figure(30);
    this->setFocus(); //Иначе события от клавиатуры будут поступать главному окну!
    idTimer = startTimer(timerInterval);
    repaint();
    emit(signalDrawNextFigure(next));
}


// создаем вектор из m_rows векторов, в каждом из которых m_columns элементов
void Glass::slotGlassInit(){
    glassArray.resize(rows());
    for(uint i = 0; i < rows(); i++) {
        glassArray[i].resize(cols());
    }
    QSize size(rows()*cellSize, cols()*cellSize); //размеры Glass. Высчитываем размер в пикселях
    setFixedSize(size); //Задаем фиксированный размер стакана (330, 540)
}




void Glass::clearGlass() { //полная очистка стакана
    score = 0;
    if(idTimer<0) {
       killTimer(idTimer);
    }

    for(uint i = 0; i < rows(); i++) {
        glassArray[i].fill(*emptyCellColor);
    }
   // cur = next = nullptr;
}


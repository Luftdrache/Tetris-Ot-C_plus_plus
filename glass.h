#ifndef GLASS_H
#define GLASS_H

#include <QWidget>
#include "figure.h"

class Glass : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(uint rows READ rows WRITE setRows)
    Q_PROPERTY(uint cols READ cols WRITE setCols)

private:

    //размер стакана:
    uint m_rows;// текущее количество строк
    uint m_cols;//количество элементов в строке

    static const uint cellSize = 30; //размер ячейки поля
    uint timerInterval = 350; //Интервал, с которым будет «падать» фигурка
    int idTimer; //возвращаемое startTimer() значение, чтобы использовать его в killTimer()

    bool isGameOn; //играем или не играем
    uint score;// текущий счет
    uint timerTics; //счетчик для уровня

    const QColor* emptyCellColor = new QColor (252, 221, 118); // цвет для пустой клетки

    QVector<QVector<QColor>>glassArray; //цвет!

    Figure *cur; //текущая (падающая) фигурка
    Figure *next; //образец следующей фигурки

public:
    explicit Glass(QWidget *parent = nullptr);

    ~Glass() {
        delete cur;
        delete next;
    }

    void clearGlass(); //очистка стакана
    void AcceptColors(int i, int j); //для сброса при нажатии пробела
    void checkEndGame();
    void checkGlass();

uint rows() const {return m_rows;}
uint cols() const{return m_cols;}

protected:
virtual void paintEvent (QPaintEvent * event) override;
virtual void keyPressEvent(QKeyEvent*event)override;
virtual void timerEvent(QTimerEvent* event) override;


public:
signals:
void signalGlassInit();
void signalDrawNextFigure(Figure*); // эмитирование сигнала о перерисовке образца;
void signalSetScore(int);


public slots:
void slotGlassInit();
void slotNewGame();

void setRows(uint rows)
{
    m_rows = rows;
}

void setCols(uint cols)
{
    m_cols = cols;
}
};

#endif // GLASS_H

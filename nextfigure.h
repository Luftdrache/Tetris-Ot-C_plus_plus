#ifndef NEXTFIGURE_H
#define NEXTFIGURE_H

#include <QWidget>
#include "figure.h"

class nextFigure : public QWidget
{
    Q_OBJECT
    Figure * next;

public:
    explicit nextFigure(QWidget *parent = nullptr);


protected:
virtual void paintEvent (QPaintEvent * event) override;

signals:

public slots:
   void slotShowNewFigure(Figure* next);
};

#endif // NEXTFIGURE_H

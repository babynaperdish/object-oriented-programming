#ifndef MYFIGURES_H
#define MYFIGURES_H

#include <QWidget>
#include <QBoxLayout>
#include <QPaintEvent>
#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include "rectangleFigure.h"
#include "triangleFigure.h"
#include "ellipseFigure.h"



class myFigures : public QWidget
{
    Q_OBJECT

public:
    explicit myFigures(QWidget* parent = nullptr);

       void addRectangle(const QRect& bounds);
       void addTriangle(const QRect& bounds);
       void addEllipse(const QRect& bounds);
       void removeActiveFigure();
       void clearAllFigures();

       int figureCount() const { return fFigures.size(); }

   protected:
       void paintEvent(QPaintEvent* event) override;
       void mousePressEvent(QMouseEvent* event) override;
       void mouseMoveEvent(QMouseEvent* event) override;
       void mouseReleaseEvent(QMouseEvent* event) override;
    signals:
       void figureClicked(const QPoint& position);
   private:
       QList<figure*> fFigures;
       figure* fActiveFigure;
       QPoint fLastMousePos;
       bool fIsDragging;

       void setActiveFigure(figure* figure);
       void bringToFront(figure* figure);
};

#endif // MYFIGURES_H

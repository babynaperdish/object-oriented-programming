#ifndef MYFIGURES_H
#define MYFIGURES_H

#include <QWidget>
#include <QBoxLayout>
#include <QPaintEvent>
#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QAbstractGraphicsShapeItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>


class myFigures : public QWidget
{
    Q_OBJECT

public:
    explicit myFigures(QWidget* parent = nullptr);

       void addRectangle(const QRectF& bounds);
       void addTriangle(const QRect& bounds);
       void addEllipse(const QRect& bounds);
       void removeActiveFigures();
       void clearAllFigures();

       int figureCount() const { return fFigures.size(); }

   private:
       QGraphicsScene* fScene;
       QGraphicsView* fView;
       QList<QGraphicsItem*> fFigures;
       QAbstractGraphicsShapeItem* fActiveFigure;
    protected:
        void updateFigureColors();
        bool event(QEvent* event) override;
};

#endif // MYFIGURES_H

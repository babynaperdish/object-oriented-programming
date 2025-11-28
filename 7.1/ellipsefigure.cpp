#include "ellipsefigure.h"

ellipseFigure::ellipseFigure(const QRect& bounds, QObject* parent)
    : figure(Ellipse, bounds, parent)
{
}

void ellipseFigure::draw(QPainter* painter)
{
    QColor lightPink(255, 182, 193);
    QColor activePink(255, 105, 180);
    QColor purple(205, 25, 255);
    painter->setBrush(fActive ? QBrush(activePink) : QBrush(lightPink));
    painter->setPen(QPen(purple, 2));
    painter->drawEllipse(fBounds);
}

bool ellipseFigure::contains(const QPoint& point) const
{
    return fBounds.contains(point);
}

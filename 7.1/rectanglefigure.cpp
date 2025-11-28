#include "rectanglefigure.h"

rectangleFigure::rectangleFigure(const QRect& bounds, QObject* parent)
    : figure(Rectangle, bounds, parent)
{
}

void rectangleFigure::draw(QPainter* painter)
{
    QColor lightPink(255, 182, 193);
    QColor activePink(255, 105, 180);
    QColor purple(205, 25, 255);
    painter->setBrush(fActive ? QBrush(activePink) : QBrush(lightPink));
    painter->setPen(QPen(purple, 2));
    painter->drawRect(fBounds);
}

bool rectangleFigure::contains(const QPoint& point) const
{
    return fBounds.contains(point);
}

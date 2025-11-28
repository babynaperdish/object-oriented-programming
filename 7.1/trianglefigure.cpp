#include "trianglefigure.h"

triangleFigure::triangleFigure(const QRect& bounds, QObject* parent)
    : figure(Triangle, bounds, parent)
{
}

void triangleFigure::draw(QPainter* painter)
{
    QColor lightPink(255, 182, 193);
    QColor activePink(255, 105, 180);
    QColor purple(205, 25, 255);
    painter->setBrush(fActive ? QBrush(activePink) : QBrush(lightPink));
    painter->setPen(QPen(purple, 2));
    painter->drawPolygon(getTrianglePolygon());
}

bool triangleFigure::contains(const QPoint& point) const
{
    return getTrianglePolygon().containsPoint(point, Qt::OddEvenFill);
}

QPolygon triangleFigure::getTrianglePolygon() const
{
    QPolygon polygon;
    polygon << QPoint(fBounds.center().x(), fBounds.top())
            << QPoint(fBounds.right(), fBounds.bottom())
            << QPoint(fBounds.left(), fBounds.bottom());
    return polygon;
}

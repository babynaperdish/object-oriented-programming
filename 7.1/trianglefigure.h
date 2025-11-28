#ifndef TRIANGLEFIGURE_H
#define TRIANGLEFIGURE_H

#include "figure.h"

class triangleFigure : public figure{
public:
    triangleFigure(const QRect& bounds, QObject* parent = nullptr);
    void draw(QPainter* painter) override;
    bool contains(const QPoint& point) const override;

private:
    QPolygon getTrianglePolygon() const;
};

#endif // TRIANGLEFIGURE_H

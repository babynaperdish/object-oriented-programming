#ifndef ELLIPSEFIGURE_H
#define ELLIPSEFIGURE_H

#include "figure.h"

class ellipseFigure: public figure
{
public:
    ellipseFigure(const QRect& bounds, QObject* parent = nullptr);
    void draw(QPainter* painter) override;
    bool contains(const QPoint& point) const override;
};

#endif // ELLIPSEFIGURE_H

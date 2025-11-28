#ifndef RECTANGLEFIGURE_H
#define RECTANGLEFIGURE_H

#include "figure.h"

class rectangleFigure: public figure{
public:
    rectangleFigure(const QRect& bounds, QObject* parent = nullptr);
    void draw(QPainter* painter) override;
    bool contains(const QPoint& point) const override;
};

#endif // RECTANGLEFIGURE_H

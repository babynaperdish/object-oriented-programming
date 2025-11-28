#ifndef FIGURE_H
#define FIGURE_H

#pragma once

#include <QObject>
#include <QPainter>

class figure: public QObject
{
    Q_OBJECT
public:
    enum figureType{Rectangle, Triangle, Ellipse};
    explicit figure(figureType type, const QRect& bounds, QObject* parent = nullptr);

    virtual void draw(QPainter* painter) = 0;
    virtual bool contains(const QPoint& point) const = 0;

    figureType type() const;
    QRect bounds() const;
    void setBounds(const QRect& bounds);
    void moveBy(const QPoint& offset);
    bool isActive() const;
    void setActive(bool active);

protected:
    figureType fType;
    QRect fBounds;
    bool fActive;
};

#endif // FIGURE_H

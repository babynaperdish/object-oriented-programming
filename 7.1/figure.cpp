#include "figure.h"

figure::figure(figureType type, const QRect& bounds, QObject* parent) : QObject(parent), fType(type), fBounds(bounds), fActive(false)
{
}

bool figure::isActive() const {
    return fActive;
}

void figure::setActive(bool active) {
    fActive = active;
}

figure::figureType figure::type() const {
    return fType;
}

QRect figure::bounds() const {
    return fBounds;
}

void figure::setBounds(const QRect& bounds){
    fBounds = bounds;
}

void figure::moveBy(const QPoint& offset){
    fBounds.translate(offset);
}

#include "point.h"

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }

bool Point::operator==(const Point& p) const {
    return (this->getX() == p.getX()) && (this->getY() == p.getY());
}

bool Point::operator<(const Point& p) const {
    return this->getX() < p.getX();
}

void Point::SetX(int x1) {
    this->x = x1;
}

void Point::SetY(int y1) {
    this->y = y1;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;////
}
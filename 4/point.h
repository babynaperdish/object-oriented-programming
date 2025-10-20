#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <ostream>

class Point {
private:
    double x;
    double y;

public:
    Point();
    Point(double x, double y);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    bool operator==(const Point&) const;
    bool operator<(const Point&) const;
    void SetX(int);
    void SetY(int);
};

std::ostream& operator<<(std::ostream& os, const Point& p);
#endif // POINT_HPP
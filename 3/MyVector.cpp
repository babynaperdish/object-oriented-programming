#include "stdafx.h"
#include "MyVector.h"


Vector::Vector(double c1, double c2)
{
	x = c1;   y = c2;
}

Vector::Vector()
{
	x = y = 0.;
}

Vector::~Vector() {}

Vector::Vector(const Vector& v) {
	*this = v;
}

Vector Vector::operator+(const Vector& c1) const {
	return Vector(x + c1.x, y + c1.y);
}

Vector Vector::operator-(const Vector& c1) const {
	return Vector(x - c1.x, y - c1.y);
}

Vector& Vector::operator+=(const Vector& v1) {
	x += v1.x;
	y += v1.y;
	return *this;
}

Vector& Vector::operator-=(const Vector& v1) {
	x -= v1.x;
	y -= v1.y;
	return *this;
}

void Vector::Out() const
{
	cout << "\nVector:  x = " << x << ",  y = " << y;
}


//====== Переопределение операций =====//
Vector& Vector::operator= (const Vector& v)	// Присвоение
{
	if (this == &v)
		return *this;
	x = v.x;
	y = v.y;
	return *this;
}

double Vector::operator! () const {
	return sqrt(x * x + y * y);
}

bool Vector::operator> (const Vector& v1) const {
	return !(*this) > !v1;
}

bool Vector::operator< (const Vector& v1) const {
	return !(*this) < !v1;
}

bool Vector::operator== (const Vector& v1) const {
	return fabs(v1.x - x) < DBL_EPSILON && fabs(v1.y - y) < DBL_EPSILON;
}

Vector Vector::operator* (const double d)const {
	Vector v(x, y);
	v.x *= d;
	v.y *= d;
	return v;
}

Vector operator* (const double v1, const Vector& v2) {
	return Vector(v1 * v2.x, v1 * v2.y);
}

double Vector::operator*(const Vector& v1)const {
	double v = x * v1.x + y * v1.y;
	return v;
}

double Vector::X() const { return x; }
double Vector::Y() const { return y; }

double Vector::Area() const {
	return 0;
}

void Vector::Move(const Vector& v) {
	*this += v;
}

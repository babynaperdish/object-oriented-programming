#pragma once
#include "MyVector.h"
#include "Shape.h"

class Rect : public Shape{
private:
	Vector ptLT, ptRB;
public:
	Rect();
	Rect(const Vector& lt, const Vector& rb);
	Rect(double left, double top, double right, double bottom);
	Rect& operator=(const Rect&);
	Rect& Inflate(double inc = 1);
	Rect& Inflate(double, double);
	Rect& Inflate(double, double, double, double);
	void Out() const;
	void Move(const Vector&);
	double Area() const;
};

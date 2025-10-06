#pragma once
#include "MyVector.h"
class Circle :public Shape
{
private:
	Vector ptCntr; 
	double R;
public:
	Circle(double, double, double);
	void Move(const Vector&);
	void Out() const;
	double Area() const;
};


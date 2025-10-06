#include "stdafx.h"
#include "Circle.h"


Circle::Circle(double d1, double d2, double d3) {
	ptCntr = Vector(d1, d2);
	R = d3;
}
void Circle::Move(const Vector& v) { 
	ptCntr += v; 
}
void Circle::Out() const {
	cout << "\nCircle:  x = " << ptCntr.X() << ",  y = " << ptCntr.Y() << ", radius = " << R;

}
double Circle::Area() const {
	return R*R;
}

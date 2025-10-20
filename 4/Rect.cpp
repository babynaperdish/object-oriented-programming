#include "stdafx.h"
#include "Rect.h"
#include <cmath>

Rect::Rect(): ptLT(0, 0), ptRB(0, 0){
}

Rect::Rect(const Vector& lt, const Vector& rb): ptLT(lt), ptRB(rb){
}

Rect::Rect(double left, double top, double right, double bottom): ptLT(left < right ? left : right, top > bottom ? top : bottom), ptRB(left > right ? left : right, top < bottom ? top : bottom) {
}

Rect& Rect::operator=(const Rect& r){
	if (this == &r)
		return *this;
	ptLT = r.ptLT;
	ptRB = r.ptRB;
	return *this;
}

Rect& Rect::Inflate(double inc) {
	Vector vinc(inc, inc);
	ptLT =  ptLT - vinc;
	ptRB = ptRB + vinc;
	return *this;
}

Rect& Rect::Inflate(double inc1, double inc2) {
	Vector vinc(inc1, inc2);
	ptLT = ptLT - vinc;
	ptRB = ptRB + vinc;
	return *this;
}

Rect& Rect::Inflate(double left, double top, double right, double bottom) {
	Vector vinc1(left, top);
	Vector vinc2(right, bottom);
	ptLT = ptLT + vinc1;
	ptRB = ptRB + vinc2;
	return *this;
}

void Rect::Out() const{
	cout << "\nRect (" << ptLT.X() << "," << ptLT.Y() << "," << ptRB.X() << "," << ptRB.Y() << ")\n";
}

void Rect::Move(const Vector& v) {
	ptLT += v;
	ptRB += v;
}

double Rect::Area() const {
	return (ptRB.X() - ptLT.X()) * (ptRB.Y() - ptLT.Y());
}

bool Rect::operator<(const Rect& rect) const {
	double dim1 = sqrt(pow(this->ptLT.X() + (this->ptRB.X() - this->ptLT.X()) / 2, 2) + pow(this->ptRB.Y() + (this->ptLT.Y() - this->ptRB.Y()) / 2, 2));
	double dim2 = sqrt(pow(rect.ptLT.X() + (rect.ptRB.X() - rect.ptLT.X()) / 2, 2) + pow(rect.ptRB.Y() + (rect.ptLT.Y() - rect.ptRB.Y()) / 2, 2));
	return dim1 < dim2;
}
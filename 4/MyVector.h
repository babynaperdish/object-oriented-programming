#pragma once
#include "Shape.h"
class Vector : public Shape {
private:
	double x, y;	// ���������� ������� �� ���������
public:
	//========== ��� ������������
	Vector(double c1, double c2);
	Vector();	// Default
	~Vector();
	Vector(const Vector&);
	//====== ��������������� �������� =====//
	Vector& operator= (const Vector& v);	// ����������
	Vector operator- (const Vector& v) const;
	Vector operator+ (const Vector&) const;
	Vector& operator+= (const Vector&);
	Vector& operator-= (const Vector&);
	double operator! () const;
	bool operator> (const Vector&) const;	
	bool operator< (const Vector&) const;
	bool operator== (const Vector&) const;
	Vector operator* (const double) const;
	friend Vector operator*(const double, const Vector&);
	double operator*(const Vector&) const;
	double X() const;
	double Y() const;
	void Out() const;
	void Move(const Vector&);
	double Area() const;
};


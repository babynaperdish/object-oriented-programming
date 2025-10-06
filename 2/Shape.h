#pragma once
#include <iostream>
#define MAX_LENGTH 1000

class Vector;

class Shape
{
private:
	static int Count;
protected:
	int Index;
public:
	static Shape** shapes;
	Shape();
	virtual ~Shape();
	static void PrintCount();
	virtual void Move(const Vector&) = 0;
	virtual void Out() const = 0;
	virtual double Area() const = 0;
	int GetNewCount();
	int GetIndex(int) const;
	static int GetCount();
};


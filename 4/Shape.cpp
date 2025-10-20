#include "stdafx.h"
#include "Shape.h"

int Shape::Count = 0;
Shape** Shape::shapes = nullptr;

void Shape::PrintCount() {
	cout << "\n Now there are " << Count << " shapes";
}

int Shape::GetNewCount() {
	if (Count == 0) {
		shapes = new Shape * [MAX_LENGTH];
		for (int i = 0; i < MAX_LENGTH; i++)
			shapes[i] = nullptr;

	}
	if (Count == MAX_LENGTH) {
		cout << "Maximum amount of shapes has been reached\n";
		return MAX_LENGTH;
	}

	return ++Count;
}

Shape::~Shape() {
	if (shapes != nullptr) {
		shapes[Index] = nullptr;  
		Count--;
		if (Count == 0) {        
			delete[] shapes;      
			shapes = nullptr;    
		}
	}
	else {
		Count--; 
	}
}

int Shape::GetIndex(int counter) const
{
	if (counter == MAX_LENGTH)
		return -1;

	for (int i = 0; i < MAX_LENGTH; ++i) {
		if (shapes[i] == nullptr)
			return i;
	}
	return -1;
}

int Shape::GetCount() {
	return Count;
}

Shape::Shape() {
	Count = GetNewCount();
	Index = GetIndex(Count);
	shapes[Index] = this;
}
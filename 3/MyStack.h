#pragma once

class StackOverflow {
public:
	StackOverflow() {}
};

class StackUnderflow {
public:
	StackUnderflow() {}
};

class StackOutOfRange {
private:
	int index;  // индекс, вызвавший исключение
public:
	StackOutOfRange(int i) : index(i) {}

	void Out() const {
		std::cout << "\nStack index out of range: " << index;
	}
};

template <typename T, int size> class MyStack{
private:
	T ptr[size];
	int top = -1;
public:
	MyStack(int s = 1000) {
		//if (s <= 0) throw s;
		//try {
		//	ptr = new T[s];
		//	if (ptr == nullptr) throw std::bad_alloc();
		//	size = s;
		//}catch (std::bad_alloc&) { std::cout << std::endl << "Memory allocation failed" << std::endl;}
	}
	bool Push(const T& val) {
		if (top >= size - 1) throw StackOverflow();
		ptr[++top] = val;
		return true;
	}
	T Pop() {
		if (top < 0) throw StackUnderflow();
		T temp = ptr[top];
		--top;
		return temp;
	}
	int Capacity(){
		return size;
	}
	int GetSize() {
		return top + 1;
	}
	T& operator[](int i) {
		if (i < 0 || i >= size) throw StackOutOfRange{i};
		return ptr[i];
	}
};
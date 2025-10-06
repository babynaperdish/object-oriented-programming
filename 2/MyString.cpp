#include <iostream>
#include "MyString.h"

void MyString::Copy (char* s)
{
	delete [] m_pStr;
	// Динамически выделяем требуемое количество памяти.
	int len = strlen(s) + 1;
	m_pStr = new char[len];
	// + 1, так как нулевой байт тоже нужно скопировать
	// Если память выделена, копируем строку-аргумент в строку-член класса
	if (m_pStr)
		strcpy_s (m_pStr, len, s);
}

MyString::MyString() {
	m_pStr = new char[1];
}

// Определение конструктора.
MyString::MyString (char* s)
{
	m_pStr = 0;
	Copy(s);
}

MyString::MyString(const char* str) {
	if (str) {
		size_t len = strlen(str);
		m_pStr = new char[len + 1];
		strcpy(m_pStr, str);
	}
	else {
		m_pStr = new char[1];
		m_pStr[0] = '\0';
	}
}

MyString::MyString(const MyString& v) {
	m_pStr = 0;
	Copy(v.m_pStr);
}

// Определение деструктора.
MyString::~MyString()
{
	// Освобождение памяти, занятой в конструкторе для строки-члена класса
	delete[] m_pStr;
}

// Метод класса
char* MyString::GetString()
{
	return m_pStr;
}

int MyString::GetLength()
{
	return strlen(m_pStr) + 1;
}

MyString& MyString::operator= (const MyString& v) {//оператор присвоения
	if (this == &v)
		return *this;
	Copy(v.m_pStr);
	return *this;
}


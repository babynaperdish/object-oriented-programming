#pragma once
#include <cstring>

class MyString
{
private:
	char* m_pStr;		// Элемент данных класса (адрес строки)
public:
    MyString ();
	MyString (char* s);	// Объявление конструктора
	MyString(const MyString&);
	MyString(const char*);
    ~MyString();		// Объявление деструктора

	void Copy (char* s);
	char* GetString();	// Объявление метода (accessor)
	int GetLength();	// Объявление метода (длина строки)
	MyString& operator= (const MyString&);
};

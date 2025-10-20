#pragma once

class MyString
{
private:
	char* m_pStr;		// Ёлемент данных класса (адрес строки)
public:
	MyString();
	MyString(const char* s);	// ќбъ€вление конструктора
	MyString(const MyString&);
	~MyString();		// ќбъ€вление деструктора

	void Copy(const char* s);
	char* GetString();	// ќбъ€вление метода (accessor)
	int GetLength();	// ќбъ€вление метода (длина строки)
	MyString& operator= (const MyString&);
	bool operator==(const char*) const;
	char at(size_t);
	friend std::ostream& operator<<(std::ostream& os, const MyString& p);
};
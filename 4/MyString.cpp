#include <iostream>
#include "MyString.h"

void MyString::Copy(const char* s)
{
	delete[] m_pStr;
	// ����������� �������� ��������� ���������� ������.
	int len = strlen(s) + 1;
	m_pStr = new char[len];
	// + 1, ��� ��� ������� ���� ���� ����� �����������
	// ���� ������ ��������, �������� ������-�������� � ������-���� ������
	if (m_pStr)
		strcpy_s(m_pStr, len, s);
}

MyString::MyString() {
	m_pStr = new char[1];
}

// ����������� ������������.
MyString::MyString(const char* s)
{
	m_pStr = 0;
	Copy(s);
}

MyString::MyString(const MyString& v) {
	m_pStr = 0;
	Copy(v.m_pStr);
}

// ����������� �����������.
MyString::~MyString()
{
	// ������������ ������, ������� � ������������ ��� ������-����� ������
	delete[] m_pStr;
}

// ����� ������
char* MyString::GetString()
{
	return m_pStr;
}

int MyString::GetLength()
{
	return strlen(m_pStr) + 1;
}

MyString& MyString::operator= (const MyString& v) {//�������� ����������
	if (this == &v)
		return *this;
	Copy(v.m_pStr);
	return *this;
}

char MyString::at(size_t index) {
	if (index >= strlen(m_pStr)) {
		throw std::out_of_range("Index out of range");
	}
	return m_pStr[index];
}

bool MyString::operator==(const char* other)const {
	return strcmp(m_pStr, other) == 0;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
	if (str.m_pStr != 0) os << str.m_pStr;
	return os;
}

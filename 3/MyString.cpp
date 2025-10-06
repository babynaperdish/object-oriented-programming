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


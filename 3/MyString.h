#pragma once

class MyString
{
private:
	char* m_pStr;		// ������� ������ ������ (����� ������)
public:
	MyString();
	MyString(const char* s);	// ���������� ������������
	MyString(const MyString&);
	~MyString();		// ���������� �����������

	void Copy(const char* s);
	char* GetString();	// ���������� ������ (accessor)
	int GetLength();	// ���������� ������ (����� ������)
	MyString& operator= (const MyString&);
};

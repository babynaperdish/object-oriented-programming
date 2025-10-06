//=======================================================================
//	������������ �3. ������� �������. ������� �������. ����������� ������� �++.
//				��������� ����������.
//=======================================================================
//����������� ����������� ����� �� ������������ 2
#include "stdafx.h"
#include "MyVector.h"
#include "MyString.h"
#include "MyStack.h"
#include <vector>
#include <list>
#include <algorithm>

//============= ������ ������� ��� ������ � ������� ���������
template <class T> void pr(T& v, string s)
{
	std::cout << "\n\n\t" << s << "  # Sequence:\n";

	// �������� ������ ����������
	typename T::iterator p;
	int i;

	for (p = v.begin(), i = 0; p != v.end(); p++, i++)
		std::cout << endl << i + 1 << ". " << *p;
	std::cout << '\n';
}

template <class T> void Swap(T& v1, T& v2) {
	T temp = v1;
	v1 = v2;
	v2 = temp;
}

int main()
{

	//===========================================================
	// ������� �������
	//===========================================================
	// �������� ������ ������� ������������ ���� ���������� - Swap().
	// ��������� ����������������� ���������� ������� � �������
	// ������������ ���� ���������.
	{
		int i = 1, j = -1;
				Swap (i, j);

		double a = 0.5, b = -5.5;
				Swap (a, b);

		Vector u(1, 2), w(-3, -4);
				Swap(u, w);

				// ���� �� ���������� ������� ����� MyString � ���������� ������,
				// �� ��������� �������� ���� ������ �������� ���������.

		MyString s1("Your fault"), s2("My forgiveness");
		Swap (s1, s2);
	}
	//===========================================================
	// ������� �������
	//===========================================================
	// �������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
	// � �������� ������ ��� ����� ����� ���� ������ ������.
	// ��� ������� ������������� ������� ����� ����� ���� �����������
	// ��������-��������� �������
	// ������������� ���������� �� ������ �������� "Push" � "Pop","GetSize" � "Capacity"
	// �������������� - ����� ���� ����� �� ������� (operator[]).
	// ��� ����, ����� ������������� ���������� ���������� ���� �������� 
	// ������� ������������ �������������� ��������.

	// � ������� ������� MyStack �������� ���� ���������� ���� int, �����
	// ���� ���������� ���� double �, �������, ���� �� ���������� ���� Vector 
	// ���� �� ����������� ��� ������ ��� ��������� ����������,
	// �� ��������� �������� ������ ��������
	try
	{
		std::cout << "\tTest MyStack\n";
		MyStack <int, 3> stack;

		std::cout << "\nInteger Stack capacity: " << stack.Capacity();

		stack.Push(1);
		stack.Push(2);
		stack.Push(3);

		std::cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

		//		stack.Push(4);	// ����� ������ ���� "���������" ����������

		std::cout << "\nInteger Stack pops: " << stack.Pop();
		std::cout << "\nInteger Stack pops: " << stack.Pop();

		std::cout << "\nInteger Stack has: " << stack.GetSize() << " elements";
		stack.Pop();
		stack.Pop();		// ����� ������ ���� "���������" ����������
		stack.Push(2);

		int i = stack[3];	// ����� ������ ���� "���������" ����������

		MyStack<Vector, 5> ptStack;

		std::cout << "\nVector Stack capacity: " << ptStack.Capacity();

		ptStack.Push(Vector(1, 1));
		ptStack.Push(Vector(2, 2));

		std::cout << "\nVector Stack pops: ";
		// ����������� ����� ������ Vector ��� ������ ��������
		ptStack.Pop().Out();

		std::cout << "\nVector Stack has: " << ptStack.GetSize() << " elements";
	}
	catch (StackOverflow)
	{
		std::cout << "\nStack overflow";
	}
	catch (StackUnderflow)
	{
		std::cout << "\nStack underflow";
	}
	catch (StackOutOfRange o)
	{
		o.Out();
	}

	stop;

	//=======================================================================
	// ���������� ����������� ����������. ������������������ ���� vector
	//=======================================================================

	// �������� ������ ������ ����� �����. ������� ��� ������ � ������� ������ size(),
	// � ������� ������ push_back() ��������� ������ ������-���� ����������.
	// �������� ����� ������ ������� � �������� �������� ��� ���������.
	// � �������� ������ � �������� �� ������ ����� ���������� ������� �����������
	// ��������� (size()) ������ ����������� ��������� ���������� ��������� (max_size()),
	// � ����� ����������������� ������ (capacity()).

	vector<int> v;
	int n = v.size();
	v.push_back(-1);
	v.push_back(-2);
	n = v.size();
	n = v.capacity();
	n = v.max_size();

	// ��� ��� �� ����� ����� �������� ������������������, �� �������������
	// ������� ������ ������� ��� ������ ������ ����������.
	// ��������������� ���� ������ �������� (pr), ������� �������� ����
	// ����������� ��� ��� ������ ������ �������

	pr(v, "Vector of ints");

	// ���������� ������ ����������� ��� �������� ������� ������������
	// � ��������� �������� � 2 �������� � ����������� (222.).
	// �������� ��������� �������. ����� ������� ������ ������� � ��� ����������
	// (����� - resize()) � ����� �������� ���������.

	vector<double> vd(2, 222.);
	pr(vd, "Vector of doubles");
	n = vd.size();
	n = vd.capacity();
	n = vd.max_size();

	vd.push_back(3);

	pr(vd, "After resize");
	n = vd.size();
	n = vd.capacity();
	n = vd.max_size();

	// ��������� ����� at(), � ����� �������� ������ [], �������� ��������
	// ��������� ��������� ������� � ��������� ���������.
	vd[1] = vd.at(0);
	vd[0] = 1;
	pr(vd, "After at");

	//// �������� ������ ������������, ������� �������� ������ �������������.
	vector<double>wd = vd;
	pr(wd, "Copy");

	//// �������� ������, ������� �������� ����� ������������ ������������������
	vector<double> ud(wd.begin(), wd.begin() + 2);
	pr(ud, "Copy part");

	//// �������� ������ ������������, ������� �������� ������ ����� �������� �������.
	double ar[] = { 0., 1., 2., 3., 4., 5. };

	vector<double> va(ar, ar + 3);
	pr(va, "Copy part of array");

	//// �������� ������ ��������, ������� �������� ������ ����� ������� ������
	char s[] = "Array is a succession of chars";

	vector<char> vc(s, s + 3);
	pr(vc, "Copy part of c-style string");

	//// �������� ������ ��������� ���� Vector � ���������������
	//// ��� �������� � ������������ (1,1).
	vector<Vector> vv;
	vv.push_back(Vector(1, 1));

	std::cout << "\n\nvector of Vectors\n";
	for (int i = 0; i < vv.size(); i++)
		vv[i].Out();

	//// �������� ������ ���������� �� Vector � ��������������� ��� ��������
	//// �������� ������ Vector

	std::vector<Vector*> vp;

	for (int i = 0; i < vv.size(); i++)
		vp.push_back(&vv[i]);  // ��������� ������ �������� �� vv

	std::cout << "\n\nvector of pointers to Vector\n";

	for (int i = 0; i < vp.size(); i++)
		vp[i]->Out();

	//// ��������� ������������ ������� assign � ���������
	//// ������������ = ��� ����������� ���� vector.
	//vp = {&vv[0], &vv[1] };
	//vp.assign(5, &vv[0]);

	std::cout << "\n\nAfter assign\n";
	for (int i = 0; i < vp.size(); i++)
		vp[i]->Out();

	//// ������������ ����� ������ ���������� �� Vector � ��������������� ��� 
	//// � ������� ������ ������ assign
	vector<Vector> vpNew; //size=
	vpNew.assign(vv.begin(), vv.end());

	std::cout << "\n\nNew vector after assign\n";
	for (int i = 0; i < vpNew.size(); i++)
		vpNew[i].Out();

	//// �� ���� ������� vector �������� ���������� ������ �
	//// ��������� ��� ���������� ������� ���������.
	//// ������ ������� - ������������� �������
	//// ������ ������� - ����������� �������


	////========= ����������� �������
	int rows = 4;
	vector <vector<double>> vdd(rows);
	for (int i = 0; i < vdd.size(); i++)
		vdd[i] = vector<double>(rows, double(i));

	cout << "\n\n\tTest vector of vector<double>\n";
	for (int i = 0; i < vdd.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < vdd[i].size(); j++)
			cout << vdd[i][j] << "  ";
	}
	cout << endl << endl;
	stop;

	//===================================
	// ���������� �������� � ������������
	//===================================
	//3�. ��������� �������� ������� � ���������� ��������� ������������������.
	//��������� ������� ������������������. ������������ ��������
	//��������� ����� ������������������ ��������� ������ - assign().

	//�������� � ������������������ ������ �� ��������� char. ������ -
	//�� �������.

	vector<char> w = { 'a', 'b', 'c', 'd', 'e' };
	//�������� � ������������������ ������ �� ��������� char. ������ -
	//�� �������.

	char cMas[] = { 'x', 'y', 'z', 'w', 'v', 'u' };
	//�������� �������� ������� �������� ������� ( front() )

	char first = w.front();
	//�������� �������� ���������� �������� ������� ( back() )

	char last = w.back();
	//�������� ������ �������

	size_t vSize = w.size();
	cout << "First element: " << first << endl;
	cout << "Last element: " << last << endl;
	cout << "Vector size: " << vSize << endl;
	//��������� ������� ����� �������� �� �������� ������� cMas.
	w.assign(cMas, cMas + 4);

	// ��������� ����� ������������
	cout << "\nAfter assign:\n";
	cout << "Vector size: " << w.size() << endl;
	cout << "First element: " << w.front() << endl;
	cout << "Last element: " << w.back() << endl;

	stop;


	//3�. ������ � ������������ ��������� ������� � ��������� - at()
	//� ��� �������� - []
	//�������� �������������������� ������ �� 8 ��������� char - vChar2.
	//� ������� at() ��������� ������ ��������� ������� ��������
	//��������� vChar1 �� ����������� �������,
	//� � ������� [] ��������� �������� ��������� ������� vChar2 ��������
	//������� {'K','U','K','U'}.

	vector<char> vChar1 = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	vector<char> vChar2(8);
	char oddVals[] = { 'K', 'U', 'K', 'U' };
	for (size_t i = 0; i < vChar2.size(); i += 2) {
		vChar2.at(i) = vChar1.at(i);
	}
	for (size_t i = 1, j = 0; i < vChar2.size(); i += 2, j++) {
		vChar2[i] = oddVals[j];
	}

	cout << "vChar2 after:\n";
	for (char ch : vChar2) cout << ch << ' ';
	cout << "\n\n";
	stop;
	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. �������� ��������: ��� ���������� ���
	//������� ��������� � ��������������� �������� � ����� �������

	try {
		cout << "at(): " << vChar2.at(10) << endl;
	}
	catch (const out_of_range& e) {
		cout << "at(10): " << e.what() << endl;
	}

	// [] �� ��������� �������, ����� �������� � ��������������� ��������� (��������� � ������ ��� ���������� ����������)

	/*cout << "[]: " << vChar2[10] << "UB" << endl;
	cout << "\n";*/

	stop;

	//3�.�������� � ����� ������� vChar2  - ����� Z (push_back()). ���
	//���������� ��������� ������ �� ����� �� � �������� (pop_back())


	stop;

	//3�. �������-�������� �������� ������������������ insert() - erase()
	//������� ������������������ - clear()

	vChar2.push_back('Z');
	vChar2.pop_back();

	//�������� ����� ������ ��������� ������� vChar2 ����� 'W'

	int ss = vChar2.size();
	for (size_t i = 0; i < ss * 2; i += 2) {
		vChar2.insert(vChar2.begin() + i, 'W');
	}
	cout << "After insert:\n";
	for (char ch : vChar2) cout << ch << ' ';
	cout << "\n\n";

	//�������� ����� 5-�� ��������� ������� vChar2 3 ����� 'X'

	vChar2.insert(vChar2.begin() + 4, 3, 'X');
	cout << "After insert 'XXX':\n";
	for (char ch : vChar2) cout << ch << ' ';
	cout << "\n\n";

	//�������� ����� 2-�� ��������� ������� vChar2 � �������� ��
	//������ �������� ������� "aaabbbccc"

	char arr2[] = { 'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c' };
	vChar2.insert(vChar2.begin() + 1, arr2 + 2, arr2 + 6);

	//������� c ������� �� ������� �������� vChar2

	if (vChar2.size() >= 10)
		vChar2.erase(vChar2.begin(), vChar2.begin() + 10);
	else
		vChar2.clear();

	stop;

	//���������� ��� �������� ������������������ - clear()

	vChar2.clear();
	stop;

	//�������� ����������� �������
	vector<vector<char>> ddarr(3, vector<char>(4));
	char val = 'A';
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			ddarr[i][j] = val++;
	stop;

	///////////////////////////////////////////////////////////////////



	//������� 4. ������. ��������, ����������� ��� �������.
		//�������� ��� ������ ������ �� ��������� Vector - ptList1 �
		//ptList2

	list<Vector> ptList1, ptList2;


	//��������� ��� ������ ���������� � ������� ������� push_back(),
	//push_front, insrert()

	ptList1.push_back(Vector(3, 4));
	ptList1.push_front(Vector(1, 2));
	ptList1.insert(next(ptList1.begin()), Vector(2, 3)); // ������� �� ������ �����

	ptList2.push_back(Vector(5, 1));
	ptList2.push_back(Vector(2, 2));
	ptList2.push_front(Vector(0, 0));



	//������������ ������ - sort().
	//���������: ��� ����, ����� �������� ����������, � ������ Vector
	//������ ���� ������������� �������� "<"

	ptList1.sort();
	ptList2.sort();

	stop;

	//���������� ��������������� ������ - merge(). ����������: ���
	//��� ���� ���������� �� ������ �������.

	ptList1.merge(ptList2);

	stop;

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ����� ���������� ����� ��������������
	//� ������ Vector �������� "=="
	ptList1.remove(Vector(2, 3));
	stop;

	///////////////////////////////////////////////////////
			//������� 5. ����������� ���������.���������� ������������ ����
		// <algorithm>
		//5�. �������� �� ����� �������� ptList1 �� �����������
		//������� � ������� ��������� for_each()


	cout << "Print ptList1 with for_each: ";
	for_each(ptList1.begin(), ptList1.end(), [](const Vector& v) { v.Out(); cout << " "; });
	cout << "\n\n";

	//5�.� ������� ��������� find() ������� �������� �� ������� Vector �
			//������������ ���������. � ������� ��������� find_if() �������
			//�������� �� �������, ��������������� ������������� �������,
			//��������, ��� ���������� ����� ������ ���� ������ 2.
			//���������: �������� �������-��������, ������� ��������� �������
			//� ���������� boolean-�������� (�������� ����� ���� ��� ����������
			//��������, ��� � ������� ������)

	Vector target(3, 4);
	auto itFind = find(ptList1.begin(), ptList1.end(), target);
	if (itFind != ptList1.end()) {
		cout << "Element (3,4) is found\n";
	}
	else {
		cout << "Element (3,4) isn't found\n";
	}


	//�������� ������ �� ���������� �� ������� Vector. � �������
	//��������� find_if() � ��������� (����� ������������ �������� -
	//����� ������ Vector, ������������ � ���������� �������) ������� �
	//������������������ �������, ��������������� �������

	auto itFindIf = find_if(ptList1.begin(), ptList1.end(), [](const Vector& v) {
		return v.X() > 2 && v.Y() > 2;
		});
	if (itFindIf != ptList1.end()) {
		cout << "Element with coordinates > 2 is found: ";
		itFindIf->Out();
		cout << "\n";
	}
	else {
		cout << "There's no element with coordinates > 2\n";
	}
	cout << "\n";

	stop;

	//5�. �������� ������ ��������� Vector. ��������� ������
	//����������. � ������� ��������� replace() �������� �������
	//� ������������ ��������� ����� ���������. � ������� ���������
	//replace_if() �������� �������, ��������������� ������-����
	//������� �� ������������ ��������. ���������: �������
	//�������� ����������.

	list<Vector> listReplace = {{1,1},{2,2},{3,3},{4,4},{5,5}};
	std::cout << "\n\n";
	// ������� Vector(3,3) �� Vector(9,9)
	replace(listReplace.begin(), listReplace.end(), Vector(3, 3), Vector(9, 9));

	// ������� �������� � x > 3 �� Vector(0,0)
	replace_if(listReplace.begin(), listReplace.end(),
	[](const Vector& v) { return v.X() > 3; },
		Vector(0, 0));

	//������������ �������� ��������� ������

	cout << "listReplace after replace and replace_if: ";
	for (const auto& v : listReplace) { v.Out(); cout << " "; }
	cout << "\n\n";


	//5�. �������� ������ ����� (string). � ������� ��������� count()
	//���������� ���������� ���������� �����. � ������� ���������
	//count_if() ���������� ���������� �����, ������������ � ��������
	//�����

	vector<string> strVec = { "apple", "banana", "avocado", "apricot", "blueberry" };

	// count ���������� "apple"
	int countApple = count(strVec.begin(), strVec.end(), "apple");
	cout << "Amount of 'apple': " << countApple << "\n";

	// count_if �����, ������������ � 'a'
	int countStartsWithA = count_if(strVec.begin(), strVec.end(), [](const string& s) {
		return !s.empty() && s[0] == 'a';
		});
	cout << "Amount of stings with 0 element 'a': " << countStartsWithA << "\n\n";

	//5�. � ������� ��������� count_if() ���������� ���������� �����,
	//������� ��������� � �������� �������. ���������: ������ ����
	//�������-�������
	const char* b = "banana";

	int countBanana = count_if(strVec.begin(), strVec.end(), [b](const string& s) {
		return s == b;
		});
	cout << "Amount of same as 'banana' strings: " << countBanana << "\n";
	stop;

	return 0;
}
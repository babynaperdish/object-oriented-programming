// ���������� STL: 
//deque, stack, queue, priority_queue
//set, multiset, map, multimap
//���������. ����������� ���������. ���������.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include "point.h"
#include "MyString.h"
#include "Rect.h"

using namespace std;
#define	  stop __asm nop

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

template <class T> void print(stack<T> v, string s) {
	std::cout << "\n\n\t" << s << "  # Sequence:\n\n";
	while (!v.empty()) {
		cout << v.top() << " ";
		v.pop();
	}
	cout << endl;
}

template <class T> void print(queue<T> v, string s) {
	std::cout << "\n\n\t" << s << "  # Sequence:\n\n";
	while (!v.empty()) {
		cout << v.front() << " ";
		v.pop();
	}
	cout << endl;
}

template <class T> void print(priority_queue<T> v, string s) {
	std::cout << "\n\n\t" << s << "  # Sequence:\n\n";
	while (!v.empty()) {
		cout << v.top() << " ";
		v.pop();
	}
	cout << endl;
}

template <class T> bool IfTheSame(stack<T> s1, stack<T> s2) {
	if (s1.empty() && s2.empty()) return true;
	if (s1.size() != s2.size()) return false;
	stack<T> temp1 = s1;
	stack<T> temp2 = s2;
	while (!temp1.empty()) {
		if (temp1.top() != temp2.top()) return false;
		temp1.pop();
		temp2.pop();
	}
	return true;
}

template <typename T>
void pr_element(const T& element) {
	std::cout << element << " ";
}

template<typename T>
void setCoor(T& point, int newX, int newY) {
	point.SetX(newX);
	point.SetY(newY);
}

bool Pred1_1(const Point& p) {
	int n = 2;
	int m = 5;
	return (p.getX() >= -n && p.getX() <= m) && (p.getY() >= -n && p.getY() <= m);
}

char to_lower(char c) {
	return tolower(static_cast<unsigned char>(c));
}

void convert_to_lowe(string& str) {
	transform(str.begin(), str.end(), str.begin(), to_lower);
}

int main()
{

	//������� � ����� ������� - ��������� deque

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������

	vector<Point> vec = { {1, 2}, {3, 4}, {5, 6} };
	deque<Point> deq;

	pr(deq, "deque before assign");

	deq.assign(vec.begin(), vec.end());

	pr(deq, "deque after assign");

	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'

	deque<MyString> mas;
	mas.push_back("Joker");
	mas.push_front("Queen");
	auto iter = mas.begin();
	mas.insert(iter + 1, "King");
	mas.push_front("Apple");
	mas.push_front("apple");

	pr(mas, "before erase");

	for (iter = mas.begin(); iter != mas.end();) {
		if (iter->at(0) == 'A' || iter->at(0) == 'a') {
			iter = mas.erase(iter);
		}
		else iter++;
	}

	pr(mas, "after erase");

	////////////////////////////////////////////////////////////////////////////////////
	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//���������, ��� "��������" ������ "� ��������"?
	//��� ���������� � ������������ ����� ������ ��������?

	stack<string> kek;
	kek.push("pig");
	kek.push("stupid");
	kek.push("little");
	kek.push("ololo");
	kek.push("WW");	

	print(kek, "test stack");

	queue<string> meow;
	meow.push("meow");
	meow.push("mandarinki");
	meow.push("kozinak");

	print(meow, "test queue");

	priority_queue<int> nums;
	nums.push(15);
	nums.push(22);
	nums.push(1);
	nums.push(3);

	print(nums, "test priority_queue");

	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 

	vector<int> testv = { 1, 2, 3, 4, 5 };
	stack<int> tests;
	for (auto i = testv.rbegin(); i != testv.rend(); i++) {
		tests.push(*i);
	}
	cout << "\n\nStack:" << endl;
	print(tests, "vector is copied");

	//��������� � ����������� ������
	//�) �������� ���� � ����� �������� ������� �������� ���������
	//�) �������� ����� ���� ����� �������, ����� �� ���� ������ �������
	//�) �������� ����� �� ���������
	//�) ������������� ����� �� ������ ����� ������� (push, pop, top)
	//�) ���������, ����� �� ������ ������ (���������, ����� ����� ������������ � ����� ���������)
	{
		stack<string> test1;
		test1.push("plump");
		test1.push("cactus");
		test1.push("fridge");

		stack<string> test2 = test1;

		cout << "\ntest comparising: " << IfTheSame(test1, test2) << endl;

		stop

	}


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?
	{

		queue<Point*, deque<Point*>> qpp;
		Point* p1 = new Point(3, 12);
		Point* p2 = new Point(8, 42);
		Point* p3 = new Point(7, 14);
		Point* p4 = new Point(15, 2);

		qpp.push(p1);
		qpp.push(p2);
		qpp.push(p3);
		qpp.push(p4);

		Point* pf = qpp.front();
		pf->setX(18);
		pf->setY(5);

		Point* pb = qpp.back();
		pb->setX(6);
		pb->setY(7);

		while (!qpp.empty()) {
			delete qpp.front();
			qpp.pop();
		}


	}
	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?								
	// 
	//		��������� �������� ���������

	{
		priority_queue<const char*> pqpp;
		const char* temp[] = { "fish", "dog", "cat", "fly"};
		for (const char* str : temp) {
			pqpp.push(str);
		}
		print(pqpp, "priority queue:");
		stop
	}

	////////////////////////////////////////////////////////////////////////////////////
	//set

	{
		//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ���������� � ������ Point (� ����� �������)
		//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
		set<Point> test = { Point(3,4) , Point(5, 6), Point(0, 0), Point(3, 4) };
		pr(test, "set test");

		//�) ���������� �������� ����� ��������... �������� ��������� ������������� => ��������� ��������� �������� � ������������ ������ 
		//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
		//		���� int, �� ���������� � ������ �������
		set<int> test1 = { 1, 2, 3, 5, 6, 8, 7 };
		set<int> test2 = { 2, 1, 7, 8, 6, 5, 3 };
		pr(test1, "First set:");
		pr(test2, "Second set:");

		//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)
		int arr[] = {1, 4, 4, 4, 9, 9};
		test1.insert(arr, arr + 5);
		pr(test1, "Set after insert:");
	}
	////////////////////////////////////////////////////////////////////////////////////
	//multiset




	////////////////////////////////////////////////////////////////////////////////////
	//map	
	{
		//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
		//	��� ���� ������ �������� ���������� ����������
		map<const char*, int> test;

		//�) ��������� ��������� ���������� ����������� operator[] � insert()
		test["Ivanova"] = 200000;
		test.insert({ "Voloschenko", 100000 });

		//�) ������������ ����������
		cout << endl;
		for (const auto& element : test)
			cout << element.first << "\t" << element.second << endl;

		//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")
		int temp = test["Ivanova"];
		test.erase("Ivanova");
		test.insert({ "Petrova", temp });
		cout << endl;
		for (const auto& element : test)
			cout << element.first << "\t" << element.second << endl;
	}
	stop

		////////////////////////////////////////////////////////////////////////////////////
		//multimap
		//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
		//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
		setlocale(LC_ALL, "Russian");
		multimap<string, string> dict;

		//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
		//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
		dict.insert(make_pair( "strange", "��������"));
		dict.insert(make_pair( "strange", "�����"));
		dict.insert(make_pair( "free", "����������" ));
		dict.insert(make_pair( "free", "���������" ));

		//�) �������� ��� ���������� ������� �� �����
		cout << endl;
		for (const auto& element : dict)
			cout << element.first << "\t" << element.second << endl;

		//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
		//		���������� ����� ������������ ������ lower_bound() � upper_bound()
		cout << endl;
		string word;
		cout << "Enter english word: ";
		cin >> word;
		cout << endl;
		auto range = dict.equal_range(word);
		cout << "�������� ��� ����� \"" << word << "\":" << endl;
		for (auto it = range.first; it != range.second; ++it) {
			cout << it->second << endl;
		}

	///////////////////////////////////////////////////////////////////

		//���������

		//����������� ���������. ����������� set<Point>. ���������, ���
		//����� ����������� � ������ Point. �������� ������, �������� �������� 
		//�������� ������� ��������� set, �� ����������� �� ��������

		{
			set<Point> test = { Point(1,2), Point(3, 3), Point(0,0) };
			vector<Point> copy_test (test.begin(), test.end());
			sort(copy_test.rbegin(), copy_test.rend());
			pr(test, "Set:");
			pr(copy_test, "Vector:");

		//��������� ���������. � ������� ostream_iterator �������� ����������
		//vector � set �� ����������� ������� �� �����.
		//��������� �������. � ������� ������������ ���������:
		//back_inserter() ������������ � ������������ � ������� �������� push_back, �������� deque, vector, list, string
			vector<Point> testv;
			copy (copy_test.begin(), copy_test.end(), back_inserter(testv));
			pr(testv, "Back inserter:");
			//front_inserter() ������������ � ������������ � ������� ���� ��������� ������� � ������ (push_front), �������� deque, list, forward_list
			// �������������, ������������� � ��������������� ���������� �� ��������������

			//inserter() �������� �� ����� �� ����������� ��������� ����������� (stack, queue, priority_queue)
			
			set<Point> tests;
			copy(test.begin(), test.end(), inserter(tests, tests.end()));
			pr(testv, "Inserter:");
			//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
			//����� �� ���������� ������� ����� ������������ � ������ �����������.
			//��������� ��������, � �� �������������� �� ������������������

		}
	///////////////////////////////////////////////////////////////////

		//���������� ��������� (������������ ���� <algorithm>). ���������.
		// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
		//(������, vector, list...)
		//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
		//������������ �������� ���������
		//��������� : ������� ���������� ������� ���������� ��� ������
		{
			vector<Point> test = { Point(1,2), Point(3, 3), Point(0,0) };
			cout << "\nElements in vector: ";
			for_each(test.begin(), test.end(), pr_element<Point>);
			cout << endl;

		}
		stop

		//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
		//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
		//��� ������) � �������� ��������� � ������� ����������� ���������
		{
			int newX = 10;
			int newY = 10;
			vector<Point> test = { Point(1,2), Point(3, 3), Point(0,0) };
			cout << "\nElements in vector before changing: ";
			for_each(test.begin(), test.end(), pr_element<Point>);
			for_each(test.begin(), test.end(), [newX, newY](Point& p) {
				setCoor(p, newX, newY);
				});
			cout << "\nElements in vector after changing: ";
			for_each(test.begin(), test.end(), pr_element<Point>);
			cout << endl;

		//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
		//��� ��������� �� ������� Point � ��������� ���������.
			Point temp2(10, 10);
			auto it = find(test.begin(), test.end(), temp2);
			while (it != test.end()) {
				cout << "(" << it->getX() << "," << it->getY() << ")\n";
				it = find(next(it), test.end(), temp2);
			}
		//� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
		////�� ��������� �������� ��������� ������������������ �� �����������.
		//��� ������ ���� ���������� � ������ Point?
		// ���������: ���������� �������� sort �� �������� �� �������, ��� ���
		//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!
				test = { Point(1,2), Point(3, 3), Point(0,0) };
				sort(test.begin(), test.end());
				pr(test, "Vector after sort: ");


		//�������� ���������� ������� ����: bool Pred1_1(const Point& ), ������� ����� ����������
		//���������� find_if(), ��������� � �������� ��������� ��������� ������� ������������������.
		//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
		//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
		//[-n, +m].

			auto it2 = std::find_if(test.begin(), test.end(), Pred1_1);
			if (it2 != test.end()) {
				cout << "������ �������: ";
				cout << "(" << it2->getX() << "," << it2->getY() << ")\n";
			}
			else {
				cout << "������� �� ������." << endl;
			}
		}
		//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
		//���������� �������������� �� �������� ������ �� ������ ���������.
		{
			vector<Rect> test = { Rect(1, 1, 2, 2), Rect(0, 0, 1, 1) };
			sort(test.begin(), test.end());
		}
		

	{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()
		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������


		list<string> strlst = { "Hahahah", "HeLIcOpTer", "AAAA" };
		set<string> stlow;

		transform(strlst.begin(), strlst.end(),
			inserter(stlow, stlow.end()),
			[](const string& str) {
				string low = str;
				convert_to_lowe(low);
				return low;
			});
		pr(stlow, "List: ");
		stop
	}
	{// map

		//����������� ����� �������� ������ � ���������� ���� string.
		//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		//��������� ������������� �� �������� ������ �
		//���������� ���������� ������ ������ � �������

		vector<string> svec = {
		"a", "b", "a", "o", "b",
		"g", "a", "b", "g", "m"
		};
		map<string, int> smp;
		for (const auto& str : svec) {
			smp[str]++;
		}
		cout << "\n������ � ���������� �� ����������:\n";
		for (const auto& pair : smp) {
			std::cout << pair.first << ": " << pair.second << std::endl;
		}
	}
	return 0;
}



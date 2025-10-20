// Контейнеры STL: 
//deque, stack, queue, priority_queue
//set, multiset, map, multimap
//Итераторы. Стандартные алгоритмы. Предикаты.

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

	// Итератор любого контейнера
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

	//Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать

	vector<Point> vec = { {1, 2}, {3, 4}, {5, 6} };
	deque<Point> deq;

	pr(deq, "deque before assign");

	deq.assign(vec.begin(), vec.end());

	pr(deq, "deque after assign");

	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'

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
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//Подумайте, как "получать" данное "с верхушки"?
	//Что происходит с контейнерами после вывода значений?

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

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 

	vector<int> testv = { 1, 2, 3, 4, 5 };
	stack<int> tests;
	for (auto i = testv.rbegin(); i != testv.rend(); i++) {
		tests.push(*i);
	}
	cout << "\n\nStack:" << endl;
	print(tests, "vector is copied");

	//Сравнение и копирование стеков
	//а) создайте стек и любым способом задайте значения элементов
	//б) создайте новый стек таким образом, чтобы он стал копией первого
	//в) сравните стеки на равенство
	//г) модифицируйте любой из стеком любым образом (push, pop, top)
	//д) проверьте, какой из стеков больше (подумайте, какой смысл вкладывается в такое сравнение)
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

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
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
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?								
	// 
	//		численное значение указателя

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
		//a) создайте множество с элементами типа Point - подумайте, что необходимо определить в классе Point (и каким образом)
		//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
		set<Point> test = { Point(3,4) , Point(5, 6), Point(0, 0), Point(3, 4) };
		pr(test, "set test");

		//в) попробуйте изменить любое значение... элементы множества отсортированы => изменение элементов приведет к некорректной работе 
		//г) Создайте два множества, которые будут содержать одинаковые значения
		//		типа int, но занесенные в разном порядке
		set<int> test1 = { 1, 2, 3, 5, 6, 8, 7 };
		set<int> test2 = { 2, 1, 7, 8, 6, 5, 3 };
		pr(test1, "First set:");
		pr(test2, "Second set:");

		//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)
		int arr[] = {1, 4, 4, 4, 9, 9};
		test1.insert(arr, arr + 5);
		pr(test1, "Set after insert:");
	}
	////////////////////////////////////////////////////////////////////////////////////
	//multiset




	////////////////////////////////////////////////////////////////////////////////////
	//map	
	{
		//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
		//	при этом строки задаются строковыми литералами
		map<const char*, int> test;

		//б) заполните контейнер значениями посредством operator[] и insert()
		test["Ivanova"] = 200000;
		test.insert({ "Voloschenko", 100000 });

		//в) распечатайте содержимое
		cout << endl;
		for (const auto& element : test)
			cout << element.first << "\t" << element.second << endl;

		//е) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
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
		//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
		//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
		setlocale(LC_ALL, "Russian");
		multimap<string, string> dict;

		//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
		//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
		dict.insert(make_pair( "strange", "странный"));
		dict.insert(make_pair( "strange", "чужой"));
		dict.insert(make_pair( "free", "бесплатный" ));
		dict.insert(make_pair( "free", "свободный" ));

		//в) Выведите все содержимое словаря на экран
		cout << endl;
		for (const auto& element : dict)
			cout << element.first << "\t" << element.second << endl;

		//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
		//		итераторов можно использовать методы lower_bound() и upper_bound()
		cout << endl;
		string word;
		cout << "Enter english word: ";
		cin >> word;
		cout << endl;
		auto range = dict.equal_range(word);
		cout << "Переводы для слова \"" << word << "\":" << endl;
		for (auto it = range.first; it != range.second; ++it) {
			cout << it->second << endl;
		}

	///////////////////////////////////////////////////////////////////

		//Итераторы

		//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
		//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
		//являются копиями элементов set, но упорядочены по убыванию

		{
			set<Point> test = { Point(1,2), Point(3, 3), Point(0,0) };
			vector<Point> copy_test (test.begin(), test.end());
			sort(copy_test.rbegin(), copy_test.rend());
			pr(test, "Set:");
			pr(copy_test, "Vector:");

		//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
		//vector и set из предыдущего задания на экран.
		//Итераторы вставки. С помощью возвращаемых функциями:
		//back_inserter() используется с контейнерами у которых доступен push_back, например deque, vector, list, string
			vector<Point> testv;
			copy (copy_test.begin(), copy_test.end(), back_inserter(testv));
			pr(testv, "Back inserter:");
			//front_inserter() используется с контейнерами у которых есть поддержка вставки в начало (push_front), например deque, list, forward_list
			// ассоциативные, упорядоченные и неупорядоченные контейнеры НЕ поддерживаются

			//inserter() работает со всеми за исключением адаптеров контейнеров (stack, queue, priority_queue)
			
			set<Point> tests;
			copy(test.begin(), test.end(), inserter(tests, tests.end()));
			pr(testv, "Inserter:");
			//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
			//какие из итераторов вставки можно использовать с каждым контейнером.
			//вставляют элементы, а не перезаписывает их последовательность

		}
	///////////////////////////////////////////////////////////////////

		//Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.
		// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
		//(массив, vector, list...)
		//С помощью алгоритма for_each в любой последовательности с элементами любого типа
		//распечатайте значения элементов
		//Подсказка : неплохо вызываемую функцию определить как шаблон
		{
			vector<Point> test = { Point(1,2), Point(3, 3), Point(0,0) };
			cout << "\nElements in vector: ";
			for_each(test.begin(), test.end(), pr_element<Point>);
			cout << endl;

		}
		stop

		//С помощью алгоритма for_each в любой последовательности с элементами типа Point
		//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
		//как шаблон) и выведите результат с помощью предыдущего предиката
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

		//С помощью алгоритма find() найдите в любой последовательности элементов Point
		//все итераторы на элемент Point с указанным значением.
			Point temp2(10, 10);
			auto it = find(test.begin(), test.end(), temp2);
			while (it != test.end()) {
				cout << "(" << it->getX() << "," << it->getY() << ")\n";
				it = find(next(it), test.end(), temp2);
			}
		//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
		////По умолчанию алгоритм сортирует последовательность по возрастанию.
		//Что должно быть определено в классе Point?
		// Замечание: обобщенный алгоритм sort не работает со списком, так как
		//это было бы не эффективно => для списка сортировка реализована методом класса!!!
				test = { Point(1,2), Point(3, 3), Point(0,0) };
				sort(test.begin(), test.end());
				pr(test, "Vector after sort: ");


		//Создайте глобальную функцию вида: bool Pred1_1(const Point& ), которая будет вызываться
		//алгоритмом find_if(), передавая в качестве параметра очередной элемент последовательности.
		//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
		//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
		//[-n, +m].

			auto it2 = std::find_if(test.begin(), test.end(), Pred1_1);
			if (it2 != test.end()) {
				cout << "Найден элемент: ";
				cout << "(" << it2->getX() << "," << it2->getY() << ")\n";
			}
			else {
				cout << "Элемент не найден." << endl;
			}
		}
		//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
		//располагая прямоугольники по удалению центра от начала координат.
		{
			vector<Rect> test = { Rect(1, 1, 2, 2), Rect(0, 0, 1, 1) };
			sort(test.begin(), test.end());
		}
		

	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()
		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр


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

		//Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе

		vector<string> svec = {
		"a", "b", "a", "o", "b",
		"g", "a", "b", "g", "m"
		};
		map<string, int> smp;
		for (const auto& str : svec) {
			smp[str]++;
		}
		cout << "\nСтроки и количество их повторений:\n";
		for (const auto& pair : smp) {
			std::cout << pair.first << ": " << pair.second << std::endl;
		}
	}
	return 0;
}



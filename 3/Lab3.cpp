//=======================================================================
//	Лабораторная №3. Шаблоны функций. Шаблоны классов. Стандартные шаблоны С++.
//				Обработка исключений.
//=======================================================================
//Используйте недостающие файлы из лабораторной 2
#include "stdafx.h"
#include "MyVector.h"
#include "MyString.h"
#include "MyStack.h"
#include <vector>
#include <list>
#include <algorithm>

//============= Шаблон функции для вывода с помощью итератора
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

template <class T> void Swap(T& v1, T& v2) {
	T temp = v1;
	v1 = v2;
	v2 = temp;
}

int main()
{

	//===========================================================
	// Шаблоны функций
	//===========================================================
	// Создайте шаблон функции перестановки двух параметров - Swap().
	// Проверьте работоспособность созданного шаблона с помощью
	// приведенного ниже фрагмента.
	{
		int i = 1, j = -1;
				Swap (i, j);

		double a = 0.5, b = -5.5;
				Swap (a, b);

		Vector u(1, 2), w(-3, -4);
				Swap(u, w);

				// Если вы достаточно развили класс MyString в предыдущей работе,
				// то следующий фрагмент тоже должен работать корректно.

		MyString s1("Your fault"), s2("My forgiveness");
		Swap (s1, s2);
	}
	//===========================================================
	// Шаблоны классов
	//===========================================================
	// Создайте шаблон класса MyStack для хранения элементов любого типа T.
	// В качестве основы для стека может быть выбран массив.
	// Для задания максимального размера стека может быть использован
	// параметр-константа шаблона
	// Обязательными операциями со стеком являются "Push" и "Pop","GetSize" и "Capacity"
	// Необязательной - может быть выбор по индексу (operator[]).
	// Для того, чтобы гарантировать корректное выполнение этих операций 
	// следует генерировать исключительные ситуации.

	// С помощью шаблона MyStack создайте стек переменных типа int, затем
	// стек переменных типа double и, наконец, стек из переменных типа Vector 
	// Если вы подготовите три класса для обработки исключений,
	// то следующий фрагмент должен работать
	try
	{
		std::cout << "\tTest MyStack\n";
		MyStack <int, 3> stack;

		std::cout << "\nInteger Stack capacity: " << stack.Capacity();

		stack.Push(1);
		stack.Push(2);
		stack.Push(3);

		std::cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

		//		stack.Push(4);	// Здесь должно быть "выброшено" исключение

		std::cout << "\nInteger Stack pops: " << stack.Pop();
		std::cout << "\nInteger Stack pops: " << stack.Pop();

		std::cout << "\nInteger Stack has: " << stack.GetSize() << " elements";
		stack.Pop();
		stack.Pop();		// Здесь должно быть "выброшено" исключение
		stack.Push(2);

		int i = stack[3];	// Здесь должно быть "выброшено" исключение

		MyStack<Vector, 5> ptStack;

		std::cout << "\nVector Stack capacity: " << ptStack.Capacity();

		ptStack.Push(Vector(1, 1));
		ptStack.Push(Vector(2, 2));

		std::cout << "\nVector Stack pops: ";
		// Используйте метод класса Vector для вывода элемента
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
	// Контейнеры стандартной библиотеки. Последовательности типа vector
	//=======================================================================

	// Создайте пустой вектор целых чисел. Узнайте его размер с помощью метода size(),
	// С помощью метода push_back() заполните вектор какими-либо значениями.
	// Получите новый размер вектора и выведите значения его элементов.
	// В процессе работы с вектором вы можете кроме количества реально заполненных
	// элементов (size()) узнать максимально возможное количество элементов (max_size()),
	// а также зарезервированную память (capacity()).

	vector<int> v;
	int n = v.size();
	v.push_back(-1);
	v.push_back(-2);
	n = v.size();
	n = v.capacity();
	n = v.max_size();

	// Так как мы часто будем выводить последовательности, то целесообразно
	// создать шаблон функции для вывода любого контейнера.
	// Проанализируйте коды такого шабдлона (pr), который приведен выше
	// Используйте его для вывода вашего вектора

	pr(v, "Vector of ints");

	// Используем другой конструктор для создания вектора вещественных
	// с начальным размером в 2 элемента и заполнением (222.).
	// Проверим параметры вектора. Затем изменим размер вектора и его заполнение
	// (метод - resize()) и вновь проверим параметры.

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

	// Используя метод at(), а также операцию выбора [], измените значения
	// некоторых элементов вектора и проверьте результат.
	vd[1] = vd.at(0);
	vd[0] = 1;
	pr(vd, "After at");

	//// Создайте вектор вещественных, который является копией существующего.
	vector<double>wd = vd;
	pr(wd, "Copy");

	//// Создайте вектор, который копирует часть существующей последовательности
	vector<double> ud(wd.begin(), wd.begin() + 2);
	pr(ud, "Copy part");

	//// Создайте вектор вещественных, который является копией части обычного массива.
	double ar[] = { 0., 1., 2., 3., 4., 5. };

	vector<double> va(ar, ar + 3);
	pr(va, "Copy part of array");

	//// Создайте вектор символов, который является копией части обычной строки
	char s[] = "Array is a succession of chars";

	vector<char> vc(s, s + 3);
	pr(vc, "Copy part of c-style string");

	//// Создайте вектор элементов типа Vector и инициализируйте
	//// его вектором с координатами (1,1).
	vector<Vector> vv;
	vv.push_back(Vector(1, 1));

	std::cout << "\n\nvector of Vectors\n";
	for (int i = 0; i < vv.size(); i++)
		vv[i].Out();

	//// Создайте вектор указателей на Vector и инициализируйте его адресами
	//// объектов класса Vector

	std::vector<Vector*> vp;

	for (int i = 0; i < vv.size(); i++)
		vp.push_back(&vv[i]);  // добавляем адреса объектов из vv

	std::cout << "\n\nvector of pointers to Vector\n";

	for (int i = 0; i < vp.size(); i++)
		vp[i]->Out();

	//// Научитесь пользоваться методом assign и операцией
	//// присваивания = для контейнеров типа vector.
	//vp = {&vv[0], &vv[1] };
	//vp.assign(5, &vv[0]);

	std::cout << "\n\nAfter assign\n";
	for (int i = 0; i < vp.size(); i++)
		vp[i]->Out();

	//// Декларируйте новый вектор указателей на Vector и инициализируйте его 
	//// с помощью второй версии assign
	vector<Vector> vpNew; //size=
	vpNew.assign(vv.begin(), vv.end());

	std::cout << "\n\nNew vector after assign\n";
	for (int i = 0; i < vpNew.size(); i++)
		vpNew[i].Out();

	//// На базе шаблона vector создание двухмерный массив и
	//// заполните его значениями разными способами.
	//// Первый вариант - прямоугольная матрица
	//// Второй вариант - ступенчатая матрица


	////========= Ступенчатая матрица
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
	// Простейшие действия с контейнерами
	//===================================
	//3б. Получение значения первого и последнего элементов последовательности.
	//Получение размера последовательности. Присваивание значений
	//элементов одной последовательности элементам другой - assign().

	//Создайте и проинициализируйте вектор из элементов char. Размер -
	//по желанию.

	vector<char> w = { 'a', 'b', 'c', 'd', 'e' };
	//Создайте и проинициализируйте массив из элементов char. Размер -
	//по желанию.

	char cMas[] = { 'x', 'y', 'z', 'w', 'v', 'u' };
	//Получите значение первого элемента вектора ( front() )

	char first = w.front();
	//Получите значение последнего элемента вектора ( back() )

	char last = w.back();
	//Получите размер вектора

	size_t vSize = w.size();
	cout << "First element: " << first << endl;
	cout << "Last element: " << last << endl;
	cout << "Vector size: " << vSize << endl;
	//Присвойте вектору любой диапазон из значений массива cMas.
	w.assign(cMas, cMas + 4);

	// Проверяем после присваивания
	cout << "\nAfter assign:\n";
	cout << "Vector size: " << w.size() << endl;
	cout << "First element: " << w.front() << endl;
	cout << "Last element: " << w.back() << endl;

	stop;


	//3в. Доступ к произвольным элементам вектора с проверкой - at()
	//и без проверки - []
	//Создайте неинициализированный вектор из 8 элементов char - vChar2.
	//С помощью at() присвойте четным элементам вектора значения
	//элементов vChar1 из предыдущего задания,
	//а с помощью [] присвойте нечетным элементам вектора vChar2 значения
	//массива {'K','U','K','U'}.

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
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. Обратите внимание: что происходит при
	//попытке обращения к несуществующему элементу в обоих случаях

	try {
		cout << "at(): " << vChar2.at(10) << endl;
	}
	catch (const out_of_range& e) {
		cout << "at(10): " << e.what() << endl;
	}

	// [] не проверяет границы, может привести к неопределенному поведению (обращению к мусору или аварийному завершению)

	/*cout << "[]: " << vChar2[10] << "UB" << endl;
	cout << "\n";*/

	stop;

	//3г.Добавьте в конец вектора vChar2  - букву Z (push_back()). Для
	//расширения кругозора можете ее сразу же и выкинуть (pop_back())


	stop;

	//3д. Вставка-удаление элемента последовательности insert() - erase()
	//Очистка последовательности - clear()

	vChar2.push_back('Z');
	vChar2.pop_back();

	//Вставьте перед каждым элементом вектора vChar2 букву 'W'

	int ss = vChar2.size();
	for (size_t i = 0; i < ss * 2; i += 2) {
		vChar2.insert(vChar2.begin() + i, 'W');
	}
	cout << "After insert:\n";
	for (char ch : vChar2) cout << ch << ' ';
	cout << "\n\n";

	//Вставьте перед 5-ым элементом вектора vChar2 3 буквы 'X'

	vChar2.insert(vChar2.begin() + 4, 3, 'X');
	cout << "After insert 'XXX':\n";
	for (char ch : vChar2) cout << ch << ' ';
	cout << "\n\n";

	//Вставьте перед 2-ым элементом вектора vChar2 с третьего по
	//шестой элементы массива "aaabbbccc"

	char arr2[] = { 'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c' };
	vChar2.insert(vChar2.begin() + 1, arr2 + 2, arr2 + 6);

	//Сотрите c первого по десятый элементы vChar2

	if (vChar2.size() >= 10)
		vChar2.erase(vChar2.begin(), vChar2.begin() + 10);
	else
		vChar2.clear();

	stop;

	//Уничтожьте все элементы последовательности - clear()

	vChar2.clear();
	stop;

	//Создание двухмерного массива
	vector<vector<char>> ddarr(3, vector<char>(4));
	char val = 'A';
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			ddarr[i][j] = val++;
	stop;

	///////////////////////////////////////////////////////////////////



	//Задание 4. Списки. Операции, характерные для списков.
		//Создайте два пустых списка из элементов Vector - ptList1 и
		//ptList2

	list<Vector> ptList1, ptList2;


	//Наполните оба списка значениями с помощью методов push_back(),
	//push_front, insrert()

	ptList1.push_back(Vector(3, 4));
	ptList1.push_front(Vector(1, 2));
	ptList1.insert(next(ptList1.begin()), Vector(2, 3)); // Вставка на второе место

	ptList2.push_back(Vector(5, 1));
	ptList2.push_back(Vector(2, 2));
	ptList2.push_front(Vector(0, 0));



	//Отсортируйте списки - sort().
	//Подсказка: для того, чтобы работала сортировка, в классе Vector
	//должен быть переопределен оператор "<"

	ptList1.sort();
	ptList2.sort();

	stop;

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит со вторым списком.

	ptList1.merge(ptList2);

	stop;

	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подсказка: для этого необходимо также переопределить
	//в классе Vector оператор "=="
	ptList1.remove(Vector(2, 3));
	stop;

	///////////////////////////////////////////////////////
			//Задание 5. Стандартные алгоритмы.Подключите заголовочный файл
		// <algorithm>
		//5а. Выведите на экран элементы ptList1 из предыдущего
		//задания с помощью алгоритма for_each()


	cout << "Print ptList1 with for_each: ";
	for_each(ptList1.begin(), ptList1.end(), [](const Vector& v) { v.Out(); cout << " "; });
	cout << "\n\n";

	//5б.С помощью алгоритма find() найдите итератор на элемент Vector с
			//определенным значением. С помощью алгоритма find_if() найдите
			//итератор на элемент, удовлетворяющий определенному условию,
			//например, обе координаты точки должны быть больше 2.
			//Подсказка: напишите функцию-предикат, которая проверяет условие
			//и возвращает boolean-значение (предикат может быть как глобальной
			//функцией, так и методом класса)

	Vector target(3, 4);
	auto itFind = find(ptList1.begin(), ptList1.end(), target);
	if (itFind != ptList1.end()) {
		cout << "Element (3,4) is found\n";
	}
	else {
		cout << "Element (3,4) isn't found\n";
	}


	//Создайте список из указателей на элеметы Vector. С помощью
	//алгоритма find_if() и предиката (можно использовать предикат -
	//метод класса Vector, определенный в предыдущем задании) найдите в
	//последовательности элемент, удовлетворяющий условию

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

	//5в. Создайте список элементов Vector. Наполните список
	//значениями. С помощью алгоритма replace() замените элемент
	//с определенным значением новым значением. С помощью алгоритма
	//replace_if() замените элемент, удовлетворяющий какому-либо
	//условию на определенное значение. Подсказка: условие
	//задается предикатом.

	list<Vector> listReplace = {{1,1},{2,2},{3,3},{4,4},{5,5}};
	std::cout << "\n\n";
	// Заменим Vector(3,3) на Vector(9,9)
	replace(listReplace.begin(), listReplace.end(), Vector(3, 3), Vector(9, 9));

	// Заменим элементы с x > 3 на Vector(0,0)
	replace_if(listReplace.begin(), listReplace.end(),
	[](const Vector& v) { return v.X() > 3; },
		Vector(0, 0));

	//Сформировали значения элементов списка

	cout << "listReplace after replace and replace_if: ";
	for (const auto& v : listReplace) { v.Out(); cout << " "; }
	cout << "\n\n";


	//5г. Создайте вектор строк (string). С помощью алгоритма count()
	//сосчитайте количество одинаковых строк. С помощью алгоритма
	//count_if() сосчитайте количество строк, начинающихся с заданной
	//буквы

	vector<string> strVec = { "apple", "banana", "avocado", "apricot", "blueberry" };

	// count количества "apple"
	int countApple = count(strVec.begin(), strVec.end(), "apple");
	cout << "Amount of 'apple': " << countApple << "\n";

	// count_if строк, начинающихся с 'a'
	int countStartsWithA = count_if(strVec.begin(), strVec.end(), [](const string& s) {
		return !s.empty() && s[0] == 'a';
		});
	cout << "Amount of stings with 0 element 'a': " << countStartsWithA << "\n\n";

	//5д. С помощью алгоритма count_if() сосчитайте количество строк,
	//которые совпадают с заданной строкой. Подсказка: смотри тему
	//объекты-функции
	const char* b = "banana";

	int countBanana = count_if(strVec.begin(), strVec.end(), [b](const string& s) {
		return s == b;
		});
	cout << "Amount of same as 'banana' strings: " << countBanana << "\n";
	stop;

	return 0;
}
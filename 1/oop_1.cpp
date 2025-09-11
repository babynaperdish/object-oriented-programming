#include <cmath>			// математические функции
#include <locale.h>	// функции, устанавливающие национальные кодировки символов
#include <iostream>	// Эта - часть библиотеки STL (Standard Template Library)
#include <limits>			// Полезные константы
#include <conio.h> // getch()

using namespace std;		// Обеспечивает видимость имен STL
#define stop __asm nop// Эта макроподстановка упрощает установку точек останова

int n;	 // Глобальная переменная. По умолчанию она обнуляется.

namespace space	 // В пространстве имен - space
{
	int n = 1;	 // Объявлена переменная n
}				 // space определяет область видимости этой переменной

int  main()
{
	// Выполняя программу по шагам, следите за значениями переменных  и интерпретируйте результат, объясняя себе
	// наблюдаемые значения. Обратите внимание на разную интерпретацию отладчиком  signed и unsigned типов данных.
	char c = 'A'; // 65 'A' 0x41 
	// В комментарии справа полезно проставить десятичное символьное и шестнадцатиричное 
	// значения переменной после выполнения указанной строки. Вы должны видеть их в окне Autos.
	c = 0x42;		// 66 'B' 0x42
	c = -1;		// -1 'я' 0xff
	c = CHAR_BIT;	 // Размер переменной типа char
	stop;

	// В комментариях напишите результат, возвращаемый оператором sizeof для
	// переменной типа wchar_t (ее размер)
	wchar_t cw = L'Ф';
	size_t ns = sizeof(cw);

	unsigned char uc = 0x41;
	uc = 'B';
	uc = -128;//
	stop;

	int i = 1;
	i = -1;
	stop;

	unsigned int ui = 1;
	ui = -1;

	short s = 0xffff;	 // Здесь compiler генерирует warning. Измените код, чтобы убрать warning
	s = short(0xffff);
	s = 1;

	//==== Измените код, чтобы убрать warning
	unsigned short us = 0xffff;
	us = 5;

	long l = 0xffffffff;
	l = -128;

	l = FLT_MAX_EXP;	//128, макс значение двоичной экспоненты
	l = DBL_MAX_EXP;	//1024, макс значение двоичной экспоненты

	l = FLT_MANT_DIG;	//24, колво бит в мантиссе
	l = DBL_DIG;		//15, колво десятичных чисел (точность)

	l = FLT_MANT_DIG;	//
	l = DBL_MANT_DIG;	//53, колво бит в мантиссе

	float f = -12.56f;	 // Здесь warning. Уберите его.
	f = -1.e-27f;

	f = FLT_MAX;		//max знач числа типа float
	f = FLT_MIN;		//min нормализованное полож знач числа типа float

	double d = 0.1234567890123456789123456789;
	d = -0.123456789012345e+306;
	d = DBL_MAX;		//max знач числа типа double
	d = DBL_MIN;		//min положительное знач числа типа double
	d = DBL_EPSILON; // Самая маленькая разность между двумя пер-ми типа double

	uc = ~1;		 // Побитовое отрицание
	i = ~0;
	stop;
	// Раннее (при компиляции) или неявное приведение типов данных
	// Объясните те значения, которые вы наблюдаете в окне Autos. Определите порядок выполения присваиваний.
	d = f = i = s = c = 1 / 3; 
	c = s = i = f = d = 100 / 3;
	c = s = i = f = d = 10 / 3;
	c = s = i = f = d = 1 / 3.;

	// Пример "небрежного" использования неявного приведения типов.	 Объясните результаты.
	i = 256;
	c = i; //c [0; 255], переполнение =>	 266 => 0

	uc = 255;
	unsigned char u = 2, sum = uc + u;//тоже переполнение
	stop;

	// Явное приведение типов	Объясните разницу результатов в строках (3) и (4)
	i = 100;
	f = d = i / 3;							// (3) int -> double
	f = d = (double)i / 3;		// (4)   double -> double -> float
	f = d = double(i) / 3;			// (4)
	f = d = static_cast<double>(i) / 3;		// (4)
	stop;

	// Область действия, область видимости и время существования. В этом фрагменте фигурируют четыре
	//  переменных с одним и тем же именем n.  Одна - глобальная, вторая определена в своем пространстве имен,
	// третья - локальная внутри функции main(), четвертая - локальная внутри блока. 
	//  Обратите внимание, что глобальная переменная и та, что в пространстве имен space - объявлены вне функции main()
	// Определите, к какой из четырех переменных идет обращение, cформулируйте область действия и область видимости
	// каждой переменной. Для выполнения задания рекомендуется пользоваться  закладкой "Watches" или "Locals" окна
	// "Autos". Подсказка: В окно "Watches" можно поместить сразу все переменные (n, ::n, и space::n)
	n = 100;
	space::n = 200;
	n++;
	int n;		//Где живет эта переменная ?  внутри функции main
	n = 10;
	::n++;//глобальня

	{				//  Начало блока
		int n;		// Эта переменная живет внутри блока
		n = -1;
		n++;
		::n++;//глобальная
		space::n++;//global
	}		// Конец блока
	n--;
	::n--;//global
	space::n--;

	// Спецификатор класса памяти - static Выполняя задание по шагам, обратите внимание на  разное поведение
	// переменных nLoc и nStat
	{
	Again:
		int outer;
		for (int i = 0; i < 5; i++)
		{
			static int nStat;
			{
				int nLoc = 0;
				nLoc++;		nStat++;
			}
			outer = nStat;
		}
		if (outer < 10)
			goto Again;
	}
	// Перечисления - enum. Обратите внимание на явную и неявную инициализацию констант
	enum RANK
	{
		One,
		Two,
		Three,
		Four,
		Jack = 6,
		Queen, //7
		Ace = Queen + 3,//10
		Joker = 20
	};
	typedef RANK RANG;

	RANG r = Jack;
	if (r == Jack)
		r = Queen;

	if (r == Queen)
	{
		// Любой целочисленной переменной можно присвоить enum-переменную 
		int i = r;
		r = RANK(i++);		// r= Обратное преобразование надо указывать явно
		i = r;
		r = RANK(++i);
		i = r;
	}
	RANK rr = Ace;
	stop;
	//	Логический тип bool.	Выполняя задание по шагам, следите за значениями переменной b
	{
		int n = 127;
		bool b = n != 0;
		b = n == 0;
		b = n > 0;
		b = n <= 0;
		b = n > 1;

		int num = static_cast<int>(b);
		if (b)
			cout << "\n\t My flag is: true" << "   or: " << b
			<< "\n\t Conversion to int: " << num << endl;
		b = n == num;
		cout << "\n\t Now the flag is: false" << "   or: " << b;
	}

	//	Модификатор const
	const double pi = acos(-1.);
	double space_permiability = 4.e-7 * pi;		//	Магнитная проницаемость пустоты
	const int dozen = 12;
	int var = dozen;

	//	Раскомментируйте следующую строчку и объясните ошибку компиляции (l-value означает left value)
	//	dozen = 1;																// const
	//	Директивы условной трансляции. Объясните значение, которое принимает переменная version.
	//	Что нужно сделать для того, чтобы результат был другим?
#define _MSVER311
	const char* version;				//нужно поменять директиву на директиву другой версии, например на _MSVER311
#if defined _MSVER400
	version = "version 4.00";
#elif defined _MSVER311
	version = "version 3.11";
#else
	version = "version Unknown";
#endif

	cout << endl << version;
	stop;

#define NDEBUG
	const char* compilationType;
#if defined _DEBUG
	compilationType = "debug";
#elif defined NDEBUG
	compilationType = "ndebug";
#else
	compilationType = "type Unknown";
#endif

	cout << endl << compilationType;
	stop;
	//В окне ClassView или Solution Explorer поставьте фокус на имя проекта дайте команду Project/Properties.
	//	В диалоге Property Pages щелкните на папке Configuration Properties, убедитесь, что в разделе Code Generation
	//	установлена константа компиляции _DEBUG. Создайте директивы препроцессора и код С++, которые
	//	в зависимости от действующей конфигурации проекта (_DEBUG или NDEBUG) выводят соответствующее
	//	сообщение. Измените конфигурацию проекта (в диалоге Property Pages) и проверьте ваш код.
	//	Чтобы изменить конфигурацию пользуйтесь кнопкой Configuration Manager

	//	Простейшие циклы. Объясните суть происходящего. 
	{
		// Цикл while надо использовать, когда неизвестно количество итераций (повторений) цикла.
		cout << "\n\nGradually eat out all the units:\n\n";
		unsigned short us = 0xff;
		while (us)
		{
			cout << hex << us << endl;//&= - сбрасывает младший бит числа, цикл выполняется 8 раз
			us &= us - 1;
		}
		cout << hex << us << "\nDone\n";
		// Цикл for надо использовать, когда известно количество итераций и/или есть код подготовки.
		// Подсказка: odd - нечетое, even - четное.
		cout << "\n\nShow even-odd:\n\n";
		for (int i = 0; i < 10; i++)
		{
			if (3 & 2) //11 & 10 
				cout << i << " - odd\n";
			else
				cout << i << " - even\n";
		}
		// Когда нужно использовать цикл do-while?          
		// тогда, когда неизвестно кол-во итераций + нужно выполнить действие даже при условии выхода
		char c = ' ';
		do
		{
			if (c == 'a')
				cout << "\nAction is a delegate type in C#";
			else if (c == 'b')
				cout << "\nbreak is one of the 'leave' statements in all C-like languages";
			else if (c == 'c')
				cout << "\ncontinue is a 'go on' statement in all C-like languages";
			else if (c == 'd')
				cout << "\ndo-while is a rarely used loop statement in all C-like languages";
			else
				cout << "\nPlease read the rules of this loop";
			cout << "\n\nEnter chars: a, b, c, d (q - to quit):\n\n";
			cin >> c;
			if (c == 'q')
				cout << "\nI am going to leave the loop\n";
		} while (c != 'q');
		stop;
	
		c = ' ';
		cout << "\n\nChoose a variant: 1 2\n\n";
		cin >> c;
		do {
			if (c == '1') {
				for (int i = 0; i <= 40; i += 1) {
					double x = i / 10.0;
					double y;
					if ((x <= 1) || (x > 3)) {
						y = 0;
					}
					else if (x <= 2) {
						y = (2 * x) - 2;
					}
					else {
						y = -2 * x + 6;
					}
					cout << x << " " << y << endl;
				}
			}
			else if (c == '2') {
				for (int i = 0; i <= 40; i += 1) {
					double x = i / 10.0;
					double y;
					(x <= 1 || x > 3) ? y = 0 : (x <= 2 ? y = 2 * x - 2 : y = -2 * x + 6);
					cout << x << " " << y << endl;
				}
			}
			else {
				cout << "\n\n Please read the rules\n\n";
				cout << "\n\n Choose a variant: 1 2\n\n";
				cin >> c;
			}

		} while ((c != '1') && (c != '2'));
		stop;

		int ch;
		int count = 0;
		bool done = false;
		for (;;) {
			cout << "\n\nEnter chars: a, b, c, Esc (q - to quit):\n\n";
			ch = _getch();
			++count;
			switch (ch) {
			case '\n':
				count--;
				break;
			case '\r':
				count--;
				break;
			case 'a':
				cout << "\n\n" << "a" << "\n\n\"Ok\"\n\n";
				break;
			case 'b':
				cout << "\n\n" << "b" << "\a";
				break;
			case 'c':
				cout << "\n\n" << "c" << "\n\n" << count << "\n\n";
				break;
			case 27:
				cout << "\n\n" << "Esc" << "\n\nto quit use 'q'";
				break;
			case 'q':
				cout << "\n\n" << "q" << "\nI am going to leave the loop\n";
				done = true;
				break;
			default:
				break;
			}
			if (done) break;
		}
	}stop;

	 short flags = 0xaabb;					//1010101010111011
	unsigned short result = (flags << 8) | (flags >> 8) & 0x00ff;			//1101110101010101
	cout << endl << hex << flags << endl << hex << result<< endl;
	stop;

	unsigned char byte = 0x26;
	unsigned char res;
	res = byte | (1 << 3);
	cout << endl << hex << (int)byte << endl << dec << (int)byte << endl;
	cout << endl << hex << (int)res << endl << dec << (int)res << endl;

	res = byte ^ 0x3;
	cout <<endl << hex << (int)res << endl << dec << (int)res << endl;

	res = byte & 0xF0; //0x0F = 0000 1111
	cout << endl << hex << (int)res << endl << dec << (int)res << endl;

	//	Логические условные операторы и циклы. Функция y = f(x) задана графиком
	//	Напишите фрагмент кода, который с шагом 0.1 вычисляет y = f(x)  и выводит в консольное окно значения x и y. y = 2x - 2 y = - 2x + 6
	//	  y
	//	  | 
	//	 2|__________
	//	  |         /\
	//	  |        /  \
	//	  |       /    \
	//	  |______/      \__________  x
	//	  0      1   2   3
	//	 Реалируйте 2 варианта этого алгоритма:   1. Используйте операторы if	 2. Используйте тернарные операции    ? :

	//	Напишите фрагмент, который с помощью for и switch реализует следующую логику. Если пользователь ввел:
	//	символ 'a',   ваш алгоритм выводит  "Ok" (в кавычках)
	//	символ 'b',   ваш алгоритм выводит  Bell (alert - звуковой сигнал)
	//	символ 'с',   ваш алгоритм выводит  число, которое равно количеству введенных символов
	//	символ 'Esc', ваш алгоритм выводит  "to quit use 'q'"
	//	символ 'q',   ваш алгоритм выводит  "Bye" и выходит из цикла ввода

	/*	Побитовые операции:  |, &, ~, ^ и сдвиги >>, <<
		Поменяйте местами байты переменной flags и выведите результат в консолное окно unsigned short flags = 0xaabb;
		Ваш код*/

	//	Для вывода в шестнадцатеричном виде используйте  cout <<"\n bits = " << hex << flags;
	/*	В переменной unsigned char byte = 0x26; 
		      - установите в единицу 3-й бит (счет от нуля). Выведите результат.
		- инвертируйте два младших бита. Выведите результат. 
		      - обнулите 4 младших бита. Выведите результат.
		cout <<endl << hex << flags << endl<<dec<<flags;    */
	cout << "\n\n";
}	// Конец функции main()

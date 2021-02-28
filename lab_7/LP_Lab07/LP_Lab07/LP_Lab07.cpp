
#include <iostream>
#include <conio.h>
#include "stdafx.h"
#include "Dictionary.h"

using namespace Dictionary;
using namespace std;

int main()
{
	setlocale(LC_ALL,"Russian");
	try {
		/*Instance d1 = Create("Преподователи", 5);                 // создание словаря
		Entry e1 = { 1,"Гладкий" }, e2 = { 2,"Веялкин" },         // элементы словаря
			  e3 = { 3,"Смелов" },  e4 = { 4,"Урбанович" }, e5 = { 2,"Пацей" };
		AddEntry(d1, e1);                                         // добавления элемента словарь
		AddEntry(d1, e2);										  // добавления элемента словарь
		AddEntry(d1, e3);										  // добавления элемента словарь
		AddEntry(d1, e4);										  // добавления элемента словарь
		Entry ex2 = GetEntry(d1, 4);                // найти элемент в словаре по идентификатору
		//Print(d1);
		DelEntry(d1, 2);                            // удалить элемент из словаря по идентификатору 
		Entry newentry1 = { 6,"Гурин" };            // элемент словаря 
		UpdEntry(d1, 3, newentry1);                 // заменить элемент словаря по идентификатору 
		Print(d1);                                  // распечатать элементы словаря 


		Instance d2 = Create("Cтуденты", 500);
		Entry s1 = { 1,"Иванов" }, s2 = { 2,"Петров" }, s3 = { 3,"Сидоров" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		Entry newentry3 = { 3,"Николаев" };
		UpdEntry(d2, 3, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);*/

#ifdef TEST_CREATE_01
		Instance d1 = Create("Преподавателииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии", 5);
#endif

#ifdef TEST_CREATE_02
		Instance d1 = Create("Преподаватели", 200);

#endif

#ifdef TEST_ADDENTRY_03

		Instance d1 = Create("Преподаватели", 3);
		Entry el1 = { 1, "Гладкий" },
			el2 = { 2, "Веялкин" },
			el3 = { 3, "Смелов" },
			el4 = { 4, "Урбанович" },
			el5 = { 5, "Пацей" };

		AddEntry(d1, el1);
		AddEntry(d1, el2);
		AddEntry(d1, el3);
		AddEntry(d1, el4);
		AddEntry(d1, el5);

#endif

#ifdef TEST_ADDENTRY_04

		Instance d1 = Create("Преподаватели", 5);
		Entry el1 = { 1, "Гладкий" },
			el2 = { 2, "Веялкин" },
			el3 = { 3, "Смелов" },
			el4 = { 4, "Урбанович" },
			el5 = { 2, "Пацей" };

		AddEntry(d1, el1);
		AddEntry(d1, el2);
		AddEntry(d1, el3);
		AddEntry(d1, el4);
		AddEntry(d1, el5);

#endif

#ifdef TEST_GETENTRY_05

		Instance d1 = Create("Преподаватели", 5);
		Entry el1 = { 1, "Гладкий" },
			el2 = { 2, "Веялкин" },
			el3 = { 3, "Смелов" };

		AddEntry(d1, el1);
		AddEntry(d1, el2);
		AddEntry(d1, el3);


		Entry ex1 = GetEntry(d1, 4);

#endif

#ifdef TEST_DELENTRY_06

		Instance d1 = Create("Преподаватели", 7);
		Entry el1 = { 1, "Гладкий" },
			el2 = { 2, "Веялкин" },
			el3 = { 3, "Смелов" },
			el4 = { 4, "Урбанович" },
			el5 = { 5, "Пацей" };
		DelEntry(d1, 6);

#endif

#ifdef TEST_UPDENTRY_07

		Instance d1 = Create("Преподаватели", 7);
		Entry el1 = { 1, "Гладкий" },
			el2 = { 2, "Веялкин" },
			el3 = { 3, "Смелов" },
			el4 = { 4, "Урбанович" },
			el5 = { 5, "Пацей" };

		AddEntry(d1, el1);
		AddEntry(d1, el2);
		AddEntry(d1, el3);
		AddEntry(d1, el4);
		AddEntry(d1, el5);

		Entry newentry1 = { 6, "Гурин" };
		UpdEntry(d1, 6, newentry1);

#endif

#ifdef TEST_UPDENTRY_08

		Instance d1 = Create("Преподаватели", 5);
		Entry el1 = { 1, "Гладкий" },
			el2 = { 2, "Веялкин" },
			el3 = { 3, "Смелов" },
			el4 = { 4, "Урбанович" },
			el5 = { 5, "Пацей" };

		AddEntry(d1, el1);
		AddEntry(d1, el2);
		AddEntry(d1, el3);
		AddEntry(d1, el4);
		AddEntry(d1, el5);

		Entry newentry1 = { 1, "Гурин" };
		UpdEntry(d1, 5, newentry1);
#endif  
#ifdef TEST_DICTIONARY
		Instance d1 = Create("Преподователи", 5);                 // создание словаря
		Entry e1 = { 1,"Гладкий" }, e2 = { 2,"Веялкин" },         // элементы словаря
			e3 = { 3,"Смелов" }, e4 = { 4,"Урбанович" }, e5 = { 2,"Пацей" };
		AddEntry(d1, e1);                                         // добавления элемента словарь
		AddEntry(d1, e2);										  // добавления элемента словарь
		AddEntry(d1, e3);										  // добавления элемента словарь
		AddEntry(d1, e4);										  // добавления элемента словарь
		Entry ex2 = GetEntry(d1, 4);                // найти элемент в словаре по идентификатору
		//Print(d1);
		DelEntry(d1, 2);                            // удалить элемент из словаря по идентификатору 
		Entry newentry1 = { 6,"Гурин" };            // элемент словаря 
		UpdEntry(d1, 3, newentry1);                 // заменить элемент словаря по идентификатору 
		Print(d1);                                  // распечатать элементы словаря 


		Instance d2 = Create("Cтуденты", 5);
		Entry s1 = { 1,"Иванов" }, s2 = { 2,"Петров" }, s3 = { 3,"Сидоров" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		//Print(d2);
		Entry newentry3 = { 3,"Николаев" };
		UpdEntry(d2, 3, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);
#endif

	}
	catch (char* e) {
			cout <<e << endl;
	}
	_getch();
}


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
		Instance d1 = Create("Преподователи", 5);                 // создание словаря
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


		Instance d2 = Create("Cтуденты", 5);
		Entry s1 = { 1,"Иванов" }, s2 = { 2,"Петров" }, s3 = { 3,"Сидоров" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		Entry newentry3 = { 3,"Николаев" };
		UpdEntry(d2, 3, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);
	}
	catch (char* e) {
			cout <<e << endl;
	}
	_getch();
}

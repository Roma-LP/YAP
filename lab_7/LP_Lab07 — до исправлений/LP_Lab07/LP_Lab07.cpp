
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
		Instance d1 = Create("�������������", 5);                 // �������� �������
		Entry e1 = { 1,"�������" }, e2 = { 2,"�������" },         // �������� �������
			  e3 = { 3,"������" },  e4 = { 4,"���������" }, e5 = { 2,"�����" };
		AddEntry(d1, e1);                                         // ���������� �������� �������
		AddEntry(d1, e2);										  // ���������� �������� �������
		AddEntry(d1, e3);										  // ���������� �������� �������
		AddEntry(d1, e4);										  // ���������� �������� �������
		Entry ex2 = GetEntry(d1, 4);                // ����� ������� � ������� �� ��������������
		//Print(d1);
		DelEntry(d1, 2);                            // ������� ������� �� ������� �� �������������� 
		Entry newentry1 = { 6,"�����" };            // ������� ������� 
		UpdEntry(d1, 3, newentry1);                 // �������� ������� ������� �� �������������� 
		Print(d1);                                  // ����������� �������� ������� 


		Instance d2 = Create("C�������", 5);
		Entry s1 = { 1,"������" }, s2 = { 2,"������" }, s3 = { 3,"�������" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		Entry newentry3 = { 3,"��������" };
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

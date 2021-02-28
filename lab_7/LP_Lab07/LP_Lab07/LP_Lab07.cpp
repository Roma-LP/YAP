
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
		/*Instance d1 = Create("�������������", 5);                 // �������� �������
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


		Instance d2 = Create("C�������", 500);
		Entry s1 = { 1,"������" }, s2 = { 2,"������" }, s3 = { 3,"�������" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		Entry newentry3 = { 3,"��������" };
		UpdEntry(d2, 3, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);*/

#ifdef TEST_CREATE_01
		Instance d1 = Create("������������������������������������������������������������������������������������", 5);
#endif

#ifdef TEST_CREATE_02
		Instance d1 = Create("�������������", 200);

#endif

#ifdef TEST_ADDENTRY_03

		Instance d1 = Create("�������������", 3);
		Entry el1 = { 1, "�������" },
			el2 = { 2, "�������" },
			el3 = { 3, "������" },
			el4 = { 4, "���������" },
			el5 = { 5, "�����" };

		AddEntry(d1, el1);
		AddEntry(d1, el2);
		AddEntry(d1, el3);
		AddEntry(d1, el4);
		AddEntry(d1, el5);

#endif

#ifdef TEST_ADDENTRY_04

		Instance d1 = Create("�������������", 5);
		Entry el1 = { 1, "�������" },
			el2 = { 2, "�������" },
			el3 = { 3, "������" },
			el4 = { 4, "���������" },
			el5 = { 2, "�����" };

		AddEntry(d1, el1);
		AddEntry(d1, el2);
		AddEntry(d1, el3);
		AddEntry(d1, el4);
		AddEntry(d1, el5);

#endif

#ifdef TEST_GETENTRY_05

		Instance d1 = Create("�������������", 5);
		Entry el1 = { 1, "�������" },
			el2 = { 2, "�������" },
			el3 = { 3, "������" };

		AddEntry(d1, el1);
		AddEntry(d1, el2);
		AddEntry(d1, el3);


		Entry ex1 = GetEntry(d1, 4);

#endif

#ifdef TEST_DELENTRY_06

		Instance d1 = Create("�������������", 7);
		Entry el1 = { 1, "�������" },
			el2 = { 2, "�������" },
			el3 = { 3, "������" },
			el4 = { 4, "���������" },
			el5 = { 5, "�����" };
		DelEntry(d1, 6);

#endif

#ifdef TEST_UPDENTRY_07

		Instance d1 = Create("�������������", 7);
		Entry el1 = { 1, "�������" },
			el2 = { 2, "�������" },
			el3 = { 3, "������" },
			el4 = { 4, "���������" },
			el5 = { 5, "�����" };

		AddEntry(d1, el1);
		AddEntry(d1, el2);
		AddEntry(d1, el3);
		AddEntry(d1, el4);
		AddEntry(d1, el5);

		Entry newentry1 = { 6, "�����" };
		UpdEntry(d1, 6, newentry1);

#endif

#ifdef TEST_UPDENTRY_08

		Instance d1 = Create("�������������", 5);
		Entry el1 = { 1, "�������" },
			el2 = { 2, "�������" },
			el3 = { 3, "������" },
			el4 = { 4, "���������" },
			el5 = { 5, "�����" };

		AddEntry(d1, el1);
		AddEntry(d1, el2);
		AddEntry(d1, el3);
		AddEntry(d1, el4);
		AddEntry(d1, el5);

		Entry newentry1 = { 1, "�����" };
		UpdEntry(d1, 5, newentry1);
#endif  
#ifdef TEST_DICTIONARY
		Instance d1 = Create("�������������", 5);                 // �������� �������
		Entry e1 = { 1,"�������" }, e2 = { 2,"�������" },         // �������� �������
			e3 = { 3,"������" }, e4 = { 4,"���������" }, e5 = { 2,"�����" };
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
		//Print(d2);
		Entry newentry3 = { 3,"��������" };
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

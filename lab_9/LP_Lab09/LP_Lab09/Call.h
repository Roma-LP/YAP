#pragma once

namespace Call {
	int _cdecl cdevl(int &num1, int &num2, int &num3); //��������� ���������� � ���� � �������� ������� (������ ������) 
	int _stdcall cstd(int&, int, int);                 //��������� ���������� � ���� � �������� �������(������ ������)
	int _fastcall cfst(int, int, int);				   //�������� � ���������, ����� ���������� � ���� 
}
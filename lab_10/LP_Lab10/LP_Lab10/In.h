#pragma once
#include<iostream>
#include<string>
using namespace std;
#define IN_MAX_LEN_TEXT 1024*1024		//������������ ������ ��������� ���� 1��
#define IN_CODE_ENDL '\n'				//������ ����� ������

//������� �������� ������� ����������, ������ = ��� (Windows-1251) �������
//�������� IN::F - ����������� ������� IN::T - ����������� ������, IN::I - ������������ (�� �������),
//			���� 0 <= �������� < 256  - �� ��������� ������ ��������

#define IN_CODE_TABLE {\
		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, \
		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
		IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
		IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::T, \
		IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::I,   '!', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
		IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::T, \
		IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::I, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
																														\
		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F	\
	}

namespace In {
	struct IN {		//�������� ������
		enum { T = 1024, F = 2048, I = 4096 };	//T - ���������� ������, F - ������������, I - ������������, ����� ��������
		int size;								//������ ��������� ����
		int lines;								//���-�� �����
		int ignor;								//���-�� ����������������� ��������	
		string text;                            //�������� ��� (Windows-1251)
		int code[256];							//������� ��������: T, F, I ����� �������
	};
	IN getIn(wchar_t infile[]);					//������ � ��������� ������� �����
}

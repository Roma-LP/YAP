#include"FST.h"
#include<iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	FST::FST fst2(                      //������������������� �������� ������� ab*(cb+(d+e)g)+b*fg
	  (char*)"acbegfg",					//������� ��� �������������
	  8,								//���������� ���������
	  FST::NODE(1, FST::RELATION('a', 1)),														// ��������� 0 (���������)
	  FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('c', 2)),								// ��������� 1
	  FST::NODE(1, FST::RELATION('b', 3)),														// ��������� 2
	  FST::NODE(3, FST::RELATION('b', 3), FST::RELATION('d', 4), FST::RELATION('e', 4)),		// ��������� 3
	  FST::NODE(1, FST::RELATION('g', 5)),														// ��������� 4			
	  FST::NODE(3, FST::RELATION('b', 5), FST::RELATION('f', 6), FST::RELATION('c', 2)),		// ��������� 5 
	  FST::NODE(1, FST::RELATION('g', 7)),														// ��������� 6 
	  FST::NODE());																				// ��������� 7 (��������)								
	  
	cout << "ab*(cb+(d+e)g)+b*fg" << endl;
	cout << endl << "1)";
	if (FST::execute(fst2))    //��������� ������
		cout << "\t������� " << fst2.string << " ����������" << endl;
	else cout << "\t������� " << fst2.string << " �� ����������" << endl;
	
	FST::udpdate(fst2, (char*)"abbcbdgcbbegfg");
	if (FST::execute(fst2))
		cout << "\t������� " << fst2.string << " ����������" << endl;
	else cout << "\t������� " << fst2.string << " �� ����������" << endl;

	FST::udpdate(fst2, (char*)"acbegcbegfg");
	if (FST::execute(fst2))
		cout << "\t������� " << fst2.string << " ����������" << endl;
	else cout << "\t������� " << fst2.string << " �� ����������" << endl;

	FST::udpdate(fst2, (char*)"abbcbdgcbbegbfg");
	if (FST::execute(fst2))
		cout << "\t������� " << fst2.string << " ����������" << endl;
	else cout << "\t������� " << fst2.string << " �� ����������" << endl;

	FST::udpdate(fst2, (char*)"acbegbfg");
	if (FST::execute(fst2))
		cout << "\t������� " << fst2.string << " ����������" << endl;
	else cout << "\t������� " << fst2.string << " �� ����������" << endl;

	FST::udpdate(fst2, (char*)"abbcbegcbbegbbbfg");
	if (FST::execute(fst2))
		cout << "\t������� " << fst2.string << " ����������" << endl;
	else cout << "\t������� " << fst2.string << " �� ����������" << endl;

	FST::udpdate(fst2, (char*)"abcbbdgcbbdgfg");
	if (FST::execute(fst2))
		cout << "\t������� " << fst2.string << " ����������" << endl;
	else cout << "\t������� " << fst2.string << " �� ����������" << endl;
	//-------------------------------------------------------------------------------
	cout << "\n2) ������� �������� ���������, �� �� ������������" << endl;
	FST::udpdate(fst2, (char*)"ab�eg");
	if (FST::execute(fst2))
		cout << "\t������� " << fst2.string << " ����������" << endl;
	else cout << "\t������� " << fst2.string << " �� ����������" << endl;
	//-------------------------------------------------------------------------------
	cout << "\n3) ������a, ��� ������� ������ �����������, �� �������� ��� ������� ������� �������" << endl;
	FST::udpdate(fst2, (char*)"ab�egfgbb");
	if (FST::execute(fst2))
		cout << "\t������� " << fst2.string << " ����������" << endl;
	else cout << "\t������� " << fst2.string << " �� ����������" << endl;
	//-------------------------------------------------------------------------------
	cout << "\n4) 2-� �������, ��	�������������� ������������� �������� �������o�" << endl;
	FST::udpdate(fst2, (char*)"ab�egfgqq");
	if (FST::execute(fst2))
		cout << "\t������� " << fst2.string << " ����������" << endl;
	else cout << "\t������� " << fst2.string << " �� ����������" << endl;

	FST::udpdate(fst2, (char*)"ab�egqop");
	if (FST::execute(fst2))
		cout << "\t������� " << fst2.string << " ����������" << endl;
	else cout << "\t������� " << fst2.string << " �� ����������" << endl;
	
	system("pause");
}
#include "Error.h" // ��������� ������
#include  "Parm.h" // ��������� ����������
#include  "Log.h" // ������ � ����������
#include  "In.h" // ���� ��������� �����
#include "FST.h"
#include <iostream>
#include <locale>
#include <cwchar>
int wmain(int argc, const wchar_t * argv[])
{
	setlocale(LC_ALL, "Russian");
	Log::LOG log;
	try
	{
		Parm::PARM param = Parm::getParm(argc, argv);
		Log::LOG log = Log::getlog(param.log);
		Log::WriteLine(log, L"����: ", L"��� ������\n", L"");
		Log::WriteLog(log);
		In::IN in = In::getIn(param.in);
		int k = in.text.size();
		int count = 0;				//���������� �������
		bool execute_parse = false;	//�������� �� ������
		int l_pos = 0;				//�������� ������� l
		int err_pos;				//������� ��������� ������
		Error::ERROR eRROR;
		char *l = new char[k];
		for (int i = 0; i <= k; i++)
			l[i] = '\0';

		for (int i = 0; i <= k; i++)
		{
			if (in.text[i] == '|' || in.text[i] == '\0')
				count++;
		}
		for (int i = 1; i <= count; i++)
		{
			l_pos = 0;
			for (static int j = 0; j < k; j++)
			{
				if (in.text[j] != '|' && in.text[j] != '\0')
				{
					l[l_pos] = in.text[j];
					l_pos++;
				}
				else
				{
					j++;
					err_pos = j;
					break;
				}
			}
			FST::FST fst1(                      //������������������� �������� ������� ab*(cb+(d+e)g)+b*fg
				l,								//������� ��� �������������
				8,								//���������� ���������
				FST::NODE(1, FST::RELATION('a', 1)),													// ��������� 0 (���������)
				FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('c', 2)),								// ��������� 1
				FST::NODE(1, FST::RELATION('b', 3)),													// ��������� 2
				FST::NODE(3, FST::RELATION('b', 3), FST::RELATION('d', 4), FST::RELATION('e', 4)),		// ��������� 3
				FST::NODE(1, FST::RELATION('g', 5)),													// ��������� 4			
				FST::NODE(3, FST::RELATION('b', 5), FST::RELATION('f', 6), FST::RELATION('c', 2)),		// ��������� 5 
				FST::NODE(1, FST::RELATION('g', 7)),													// ��������� 6 
				FST::NODE());																			// ��������� 7 (��������)								

			execute_parse = FST::execute(fst1);
			eRROR = Error::getErrorIn(err_pos, i, l_pos);
			if (!execute_parse)
			{
				cout << "������� " << fst1.string << " �� ����������" << endl;
				WriteKey(log, fst1.string, execute_parse);
				WriteError(log, eRROR);
			}
			else
			{
				cout << "������� " << fst1.string << " ����������" << endl;
				WriteKey(log, fst1.string, execute_parse);
			}
			for (int k = 0; k < l_pos; k++)
				l[k] = '\0';

		}
		Log::WriteParm(log, param);
		Log::WriteIn(log, in);
		Log::WriteInsideTextTo_OutFile(param, in);
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
		Log::Close(log);
	}

	system("pause");
	return 0;

};


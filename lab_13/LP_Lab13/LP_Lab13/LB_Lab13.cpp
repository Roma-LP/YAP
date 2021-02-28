#include "Error.h" // обработка ошибок
#include  "Parm.h" // обработка параметров
#include  "Log.h" // работа с протоколом
#include  "In.h" // ввод исходного Файла
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
		Log::WriteLine(log, L"Тест: ", L"без ошибок\n", L"");
		Log::WriteLog(log);
		In::IN in = In::getIn(param.in);
		int k = in.text.size();
		int count = 0;				//количесвто цепочек
		bool execute_parse = false;	//проверка на разбор
		int l_pos = 0;				//активная позиция l
		int err_pos;				//позиция возможной ошибки
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
			FST::FST fst1(                      //недетерминированный конечный автомат ab*(cb+(d+e)g)+b*fg
				l,								//цепочка для распознавания
				8,								//количесвто состояний
				FST::NODE(1, FST::RELATION('a', 1)),													// состояние 0 (начальное)
				FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('c', 2)),								// состояние 1
				FST::NODE(1, FST::RELATION('b', 3)),													// состояние 2
				FST::NODE(3, FST::RELATION('b', 3), FST::RELATION('d', 4), FST::RELATION('e', 4)),		// состояние 3
				FST::NODE(1, FST::RELATION('g', 5)),													// состояние 4			
				FST::NODE(3, FST::RELATION('b', 5), FST::RELATION('f', 6), FST::RELATION('c', 2)),		// состояние 5 
				FST::NODE(1, FST::RELATION('g', 7)),													// состояние 6 
				FST::NODE());																			// состояние 7 (конечное)								

			execute_parse = FST::execute(fst1);
			eRROR = Error::getErrorIn(err_pos, i, l_pos);
			if (!execute_parse)
			{
				cout << "Цепочка " << fst1.string << " не распознана" << endl;
				WriteKey(log, fst1.string, execute_parse);
				WriteError(log, eRROR);
			}
			else
			{
				cout << "Цепочка " << fst1.string << " распознана" << endl;
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


#pragma once

namespace Call {
	int _cdecl cdevl(int &num1, int &num2, int &num3); //Параметры помещаются в стек в обратном порядке (справа налево) 
	int _stdcall cstd(int&, int, int);                 //Параметры помещаются в стек в обратном порядке(справа налево)
	int _fastcall cfst(int, int, int);				   //Хранятся в регистрах, затем помещаются в стек 
}
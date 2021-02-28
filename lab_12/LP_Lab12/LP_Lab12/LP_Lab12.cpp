#include"FST.h"
#include<iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	FST::FST fst2(                      //недетерминированный конечный автомат ab*(cb+(d+e)g)+b*fg
	  (char*)"acbegfg",					//цепочка для распознавания
	  8,								//количесвто состояний
	  FST::NODE(1, FST::RELATION('a', 1)),														// состояние 0 (начальное)
	  FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('c', 2)),								// состояние 1
	  FST::NODE(1, FST::RELATION('b', 3)),														// состояние 2
	  FST::NODE(3, FST::RELATION('b', 3), FST::RELATION('d', 4), FST::RELATION('e', 4)),		// состояние 3
	  FST::NODE(1, FST::RELATION('g', 5)),														// состояние 4			
	  FST::NODE(3, FST::RELATION('b', 5), FST::RELATION('f', 6), FST::RELATION('c', 2)),		// состояние 5 
	  FST::NODE(1, FST::RELATION('g', 7)),														// состояние 6 
	  FST::NODE());																				// состояние 7 (конечное)								
	  
	cout << "ab*(cb+(d+e)g)+b*fg" << endl;
	cout << endl << "1)";
	if (FST::execute(fst2))    //выполнить разбор
		cout << "\tЦепочка " << fst2.string << " распознана" << endl;
	else cout << "\tЦепочка " << fst2.string << " не распознана" << endl;
	
	FST::udpdate(fst2, (char*)"abbcbdgcbbegfg");
	if (FST::execute(fst2))
		cout << "\tЦепочка " << fst2.string << " распознана" << endl;
	else cout << "\tЦепочка " << fst2.string << " не распознана" << endl;

	FST::udpdate(fst2, (char*)"acbegcbegfg");
	if (FST::execute(fst2))
		cout << "\tЦепочка " << fst2.string << " распознана" << endl;
	else cout << "\tЦепочка " << fst2.string << " не распознана" << endl;

	FST::udpdate(fst2, (char*)"abbcbdgcbbegbfg");
	if (FST::execute(fst2))
		cout << "\tЦепочка " << fst2.string << " распознана" << endl;
	else cout << "\tЦепочка " << fst2.string << " не распознана" << endl;

	FST::udpdate(fst2, (char*)"acbegbfg");
	if (FST::execute(fst2))
		cout << "\tЦепочка " << fst2.string << " распознана" << endl;
	else cout << "\tЦепочка " << fst2.string << " не распознана" << endl;

	FST::udpdate(fst2, (char*)"abbcbegcbbegbbbfg");
	if (FST::execute(fst2))
		cout << "\tЦепочка " << fst2.string << " распознана" << endl;
	else cout << "\tЦепочка " << fst2.string << " не распознана" << endl;

	FST::udpdate(fst2, (char*)"abcbbdgcbbdgfg");
	if (FST::execute(fst2))
		cout << "\tЦепочка " << fst2.string << " распознана" << endl;
	else cout << "\tЦепочка " << fst2.string << " не распознана" << endl;
	//-------------------------------------------------------------------------------
	cout << "\n2) цепочка проходит полностью, но не распознается" << endl;
	FST::udpdate(fst2, (char*)"abсeg");
	if (FST::execute(fst2))
		cout << "\tЦепочка " << fst2.string << " распознана" << endl;
	else cout << "\tЦепочка " << fst2.string << " не распознана" << endl;
	//-------------------------------------------------------------------------------
	cout << "\n3) цепочкa, при которой разбор завершается, не перебрав все символы входной цепочки" << endl;
	FST::udpdate(fst2, (char*)"abсegfgbb");
	if (FST::execute(fst2))
		cout << "\tЦепочка " << fst2.string << " распознана" << endl;
	else cout << "\tЦепочка " << fst2.string << " не распознана" << endl;
	//-------------------------------------------------------------------------------
	cout << "\n4) 2-е цепочки, не	распознающиеся разработанным конечным автоматoм" << endl;
	FST::udpdate(fst2, (char*)"abсegfgqq");
	if (FST::execute(fst2))
		cout << "\tЦепочка " << fst2.string << " распознана" << endl;
	else cout << "\tЦепочка " << fst2.string << " не распознана" << endl;

	FST::udpdate(fst2, (char*)"abсegqop");
	if (FST::execute(fst2))
		cout << "\tЦепочка " << fst2.string << " распознана" << endl;
	else cout << "\tЦепочка " << fst2.string << " не распознана" << endl;
	
	system("pause");
}
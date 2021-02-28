#include "stdafx.h"

int sum(int x, int y);
int sub(int x, int y);
int mul(int x, int y);

int main()
{
	int x=6,y=1;
	cout << "x - 6"<<endl;
	cout << "y- 1"<<endl;
	cout << "sum = " << sum(x, y)<<endl;
	cout << "sub = " << sub(x, y) << endl;
	cout << "mul = " << mul(x, y) << endl;

	system("pause");
}
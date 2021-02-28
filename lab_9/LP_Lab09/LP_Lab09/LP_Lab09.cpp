#include "Varparm.h"
#include "Call.h"
#include <iostream>
#include <conio.h>

using namespace std;
using namespace Varparm;

int main() {
		
	int l = Varparm::ivarparm(3, 4, 5, 6);
	cout << "l=" << l << endl;
	int l1 = Varparm::svarparm(2, 3, 4);
	cout << "l1=" << l << endl;
	float l2 = Varparm::fvarparm(3.1, 4.1, FLT_MAX);
	cout << "l2=" << l << endl;
	double l3 = Varparm::dvarparm(3.3, 5.1, DBL_MAX);
	cout << "l3=" << l << endl;
	
	int a = 1, b = 2, c = 3;
	int k1, k2, k3;
	k1 = Call::cdevl(a, b, c);
	cout << "k1=" << k1 << endl;
	k2 = Call::cstd(a, b, c);
	cout << "k2=" << k2 << endl;
	k3 = Call::cfst(a, b, c);
	cout << "k3=" << k3 << endl;

	
	cout << "d1=" << (1, 2, 3, 4, 5) << endl;
	cout << "d2=" << defaultparm(1, 2, 3, 4, 5, 6, 7) << endl;

	_getch();
}
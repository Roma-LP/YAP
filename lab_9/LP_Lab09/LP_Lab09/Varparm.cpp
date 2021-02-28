#include"Varparm.h"
#include <iostream>

using namespace std;

int Varparm::ivarparm(int size, ...) {
	int *pnum = &size;
	int result = 1;
	for (int i = 1; i <= size; i++) {
		result *= *(pnum + i);
	}
	return result;
}

int Varparm::svarparm(short size, ...) {
	int *pnum = (int*)&size;
	int result = 1;
	for (int i = 1; i <= size; i++) {
		result *= *(pnum + i);
	}
	return result;
}

double Varparm::fvarparm(float num, ...) {
	double *pnum = (double*)(&num + 1);
	double result = num;
	for (int i = 0; *(pnum + i) != FLT_MAX; i++) {
		result += *(pnum + i);
	}
	return result;
}

double Varparm::dvarparm(double num, ...) {
	double *pnum = &num;
	double result = 0;
	for (int i = 0; *(pnum + i) != DBL_MAX; i++) {
		result += *(pnum + i);
	}
	return result;
}

int defaultparm(int x1, int x2, int x3, int x4, int x5, int x6, int x7)
{	
	return (x1+x2+x3+x4+x5+x6+x7)/7;
}
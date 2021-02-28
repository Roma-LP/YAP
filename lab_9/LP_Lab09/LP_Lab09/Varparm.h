#pragma once
namespace Varparm {
	int ivarparm(int, ...);
	int svarparm(short, ...);
	double fvarparm(float, ...);
	double dvarparm(double, ...);
}
int defaultparm(int x1, int x2, int x3, int x4, int x5, int x6=1 , int x7=2 );


#include <iostream>
#include <conio.h>
#pragma comment (lib, "C:\\БГТУ\\ЯП\\lab_17\\lab17\\Project1\\Debug\\LP_asm01a.lib")
extern "C"
{
	long __stdcall  getmin(void* pArray, long countOfElements);
	long __stdcall  getmax(void* pArray, long countOfElements);
}
//getmax PROTO, pArray: PTR sdword,
//countOfElements : sdword
int main()
{
	long mass[10] = { 1,2,3,4,5,6,7,-88,9,10 };
	long min = getmin(mass, 10);
	long max = getmax(mass, 10);
	printf(" getmax (%d) - getmin (%d) = %d",max,min, max-min);
	_getch();
}



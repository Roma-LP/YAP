#include "stdafx.h"

extern "C"
{
	long __stdcall getmax(void* pArray, long countOfElements)
	{
		long max = 0 - 2147483648;
		for (int i = 0; i < countOfElements; i++)
		{
			if (*((long*)pArray + i) > max) max = *((long*)pArray + i);
		}
		return max;
	}
	long __stdcall getmin(void* pArray, long countOfElements)
	{
		long min = 2147483647;
		for (int i = 0; i < countOfElements; i++)
		{
			if (*((long*)pArray + i) < min) min = *((long*)pArray + i);
		}
		return min;
	}
}
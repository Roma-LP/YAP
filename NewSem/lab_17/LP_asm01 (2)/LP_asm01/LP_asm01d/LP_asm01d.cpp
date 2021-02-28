#include "pch.h"
#include "framework.h"

extern "C"
{
    int getmin(int* a, int l)
    {
        int min = *a;
        for (int i = 0; i < l; i++)
            if (a[i] < min)
                min = a[i];
        return min;
    }

    int getmax(int* a, int l)
    {
        int max = *a;
        for (int i = 0; i < l; i++)
            if (a[i] > max)
                max = a[i];
        return max;
    }
}

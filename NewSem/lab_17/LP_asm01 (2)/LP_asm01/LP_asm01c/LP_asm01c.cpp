#include <iostream>

extern "C"
{
    int __stdcall getmin(int*, int);
    int __stdcall getmax(int*, int);
}

int main()
{
    int arr[10] = { -1, 32, 56, 15, 24, -13, 2, 9, 45, 0 };
    int min = getmin(arr, sizeof(arr) / sizeof(int));
    int max = getmax(arr, sizeof(arr) / sizeof(int));
    std::cout << "getmax - getmin = " << max - min;
    return 0;
}
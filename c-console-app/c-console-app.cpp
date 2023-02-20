// c-console-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int sumValue = 0;

int sum(int *sumPtr, int sumLen)
{
    if (sumLen == 0) { return sumValue; }
    sumValue += *sumPtr;
    sumPtr++;
    sum(sumPtr, sumLen-1);
}



int main()
{
    int sumArray[] = { 7, 5, 4, 20 };
    int sumLen = 4;
    int* sumPtr = sumArray;

    cout << sum(sumPtr, sumLen) << '\n';

    return 0;
}

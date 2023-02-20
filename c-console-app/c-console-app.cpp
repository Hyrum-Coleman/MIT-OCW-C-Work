// c-console-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void doubleNumber(int *numPtr)
{
    *numPtr = *numPtr * 2;
}

int main()
{
    int num = 35;
    doubleNumber(&num);
    cout << num;
    return 0;
}


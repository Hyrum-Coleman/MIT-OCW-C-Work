// c-console-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

const int ARRAY_LEN = 10;

int main()
{
    int arr[ARRAY_LEN] = { 10 };

    int *xPtr = arr, *yPtr = arr + ARRAY_LEN - 1;
    cout << *xPtr << ' ' << *yPtr;
    return 0;
}


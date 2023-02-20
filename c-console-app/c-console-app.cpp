// c-console-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int sum(int sumArray[], int sumLen)
{
    int sum = 0;
    for (int i = 0; i < sumLen; i++) 
    {
        sum += sumArray[i];
    }
    return sum;
}



int main()
{
    int sumArray[] = { 1, 2, 4 };
    int sumLen = 3;
    cout << sum(sumArray, sumLen) << '\n';

    return 0;
}

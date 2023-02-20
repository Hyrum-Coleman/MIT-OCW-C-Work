// c-console-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printArray(int arrayToPrint[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (i + 1 == len)
        {
            cout << arrayToPrint[i];
            continue;
        }
        cout << arrayToPrint[i] << ", ";
    }
    
}


int main()
{
    int arrayToPrint[] = { 1, 45, 2, 5, 3, 24, 267, 73, 69 };
    int len = *(&arrayToPrint + 1) - arrayToPrint;

    printArray(arrayToPrint, len);

    return 0;
}

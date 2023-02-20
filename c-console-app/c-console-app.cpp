// c-console-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int difference(const int x, const int y) {
    return abs(x - y);
}

int main()
{
    cout << difference(24, 1238);
    return 0;
}


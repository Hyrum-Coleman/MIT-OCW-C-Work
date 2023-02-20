// c-console-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int sum(const int x, const int y, const int z) {
    return x + y + z;
}

int main()
{
    cout << sum(1, 2, 3);
    return 0;
}


// c-console-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int sum(int x, int y, int z = 1, int g = 4) { return x + y + z + g; }



int main()
{
    cout << sum(4, 2, 3) << '\n';

    return 0;
}


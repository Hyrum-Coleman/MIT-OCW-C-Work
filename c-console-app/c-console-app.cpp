// c-console-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int sum(int x, int y) { return x + y; }
int sum(int x, int y, int z) { return x + y + z; }
int sum(int x, int y, int z, int g) { return x + y + z + g; }

double sum(double x, double y){ return x + y; }

int main()
{
    int firstInt = 25;
    int secondInt = 42;

    double firstDouble = 2.25;
    double secondDouble = 4.66;

    cout << sum(firstInt, secondInt) << '\n';
    cout << sum(firstDouble, secondDouble) << '\n';

    return 0;
}


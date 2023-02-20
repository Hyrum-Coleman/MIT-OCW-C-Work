// c-console-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "computePi.h"
using namespace std;




int main()
{
    unsigned long numThrows;
    cin >> numThrows;

    double piApprox = computePi(numThrows);

    cout << piApprox;

    return 0;
}

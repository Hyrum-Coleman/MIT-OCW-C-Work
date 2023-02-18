// c-console-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void statGen()
{
    int N;
    int sum = 0;
    int max = -1000000;
    int min = 10000000;
    int range = 0;
    int mean = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int userNum;
        cin >> userNum;


        sum += userNum;

        if (userNum < min)
        {
            min = userNum;
        }
        if (userNum > max)
        {
            max = userNum;
        }
        
    }
    range = max - min;
    mean = sum / N;

    cout << "Mean: " << mean << "\n";
    cout << "Max: " << max << "\n";
    cout << "Min: " << min << "\n";
    cout << "Range: " << range << "\n";
}


int main()
{
    statGen();
    return 0;
}


#include <iostream>
#define LENGTH 3
#define WIDTH 3
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
    cout << "\n";
}

void reverse(int *arrPtr, int len)
{
    int i = (len - 1);
    int* lastValPtr = (arrPtr + i);
    for (; i >= (len / 2); i--)
    {
        int tempVal = *arrPtr;
        *arrPtr = *lastValPtr;
        *lastValPtr = tempVal;

        arrPtr++;
        lastValPtr--;
    }
}

void transpose(const int input[WIDTH][LENGTH], int output[LENGTH][WIDTH])
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            output[j][i] = input[i][j];
        }
    }
}


int main()
{
    int testArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int len = *(&testArray + 1) - testArray;

    reverse(testArray, len);
    reverse(testArray, len);
    reverse(testArray, len);
    printArray(testArray, len);

    const int input[WIDTH][LENGTH] = { {2, 0, 1} , {4, 5, 9 } , { 6, 8, 3 } };
    int output[LENGTH][WIDTH];

    transpose(input, output);

    for (auto & i : output)
    {
        cout << '\n';
        for (int j : i)
        {
            cout << j << ", ";
        }
    }
    cout << '\b' << '\b';
    cout << '\n';

    return 0;
}

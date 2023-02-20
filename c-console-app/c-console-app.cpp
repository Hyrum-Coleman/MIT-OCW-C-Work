#include <iostream>
#define LENGTH 2
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
    int testArray[] = { 27, 54, 245, 77, 123, 36};

    int len = *(&testArray + 1) - testArray;

    reverse(testArray, len);
    printArray(testArray, len);

    const int input[WIDTH][LENGTH] = { {2, 0} , {4, 5 } , { 6, 8 } };
    int output[LENGTH][WIDTH];

    transpose(input, output);

    for (int i = 0; i < LENGTH; i++)
    {
        cout << '\n';
        for (int j = 0; j < WIDTH; j++)
        {
            cout << output[i][j] << ", ";
        }
    }
    

    return 0;
}

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

void reverse(int *arrPtr, const int len)
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


int main()
{
    int testArray[] = { 27, 54, 245, 77, 123, 36};

    const int len = *(&testArray + 1) - testArray;

    reverse(testArray, len);
    printArray(testArray, len);

    return 0;
}

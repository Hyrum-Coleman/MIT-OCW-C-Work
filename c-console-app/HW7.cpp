#include <iostream>

using namespace std;

int returnStringLength(char const* ptr) // 7.1
{
    int len = 0;
    while(*(ptr + len) != '\0')
    {
        ++len;
    }
    return len;
}

void swapByReference(int &x, int &y) // 7.2
{
    int tempVar = x;
    x = y;
    y = tempVar;
}

void swapByPointer(int * const x, int * const y) // 7.3
{
    int tempVar = *x;
    *x = *y;
    *y = tempVar;
}

void swapPointers(int **ptr1, int** ptr2) // 7.4
{
    int* temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int findLength(char const* ptr)
{
    char const* hold = ptr;
    while (*hold++);
    return hold - ptr;
}

int runHW1_7()
{
    char const *ptr = "We ball!";
    int len = returnStringLength(ptr);
    cout << len << "\n";

    // 7.1 done

    int x = 2;
    int y = 3;

    swapByReference(x, y);
    cout << x << ", " << y << '\n';

    // 7.2 done

    swapByPointer(&x, &y);
    cout << x << ", " << y << '\n';

    // 7.3 done

    int x1 = 5, y1 = 6;
    int *ptr1 = &x1, *ptr2 = &y1;
    swapPointers(&ptr1, &ptr2);
    cout << *ptr1 << ", " << *ptr2 << '\n';

    // 7.4 done

    char const *oddOrEven = "Never odd or even";
    char const *NthCharPtr = oddOrEven + 5;
    NthCharPtr -= 2;
    cout << *NthCharPtr << '\n';
    char const **pointerPtr = &NthCharPtr;
    cout << *pointerPtr << '\n';
    cout << **pointerPtr << '\n';
    NthCharPtr++;
    cout << (NthCharPtr - oddOrEven) << '\n';

    // 7.5 done
    return 0;
}
#include <iostream>
#include "HW4_min.h"
#define MIN_MACRO(val1, val2) ((val1 < val2) ? val1 : val2 )

using namespace std;

int main()
{
    int intVal1;
    int intVal2;
    int intMin;
    cout << "Enter 2 integers to compare!";
    cin >> intVal1 >> intVal2;

    double doubleVal1;
    double doubleVal2;
    double doubleMin;
    cout << "Enter 2 doubles to compare!";
    cin >> doubleVal1 >> doubleVal2;

    char charVal1;
    char charVal2;
    char charMin;

    cout << "Enter 2 characters to compare!";
    cin >> charVal1 >> charVal2;

    float floatVal1;
    float floatVal2;
    float floatMin;

    cout << "Enter 2 floats to compare";
    cin >> floatVal1 >> floatVal2;

    intMin = min_template(intVal1, intVal2);
    doubleMin = min_template(doubleVal1, doubleVal2);
    charMin = min_template(charVal1, charVal2);
    floatMin = MIN_MACRO(floatVal1, floatVal2);

    cout << endl;

    cout << "The minimum int is... " << intMin << endl;
    cout << "The minimum double is... " << doubleMin << endl;
    cout << "The minimum char is... " << charMin << endl;
    cout << "The minimum float is... " << floatMin << endl;

    return 0;
}
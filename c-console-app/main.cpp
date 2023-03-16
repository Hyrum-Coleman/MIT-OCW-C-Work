#include <iostream>
#include "HW4_min.h"
#include "geometry.h"
#define MIN_MACRO(val1, val2) ((val1 < val2) ? val1 : val2 )

using namespace std;

int main()
{
//    int intVal1;
//    int intVal2;
//    int intMin;
//    cout << "Enter 2 integers to compare!";
//    cin >> intVal1 >> intVal2;
//
//    double doubleVal1;
//    double doubleVal2;
//    double doubleMin;
//    cout << "Enter 2 doubles to compare!";
//    cin >> doubleVal1 >> doubleVal2;
//
//    char charVal1;
//    char charVal2;
//    char charMin;
//
//    cout << "Enter 2 characters to compare!";
//    cin >> charVal1 >> charVal2;
//
//    float floatVal1;
//    float floatVal2;
//    float floatMin;
//
//    cout << "Enter 2 floats to compare";
//    cin >> floatVal1 >> floatVal2;
//
//    intMin = MIN_MACRO(intVal1, intVal2);
//    doubleMin = min_template(doubleVal1, doubleVal2);
//    charMin = MIN_MACRO(charVal1, charVal2);
//    floatMin = min_template(floatVal1, floatVal2);
//
//    cout << endl;
//
//    cout << "The minimum int is... " << intMin << endl;
//    cout << "The minimum double is... " << doubleMin << endl;
//    cout << "The minimum char is... " << charMin << endl;
//    cout << "The minimum float is... " << floatMin << endl;
//
//    cout << endl << "BIG BREAK" << endl;
//
//    auto bLeftPoint = Point(3, 5);
//    auto tRightPoint = Point (7, 9);
//    auto rectPtr = new Rectangle(bLeftPoint, tRightPoint);
//
//    auto triPtr = dynamic_cast<Triangle*>(rectPtr);
//
//    cout << triPtr; // check it out, this is a null pointer!!
//    delete triPtr; // ask greg if I actually need to delete triPtr (I assume so because nobody is complaining)
//    delete rectPtr;
//
//    cout << endl << "BIG BREAK" << endl;

    Stack<int> myStack;



    cout << "The stack is empty: " << myStack.isEmpty() << endl;

    myStack.push(34);
    myStack.push(3);
    myStack.pop();
    int topVal = myStack.top();

    cout << "The stack is empty: " << myStack.isEmpty() << endl;
    cout << "The value at the top is: " << topVal << endl;

    myStack.pop();
    cout << "The Stack is empty: " << myStack.isEmpty() << endl;


    return 0;
}
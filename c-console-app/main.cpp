#include <iostream>
#include "HW4_min.h"
#include "geometry.h"
#include <vector>
#define MIN_MACRO(val1, val2) (((val1) < (val2)) ? (val1) : (val2) )

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

    Stack<int> my_stack;
    Stack<int> my_stack2;
    my_stack.push(1);
    my_stack.push(2);

    my_stack2.push(3);
    my_stack2.push(4);

Stack<int> added_stack = my_stack + my_stack2;

added_stack.push(26);
    added_stack.push(18);
    added_stack.push(5);

    added_stack.print_stack();



    return 0;
}
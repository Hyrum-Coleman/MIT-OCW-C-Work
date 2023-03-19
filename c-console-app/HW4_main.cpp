#include <iostream>

#include "geometry.h"
#include "HW4_min.h"
#define MIN_MACRO(val1, val2) (((val1) < (val2)) ? (val1) : (val2) )

using namespace std;

int main_old()
{
    int int_val1;
    int int_val2;
    cout << "Enter 2 integers to compare!";
    cin >> int_val1 >> int_val2;

    double double_val1;
    double double_val2;
    cout << "Enter 2 doubles to compare!";
    cin >> double_val1 >> double_val2;

    char char_val1;
    char char_val2;
    cout << "Enter 2 characters to compare!";
    cin >> char_val1 >> char_val2;

    float float_val1;
    float float_val2;

    cout << "Enter 2 floats to compare";
    cin >> float_val1 >> float_val2;

    const int int_min = MIN_MACRO(int_val1, int_val2);
    const double double_min = min_template(double_val1, double_val2);
    const char char_min = MIN_MACRO(char_val1, char_val2);
    const float float_min = min_template(float_val1, float_val2);

    cout << endl;

    cout << "The minimum int is... " << int_min << endl;
    cout << "The minimum double is... " << double_min << endl;
    cout << "The minimum char is... " << char_min << endl;
    cout << "The minimum float is... " << float_min << endl;

    cout << endl << "BIG BREAK" << endl;

    auto b_left_point = Point(3, 5);
    auto t_right_point = Point(7, 9);
    const auto rect_ptr = new Rectangle(b_left_point, t_right_point);

    const auto tri_ptr = dynamic_cast<Triangle*>(rect_ptr);

    cout << tri_ptr; // check it out, this is a null pointer!!
    delete tri_ptr; // ask greg if I actually need to delete triPtr (I assume so because nobody is complaining)
    delete rect_ptr;

    cout << endl << "BIG BREAK" << endl;

    Stack<int> my_stack;
    Stack<int> my_stack2;
    my_stack.push(1);
    my_stack.push(2);

    my_stack2.push(3);
    my_stack2.push(4);

    auto added_stack = my_stack + my_stack2;

    added_stack.push(26);
    added_stack.push(18);
    added_stack.push(5);

    added_stack.print_stack();

    return 0;
}
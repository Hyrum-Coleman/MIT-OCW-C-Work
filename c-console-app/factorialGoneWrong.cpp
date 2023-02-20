#include <iostream>
using namespace std;

void computeFac(int number, int accumulator)
{

}

void factorialCode()
{
	short number;
	cout << "Enter a number: ";
	cin >> number;

	cout << "The factorial of " << number << " is ";
	if (number < 0)
	{
		long double accumulator = -1;
		for (; number < 0; accumulator *= number++);
		cout << accumulator << ".\n";
	}
	else
	{
		long double accumulator = 1;
		for (; number > 0; accumulator *= number--);
		cout << accumulator << ".\n";

	}

}
#include <iostream>
using namespace std;

void factorialCode()
{
	short number;
	cout << "Enter a number: ";
	cin >> number;

	cout << "The factorial of " << number << " is ";
	if (number < 0)
	{
		cout << "Apparently we don't allow negative values for our factorials";
	}
	else
	{
		long double accumulator = 1;
		for (; number > 0; accumulator *= number--);
		cout << accumulator << ".\n";
	}

}
// Stack2Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Calculator.h"
#include "StackOnDynamicArray.h"
#include "StackOnOneWayList.h"
#include <stack>

using namespace std;

int main()
{
	string expr;
	char select{};
	Calculator* calc = new Calculator();

	while (select != '0')
	{
		cout << "\nEnter expression: ";
		cin >> expr;
		cout << "Select environment (1 --> OneWayList, 2 --> DynamicArray, 3 --> std::stack or 0 --> exit): ";
		cin >> select;
		if (select == '1')
		{
			calc->calulateExpression<StackOnOneWayList>(expr);
		}
		else if (select == '2') {
			calc->calulateExpression<StackOnDynamicArray>(expr);
		}
		else if (select == '3') {
			//calc->calulateExpressionByUsingSTLStack(expr);
			calc->calulateExpression<stack<char>>(expr);
		}
		else if (select == '0') {
			break;
		}
		else {
			cout << "Error while selecting method \n";
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

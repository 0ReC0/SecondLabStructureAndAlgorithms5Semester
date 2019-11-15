#include "Calculator.h"
#include "Stack.h"
#include <string>
#include <iostream>

using namespace std;

Calculator::Calculator() {}

Calculator::~Calculator() {}

int Calculator::calulateExpression(string expr) {

	Stack* stack = new Stack();
	try
	{
		for (int i = 0; i < expr.length(); i++)
		{
			switch (expr[i])
			{
			case '!':

				if (i + 1 < expr.length() && expr[i + 1] == 0 || expr[i + 1] == 1) {

				}
				else {
					throw - 2;
				}
				break;
			case '&':
				break;
			case '|':
				break;
			case '0':
				break;
			case '1':
				break;
			default:
				throw - 1;
				break;
			}

		}

	}
	catch (int code)
	{
		cerr << "Wrong expression" << endl;
	}

	return -1;
}
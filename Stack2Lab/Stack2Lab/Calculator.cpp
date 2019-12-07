#include "Calculator.h"
#include <string>
#include <iostream>
#include "StackOnOneWayList.h"
#include <stack>

using namespace std;


Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

int Calculator::calulateExpressionByUsingSTLStack(string expr)
{
	stack<char>* st = new stack<char>();
	char result{};
	try
	{
		for (int i = expr.length() - 1; i >= 0; i--)
		{

			st->push(expr.at(i));

		}

		while (st->size() > 0) {

			if (st->size() == 1) {
				if (st->top() == '0' || st->top() == '1') {
					result = st->top();

					st->pop();
					break;
				}
				else {
					throw - 6;
				}
			}

			switch (st->top())
			{
			case '!':

				st->pop();

				if (st->top() == '1') {
					st->pop();

					st->push('0');
				}
				else if (st->top() == '0') {
					st->pop();

					st->push('1');
				}
				else {
					throw - 2;
				}
				break;
			case '0':
				st->pop();

				if (this->calculateZeroAND<stack<char>>(st) == 1) {
					continue;
				}

				if (this->calculateZeroOR<stack<char>>(st) == 1) {
					continue;
				}

				break;
			case '1':
				st->pop();

				if (this->calculateOneAND<stack<char>>(st) == 1) {
					continue;
				}

				if (this->calculateOneOR<stack<char>>(st) == 1) {
					continue;
				}

				break;
			default:
				throw - 1;
				break;
			}

		}
		cout << "Result by using std::stack: " << result << endl;

		return 0;

	}
	catch (int code)
	{
		cerr << "Wrong expression " << code << endl;
	}

	return -1;
}

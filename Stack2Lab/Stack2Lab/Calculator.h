#pragma once
#include <string>
#include "StackOnOneWayList.h"
#include <iostream>
#include <stack>
#include <string>
#include "Stack.h"

using namespace std;


class Calculator
{
public:
	Calculator();

	~Calculator();

	template<typename TemplateStack>
	int calulateExpression(string expr)
	{
		TemplateStack* stack = new TemplateStack();
		char result{};
		try
		{
			for (int i = expr.length() - 1; i >= 0; i--)
			{

				stack->push(expr.at(i));

			}

			while (stack->arrSize > 0) {

				if (stack->arrSize == 1) {
					if (stack->top() == '0' || stack->top() == '1') {
						result = stack->top();

						stack->pop();
						break;
					}
					else {
						throw - 6;
					}
				}

				switch (stack->top())
				{
				case '!':

					stack->pop();

					if (stack->top() == '1') {
						stack->pop();

						stack->push('0');
					}
					else if (stack->top() == '0') {
						stack->pop();

						stack->push('1');
					}
					else {
						throw - 2;
					}
					break;
				case '0':
					stack->pop();

					if (this->calculateZeroAND<TemplateStack>(stack) == 1) {
						continue;
					}

					if (this->calculateZeroOR<TemplateStack>(stack) == 1) {
						continue;
					}
					break;
				case '1':
					stack->pop();

					if (this->calculateOneAND<TemplateStack>(stack) == 1) {
						continue;
					}

					if (this->calculateOneOR<TemplateStack>(stack) == 1) {
						continue;
					}
					break;
				default:
					throw - 1;
					break;
				}

			}
			cout << "Result by using " << typeid(TemplateStack).name() << ": " << result << endl;

			return 0;

		}
		catch (int code)
		{
			cerr << "Wrong expression " << code << endl;
		}

		return -1;
	}

	int calulateExpressionByUsingSTLStack(string expr);

private:
	template<typename TemplateStack>
	int calculateOneAND(TemplateStack* st) {
		if (st->top() == '&') {
			st->pop();

			if (st->top() == '0') {
				st->pop();

				st->push('0');
			}
			else if (st->top() == '1') {
				st->pop();

				st->push('1');
			}
			else if (st->top() == '!') {
				st->pop();

				if (st->top() == '0') {
					st->pop();

					st->push('1');
				}
				else if (st->top() == '1') {
					st->pop();

					st->push('0');
				}
				else {
					throw - 17;
				}
			}
			else {
				throw - 9;
			}
			// return check code | 1 --> good
			return 1;
		}
	}

	template<typename TemplateStack>
	int calculateZeroAND(TemplateStack* st) {
		if (st->top() == '&') {
			st->pop();

			if (st->top() == '0' || st->top() == '1') {
				st->pop();

				st->push('0');
			}
			else if (st->top() == '!') {
				st->pop();

				if (st->top() == '0' || st->top() == '1') {
					st->pop();

					st->push('0');
				}
				else {
					throw - 15;
				}
			}
			else {
				throw - 12;
			}
			// return good code
			return 1;
		}
	}

	template<typename TemplateStack>
	int calculateZeroOR(TemplateStack* st) {
		if (st->top() == '|') {
			st->pop();

			if (st->top() == '0') {
				st->pop();

				if (st->top() == '|') {
					st->push('0');
				}
				else if (st->top() == '&') {

					if (this->calculateZeroAND<TemplateStack>(st) == 1) {
						return 1;
					}
				}
				else {
					throw - 22;
				}

			}
			else if (st->top() == '1') {
				st->pop();

				if (st->top() == '|') {
					st->push('1');
				}
				else if (st->top() == '&') {

					if (this->calculateOneAND<TemplateStack>(st) == 1) {
						return 1;
					}
				}
				else {
					throw - 22;
				}
			}
			else if (st->top() == '!') {
				st->pop();

				if (st->top() == '0') {
					st->pop();

					st->push('1');
				}
				else if (st->top() == '1') {
					st->pop();

					st->push('0');
				}
				else {
					throw - 16;
				}
			}
			else {
				throw - 11;
			}
		}
		else {
			throw - 5;
		}
		// return good code
		return 1;
	}

	template<typename TemplateStack>
	int calculateOneOR(TemplateStack* st) {
		if (st->top() == '|') {
			st->pop();

			if (st->top() == '0' || st->top() == '1') {
				st->pop();

				if (st->top() == '|') {
					st->push('1');
				}
				else if (st->top() == '&') {

					if (this->calculateOneAND<TemplateStack>(st) == 1) {
						return 1;
					}
				}
				else {
					throw - 22;
				}
			}
			else if (st->top() == '!') {
				st->pop();

				if (st->top() == '0' || st->top() == '1') {
					st->pop();

					st->push('1');
				}
				else {
					throw - 18;
				}
			}
			else {
				throw - 8;
			}
		}
		else {
			throw - 7;
		}
		// return good code;
		return 1;
	}


};


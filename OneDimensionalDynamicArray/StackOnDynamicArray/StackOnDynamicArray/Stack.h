#pragma once
class Stack
{
public:
	Stack();

	~Stack();

	Stack(int arrSize);

	void push(char newItem);

	void pop();

	char top();

	char* arr;

	int arrSize;

};


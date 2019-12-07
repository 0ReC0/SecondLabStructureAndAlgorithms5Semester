#pragma once
#include "Stack.h"

class StackOnDynamicArray : public Stack
{
public:
	StackOnDynamicArray();

	~StackOnDynamicArray();

	StackOnDynamicArray(int arrSize);

	virtual void push(char newItem) override;

	virtual void pop() override;

	virtual bool isEmpty() override;

	virtual char top() override;

private:
	char* arr;

};
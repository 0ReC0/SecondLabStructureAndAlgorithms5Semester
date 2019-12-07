#pragma once
#include "ListNode.h"
#include "Stack.h"

class StackOnOneWayList : public Stack
{
public:
	StackOnOneWayList();

	~StackOnOneWayList();

	void push(char newItem) override;

	void pop() override;

	bool isEmpty() override;

	char top() override;

private:
	ListNode* head;

};


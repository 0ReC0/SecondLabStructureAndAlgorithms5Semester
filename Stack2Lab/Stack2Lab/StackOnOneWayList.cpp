#include "StackOnOneWayList.h"

StackOnOneWayList::StackOnOneWayList() {
	this->head = nullptr;
	this->arrSize = 0;
}
StackOnOneWayList::~StackOnOneWayList() {
	while (this->arrSize > 0)
	{
		pop();
	}
}
void StackOnOneWayList::push(char newItem)
{
	if (!this->head || !(this->arrSize > 0)) {

		this->arrSize++;

		this->head = new ListNode;
		this->head->data = newItem;

		return;
	}

	ListNode* iterator = this->head;
	while (iterator->next)
	{
		iterator = iterator->next;
	}
	ListNode* newNode = new ListNode;
	newNode->data = newItem;

	iterator->next = newNode;

	this->arrSize++;
}
void StackOnOneWayList::pop()
{
	if (!this->head || !(this->arrSize > 0))
		return;

	ListNode* iterator = this->head;
	ListNode* prevNode;

	while (iterator->next != nullptr)
	{

		if (!(iterator->next->next)) {
			delete iterator->next;
			iterator->next = nullptr;
		}
		else {
			iterator = iterator->next;
		}
	}

	this->arrSize--;
}
bool StackOnOneWayList::isEmpty()
{
	if (this->arrSize <= 0) {
		return true;
	}
	else {
		return false;
	}
}
char StackOnOneWayList::top()
{
	if (!this->head || !(this->arrSize > 0))
		return '-1';

	ListNode* iterator = this->head;
	while (iterator->next)
	{
		iterator = iterator->next;
	}

	return iterator->data;
}
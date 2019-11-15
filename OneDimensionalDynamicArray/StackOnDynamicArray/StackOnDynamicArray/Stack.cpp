#include "Stack.h"

Stack::Stack() {
	this->arr = new char[1]{ 0 };
	this->arrSize = 1;
}
Stack::Stack(int arrSize) {
	this->arr = new char[arrSize] {0};
	this->arrSize = arrSize;
}
void Stack::push(char newItem)
{
	if (!this->arr || !(this->arrSize > 0))
		return;

	char* oldArray = this->arr;

	this->arr = new char[this->arrSize + 1];

	for (int i = 0; i < this->arrSize; i++) {
		this->arr[i] = oldArray[i];
	}
	delete[] oldArray;

	this->arrSize++;

	this->arr[this->arrSize] = newItem;
}
void Stack::pop()
{
	if (!this->arr || !(this->arrSize > 0))
		return;

	char* oldArray = this->arr;

	this->arr = new char[this->arrSize - 1];

	for (int i = 0; i < this->arrSize - 1; i++) {
		this->arr[i] = oldArray[i];
	}
	delete[] oldArray;

	this->arrSize--;
}
char Stack::top()
{
	if (!this->arr || !(this->arrSize > 0))
		return;

	return this->arr[this->arrSize - 1];
}
Stack::~Stack() {}
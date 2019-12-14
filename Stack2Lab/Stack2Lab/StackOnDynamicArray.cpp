#include "StackOnDynamicArray.h"

StackOnDynamicArray::StackOnDynamicArray() {
	this->arr = nullptr;
	this->arrSize = 0;
}
StackOnDynamicArray::StackOnDynamicArray(int arrSize) {
	this->arr = new char[arrSize];
	this->arrSize = arrSize;
}
void StackOnDynamicArray::push(char newItem)
{
	if (!this->arr || !(this->arrSize > 0)) {

		this->arrSize++;

		this->arr = new char[this->arrSize];
		this->arr[this->arrSize - 1] = newItem;

		return;
	}

	char* oldArray = this->arr;

	this->arr = new char[this->arrSize + 1];


	for (int i = 0; i < this->arrSize; i++) {
		this->arr[i] = oldArray[i];
	}
	delete[] oldArray;

	this->arrSize++;

	this->arr[this->arrSize - 1] = newItem;
}
void StackOnDynamicArray::pop()
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
bool StackOnDynamicArray::isEmpty()
{
	if (this->arrSize <= 0) {
		return true;
	}
	else {
		return false;
	}
}
char StackOnDynamicArray::top()
{
	if (!this->arr || !(this->arrSize > 0))
		return '-1';

	return this->arr[this->arrSize - 1];
}
int StackOnDynamicArray::size()
{
	return arrSize;
}
StackOnDynamicArray::~StackOnDynamicArray() {}
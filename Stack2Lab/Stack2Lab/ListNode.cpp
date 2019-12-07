#include "ListNode.h"

ListNode::ListNode() {
	this->next = nullptr;
	this->data = '\n';
}
ListNode::ListNode(char data, ListNode* next) {
	this->next = next;
	this->data = data;
}

#include "MyQueue.h"

void MyQueue::push(Node* newValue)
{
	NodeQueue* top = new NodeQueue(newValue);
	if (!head)
	{
		head = top;
		return;
	}
	NodeQueue* current = head;
	while (current->next && current->value->frequency < newValue->frequency)
		current = current->next;
	if (!current->next)
		current->next = top;
	else
	{
		NodeQueue* tmp = current->next;
		current->next = top;
		top->next = tmp;
	}
}

Node* MyQueue::pop()
{
	NodeQueue* tmp = head;
	head = head->next;
	return tmp->value;
}

bool MyQueue::checkSize()
{
	if (head && head->next)
		return true;
	return false;
}

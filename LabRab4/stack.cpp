#include"stack.h"
#include<new>

void stack::push(float nmb)
{
	stack * node = new stack;
	node->nmb = nmb;
	node->next = next;
	next = node;
}

float stack::pop()
{
	float tmp = next->nmb;
	stack * node = next;
	next = next->next;
	delete node;
	return tmp;
}

bool stack::empty()
{
	return (next == nullptr);
}
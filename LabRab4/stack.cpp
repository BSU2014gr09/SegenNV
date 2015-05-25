#include<iostream>
#include"stack.h"
#include<new>

void stack::push(float nmb)
{
	node * tmpNode = new(std::nothrow) node;
	if (!tmpNode)
	{
		std::cout << "no memory!\n";
	}
	else 
	{
		tmpNode->nmb = nmb;
		tmpNode->next = top;
		top = tmpNode;
	}
}

float stack::pop()
{
	float tmp = top->nmb;
	node * tmpNode = top;
	top = top->next;
	delete tmpNode;
	return tmp;
}

bool stack::isEmpty()
{
	return (top == nullptr);
}
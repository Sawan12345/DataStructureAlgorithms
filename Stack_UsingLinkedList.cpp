#include "stdafx.h"
#include <iostream>
#include <array>



using namespace std;

class node{
private:
	int value;
	node* pNext;
public:
	node() :pNext(NULL){}
	node(int val) : value(val), pNext(NULL){}
	node(int val, node* elem) :value(val), pNext(elem){}
	int getValue()
	{
		return value; 
	}
	node* getNext()
	{
		return pNext;
	}
	void setNext(node* elem)
	{
		pNext = elem;
		
	}

};

class Stack
{
private:
	node* head;
public:
	Stack() : head(NULL){};
	~Stack();
	bool push(int value);
	int pop();
	void printStack();
};

bool Stack::push(int value)
{
	node* newNode = new node(value);
	newNode->setNext(head);
	head = newNode;
	return true;
}

int Stack::pop()
{
	int val;
	if (head)
	{
		val = head->getValue();
		node *temp = head->getNext();
		delete head;
		head = temp;
	}
	else
	{
		cout << "Stack is empty" << endl;
		val = -1;
	}

	return val;
}

Stack::~Stack()
{
	cout << "Deleting stack:" << endl;
	while (head)
	{
		node* temp = head;
		cout << temp->getValue() << " ";
		head = head->getNext();
		delete temp;
	}

}

void Stack::printStack()
{
	node *curr = head;
	while (curr)
	{
		cout <<  curr->getValue() << endl;
		curr = curr->getNext();
	}

}

int main()
{
	Stack stack;
		stack.push(2);
		stack.push(3);
		stack.push(4);
		stack.push(5);
		stack.printStack();
		stack.pop();
		stack.pop();
		stack.pop();
		stack.push(3);
		stack.printStack();
	
}
// Add/Delete node in Linked list 
// printList


#include "stdafx.h"
#include <iostream>

using namespace std;

class Node{
private:	
	int _value;
	Node *_pNext;

public:
	Node():_pNext(NULL){}
	Node(int val) :_value(val),_pNext(NULL) {}
	Node(int val, Node* elem) : _value(val), _pNext(elem){}
	~Node(){};

	void setValue(int val){
		_value = val;
	}
	int getValue(){
		return _value;
	}
	void setNext(Node* elem){
		_pNext = elem;
	}
	Node* getNext(){
		return _pNext;
	}
};


class LinkedList{
private:
	Node* _pHead;

public:
	LinkedList() :_pHead(NULL){};
	LinkedList(int a){
		_pHead = new Node(a);
	}
	void addNode(int a){
		Node* elem = new Node(a);
		if (_pHead != NULL){
			Node *p = _pHead;
			while (p->getNext() != NULL){
				p = p->getNext();
			}
			p->setNext(elem);
		}
		else{
			_pHead = elem;
		
		}
	}
	void printList()
	{
		if (_pHead == NULL)
		{
			cout << "LinkedList is empty" << endl;
			return;
		}

		Node *p = _pHead;
		while (p != NULL)
		{
			cout << p->getValue() << endl;
			p = p->getNext();
		}
	}

	bool deleteNode(int val)
	{
		if (_pHead == NULL)
		{
			cout << "List is empty";
			return false;
		}
		if (_pHead->getValue() == val)
		{
			Node* temp = _pHead;
			_pHead = _pHead->getNext();
			delete temp;
		}

		Node* ptr = _pHead;
		
		while (ptr != NULL && ptr->getNext() !=NULL)
		{
			if (ptr->getNext()->getValue() == val)
			{
				Node* temp = ptr->getNext();
				if (ptr->getNext()->getNext() != NULL)
					ptr->setNext(ptr->getNext()->getNext());
				else
					ptr->setNext(NULL);
				delete temp;
			}
			ptr = ptr->getNext();
		}
	
	}
};

int main(){
	LinkedList *newList = new LinkedList();

	newList->addNode(1);
	newList->addNode(2);
	newList->addNode(3);
	newList->addNode(4);
	newList->printList();
	newList->deleteNode(1);
	newList->deleteNode(2);
	newList->deleteNode(3);
	newList->deleteNode(4);
	newList->deleteNode(0);
	newList->printList();
}

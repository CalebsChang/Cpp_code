
#ifndef _LINKEDSTACK
#define _LINKEDSTACK

#include<iostream>
#include<iomanip>
#include"Node.h"
using namespace std;
template<class ItemType>
class LinkedStack
{
private:
	Node<ItemType>* top; 
	Node<ItemType>* getCurrentTop() {
		return top;
	}
public:
	LinkedStack();
	bool isEmpty(); //see if the stack is empty
	bool push(ItemType newItem); //adds newItem into the stack/true if does, false if not
	bool pop(); //removes top of the stack/remove the most recent item added
	ItemType peek(); //returns the top of the stack w/ recent item, doesn't change stack
	void clean(); //takes everything out of the stack (assuming it does)
	bool display();
};

template<class ItemType>
LinkedStack<ItemType>::LinkedStack()
{
	top = NULL;
}
template<class ItemType>
bool LinkedStack<ItemType>::isEmpty()
{
	return (top == NULL);
}
template<class ItemType>
bool LinkedStack<ItemType>::push(ItemType newItem)
{
		top = new Node<ItemType>(newItem, top);
		return true;
}
template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
	if (isEmpty()) {
		cout << "Pop failed, the stack is empty" << endl;
		return false;
	}
	else {
		Node<ItemType>* curNode = top;
		top = top->getNext();
		curNode->setNext(NULL);
		delete(curNode);
		return top;
	}
}
template<class ItemType>
ItemType LinkedStack<ItemType>::peek()
{
	if (isEmpty()) {
		cout << "Empty Stack!" << endl;
		exit(0);
	}
	return top->getItem();
}
template<class ItemType>
void LinkedStack<ItemType>::clean()
{
	while (!isEmpty()) {
		pop();
	}
	cout << "Clean was executed" << endl;
}
template<class ItemType>
bool LinkedStack<ItemType>::display()
{
	int k = 0;
	if (isEmpty()) {
		cout << "It's an empty stack!" << endl;
		return false;
	}
	else {
		cout << "The Stack contains the following items:" << endl;
		Node<ItemType>* curNode = top;
		while (curNode != NULL) {
			cout << curNode->getItem() << endl;
			curNode = curNode->getNext();
		}
		curNode = top;
		return curNode;
	}
}
#endif


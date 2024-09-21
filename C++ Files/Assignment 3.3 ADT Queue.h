//Header File of Class Template for ADT Queue
#ifndef _QUEUE
#define _QUEUE

#include<iostream>
#include"Node.h"
using namespace std;

template<class ItemType>
class Queue
{
private:
	Node<ItemType>* backPtr;
	Node<ItemType>* frontPtr;
public:
	Queue();  //Default constructor
	Queue(const Queue<ItemType>& aQueue); //Copy constructor
	
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const;
	void display();
};
template<class ItemType>
Queue<ItemType>::Queue()
{
	frontPtr = NULL;
	backPtr = NULL;
}
template<class ItemType>
Queue<ItemType>::Queue(const Queue<ItemType>& aQueue)
{
	Node<ItemType>* originalNodePtr = aQueue.frontPtr;
	if (originalNodePtr == NULL) {
		frontPtr = NULL;
		backPtr = NULL;
	}
	else {
		//copy the first node
		frontPtr = new Node<ItemType>;
		frontPtr->setItem(originalNodePtr->getItem());
		//copy the remaining nodes
		backPtr = frontPtr;
		while (originalNodePtr->getNext() != NULL) {
			originalNodePtr = originalNodePtr->getNext();
			ItemType nextItem = originalNodePtr->getItem();
			Node<ItemType>* newNode = new Node<ItemType>(nextItem);
			backPtr->setNext(newNode);
			backPtr = backPtr->getNext();
		}
		backPtr->setNext(NULL);
	}
}
template<class ItemType>
bool Queue<ItemType>::isEmpty() const
{
	return (frontPtr == NULL && backPtr == NULL);
}
template<class ItemType>
bool Queue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<int>* newNode = new Node<ItemType>(newEntry, NULL);
	if (isEmpty()) {
		frontPtr = newNode;
		backPtr = newNode;
		return true;
	}
	else {
		backPtr->setNext(newNode);
		backPtr = newNode;
		return true;
	}
}
template<class ItemType>
bool Queue<ItemType>::dequeue()
{
	if (isEmpty()) {
		cout << "Queue is empty!" << endl;
		return false;
	}
	else {
		Node<ItemType>* curNode = frontPtr;
		if (frontPtr == backPtr) {
			delete(curNode);
			frontPtr = NULL;
			backPtr = NULL;
			return true;
		}
		else {
			frontPtr = frontPtr->getNext();
			curNode->setNext(NULL);
			delete(curNode);
			return true;
		}
	}
}
//PeekFront is similar or same as peek in LinkedStack
template<class ItemType>
ItemType Queue<ItemType>::peekFront() const
{
	if (isEmpty()) {
		cout << "Peek failed, Empty Queue!" << endl;
		exit(1);
	}
	else {
		return (frontPtr->getItem());
	}
}
template<class ItemType>
void Queue<ItemType>::display()
{
	Node<ItemType>* curNode = frontPtr;
	if (isEmpty()) {
		cout << "Queue failed" << endl;
		exit(1);
	}
	else {
		cout << "Display what in the queue" << endl;
		while (curNode != NULL) {
			cout << curNode->getItem() << endl;
			curNode = curNode->getNext();
		}
	}
}
#endif
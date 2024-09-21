#ifndef _LIST
#define _LIST

#include "Node.h"
#include<iostream>
using namespace std;
template<class ItemType>
class List
{
private:
	Node<ItemType>* head;
	int itemCount;
	Node<ItemType>* getNodeAt(int position) const;
public:
	List();
	List(const List<ItemType>& aList);
	bool isEmpty() const;
	int getLength() const;
	bool insert(int position, const ItemType& newEntry);
	void displayList();
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const;
	void setEntry(int position, const ItemType& newEntry);
};
template<class ItemType>
Node<ItemType>* List<ItemType>::getNodeAt(int position) const 
{
	Node<ItemType>* curNode = head;
	if (position < 1 or position > itemCount) {
		cout << "INVALID POSITION" << endl;
		return NULL;
	}
	for (int i = 0; i < position-1; i++)
		curNode = curNode->getNext();
		return curNode;
}
//Done 
template<class ItemType>
List<ItemType>::List()
{
	head = NULL;
	itemCount = 0;
}
//Done (i think)
template<class ItemType>
List<ItemType>::List(const List<ItemType> &aList)
{
	if (aList.isEmpty())
	{
		head = NULL;
		itemCount = 0;
	}
	else
	{
		Node<ItemType>* origNode = aList.head;
		head = new Node<ItemType>(origNode->getItem(), NULL);
		itemCount++;
		
		Node<ItemType>* curNode = head;
		Node<ItemType>* newNode;
		
		while (origNode->getNext() != NULL)
		{
			origNode = origNode->getNext();
			newNode = new Node<ItemType>(origNode->getItem(), NULL);
			curNode->setNext(newNode);
			curNode = curNode->getNext();
			itemCount++;
		}
	}
}
//Done
template<class ItemType>
bool List<ItemType>::isEmpty() const
{
	return (itemCount == 0);
}
template<class ItemType>
int List<ItemType>::getLength() const
{
	return itemCount;
}
template<class ItemType>
//come back to this one 
bool List<ItemType>::insert(int position, const ItemType& newEntry)
{
	if ((position >= 1) && (position <= itemCount + 1)) 
	{
		Node<ItemType>* newNode, *curNode, *preNode;
		if (position == 1)
		{
			newNode = new Node<ItemType>(newEntry, head);
			head = newNode;
			itemCount++;
			return true;
		}

		preNode = getNodeAt(position - 1);
		curNode = preNode->getNext();
		newNode = new Node<ItemType>(newEntry, curNode);
		preNode->setNext(newNode);
		itemCount++;
		return true;
		
	}
	else {
		cout << "Warning: INVALID POSITION!\n";
		cout << "Warning: INSERTION FAILED!\n";
		return false;
	}
}

//Done
template<class ItemType>
void List<ItemType>::displayList()
{
	Node<ItemType>* curNode = head;
	if (head == NULL)
		cout << "It is an empty list!\n";

	while (curNode != NULL) {
		cout << curNode->getItem() << endl;
		curNode = curNode->getNext();
	}
}
template<class ItemType>
//Could possibly work but maybe 
bool List<ItemType>::remove(int position)
{
	if (position < 1 or position > itemCount)
	{
		cout << "Invalid Position!" << endl;
		return false;
	}
	else
	{
		Node<ItemType>* curNode, * preNode;
		if (position == 1)
		{
			curNode = getNodeAt(position);
			head = curNode->getNext();
			curNode->setItem(NULL);
			delete(curNode);
			itemCount--;
			return true;
		}
		else {
			preNode = getNodeAt(position - 1);
			curNode = preNode->getNext();
			preNode->setNext(curNode->getNext());
			curNode->setItem(NULL);
			delete(curNode);
			itemCount--;
			return true;
		}
	}
}
template<class ItemType>
void List<ItemType>::clear()
{
	while (head != NULL) 
		remove(1);
}
template<class ItemType>
ItemType List<ItemType>::getEntry(int position) const
{
	if (position < 1 or position > itemCount)
	{
		cout << "Invalid Position!" << endl;
		return false;
	}
	else
	{
		Node<ItemType>* curNode;
		curNode = getNodeAt(position);
		return(curNode->getItem());
	}
}
template<class ItemType>
void List<ItemType>::setEntry(int position, const ItemType& newEntry)
{
	Node<ItemType>* curNode;
	curNode = getNodeAt(position);
	curNode->setItem(newEntry);
}
#endif
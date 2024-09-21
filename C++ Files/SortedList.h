#ifndef _SORTED_LIST
#define _SORTED_LIST

#include"Node.h"
#include<iostream>
using namespace std;

template<class ItemType>
class SortedList
{
private:
	Node<ItemType>* head;
	int itemCount; //Current count of list items
	Node<ItemType>* getNodeBefore(const ItemType& anEntry)const;
	Node<ItemType>* getNodeAt(int position) const; //Return a pointer that hold the address of the node at 'position'
public:
	SortedList(); //Default constructor
	SortedList(const SortedList<ItemType>& aList); //Copy constructor
	bool isEmpty() const;  //Check if the list empty (no item stored in the array)
	int getLength() const; //Returns the number of items in the list
	bool remove(int position); //Remove an entry at given position from the list
	void clear(); //remove all the items from the list
	ItemType getEntry(int position) const; //Retrieves an item on the list at the given position
	void displayList();
	
	//Following are three new methods:
	void insertSorted(const ItemType& newEntry);
	bool removeSorted(const ItemType& anEntry);
	int getPosition(const ItemType& newEntry) const;
};
//Complete all the constructors and methods here:
template<class ItemType>
//return value can be wrong
Node<ItemType>* SortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
	Node<ItemType>* curNode = head, * preNode = NULL;
	if (curNode == NULL or isEmpty()) {
		return NULL;
	}
	else {
		while (curNode != NULL and curNode->getItem() < anEntry)
		{
			preNode = curNode;
			curNode = curNode->getNext();
		}
		return preNode; 
	}
}
template<class ItemType>
Node<ItemType>* SortedList<ItemType>::getNodeAt(int position) const
{
	Node<ItemType>* curNode = head;
	if (position < 1 or position > itemCount or isEmpty()) {
		cout << "INVALID POSITION" << endl;
		return NULL;
	}
	for (int i = 0; i < position - 1; i++) 
		curNode = curNode->getNext();
		return curNode;
	
}
template<class ItemType>
SortedList<ItemType>::SortedList()
{
	head = NULL;
	itemCount = 0;
}
template<class ItemType>
SortedList<ItemType>::SortedList(const SortedList<ItemType>& aList)
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
template<class ItemType>
bool SortedList<ItemType>::isEmpty() const
{
	return (itemCount == 0);
}
template<class ItemType>
int SortedList<ItemType>::getLength() const
{
	return itemCount;
}
template<class ItemType>
void SortedList<ItemType>::displayList()
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
bool SortedList<ItemType>::remove(int position)
{
	if (position < 1 or position > itemCount or isEmpty())
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
			curNode->setNext(NULL);
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
void SortedList<ItemType>::clear()
{
	while (head != NULL)
		remove(1);
	itemCount = 0;
}
template<class ItemType>
ItemType SortedList<ItemType>::getEntry(int position) const
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

//Three new Functions/Menthods
//Potentially could work followed the steps and maybe right
template<class ItemType>
void SortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
	Node<ItemType>* newNode = new Node<ItemType>(newEntry, NULL);
	Node<ItemType>* preNode = getNodeBefore(newEntry);
	//Need to be less or equal to the newEntry while also being in the if statement
	if (preNode == NULL or newNode > preNode)
	{
		newNode->setNext(head);
		head = newNode;
	}
	else {
		newNode->setNext(preNode->getNext());
		preNode->setNext(newNode);
	}
	itemCount++;
}
template<class ItemType>
bool SortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
	if (head == NULL)
		return false;
	else {
		Node<ItemType>* preNode, * curNode = head;
		preNode = getNodeBefore(anEntry);
		//if statement below is if function recived is less or equal to the first node
		if (preNode == NULL) {
			if (anEntry < curNode->getItem()) {
				return false;
			}
			else { //this else is when anEntry equals to curNode 
				head = head->getNext();
				curNode->setNext(NULL);
				delete(curNode);
				itemCount--;
				return true;
			}
		}
		else { //this else is anything other than anentry being equal or less than
			curNode = preNode->getNext();
			if (curNode == NULL) {
				return false;
			}
			else {
				if (curNode->getItem() == anEntry) {
					preNode->setNext(curNode->getNext());
					curNode->setNext(NULL);
					delete(curNode);
					itemCount--;
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}
template<class ItemType>
int SortedList<ItemType>::getPosition(const ItemType& newEntry) const
{
	int position = 1;
	Node<ItemType>* curNode = head;
	//if statement is to make sure the list is empty
	if (isEmpty()) {
		return position;
	}
	else {
		while (curNode != NULL and curNode->getItem() < newEntry) {
			curNode = curNode->getNext();
			position++;
		}
		return position; 
	}
}
#endif

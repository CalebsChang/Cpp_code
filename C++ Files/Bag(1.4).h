//Header File for class Bag (Example for ADT and its Implementations)
#ifndef _Bag
#define _Bag
#include <iostream>
using namespace std;

//Class Definition (Interface)
template<class ItemType>
class Bag
{
private:
	ItemType items[100]; //Array as (items) / variable as (itemCount)
	int itemCount; //This will record the number of data stored
public:
	Bag(); //Default Constructor / There is no non-default constructor for this class
	int getItemCount();
	bool isEmpty();
	void add(ItemType item);
	void remove(ItemType item);
	void display();
	void clear();
	bool contains(ItemType item);
	bool removeMax();
	ItemType getMax();
	ItemType getSum();
};
//Definition of Contructors
template<class ItemType>
Bag<ItemType>::Bag() //To ensure the object will have an empty bag or 0
{
	itemCount = 0;
}

template<class ItemType>
int Bag<ItemType>::getItemCount() //Will return the value of the variable itemCount in the class
{
	return itemCount;
}

template<class ItemType>
bool Bag<ItemType>::isEmpty() //Will return true if bag doesnt contain data, otherwise return false
{
	return (itemCount == 0); //Basically a shorter version of true/false statement
}

template<class ItemType>
void Bag<ItemType>::add(ItemType item) //Will add a new integer into the bag
{
	if (itemCount == 100)
		cout << "The Bag is full!" << endl;
	else {
		items[itemCount] = item;
		itemCount++;
	}
}

template<class ItemType>
void Bag<ItemType>::remove(ItemType item)
{
	if (isEmpty()) {
		cout << "Removal is failed! The bad is empty!" << endl;
	}
	else 
		if (!contains(item)) {
		cout << "Removal is faled! the item is not in the bag." << endl;
	}
	else {
		//First, find the index of the item
		int index = 0;
		for (int i = 0; i < itemCount; i++) {
			if (items[i] == item)
			{
				index = i;
				break;
			}
		}
		//To remove the item, shifting all # on the right to the left by one 
		for (int i = index; i < itemCount - 1; i++) {
			items[i] = items[i + 1];
		}
		itemCount--;
	}
}

template<class ItemType>
void Bag<ItemType>::display() //Display items in bag
{
	for (int i = 0; i < itemCount; i++) {
		cout << items[i] << " ";
	}
}

template<class ItemType>
void Bag<ItemType>::clear() //Will empty the bag 
{
	itemCount = 0;
}

template<class ItemType>
bool Bag<ItemType>::contains(ItemType anItem)
{
	for (int i = 0; i < itemCount; i++) {
		if (items[i] == anItem)
			return true;
	}
	return false;
}

//HW Programs
template<class ItemType>
ItemType Bag<ItemType>::getMax()
{
	ItemType max = items[0];

	for (int i = 0; i < itemCount; i++) {
		if (items[i+1] > max)
			max = items[i+1];
	}
	if (itemCount == 0)
		exit(1);
	else {
		cout << "The radius is: " << max << endl;
		return max;
	}
}
template<class ItemType>
bool Bag<ItemType>::removeMax()
{
	if (isEmpty())
		return false;
	else {
		ItemType a = items[0];
		for (int i = 1; i < itemCount; i++) {
			if (items[i] > a)
				a = items[i];
		}
		remove(a);
		return true;
	}
}
template<class ItemType>
ItemType Bag<ItemType>::getSum()
{
	ItemType s = 0;
	for (int i = 0; i < itemCount; i++) {
		s = s + items[i];
	}
		if (itemCount == 0)
			exit(1);
		else {
			cout << "The radius is: " << s << endl;
			
		}
		return s;
}

#endif

#include<iostream>
#include<iomanip>
using namespace std;

//This Bag header/function purpose is to hold integers in the Bag
class Bag
{
private:
	int item[100]; //Item is the slots/amount that the bag can hold array(100)
	int itemCount; //ItemCount is ment to record the amount that in the bag currently 
public:
	Bag();
	bool add(int newItem);
	void display(); //If fucntion does not has return value put void in front of it
	bool remove(int anItem);
	bool isEmpty(); //This function checks if the Bag is empty
	bool contain(int anItem);
	void clear(); //This function clears the Bag that holds integers
	int getSum();
	void getMax();
	void getMin();
	int getPos(int arr);
	void sortItems();
};
//Implementations
Bag::Bag()
{
	itemCount = 0;
}
bool Bag::add(int newItem)
{
	if (itemCount == 100)
	{
		cout << "The Bag is full!" << endl;
		return false;
	}
	else
	{
		item[itemCount] = newItem; //item is the array, itemCount holds the array slots, newItem is the integer going into the Bag 
		itemCount++; //Must (++) itemCount in order to continue to put more in the array slots
		return true;
	}
}
void Bag::display()
{
	cout << "The bag has the following integers in it: " << endl;
	for (int i = 0; i < itemCount; i++)
	{
		cout << item[i] << setw(5);
	}
}
bool Bag::remove(int anItem) //This is to remove the last integer in the array
{
	if (itemCount == 0)
	{
		return false;
		cout << "Item is not in the bag, removal failed." << endl;
	}
	else
	{
		int index = 0;
		for (int i = 0; i < itemCount; i++)
		{
			if (item[i] == anItem)
			{
				index = i;
				for (int k = index; k < itemCount - 1; k++)
				{
					item[k] = item[k + 1];
				}
				itemCount -- ;
				return true;
			}
		}
		cout << "Item is not in the bag, removal failed." << endl;
		return false;
	}
}
bool Bag::isEmpty()
{
	return(itemCount == 0);
	//If and else statement
	/*if (itemCount == 0)
		return true;
	else
		return false;*/
}
bool Bag::contain(int anItem)
{
	for (int i = 0; i < itemCount; i++)
	{
		if (item[i] == anItem)
			return true;
	}
	return false;
}
void Bag::clear()
{
	itemCount = 0;
}
int Bag::getSum()
{
	int s = 0;
	for (int i = 0; i < itemCount; i++)
		s += item[i];
	s /= 78;
	return s;
}
void Bag::getMax()
{
	//item[0] is 41 the first array
	int max = item[0];
		for (int i = 0; i < itemCount; i++)
		{
			if (max < item[i+1])
				max = item[i+1];
		}
		cout <<"the max is: " << max << endl;
}
void Bag::getMin()
{
	int min = item[0];
	for (int i = 0; i < itemCount; i++)
	{
		if (item[i] < min)
			min = item[i];
	}
	cout << "the min is: " << min << endl;
}
int Bag::getPos(int arr)
{
	int aPos = -1;
	for (int i = 0; i < itemCount; i++)
	{
		if (item[i] == arr)
			aPos = i;
	}
	//ItemCount = 10
	cout << "The # position is: " << aPos << endl;
	return aPos;
}
void Bag::sortItems(itemCount, b)
{
	int fPlace = item[0];
	int store;
	for (int i = 1; i < itemCount; i++)
	{
		if (fPlace < item[i])
		{
			store = item[i];
			item[i] = fPlace;
			fPlace = store;
		}
	}
}
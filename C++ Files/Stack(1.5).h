//Header file of the class template Stack

#ifndef _STACK
#define _STACK

#include<iostream>
#include<iomanip>
using namespace std;
template<class ItemType>
class Stack
{
private:
	ItemType items[100];
	int top; //index of the item unit is on the top of the stack (the array #)
	int getCurrentTop() {
		return top;
	}
	void setCurrentTop(int s) {
		top = s;
	}
public:
	Stack();
	bool isEmpty(); 
	bool push(ItemType newItem); 
	bool pop(); 
	ItemType peek();
	void clean(); 
	//bool display();

	//HW Fuctions
	int GetItemCount();
	void display();
};

template<class ItemType>
Stack<ItemType>::Stack()
{
	setCurrentTop(-1);
}
template<class ItemType>
bool Stack<ItemType>::isEmpty()
{
	return (top == -1);
}
template<class ItemType>
bool Stack<ItemType>::push(ItemType newItem)
{
	if (top == 99) {
		cout << "Push failed, the Stack is full!" << endl;
		return false;
	}
	else {
		items[++top] = newItem; //++top is ([top + 1] & top++) into one code
		return true;
	}
}
template<class ItemType>
bool Stack<ItemType>::pop()
{
	if (isEmpty()) {
		cout << "Pop failed, the stack is empty" << endl;
		return false;
	}
	else {
		top--;
		return true;
	}
}
template<class ItemType>
ItemType Stack<ItemType>::peek()
{
	if (isEmpty()) {
		cout << "The stack is empty, program aborted!" << endl;
		exit(0);
	}
	else {
		return items[top];
	}
}
template<class ItemType>
void Stack<ItemType>::clean()
{
	setCurrentTop(-1);
}
/*template<class ItemType>
bool Stack<ItemType>::display()
{
	int k = 0;
	if (isEmpty()) {
		cout << "It's an empty stack!" << endl;
		return false;
	}
	else {
		cout << "The Stack contains the following items:" << endl;
		for (int i = 0; i <= top; i++) {
			cout << items[i] << setw(1) << " ";
		}
		cout << endl;
		return true;
	}
}*/


template<class ItemType>
int Stack<ItemType>::GetItemCount() {
	return top;
}
template<class ItemType>
void Stack<ItemType>::display() {
	for (int i = 0; i <= top; i++) {
		cout << items[i] << " ";
	}
	cout << endl;
}
#endif

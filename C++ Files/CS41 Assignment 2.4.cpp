#include<iostream>
#include"Node.h"
using namespace std;

//Double Check Functions in case it wrong
//Task 1 (Completed)
bool contains(Node<char>* list, char item)
{
	Node<char>* cNode = list;
	while (cNode != NULL) {
		if (cNode->getItem() == item)
			return true;
		cNode = cNode->getNext();
	}
	return false;
}
//Task 2 (Completed)
int getLength(Node<int>* list) 
{
	int s = 0;
	Node<int>* cNode3 = list;
	while (cNode3 != NULL) {
		s++;
		cNode3 = cNode3->getNext();
	}
	return s;
}
//Task 3 (Completed)
int getMax(Node<int>* list)
{
	int nMax = list->getItem();
	Node<int>* cNode3 = list;
	while (list->getNext() != NULL) {
		if (nMax < list->getItem())
			nMax = list->getItem();
		list = list->getNext();
	}
	return nMax;
}
//Task 4 (Completed)
int getLast(Node<int>* list)
{
	int nLast;
	Node<int>* cNode3 = list;
	Node<int>* pNode2;
	while (cNode3->getNext() != NULL) {
		pNode2 = cNode3;
		cNode3 = cNode3->getNext();
	}
	cNode3->setNext(NULL);
	nLast = cNode3->getItem();
	return nLast;
}

int main()
{
	Node<char>* tHead2 = NULL;
	string input;
	cout << "Enter a string of characters: " << endl;
	cin >> input;
	int c = input.length();
	for (int i = 0; i < input.length(); i++) {
		input[i] = input[i];
		tHead2 = new Node<char>(input[i], tHead2);
	}
	cout << "=====" << endl;
	Node <char>* cNode2 = tHead2;
	while (cNode2 != NULL) {
		cout << cNode2->getItem() << endl;
		cNode2 = cNode2->getNext();
	}
	cout << "=============" << endl;
	if (contains(tHead2, 'c')) {
		cout << "Yes it in the linked list " << endl;
	}
	else {
		cout << "No it is not in the linked list " << endl;
	}
	cout << "============" << endl;
	Node<int>* Thead3 = NULL;
	int iNum, r;
	for (int i = 0; i < 50; i++) {
		r = rand() % 100;
		Thead3 = new Node<int>(r, Thead3);
	}
	cout << "==========" << endl;
	int s = getLength(Thead3);
	cout << "The amount of nodes in the linked list " << s << endl;
	cout << "==========" << endl;
	int nMax = getMax(Thead3);
	cout << "The Max # in the linked list: " << nMax << endl;
	cout << "==========" << endl;
	int nLast = getLast(Thead3);
	cout << "The last integer in the linked list is: " << nLast << endl;
	cout << "==========" << endl;

	return 0;
}
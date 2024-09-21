#include<iostream>
#include<string>
#include"Node.h"
using namespace std;

int main() 
{
	//HW Task 1 (Completed)
	Node<string>* head = NULL;
	string dItems;
	for (int i = 0; i < 4; i++) {
		cout << "Please enter a word: " << endl;
		cin >> dItems;
		head = new Node<string>(dItems, head);
	}
	cout << "============" << endl;
	//Display Task 1
	Node<string>* cNode = head;
	for (int i = 0; i < 4; i++) {
		cout << cNode->getItem() << endl;
		cNode = cNode->getNext();
	}
	cout << "=============" << endl;

	//Hw Task 2 (Complete)
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

	//Hw Task 3 (Complete)
	Node<int>* Thead3 = NULL;
	int iNum, r;
	for (int i = 0; i < 12; i++) {
		r = rand() % 100;
		Thead3 = new Node<int>(r, Thead3);
	}
	cout << "Guess a number between 0-99" << endl;
	cin >> iNum;
	Node<int>* cNode3 = Thead3;
	while (cNode3 != NULL) {
		if (iNum == cNode3->getItem()) {
			cout << "You got it!" << endl;
			break;
		}
		cNode3 = cNode3->getNext();
		if (cNode3 == NULL) {
			cout << "No it is not in the list" << endl;
		}
	}
	cout << "==========" << endl;

	//Hw Task 4 (Complete)
	Node<int>* tHead4 = NULL;
	int rNum;
	int Ccount = 0;
	for (int i = 0; i < 50; i++) {
		rNum = rand() % 100;
		tHead4 = new Node<int>(rNum, tHead4);
	}
	Node<int>* cNode4 = tHead4;
	while (cNode4 != NULL) {
		if (cNode4->getItem() % 2 != 0)
			Ccount++;
		cNode4 = cNode4->getNext();
	}
	cout << "Total # of odd integers in the list: " << Ccount << endl;

	return 0;
}
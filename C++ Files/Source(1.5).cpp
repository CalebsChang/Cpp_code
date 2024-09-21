#include <iostream>
#include <iomanip>
#include "Stack.h"
#include <string>
using namespace std;

int main()
{
	Stack<int> intStack;
	Stack<char> charStack;
	int r;
	for (int i = 0; i < 50; i++)
	{
		r = rand() % 100;
		if (r % 2 != 0)
			intStack.push(r);
	} 
	cout << "This is all the odd integers that is in the Stack:" << endl;
	intStack.display();
	cout << "==========" << endl;
	string c;
	cout << "Please enter a string of characters. " << endl;
	getline(cin, c);
	int a;
	a = (c.length() / 2);
	for (int i = 0; i <= a; i++) {
		charStack.push(c[i]);
	}
	cout << "=============" << endl;
	cout << "This is the first half of the char string:" << endl;
	charStack.display();
	cout << endl;
	return 0;
}
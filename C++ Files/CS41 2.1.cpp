#include <iostream>
#include"Stack.h"
using namespace std;

bool isInLanguage(string aString) {

	
	Stack<char> myStack;
	int k = aString.length();
	if (aString.length() == 0) {
		return false;
	}
	else {
		for (int i = 0; i < aString.length(); i++) {
			myStack.push(aString[i]);
		}
			while (aString[k] != '\0') {
				if (myStack.peek() == myStack.peek()) {
					myStack.pop();
					k++;
				}
				else
					return false;
			}
		return true;
	}
}

int main()
{
	string a = "a-b-d-c";
	if (isInLanguage(a)) {
		cout << "It is in language." << endl;
	}
	else {
		cout << "It is not in language." << endl;
	}
	return 0;
};
#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;
bool balanced_Checking(string str)
{
	Stack<char> charStack;
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == '{' or str[i] == '(') { //Push into stack
			charStack.push(str[i]);
			i++;
		}
		else {
			if (str[i] == '}') { //Make sure stack is empty or match
				if (charStack.isEmpty() or charStack.peek() != '{') {
					cout << "Falied to pop charstack: }" << endl;
					return false;
				}
				else {
					charStack.pop();
					i++;
				}
			}
			else {
				if (str[i] == ')') {
					if (charStack.isEmpty() or charStack.peek() != '(') {
						cout << "Failed to pop charStack: )" << endl;
						return false;
					}
					else {
						charStack.pop();
						i++;
					}
				}
				else {
					i++;
				}
			}
		}
	}
	if (charStack.isEmpty()) {
		cout << "the stack is empty" << endl;
		return true;
	}
	else {
		return false;
	}
}
int main()
{
	string a = "abc{abc(abc)ba}abc", b = "cba(abc{cac)acb";
	balanced_Checking(a);
	balanced_Checking(b);
	return 0;
}

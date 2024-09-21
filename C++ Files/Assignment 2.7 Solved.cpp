#include<iostream>
using namespace std;

int main()
{
	int a;
	cout << "Please enter a # " << endl;
	cin >> a;
	for (int i = 0; i < a; i++) //This will start with max amount of # but will get smaller to the right 
	{
		for (int k = 0; k < i; k++) //This will be the blank space in between
		{
			cout << "  ";
		}
		for (int j = 0; j < a - i; j++) //The amount of what's going to be display below
		{
			cout << "* ";
		}
		cout << endl;
	}
	cout << "------------------" << endl;

	int length, width = 0;
	cout << "Please enter a length and width " << endl;
	cin >> length;
	cin >> width;
	for (int i = 0; i < length; i++) //This will create a rectangle Length
	{
		for (int k = 0; k < width; k++) { //Create the width
			if (i == 0 or i == length - 1 or k == 0 or k == width - 1)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << endl;
	}
	return 0;
}
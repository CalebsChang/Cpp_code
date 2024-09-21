#include <iostream>
using namespace std;

int main()
{
	int score; 
	char A;
	int points = 0;
	cout << "=============" << endl;
	cout << "    Quiz    " << endl;
	cout << "=============" << endl;
	cout << "1. What is 21%7? " << endl;
	cout << "                 " << endl;
	cout << "a) 6  b) 9  c) 3  d) 10" << endl;
	cin >> A;
	if (A == 'c') {
		cout << "That the correct answer!" << endl;
		points++;
	}
	else {
		cout << "That's the wrong answer! Try again." << endl;
	}
	cout << "------------------------------" << endl;
	cout << "2. How many states are there in the USA? " << endl;
	cout << "                                         " << endl;
	cout << "a) 30  b) 50 c) 51 d) 49" << endl;
	cin >> A;
	if (A == 'b') {
		cout << "That the correct answer!" << endl;
		points++; 
	}
	else {
		cout << "That's the wrong answer! Try again." << endl;
	}
	cout << "------------------------------" << endl;
	cout << "3. What planet are we on? " << endl; 
	cout << "     " << endl;
	cout << "a) Earth b) Mars c) Sun d) Moon" << endl;
	cin >> A;
	if (A == 'a') {
		cout << "That the correct answer!" << endl;
		points++; 
	}
	else {
		cout << "That's the wrong answer! Try again." << endl;
	}
	cout << "------------------------------" << endl;
	cout << "4. How many cycles are there in a moon cycle? " << endl;
	cout << "    " << endl; 
	cout << "a) 6 b) 10 c) 4 d) 8" << endl;
	cin >> A;
	if (A == 'd') {
		cout << "That the correct answer!" << endl;
		points++; 
	}
	else {
		cout << "That's the wrong answer! Try again." << endl;
	}
	cout << "------------------------------" << endl;
	cout << " Your Score on the quiz is: " << points << endl;
	cout << "==================================" << endl;
	cout << "Please Enter 4 intergers" << endl;
	int B, C; 


	return 0;
}
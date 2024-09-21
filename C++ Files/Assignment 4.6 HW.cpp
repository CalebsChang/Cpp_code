#include<iostream>
using namespace std;

void display(int n)
{
	if (n == 1)
		cout << n << endl;
	else {
		cout << n << endl;
		display(n - 1);
	}
}

int sumSquares(int n)
{
	int s = 0;
	if (n == 1)
		return 1;
	else
	{
		s = sumSquares(n - 1);
		return s + n;
	}
}

bool containZero(int a[], int length) //Return true if there is a 0
{
	if (length == 0) {
		return false;
	}
	if (a[length] == 0) {
		return true;
	}
	return containZero(a, length - 1);
}

int min(int a[], int length) //Returns Minimum # in array
{
	if (length == 1)
		return a[0];
	else {
		int m = min(a, length - 1);
		if (m < a[length - 1])
			return m;
		else
			return a[length - 1];
	}
}

int main()
{
	int a, b;
	cout << "please enter a integer: " << endl;
	cin >> a;
	cout << "======" << endl;
	display(a);
	cout << "======" << endl;
	int s = sumSquares(a);
	cout << "The sum is: " << s << endl;
	cout << "======" << endl;
	int sample[5] = { 8,1,0,5,10 };
	int bsample[1] = { 0 };
	containZero(sample, 5);
	if (containZero(sample, 5)) {
		cout << "yes, it has a 0" << endl;
	}
	else {
		cout << "no, it don't have a 0" << endl;
	}
	cout << "======" << endl;
	cout <<"the smallest # is: " << min(sample, 5) << endl;
	cout << "=======" << endl;
	return 0;
}
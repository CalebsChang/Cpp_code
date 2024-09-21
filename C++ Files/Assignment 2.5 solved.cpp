#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	double a=0.0;
	int	b = 0,c = 0, d = 0, e;
	double spendOne = 0.0;
	double spendTwo = 0.0;
	double spendThree = 0.0;
	do
	{
		cout << "Please enter the customer's spending: " << endl;
		cin >> a;
		if (a <= 200)
		{
			spendOne += a;
			b++;
		}
		if (a >= 200.01 && a <= 800)
		{
			spendTwo += a;
			c++;
		}
		if (a >= 800.01)
		{
			spendThree += a;
			d++;
		}

		cout << "Continue the Program?" << endl;
		cout << "Enter 0 for yes, Enter other number for no" << endl;
		cin >> e;
	} while (e == 0); //This will ask the user to repeat the program if they want to
	cout << "Customers that spended between $1 to $200: " << b << endl;
	cout << "Total Amount: " << spendOne << endl;
	cout << "Customers that spended between $200 and $800: " << c << endl;
	cout << "Total Amount: " << spendTwo << endl;
	cout << "Customers that spended more than $800: " << d << endl;
	cout << "Total Amount: " << spendThree << endl;

	return 0;


}
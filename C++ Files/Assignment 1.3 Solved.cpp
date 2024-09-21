#include <iostream>
using namespace std;
int main()
{
	double total, month, rate, term;
	double x, y, z;
	cout << "Please Enter the Monthly Deposit: ";
	cin >> month;
	cout << "Please Enter the Interest Rate: ";
	cin >> rate;
	cout << "Please Enter the yearly term: ";
	cin >> term;
	x = pow((1+rate / 1200), 12*term);
	y = rate / 1200;
	z = (x-1) / y;
	total = month * z;
	for (int i = 0; i < total; ++i); 
	cout << "Your monthly payment will be: $" << total << endl;
	return 0;
}
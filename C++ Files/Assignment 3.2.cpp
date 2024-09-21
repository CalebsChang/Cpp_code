#include<iostream>
#include<cmath>
using namespace std;

void sum(double A,double r, double t, double &s1, double &s2, double &s3)
{
	//A is the loan, r is the annual interest, R is the Monthly Payment, and t is the term.
	s1 = A / ((1 - pow((1 + r / 1200), (- 12 * t))) / (r / 1200));
	s2 = s1 * (12 * t);
	s3 = s2 - A; 
}
int main()
{
	int i=0, j;
	double x, y, z, s1, s2, s3; 
	cout << "How many times do you want to see the program: ";
	cin >> j;
	while (i < j)
	{
		cout << "===============================" << endl;
		cout << "Please enter your loan: ";
		cin >> x;
		cout << "Please enter your interest rate: ";
		cin >> y;
		cout << "Please enter your term: ";
		cin >> z;
		sum(x, y, z, s1, s2, s3);
		cout << "===============================" << endl;
		cout << "Your Monthly Payment is: " << s1 << endl;
		cout << "Your Total Payment is: " << s2 << endl;
		cout << "Your Total interest is: " << s3 << endl;
		i++;
	}
	return 0;
}
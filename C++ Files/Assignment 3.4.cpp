#include<iostream>
#include<iomanip>
using namespace std; 

int addFunc(int a[], int len)
{
	int t = 0, i = 0;
	while (i < len)
	{
		t += a[i];
		i++;
	}
	return t;
}
int Large(int a[], int len)
{
	int s = 0, i = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] > s)
			s = a[i];
	}
	return s;
}
int small(int a[], int len)
{
	int k = 0, i = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] < k)
			k = a[i];
	}
	return k;
}
void zeroSmall(int a[], int len)
{
}

int main()
{
	int a[15], min = 0, max = 0, count = 0;
	for (int i = 0; i < 15; i++)
	{
		a[i] = rand() % 100;
		cout << setw(5) << a[i];
	}
	cout << endl;
	for (int i = 0; i < 15; i++)
	{

		if (a[i] >= 70)
		{
			count++;
		}
	}
	cout << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "======================" << endl;
	cout << "The highest score is: " << Large(a,5) << endl;
	cout << "The smallest score is: " << small(a, 5) << endl;
	cout << "The sum of the # is: " << addFunc(a, 5) << endl;
	cout << "Total integers greater and equal to 70 is: " << count << endl;
	cout << "======================" << endl;
	cout << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << a[i] << " ";
		if (a[i] > a[i + 1])
		{
			a[i] = 0;
		}
	}
	cout << endl;
	return 0;
}